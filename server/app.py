"""civ5-decomp coordination server: dashboard + claim service.

Standard library only. Configure with environment variables:

  C5D_DB                 SQLite path (default server/data/c5d.sqlite)
  C5D_HOST / C5D_PORT    bind address (default 127.0.0.1:8765)
  C5D_PUBLIC_URL         external URL, used for OAuth redirects (default http://<host>:<port>)
  C5D_SESSION_SECRET     secret for signing session cookies (required in production)
  GITHUB_CLIENT_ID       GitHub OAuth app credentials (sign-in with GitHub)
  GITHUB_CLIENT_SECRET
  C5D_ADMINS             comma-separated GitHub logins allowed to push verify results
                         (POST /api/admin/verify, bearer token only; see manage.py push)
  C5D_DEV_AUTH=1         local testing only: /dev-login?login=<name> signs in without
                         GitHub. Refused unless bound to 127.0.0.1/localhost.

  python server/app.py
"""
import hashlib
import hmac
import json
import mimetypes
import os
import secrets
import sys
import threading
import time
import traceback
import urllib.parse
import urllib.request
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from db import DB  # noqa: E402

HERE = Path(__file__).resolve().parent
STATIC = HERE / "static"
PAGES = {"/": "index.html", "/how": "how.html", "/legal": "legal.html", "/account": "account.html"}
MAX_BODY = 16 * 1024
ADMIN_MAX_BODY = 8 * 1024 * 1024      # a full status list (~20k functions) for /api/admin/verify
SESSION_DAYS = 30
REQUEST_TIMEOUT = 30                  # seconds a client may sit idle on a socket


def env(name, default=None):
    return os.environ.get(name, default)


class Config:
    def __init__(self):
        self.host = env("C5D_HOST", "127.0.0.1")
        self.port = int(env("C5D_PORT", "8765"))
        self.public_url = env("C5D_PUBLIC_URL", f"http://{self.host}:{self.port}").rstrip("/")
        self.secret = (env("C5D_SESSION_SECRET") or "").encode()
        if not self.secret:
            self.secret = secrets.token_bytes(32)      # sessions won't survive restarts
            print("warning: C5D_SESSION_SECRET not set; using a random one", file=sys.stderr)
        self.gh_id = env("GITHUB_CLIENT_ID")
        self.gh_secret = env("GITHUB_CLIENT_SECRET")
        self.admins = {a.strip().lower() for a in (env("C5D_ADMINS") or "").split(",") if a.strip()}
        self.dev_auth = env("C5D_DEV_AUTH") == "1"
        if self.dev_auth and self.host not in ("127.0.0.1", "localhost", "::1"):
            raise SystemExit("C5D_DEV_AUTH is only allowed when bound to localhost")
        self.secure_cookies = self.public_url.startswith("https://")


class ApiError(Exception):
    def __init__(self, code, msg):
        super().__init__(msg)
        self.code = code


def sign(cfg, value):
    mac = hmac.new(cfg.secret, value.encode(), hashlib.sha256).hexdigest()
    return f"{value}.{mac}"


def unsign(cfg, signed):
    if not signed or "." not in signed:
        return None
    value, mac = signed.rsplit(".", 1)
    good = hmac.new(cfg.secret, value.encode(), hashlib.sha256).hexdigest()
    return value if hmac.compare_digest(mac, good) else None


def parse_addr(v):
    try:
        a = int(str(v), 16) if isinstance(v, str) else int(v)
    except (TypeError, ValueError):
        raise ApiError(400, "addr must be a hex address like 0x00540240")
    if not 0x400000 <= a < 0x10000000:
        raise ApiError(400, "addr out of range")
    return a


def as_int(v, name, default=0):
    if v is None or v == "":
        return default
    try:
        return int(v)
    except (TypeError, ValueError):
        raise ApiError(400, f"{name} must be an integer")


STATS_TTL = 30                        # seconds /api/stats is served from memory


def make_handler(cfg, db):
    stats_cache = {"t": 0.0, "v": None, "fp": None}
    stats_lock = threading.Lock()

    def stats():
        """db.stats() at most once per STATS_TTL. Recomputed early when a successful POST
        clears the cache or the DB fingerprint changes (writes from manage.py etc.)."""
        with stats_lock:
            now, fp = time.monotonic(), db.fingerprint()
            if stats_cache["v"] is None or fp != stats_cache["fp"] or now - stats_cache["t"] >= STATS_TTL:
                stats_cache.update(v=db.stats(), t=now, fp=fp)
            return stats_cache["v"]

    class Handler(BaseHTTPRequestHandler):
        server_version = "c5d"
        timeout = REQUEST_TIMEOUT          # socket timeout: idle/slow clients can't pin a thread

        # ---------------------------------------------------- plumbing
        def address_string(self):
            # behind the reverse proxy every request comes from loopback; log the real client
            ip = self.client_address[0]
            fwd = self.headers.get("X-Forwarded-For") if getattr(self, "headers", None) else None
            if fwd and ip in ("127.0.0.1", "::1"):
                return fwd.split(",")[-1].strip()
            return ip

        def log_message(self, fmt, *args):
            sys.stderr.write("%s %s\n" % (self.address_string(), fmt % args))

        def fail(self, exc):
            """Last-resort handler: log the traceback, answer 500 JSON (never leak details)."""
            if isinstance(exc, (BrokenPipeError, ConnectionResetError)):
                return                     # client went away; nothing to answer
            sys.stderr.write(f"error handling {self.command} {self.path}:\n{traceback.format_exc()}")
            try:
                self.send(500, {"error": "internal server error"})
            except OSError:
                pass

        def send(self, code, body, ctype="application/json", headers=None):
            data = body if isinstance(body, bytes) else (
                json.dumps(body).encode() if ctype == "application/json" else body.encode())
            self.send_response(code)
            self.send_header("Content-Type", ctype + ("; charset=utf-8" if ctype.startswith("text") or
                                                       ctype == "application/json" else ""))
            self.send_header("Content-Length", str(len(data)))
            self.send_header("X-Content-Type-Options", "nosniff")
            self.send_header("Referrer-Policy", "same-origin")
            self.send_header("Content-Security-Policy",
                             "default-src 'self'; img-src 'self' data:; style-src 'self'; "
                             "script-src 'self'; frame-ancestors 'none'")
            for k, v in (headers or {}).items():
                self.send_header(k, v)
            self.end_headers()
            if self.command != "HEAD":
                self.wfile.write(data)

        def redirect(self, location, headers=None):
            self.send_response(302)
            self.send_header("Location", location)
            for k, v in (headers or {}).items():
                self.send_header(k, v)
            self.send_header("Content-Length", "0")
            self.end_headers()

        def cookies(self):
            out = {}
            for part in (self.headers.get("Cookie") or "").split(";"):
                if "=" in part:
                    k, v = part.strip().split("=", 1)
                    out[k] = v
            return out

        def set_cookie(self, name, value, max_age):
            flags = f"Path=/; HttpOnly; SameSite=Lax; Max-Age={max_age}"
            if cfg.secure_cookies:
                flags += "; Secure"
            return {"Set-Cookie": f"{name}={value}; {flags}"}

        def json_body(self, limit=MAX_BODY):
            if not (self.headers.get("Content-Type") or "").startswith("application/json"):
                raise ApiError(415, "send application/json")      # also blocks cross-site form posts
            try:
                n = int(self.headers.get("Content-Length") or 0)
            except ValueError:
                raise ApiError(400, "bad Content-Length")
            if n < 0 or n > limit:
                raise ApiError(413, "body too large")
            try:
                body = json.loads(self.rfile.read(n) or b"{}")
            except (json.JSONDecodeError, UnicodeDecodeError):
                raise ApiError(400, "invalid JSON")
            if not isinstance(body, dict):
                raise ApiError(400, "body must be a JSON object")
            return body

        def current_user(self, required=True):
            auth = self.headers.get("Authorization") or ""
            user = None
            if auth.startswith("Bearer "):
                user = db.user_by_token(auth[7:].strip())
            else:
                v = unsign(cfg, self.cookies().get("c5d_session"))
                parts = v.split(":") if v else []
                if len(parts) == 3 and float(parts[2]) > time.time():
                    row = db.one("SELECT * FROM users WHERE id=?", (int(parts[0]),))
                    # session_gen is bumped by "sign out everywhere" / manage.py revoke
                    if row and row["session_gen"] == int(parts[1]):
                        user = row
            if required and not user:
                raise ApiError(401, "sign in first (GitHub) or pass Authorization: Bearer <token>")
            return user

        def require_terms(self, user):
            if not user["accepted_terms"]:
                raise ApiError(403, "accept the contributor terms on /account first")

        # ---------------------------------------------------- routing
        def do_HEAD(self):
            self.do_GET()

        def do_GET(self):
            try:
                path = urllib.parse.urlparse(self.path).path
                if path in PAGES:
                    return self.send(200, (STATIC / PAGES[path]).read_bytes(), "text/html")
                if path.startswith("/static/"):
                    return self.static(path[len("/static/"):])
                if path == "/healthz":
                    db.one("SELECT 1")
                    return self.send(200, {"ok": True}, headers={"Cache-Control": "no-store"})
                if path == "/api/stats":
                    return self.send(200, stats(), headers={"Cache-Control": "max-age=30"})
                if path == "/api/me":
                    u = self.current_user()
                    return self.send(200, {"login": u["login"], "display": u["display"],
                                           "accepted_terms": bool(u["accepted_terms"]),
                                           "claims": db.my_claims(u["id"])})
                if path == "/api/claims":
                    return self.send(200, db.my_claims(self.current_user()["id"]))
                if path == "/login":
                    return self.login()
                if path == "/auth/callback":
                    return self.callback()
                if path == "/logout":
                    # signing out is POST /api/logout (JSON), so other sites can't do it with a link
                    raise ApiError(405, "sign out with POST /api/logout")
                if path == "/dev-login":
                    return self.dev_login()
                raise ApiError(404, "not found")
            except ApiError as e:
                self.send(e.code, {"error": str(e)})
            except Exception as e:
                self.fail(e)

        def do_POST(self):
            try:
                self.post()
                stats_cache["v"] = None        # writes show up on the dashboard right away
            except ApiError as e:
                self.send(e.code, {"error": str(e)})
            except Exception as e:
                self.fail(e)

        def post(self):
            path = urllib.parse.urlparse(self.path).path
            if path == "/api/admin/verify":
                return self.admin_verify()
            body = self.json_body()             # JSON-only: a cross-site form can't post here
            if path == "/api/logout":
                return self.send(200, {"ok": True}, headers=self.set_cookie("c5d_session", "", 0))
            u = self.current_user()
            if path == "/api/logout-all":
                db.revoke_sessions(u["id"])
                return self.send(200, {"ok": True}, headers=self.set_cookie("c5d_session", "", 0))
            if path == "/api/terms":
                db.accept_terms(u["id"])
                return self.send(200, {"ok": True})
            if path == "/api/display":
                d = str(body.get("display", ""))[:40].strip()
                db.set_display(u["id"], d)
                return self.send(200, {"ok": True, "display": d})
            if path == "/api/token":
                return self.send(200, {"token": db.new_token(u["id"])})
            self.require_terms(u)
            if path == "/api/claim":
                n = max(1, min(as_int(body.get("n"), "n", 1), 25))
                addr = parse_addr(body["addr"]) if body.get("addr") is not None else None
                prefix = "".join(c for c in str(body.get("worker_prefix", "w")) if c.isalnum())[:8] or "w"
                min_size = as_int(body.get("min_size"), "min_size", 0)
                max_size = as_int(body.get("max_size"), "max_size", None) or None
                try:
                    got = db.claim(u["id"], n=n, addr=addr, worker_prefix=prefix,
                                   min_size=min_size, max_size=max_size)
                except LookupError as e:
                    raise ApiError(404, str(e))
                except ValueError as e:
                    raise ApiError(409, str(e))
                return self.send(200, {"claims": [{"addr": f"0x{a:08x}", "worker": w} for a, w in got]})
            if path == "/api/release":
                ok = db.release(u["id"], parse_addr(body.get("addr")))
                return self.send(200 if ok else 404, {"released": ok})
            if path == "/api/report":
                try:
                    db.report(u["id"], parse_addr(body.get("addr")), str(body.get("status", "")),
                              str(body.get("detail", "")), str(body.get("model", "")),
                              body.get("tokens_in", 0), body.get("tokens_out", 0),
                              body.get("tokens_cached", 0), body.get("tries", 0))
                except PermissionError as e:
                    raise ApiError(403, str(e))
                except ValueError as e:
                    raise ApiError(400, str(e))
                return self.send(200, {"ok": True})
            raise ApiError(404, "not found")

        def admin_verify(self):
            """Maintainer pushes a full local `c5d match` result: {"statuses": {"0x..": "MATCH"}}.
            Bearer token only (no cookies), and the user's login must be in C5D_ADMINS.
            Authenticated before the (large) body is read."""
            if not (self.headers.get("Authorization") or "").startswith("Bearer "):
                raise ApiError(401, "admin calls need Authorization: Bearer <token>")
            u = self.current_user()
            if u["login"].lower() not in cfg.admins:
                raise ApiError(403, "not an admin (C5D_ADMINS)")
            body = self.json_body(ADMIN_MAX_BODY)
            raw = body.get("statuses")
            if not isinstance(raw, dict):
                raise ApiError(400, "statuses must be an object of addr -> status")
            statuses = {parse_addr(a): str(s) for a, s in raw.items()}
            ready = body.get("ready")
            if ready is not None and not isinstance(ready, dict):
                raise ApiError(400, "ready must be an object of addr -> 0/1")
            ready = {parse_addr(a): bool(v) for a, v in (ready or {}).items()}
            changed = db.apply_verified(statuses)
            ready_changed = db.set_ready(ready)
            requeued = db.expire_reports()
            sys.stderr.write(f"admin verify by {u['login']}: {len(statuses)} statuses, {changed} changes, "
                             f"{ready_changed} readiness changes, {requeued} stale reports requeued\n")
            return self.send(200, {"received": len(statuses), "changed": changed,
                                   "ready_changed": ready_changed, "requeued": requeued})

        # ---------------------------------------------------- static
        def static(self, rel):
            p = (STATIC / rel).resolve()
            if STATIC.resolve() not in p.parents or not p.is_file():
                raise ApiError(404, "not found")
            # explicit map: on Windows mimetypes reads the registry, which can say
            # text/plain for .js (and with nosniff the browser then refuses it)
            ctype = {".js": "text/javascript", ".css": "text/css", ".html": "text/html",
                     ".svg": "image/svg+xml", ".png": "image/png", ".ico": "image/x-icon"}.get(
                p.suffix.lower()) or mimetypes.guess_type(p.name)[0] or "application/octet-stream"
            self.send(200, p.read_bytes(), ctype, {"Cache-Control": "max-age=300"})

        # ---------------------------------------------------- auth
        def start_session(self, user_id):
            exp = time.time() + SESSION_DAYS * 86400
            gen = db.one("SELECT session_gen FROM users WHERE id=?", (user_id,))["session_gen"]
            return self.set_cookie("c5d_session", sign(cfg, f"{user_id}:{gen}:{exp:.0f}"),
                                   SESSION_DAYS * 86400)

        def login(self):
            if not (cfg.gh_id and cfg.gh_secret):
                raise ApiError(503, "GitHub sign-in is not configured on this server")
            state = secrets.token_urlsafe(16)
            q = urllib.parse.urlencode({"client_id": cfg.gh_id, "state": state, "allow_signup": "true",
                                        "redirect_uri": cfg.public_url + "/auth/callback"})
            # no scopes requested: we only need the public login name
            self.redirect("https://github.com/login/oauth/authorize?" + q,
                          self.set_cookie("c5d_state", sign(cfg, state), 600))

        def callback(self):
            qs = urllib.parse.parse_qs(urllib.parse.urlparse(self.path).query)
            state, code = qs.get("state", [""])[0], qs.get("code", [""])[0]
            if not code or unsign(cfg, self.cookies().get("c5d_state")) != state:
                raise ApiError(400, "sign-in state mismatch; try again")
            if not (cfg.gh_id and cfg.gh_secret):
                raise ApiError(503, "GitHub sign-in is not configured on this server")
            try:
                req = urllib.request.Request(
                    "https://github.com/login/oauth/access_token",
                    data=urllib.parse.urlencode({"client_id": cfg.gh_id, "client_secret": cfg.gh_secret,
                                                 "code": code}).encode(),
                    headers={"Accept": "application/json"})
                with urllib.request.urlopen(req, timeout=15) as r:
                    tok = json.loads(r.read()).get("access_token")
                if not tok:
                    raise ApiError(400, "GitHub sign-in failed")
                req = urllib.request.Request("https://api.github.com/user",
                                             headers={"Authorization": f"Bearer {tok}",
                                                      "Accept": "application/vnd.github+json",
                                                      "User-Agent": "c5d-server"})
                with urllib.request.urlopen(req, timeout=15) as r:
                    login = json.loads(r.read())["login"]
            except (OSError, ValueError, KeyError) as e:   # URLError/timeout are OSError
                sys.stderr.write(f"GitHub sign-in error: {e!r}\n")
                raise ApiError(502, "could not reach GitHub to finish sign-in; try again")
            uid = db.upsert_user(login)
            self.redirect("/account", self.start_session(uid))

        def dev_login(self):
            if not cfg.dev_auth:
                raise ApiError(404, "not found")
            qs = urllib.parse.parse_qs(urllib.parse.urlparse(self.path).query)
            login = "".join(c for c in qs.get("login", ["dev"])[0] if c.isalnum() or c in "-_")[:39] or "dev"
            uid = db.upsert_user("dev:" + login, login)
            self.redirect("/account", self.start_session(uid))

    return Handler


class Server(ThreadingHTTPServer):
    # http.server sets SO_REUSEADDR, which on Windows lets a second process bind the
    # same port silently (and could let another local process hijack it). Use
    # exclusive binding there; elsewhere SO_REUSEADDR only affects TIME_WAIT.
    allow_reuse_address = os.name != "nt"
    daemon_threads = True

    def server_bind(self):
        import socket
        if os.name == "nt" and hasattr(socket, "SO_EXCLUSIVEADDRUSE"):
            self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_EXCLUSIVEADDRUSE, 1)
        super().server_bind()


def main():
    cfg = Config()
    db_path = Path(env("C5D_DB", HERE / "data" / "c5d.sqlite"))
    db_path.parent.mkdir(parents=True, exist_ok=True)
    db = DB(db_path)
    try:
        srv = Server((cfg.host, cfg.port), make_handler(cfg, db))
    except OSError as e:
        raise SystemExit(f"cannot bind {cfg.host}:{cfg.port}: {e} (is another server already running?)")
    print(f"c5d server on http://{cfg.host}:{cfg.port}  (db: {db_path})"
          + ("  [DEV AUTH ON]" if cfg.dev_auth else ""))
    try:
        srv.serve_forever()
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()
