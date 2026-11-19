"""Client for the coordination server (c5d remote ...).

Server URL and token live in config.local.json (git-ignored).
"""
import json
import urllib.error
import urllib.request

import config
from config import load_local, save_local  # noqa: F401  (config.local.json)

# calls about one function; they carry the module this run works on (see Remote.call)
FUNCTION_CALLS = ("/api/claim", "/api/release", "/api/report")


class RemoteError(SystemExit):
    """A failed server call. `status` is the HTTP status, or None if the server was unreachable."""

    def __init__(self, msg, status=None):
        super().__init__(msg)
        self.status = status


def logged_in():
    loc = load_local()
    return bool(loc.get("server") and loc.get("token"))


class Remote:
    def __init__(self, server=None, token=None, module=None):
        loc = load_local()
        # functions are (module, addr) on the server; a call that doesn't name a module
        # means the exe, so only other modules need to say so (older servers know only the exe)
        self.module = config.current_module_id(module)
        self.server = (server or loc.get("server") or "").rstrip("/")
        self.token = token or loc.get("token")
        if not self.server or not self.token:
            raise SystemExit("not logged in: run `c5d remote login --server URL --token TOKEN`")

    def call(self, method, path, body=None):
        if (method == "POST" and path in FUNCTION_CALLS and self.module != config.DEFAULT_MODULE
                and "module" not in (body or {})):
            body = {**(body or {}), "module": self.module}
        if method == "POST" and path in FUNCTION_CALLS and "build" not in (body or {}):
            # which build of the binary this checkout targets; the server refuses work
            # from a checkout that's behind (e.g. still on the 2014 exe)
            build = config.module((body or {}).get("module") or self.module).build_id
            if build:
                body = {**(body or {}), "build": build}
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


LOCAL_WARNING = ("warning: --local: these claims exist only on this machine. The server can "
                 "hand the same functions to someone else, so use it only for work nobody "
                 "else will pick up (offline, or agreed with the others).")

NOT_LOGGED_IN = ("not logged in, so nobody else would know you're working on these functions "
                 "and the server could hand them to someone else. Run `c5d remote login --server "
                 "URL --token TOKEN` (see CONTRIBUTING.md), or pass --local to work without the "
                 "server anyway.")


class ServerClaims:
    """Mirror local task claims (`c5d task next`, `c5d agent`) on the server, so nobody else
    is handed the same function.

    Claiming never falls back to local-only on its own: everyone's local queue has the same
    order, so a silent local claim almost always collides with what the server hands out
    next. Not being logged in or the server failing stops the run; working local-only takes
    an explicit `--local`, which warns. Releasing never stops anything (a claim left on the
    server just expires)."""

    def __init__(self, remote=None, model=""):
        self.r = remote
        self.model = model          # sent with each claim: credits a match merged before its report

    @classmethod
    def from_config(cls, local_only=False, for_release=False, model=""):
        if local_only:
            if not for_release:
                print(LOCAL_WARNING, flush=True)
            return cls(None)
        if not logged_in():
            if for_release:
                return cls(None)
            raise SystemExit(NOT_LOGGED_IN)
        return cls(Remote(), model)

    def claim(self, addr, worker):
        """True: go ahead (claimed on the server, or the server isn't in play because of
        --local). False: someone else holds it or it's already matched there, so skip it.
        Any other server failure stops the run instead of claiming locally."""
        if self.r is None:
            return True
        try:
            body = {"addr": f"0x{addr:08x}", "worker_prefix": worker}
            if self.model:
                body["model"] = self.model
            self.r.call("POST", "/api/claim", body)
            return True
        except RemoteError as e:
            if e.status == 409 and "limit" in str(e):
                raise SystemExit(f"{e}. Release some with `c5d task release <addr>` "
                                 "(see `c5d remote status`)")
            if e.status == 409:
                print(f"0x{addr:08x}: skipped ({str(e).removeprefix('server: ')})", flush=True)
                return False
            if e.status == 404 and "isn't on this server" in str(e):
                raise SystemExit(f"{e}. Its functions haven't been imported there, so nobody else "
                                 "can see your claims; wait for the import, or pass --local if "
                                 "you've agreed the work with the others.")
            if e.status == 404:             # server doesn't track it: nobody else can claim it
                return True
            raise SystemExit(f"{e}\nCouldn't claim 0x{addr:08x} on the server, so stopping rather "
                             "than claiming it only locally (someone else could be handed it). "
                             "Functions claimed earlier in this run stay claimed; release them "
                             "with `c5d remote release <addr> ...` or let them expire. Pass "
                             "--local to work without the server.")

    def release(self, addr):
        if self.r is None:
            return
        try:
            self.r.call("POST", "/api/release", {"addr": f"0x{addr:08x}"})
        except RemoteError as e:
            if e.status is None or e.status >= 500:
                print(f"warning: {e}; 0x{addr:08x} stays claimed on the server until it "
                      "expires", flush=True)
                self.r = None
