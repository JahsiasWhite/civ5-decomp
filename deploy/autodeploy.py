"""Pull-based auto deploy for the coordination server (run by c5d-deploy.timer as root).

Every few minutes: fetch origin/main. If it moved, wait until the GitHub Actions "tests"
workflow for that commit has passed, fast-forward the checkout, and restart c5d if anything
under server/ changed. If /healthz doesn't come back, roll back to the previous commit.

Pull rather than push, so GitHub never holds a key to this machine. For a private repo,
put a read-only token in /etc/c5d-deploy.env as C5D_GITHUB_TOKEN: a fine-grained token for
this repo only, with Contents: read and Actions: read. It's used for both the git fetch and
the workflow lookup (passed to git through the environment, never on the command line).
A public repo needs none (60 API requests/hour unauthenticated; this makes at most one per
run, only while a new commit is waiting).
Standard library only. Logs go to the journal: journalctl -u c5d-deploy
"""
import base64
import json
import os
import subprocess
import sys
import time
import urllib.error
import urllib.request
from pathlib import Path

REPO = Path(os.environ.get("C5D_REPO", "/opt/civ5-decomp"))
BRANCH = os.environ.get("C5D_BRANCH", "main")
SLUG = os.environ.get("C5D_GITHUB_REPO", "JahsiasWhite/civ5-decomp")
WORKFLOW = os.environ.get("C5D_WORKFLOW_NAME", "tests")
TOKEN = os.environ.get("C5D_GITHUB_TOKEN", "")
SERVICE = os.environ.get("C5D_SERVICE", "c5d")
HEALTH = f"http://127.0.0.1:{os.environ.get('C5D_PORT', '8765')}/healthz"
STATE = Path(os.environ.get("STATE_DIRECTORY", "/var/lib/c5d-deploy")) / "last_rejected"


def log(msg):
    print(msg, flush=True)


def git_env():
    env = dict(os.environ)
    if TOKEN:   # same mechanism actions/checkout uses; GIT_CONFIG_* keeps it out of `ps`
        auth = base64.b64encode(f"x-access-token:{TOKEN}".encode()).decode()
        env.update(GIT_CONFIG_COUNT="1", GIT_CONFIG_KEY_0="http.https://github.com/.extraheader",
                   GIT_CONFIG_VALUE_0=f"AUTHORIZATION: basic {auth}", GIT_TERMINAL_PROMPT="0")
    return env


def git(*args, check=True):
    r = subprocess.run(["git", "-C", str(REPO), "-c", f"safe.directory={REPO}", *args],
                       capture_output=True, text=True, env=git_env())
    if check and r.returncode:
        raise RuntimeError(f"git {args[0]} failed: {r.stderr.strip()}")
    return r if not check else r.stdout.strip()


def check_state(sha):
    """'success', 'pending' or 'failed' for the CI workflow on this commit."""
    req = urllib.request.Request(
        f"https://api.github.com/repos/{SLUG}/actions/runs?head_sha={sha}&event=push",
        headers={"Accept": "application/vnd.github+json", "User-Agent": "c5d-autodeploy",
                 **({"Authorization": f"Bearer {TOKEN}"} if TOKEN else {})})
    with urllib.request.urlopen(req, timeout=20) as r:
        runs = [x for x in json.load(r).get("workflow_runs", []) if x.get("name") == WORKFLOW]
    if not runs or any(x["status"] != "completed" for x in runs):
        return "pending"
    return "success" if all(x["conclusion"] == "success" for x in runs) else "failed"


def healthy(tries=15):
    for _ in range(tries):
        time.sleep(2)
        try:
            with urllib.request.urlopen(HEALTH, timeout=5) as r:
                if json.load(r).get("ok"):
                    return True
        except Exception:
            pass
    return False


def restart():
    subprocess.run(["systemctl", "restart", SERVICE], check=True)


def reject(sha):
    STATE.parent.mkdir(parents=True, exist_ok=True)
    STATE.write_text(sha)


def main():
    git("fetch", "--quiet", "origin", BRANCH)
    cur, new = git("rev-parse", "HEAD"), git("rev-parse", f"origin/{BRANCH}")
    if cur == new:
        return 0
    if STATE.exists() and STATE.read_text().strip() == new:
        return 0                                   # already rejected (failed CI or rolled back)
    if git("merge-base", "--is-ancestor", cur, new, check=False).returncode != 0:
        log(f"origin/{BRANCH} {new[:8]} is not a fast-forward of {cur[:8]}; fix the checkout by hand")
        return 1

    try:
        state = check_state(new)
    except urllib.error.HTTPError as e:
        hint = " (private repo? set C5D_GITHUB_TOKEN in /etc/c5d-deploy.env)" if e.code == 404 else ""
        log(f"GitHub check lookup for {new[:8]} failed: HTTP {e.code}{hint}")
        return 1
    except OSError as e:
        log(f"GitHub check lookup for {new[:8]} failed: {e}")
        return 1
    if state == "pending":
        return 0                                   # CI still running; next tick
    if state == "failed":
        log(f"{new[:8]}: '{WORKFLOW}' workflow failed on GitHub; not deploying")
        reject(new)
        return 0

    changed = git("diff", "--name-only", cur, new).splitlines()
    server_changed = any(p.startswith("server/") for p in changed)
    git("merge", "--ff-only", "--quiet", new)
    log(f"deployed {cur[:8]} -> {new[:8]} ({len(changed)} files)")
    if not server_changed:
        return 0                                   # nothing the running server reads changed

    restart()
    if healthy():
        log(f"{SERVICE} restarted, /healthz ok")
        return 0

    log(f"/healthz failed after deploying {new[:8]}; rolling back to {cur[:8]}")
    git("reset", "--hard", "--quiet", cur)
    restart()
    log("rolled back, /healthz " + ("ok" if healthy() else "STILL FAILING"))
    reject(new)
    return 1


if __name__ == "__main__":
    try:
        sys.exit(main())
    except RuntimeError as e:
        hint = "" if TOKEN else " (private repo? set C5D_GITHUB_TOKEN in /etc/c5d-deploy.env)"
        log(f"{e}{hint}")
        sys.exit(1)
