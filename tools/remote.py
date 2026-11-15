"""Client for the coordination server (c5d remote ...).

Server URL and token live in config.local.json (git-ignored).
"""
import json
import urllib.error
import urllib.request

from config import load_local, save_local  # noqa: F401  (config.local.json)


class RemoteError(SystemExit):
    """A failed server call. `status` is the HTTP status, or None if the server was unreachable."""

    def __init__(self, msg, status=None):
        super().__init__(msg)
        self.status = status


def logged_in():
    loc = load_local()
    return bool(loc.get("server") and loc.get("token"))


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
            raise RemoteError(f"server: {msg}", e.code)
        except urllib.error.URLError as e:
            raise RemoteError(f"cannot reach {self.server}: {e.reason}")


class ServerClaims:
    """Mirror local task claims (`c5d task next`, `c5d agent`) on the server, so nobody else
    is handed the same function. Without a login, or with `--local`, everything stays local.
    The server never blocks local work: if it can't be reached (or refuses for another
    reason, e.g. terms not accepted) this warns once and carries on locally."""

    def __init__(self, remote=None):
        self.r = remote

    @classmethod
    def from_config(cls, local_only=False):
        return cls(None if local_only or not logged_in() else Remote())

    def _offline(self, e):
        print(f"warning: {e}; claims stay local for this run", flush=True)
        self.r = None

    def claim(self, addr, worker):
        """True: go ahead (claimed on the server, or the server isn't in play).
        False: someone else holds it or it's already matched there, so skip it."""
        if self.r is None:
            return True
        try:
            self.r.call("POST", "/api/claim", {"addr": f"0x{addr:08x}", "worker_prefix": worker})
            return True
        except RemoteError as e:
            if e.status == 409 and "limit" in str(e):
                raise SystemExit(f"{e}. Release some with `c5d task release <addr>` "
                                 "(see `c5d remote status`)")
            if e.status == 409:
                print(f"0x{addr:08x}: skipped ({str(e).removeprefix('server: ')})", flush=True)
                return False
            if e.status == 404:             # server doesn't track it: nobody else can claim it
                return True
            self._offline(e)
            return True

    def release(self, addr):
        if self.r is None:
            return
        try:
            self.r.call("POST", "/api/release", {"addr": f"0x{addr:08x}"})
        except RemoteError as e:
            if e.status is None or e.status >= 500:
                self._offline(e)
