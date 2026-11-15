"""Client for the coordination server (c5d remote ...).

Server URL and token live in config.local.json (git-ignored).
"""
import json
import urllib.error
import urllib.request
from pathlib import Path

LOCAL = Path(__file__).resolve().parent.parent / "config.local.json"


def load_local():
    return json.loads(LOCAL.read_text()) if LOCAL.exists() else {}


def save_local(d):
    LOCAL.write_text(json.dumps(d, indent=2) + "\n")


class Remote:
    def __init__(self, server=None, token=None):
        loc = load_local()
        self.server = (server or loc.get("server") or "").rstrip("/")
        self.token = token or loc.get("token")
        if not self.server or not self.token:
            raise SystemExit("not logged in: run `c5d remote login --server URL --token TOKEN`")

    def call(self, method, path, body=None):
        req = urllib.request.Request(
            self.server + path, method=method,
            data=json.dumps(body or {}).encode() if method == "POST" else None,
            headers={"Authorization": f"Bearer {self.token}", "Content-Type": "application/json",
                     "User-Agent": "c5d-cli"})
        try:
            with urllib.request.urlopen(req, timeout=30) as r:
                return json.loads(r.read() or b"{}")
        except urllib.error.HTTPError as e:
            try:
                msg = json.loads(e.read()).get("error", str(e))
            except Exception:
                msg = str(e)
            raise SystemExit(f"server: {msg}")
        except urllib.error.URLError as e:
            raise SystemExit(f"cannot reach {self.server}: {e.reason}")
