"""Pull-based auto deploy for the coordination server (run by c5d-deploy.timer as root).

Every few minutes: fetch origin/main. If it moved, wait until GitHub's "server-tests"
check for that commit has passed, fast-forward the checkout, and restart c5d if anything
under server/ changed. If /healthz doesn't come back, roll back to the previous commit.

Pull rather than push, so GitHub never holds a key to this machine. The repo is public,
so the check lookup needs no token (unauthenticated limit: 60 requests/hour; this makes
at most one per run, and only while a new commit is waiting).
Standard library only. Logs go to the journal: journalctl -u c5d-deploy
"""
import json
import os
import subprocess
import sys
import time
import urllib.request
from pathlib import Path

REPO = Path(os.environ.get("C5D_REPO", "/opt/civ5-decomp"))
BRANCH = os.environ.get("C5D_BRANCH", "main")
SLUG = os.environ.get("C5D_GITHUB_REPO", "JahsiasWhite/civ5-decomp")
CHECK = os.environ.get("C5D_CHECK_NAME", "server-tests")
SERVICE = os.environ.get("C5D_SERVICE", "c5d")
HEALTH = f"http://127.0.0.1:{os.environ.get('C5D_PORT', '8765')}/healthz"
STATE = Path(os.environ.get("STATE_DIRECTORY", "/var/lib/c5d-deploy")) / "last_rejected"


def log(msg):
    print(msg, flush=True)


def git(*args):
    return subprocess.run(["git", "-C", str(REPO), "-c", f"safe.directory={REPO}", *args],
                          check=True, capture_output=True, text=True).stdout.strip()


def check_state(sha):
    """'success', 'pending' or 'failed' for the CI check on this commit."""
    req = urllib.request.Request(
        f"https://api.github.com/repos/{SLUG}/commits/{sha}/check-runs?check_name={CHECK}",
        headers={"Accept": "application/vnd.github+json", "User-Agent": "c5d-autodeploy"})
    with urllib.request.urlopen(req, timeout=20) as r:
        runs = json.load(r).get("check_runs", [])
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
    if subprocess.run(["git", "-C", str(REPO), "-c", f"safe.directory={REPO}",
                       "merge-base", "--is-ancestor", cur, new]).returncode != 0:
        log(f"origin/{BRANCH} {new[:8]} is not a fast-forward of {cur[:8]}; fix the checkout by hand")
        return 1

    state = check_state(new)
    if state == "pending":
        return 0                                   # CI still running; next tick
    if state == "failed":
        log(f"{new[:8]}: '{CHECK}' failed on GitHub; not deploying")
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
    sys.exit(main())
