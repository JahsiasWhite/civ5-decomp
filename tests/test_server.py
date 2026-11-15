"""End-to-end tests for the coordination server (stdlib server, temp DB)."""
import json
import os
import sys
import threading
import time
import urllib.error
import urllib.request
from http.server import ThreadingHTTPServer
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "server"))


@pytest.fixture()
def srv(tmp_path, monkeypatch):
    monkeypatch.setenv("C5D_DEV_AUTH", "1")
    monkeypatch.setenv("C5D_HOST", "127.0.0.1")
    monkeypatch.setenv("C5D_SESSION_SECRET", "test-secret")
    monkeypatch.setenv("C5D_ADMINS", "Boss, other")
    import app as appmod
    import db as dbmod
    db = dbmod.DB(tmp_path / "t.sqlite")
    db.import_functions([
        {"addr": 0x401000 + i * 0x10, "size": 20 + i, "name": f"F{i}", "conv": "stack", "depth": 0,
         "cluster": 0x401000 + i * 0x10, "ready": 1 if i < 8 else 0, "queue_pos": i}
        for i in range(10)])
    cfg = appmod.Config()
    httpd = appmod.Server(("127.0.0.1", 0), appmod.make_handler(cfg, db))
    t = threading.Thread(target=httpd.serve_forever, daemon=True)
    t.start()
    yield f"http://127.0.0.1:{httpd.server_address[1]}", db
    httpd.shutdown()


def req(base, method, path, body=None, token=None, ctype="application/json", cookie=None):
    h = {"Content-Type": ctype}
    if token:
        h["Authorization"] = f"Bearer {token}"
    if cookie:
        h["Cookie"] = cookie
    r = urllib.request.Request(base + path, method=method, headers=h,
                               data=json.dumps(body or {}).encode() if method == "POST" else None)
    try:
        with urllib.request.urlopen(r) as resp:
            return resp.status, json.loads(resp.read() or b"{}")
    except urllib.error.HTTPError as e:
        return e.code, json.loads(e.read() or b"{}")


def make_user(db, login, terms=True):
    uid = db.upsert_user(login)
    if terms:
        db.accept_terms(uid)
    return db.new_token(uid)


def test_pages_and_stats(srv):
    base, _ = srv
    for p in ("/", "/how", "/legal", "/account", "/static/style.css", "/static/dashboard.js"):
        with urllib.request.urlopen(base + p) as r:
            assert r.status == 200
            assert "Content-Security-Policy" in r.headers
    code, s = req(base, "GET", "/api/stats")
    assert code == 200 and s["functions"] == 10 and s["ready"] == 8 and s["matched"] == 0


def test_static_content_types(srv):
    base, _ = srv
    for path, want in (("/static/dashboard.js", "text/javascript"), ("/static/account.js", "text/javascript"),
                       ("/static/style.css", "text/css")):
        with urllib.request.urlopen(base + path) as r:
            assert r.headers["Content-Type"].startswith(want), (path, r.headers["Content-Type"])


def test_static_path_traversal_blocked(srv):
    base, _ = srv
    code, _ = req(base, "GET", "/static/../db.py")
    assert code == 404


def test_auth_required(srv):
    base, _ = srv
    assert req(base, "POST", "/api/claim", {"n": 1})[0] == 401
    assert req(base, "POST", "/api/claim", {"n": 1}, token="c5d_wrong")[0] == 401


def test_terms_required(srv):
    base, db = srv
    tok = make_user(db, "alice", terms=False)
    assert req(base, "POST", "/api/claim", {"n": 1}, token=tok)[0] == 403
    assert req(base, "POST", "/api/terms", {}, token=tok)[0] == 200
    assert req(base, "POST", "/api/claim", {"n": 1}, token=tok)[0] == 200


def test_form_posts_rejected(srv):
    base, db = srv
    tok = make_user(db, "alice")
    assert req(base, "POST", "/api/claim", {"n": 1}, token=tok, ctype="text/plain")[0] == 415


def test_claim_order_conflicts_and_release(srv):
    base, db = srv
    a, b = make_user(db, "alice"), make_user(db, "bob")
    code, j = req(base, "POST", "/api/claim", {"n": 3, "worker_prefix": "w"}, token=a)
    assert code == 200
    assert [c["addr"] for c in j["claims"]] == ["0x00401000", "0x00401010", "0x00401020"]
    assert [c["worker"] for c in j["claims"]] == ["w1", "w2", "w3"]
    # bob gets the next ones, never alice's
    _, j2 = req(base, "POST", "/api/claim", {"n": 2}, token=b)
    assert [c["addr"] for c in j2["claims"]] == ["0x00401030", "0x00401040"]
    # explicit claim of a held function conflicts
    assert req(base, "POST", "/api/claim", {"addr": "0x00401000"}, token=b)[0] == 409
    # bob can't release alice's claim; alice can
    assert req(base, "POST", "/api/release", {"addr": "0x00401000"}, token=b)[0] == 404
    assert req(base, "POST", "/api/release", {"addr": "0x00401000"}, token=a)[0] == 200
    assert req(base, "POST", "/api/claim", {"addr": "0x00401000"}, token=b)[0] == 200


def test_not_ready_functions_not_handed_out(srv):
    base, db = srv
    tok = make_user(db, "alice")
    _, j = req(base, "POST", "/api/claim", {"n": 25}, token=tok)
    assert len(j["claims"]) == 8          # 2 of 10 have pending callees


def test_claim_limit(srv, monkeypatch):
    base, db = srv
    import db as dbmod
    monkeypatch.setattr(dbmod, "MAX_ACTIVE_CLAIMS", 2)
    tok = make_user(db, "alice")
    _, j = req(base, "POST", "/api/claim", {"n": 5}, token=tok)
    assert len(j["claims"]) == 2
    assert req(base, "POST", "/api/claim", {"n": 1}, token=tok)[0] == 409


def test_report_verify_flow(srv):
    base, db = srv
    a, b = make_user(db, "alice"), make_user(db, "bob")
    req(base, "POST", "/api/claim", {"n": 2}, token=a)
    # only the claim holder can report
    assert req(base, "POST", "/api/report", {"addr": "0x00401000", "status": "MATCH"}, token=b)[0] == 403
    assert req(base, "POST", "/api/report", {"addr": "0x00401000", "status": "MATCH", "model": "model-a",
                                             "tokens_in": 1000, "tokens_out": 200, "tokens_cached": 5000,
                                             "tries": 2}, token=a)[0] == 200
    assert req(base, "POST", "/api/report", {"addr": "0x00401010", "status": "MATCH", "model": "model-b",
                                             "tokens_in": 10}, token=a)[0] == 200
    s = req(base, "GET", "/api/stats")[1]
    assert s["reported"] == 2 and s["matched"] == 0 and s["claimed"] == 0
    assert s["tokens"] == {"input": 1010, "output": 200, "cached": 5000}
    # maintainer verify: one confirmed, one fails
    db.apply_verified({0x401000: "MATCH", 0x401010: "DIFF"})
    s = req(base, "GET", "/api/stats")[1]
    assert s["matched"] == 1 and s["reported"] == 0 and s["diff"] == 1
    assert s["matched_today"] == 1 and s["models_on_board"] == 1
    lb = s["leaderboard"][0]
    assert lb["who"] == "alice" and lb["functions"] == 1 and lb["submissions"] == 2
    assert s["squad"]["all"][0]["model"] == "model-a" and s["squad"]["all"][0]["share"] == 1
    assert {t["model"]: t["matches"] for t in s["squad"]["tries"]} == {"model-a": 1, "model-b": 1}
    assert s["squad"]["runs"][0]["kept"] == 1 and s["squad"]["runs"][0]["rejected"] == 1
    assert len(s["trend"]) == 1 and s["trend"][0]["functions"] == 1
    assert s["trend_by_model"][0]["model"] == "model-a"
    tier = s["tiers"][0]
    assert tier["matched"] == 1 and tier["open"] == 1 and tier["untried"] == 8
    assert {r["source"] for r in s["cost"]["ledger"]} == {"model-a", "model-b"}
    db.add_spend("2026-11-15", "model-a", 12.5, "test")
    db.add_milestone("2026-11-15", "first verified match")
    s = req(base, "GET", "/api/stats")[1]
    assert s["cost"]["total_dollars"] == 12.5 and s["log"][0]["text"] == "first verified match"
    # matched functions can't be claimed again; failed ones go back in the pool
    assert req(base, "POST", "/api/claim", {"addr": "0x00401000"}, token=b)[0] == 409
    assert req(base, "POST", "/api/claim", {"addr": "0x00401010"}, token=b)[0] == 200


def test_anonymous_display(srv):
    base, db = srv
    tok = make_user(db, "alice")
    req(base, "POST", "/api/display", {"display": ""}, token=tok)
    req(base, "POST", "/api/claim", {"n": 1}, token=tok)
    req(base, "POST", "/api/report", {"addr": "0x00401000", "status": "MATCH"}, token=tok)
    db.apply_verified({0x401000: "MATCH"})
    assert req(base, "GET", "/api/stats")[1]["leaderboard"][0]["who"] == "anonymous"


def test_claim_expiry(srv):
    base, db = srv
    tok = make_user(db, "alice")
    req(base, "POST", "/api/claim", {"n": 1}, token=tok)
    db.conn.execute("UPDATE claims SET expires=?", (time.time() - 1,))
    tok2 = make_user(db, "bob")
    _, j = req(base, "POST", "/api/claim", {"n": 1}, token=tok2)
    assert j["claims"][0]["addr"] == "0x00401000"


def test_bad_input(srv):
    base, db = srv
    tok = make_user(db, "alice")
    assert req(base, "POST", "/api/claim", {"addr": "zzz"}, token=tok)[0] == 400
    assert req(base, "POST", "/api/claim", {"addr": "0x00000010"}, token=tok)[0] == 400
    assert req(base, "POST", "/api/claim", {"addr": "0x00999999"}, token=tok)[0] == 404


def test_dev_login_session_cookie(srv):
    base, db = srv

    class NoRedirect(urllib.request.HTTPRedirectHandler):
        def redirect_request(self, *a, **k):
            return None
    opener = urllib.request.build_opener(NoRedirect)
    set_cookie = None
    try:
        opener.open(base + "/dev-login?login=carol")
    except urllib.error.HTTPError as e:
        assert e.code == 302
        set_cookie = e.headers["Set-Cookie"]
    assert set_cookie and "HttpOnly" in set_cookie and "SameSite=Lax" in set_cookie
    cookie = set_cookie.split(";")[0]
    code, me = req(base, "GET", "/api/me", cookie=cookie)
    assert code == 200 and me["login"] == "dev:carol"
    # tampered cookie is rejected
    assert req(base, "GET", "/api/me", cookie=cookie[:-1] + ("0" if cookie[-1] != "0" else "1"))[0] == 401


def test_port_cannot_be_bound_twice(srv):
    base, _ = srv
    import app as appmod
    port = int(base.rsplit(":", 1)[1])
    with pytest.raises(OSError):
        appmod.Server(("127.0.0.1", port), appmod.make_handler(appmod.Config(), None))


def test_dev_auth_refused_on_public_bind(monkeypatch):
    monkeypatch.setenv("C5D_DEV_AUTH", "1")
    monkeypatch.setenv("C5D_HOST", "0.0.0.0")
    import app as appmod
    with pytest.raises(SystemExit):
        appmod.Config()


# ------------------------------------------------------------ deploy hardening

def test_healthz(srv):
    base, _ = srv
    assert req(base, "GET", "/healthz") == (200, {"ok": True})


def test_malformed_numbers_are_400_not_500(srv):
    base, db = srv
    tok = make_user(db, "alice")
    for body in ({"n": "lots"}, {"n": [1]}, {"min_size": "x"}, {"max_size": {}}):
        code, j = req(base, "POST", "/api/claim", body, token=tok)
        assert code == 400 and "integer" in j["error"], body


def test_non_object_json_body(srv):
    base, db = srv
    tok = make_user(db, "alice")
    r = urllib.request.Request(base + "/api/claim", method="POST", data=b"[1,2]",
                               headers={"Content-Type": "application/json", "Authorization": f"Bearer {tok}"})
    with pytest.raises(urllib.error.HTTPError) as e:
        urllib.request.urlopen(r)
    assert e.value.code == 400


def test_unexpected_error_returns_500_json(srv, monkeypatch, capsys):
    base, db = srv
    monkeypatch.setattr(db, "stats", lambda: 1 / 0)
    code, j = req(base, "GET", "/api/stats")
    assert code == 500 and j == {"error": "internal server error"}     # no traceback leaked
    tok = make_user(db, "alice")
    monkeypatch.setattr(db, "release", lambda *a: {}["boom"])
    assert req(base, "POST", "/api/release", {"addr": "0x00401000"}, token=tok)[0] == 500
    # server still serves afterwards
    assert req(base, "GET", "/healthz")[0] == 200


def test_idle_client_is_disconnected(tmp_path, monkeypatch):
    import socket
    monkeypatch.setenv("C5D_SESSION_SECRET", "x")
    import app as appmod
    import db as dbmod
    monkeypatch.setattr(appmod, "REQUEST_TIMEOUT", 0.5)
    httpd = appmod.Server(("127.0.0.1", 0), appmod.make_handler(appmod.Config(), dbmod.DB(tmp_path / "t.sqlite")))
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    try:
        s = socket.create_connection(httpd.server_address)
        s.settimeout(5)
        s.sendall(b"GET / HTTP/1.1\r\n")          # never finish the request
        t0 = time.time()
        assert s.recv(1024) == b""                  # server hung up on us
        assert time.time() - t0 < 4
        s.close()
    finally:
        httpd.shutdown()


def test_admin_verify(srv):
    base, db = srv
    boss, alice = make_user(db, "boss"), make_user(db, "alice")
    payload = {"statuses": {"0x00401000": "MATCH", "0x00401010": "DIFF", "0x00999999": "MATCH"}}
    assert req(base, "POST", "/api/admin/verify", payload)[0] == 401
    assert req(base, "POST", "/api/admin/verify", payload, token=alice)[0] == 403
    code, j = req(base, "POST", "/api/admin/verify", payload, token=boss)    # C5D_ADMINS is case-insensitive
    assert code == 200 and j == {"received": 3, "changed": 2}
    f = {r["addr"]: r["status"] for r in db.q("SELECT addr, status FROM functions")}
    assert f[0x401000] == "matched" and f[0x401010] == "diff"
    assert req(base, "POST", "/api/admin/verify", {"statuses": {"zz": "MATCH"}}, token=boss)[0] == 400
    assert req(base, "POST", "/api/admin/verify", {"statuses": []}, token=boss)[0] == 400


def test_admin_verify_accepts_large_body_others_dont(srv):
    base, db = srv
    boss, alice = make_user(db, "boss"), make_user(db, "alice")
    big = {"statuses": {f"0x{0x500000 + i * 16:08x}": "MATCH" for i in range(20000)}}   # ~550 KB
    assert req(base, "POST", "/api/admin/verify", big, token=boss)[0] == 200
    assert req(base, "POST", "/api/display", {"display": "x" * 20000}, token=alice)[0] == 413


def test_manage_push(srv, tmp_path):
    base, db = srv
    import argparse
    import manage
    boss = make_user(db, "boss")
    csvp = tmp_path / "status.csv"
    csvp.write_text("address,symbol,status,bytes,source,since\n"
                    "0x00401020,?F2@@YAXXZ,MATCH,22,src/auto/f.cpp,2026-11-15\n")
    manage.cmd_push(None, argparse.Namespace(status=str(csvp), server=base, token=boss))
    assert db.one("SELECT status FROM functions WHERE addr=?", (0x401020,))["status"] == "matched"


def test_manage_backup(tmp_path):
    import manage
    import db as dbmod
    src = tmp_path / "live.sqlite"
    live = dbmod.DB(src)
    live.import_functions([{"addr": 0x401000, "size": 9, "name": "F", "conv": "stack", "depth": 0,
                            "cluster": 0x401000, "ready": 1, "queue_pos": 0}])
    out = tmp_path / "bk"
    for i in range(3):
        (out / f"c5d-2000010{i}-000000.sqlite").parent.mkdir(exist_ok=True)
        (out / f"c5d-2000010{i}-000000.sqlite").write_bytes(b"old")
    dest, pruned = manage.backup_db(src, out, keep=2)
    assert pruned == 2 and sorted(p.name for p in out.iterdir())[-1] == dest.name
    assert dbmod.DB(dest).one("SELECT COUNT(*) c FROM functions")["c"] == 1


# ------------------------------------------------------------ sessions, logout, stats cache

def dev_cookie(base, login):
    class NoRedirect(urllib.request.HTTPRedirectHandler):
        def redirect_request(self, *a, **k):
            return None
    try:
        urllib.request.build_opener(NoRedirect).open(base + "/dev-login?login=" + login)
    except urllib.error.HTTPError as e:
        return e.headers["Set-Cookie"].split(";")[0]
    raise AssertionError("no redirect")


def raw_post(base, path, cookie, ctype="application/json"):
    r = urllib.request.Request(base + path, method="POST", data=b"{}",
                               headers={"Content-Type": ctype, "Cookie": cookie})
    try:
        with urllib.request.urlopen(r) as resp:
            return resp.status, resp.headers.get("Set-Cookie")
    except urllib.error.HTTPError as e:
        return e.code, e.headers.get("Set-Cookie")


def test_logout_is_post_only(srv):
    base, _ = srv
    cookie = dev_cookie(base, "dana")
    assert req(base, "GET", "/logout", cookie=cookie)[0] == 405
    assert req(base, "GET", "/api/me", cookie=cookie)[0] == 200          # GET didn't sign out
    assert raw_post(base, "/api/logout", cookie, ctype="application/x-www-form-urlencoded")[0] == 415
    code, sc = raw_post(base, "/api/logout", cookie)
    assert code == 200 and sc.startswith("c5d_session=;") and "Max-Age=0" in sc


def test_logout_everywhere_revokes_old_sessions(srv):
    base, db = srv
    laptop, phone = dev_cookie(base, "erin"), dev_cookie(base, "erin")
    uid = db.one("SELECT id FROM users WHERE login='dev:erin'")["id"]
    tok = db.new_token(uid)
    assert raw_post(base, "/api/logout-all", laptop)[0] == 200
    assert req(base, "GET", "/api/me", cookie=phone)[0] == 401           # other browser is out too
    assert req(base, "GET", "/api/me", cookie=laptop)[0] == 401
    assert req(base, "GET", "/api/me", token=tok)[0] == 200              # CLI token unaffected
    assert req(base, "GET", "/api/me", cookie=dev_cookie(base, "erin"))[0] == 200   # can sign in again


def test_manage_revoke(srv):
    base, db = srv
    import argparse
    import manage
    cookie = dev_cookie(base, "finn")
    uid = db.one("SELECT id FROM users WHERE login='dev:finn'")["id"]
    tok = db.new_token(uid)
    manage.cmd_revoke(db, argparse.Namespace(login="dev:finn", keep_token=False))
    assert req(base, "GET", "/api/me", cookie=cookie)[0] == 401
    assert req(base, "GET", "/api/me", token=tok)[0] == 401
    with pytest.raises(SystemExit):
        manage.cmd_revoke(db, argparse.Namespace(login="nobody", keep_token=False))


def test_stats_cached_and_invalidated(srv, monkeypatch):
    base, db = srv
    real, calls = db.stats, []
    monkeypatch.setattr(db, "stats", lambda: calls.append(1) or real())
    for _ in range(5):
        assert req(base, "GET", "/api/stats")[0] == 200
    assert len(calls) == 1                                               # served from memory
    tok = make_user(db, "alice")                                         # new user: fingerprint changes
    req(base, "GET", "/api/stats")
    assert len(calls) == 2
    req(base, "POST", "/api/display", {"display": "Al"}, token=tok)      # POST clears the cache
    req(base, "GET", "/api/stats")
    assert len(calls) == 3
    assert req(base, "POST", "/api/claim", {"n": 2}, token=tok)[0] == 200
    assert req(base, "GET", "/api/stats")[1]["claimed"] == 2           # fresh, not the cached 0
