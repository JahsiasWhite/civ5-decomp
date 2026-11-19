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
    assert lb["who"] == "alice" and lb["functions"] == 1 and "submissions" not in lb
    assert s["squad"]["all"][0]["model"] == "model-a" and s["squad"]["all"][0]["share"] == 1
    assert {t["model"]: t["matches"] for t in s["squad"]["tries"]} == {"model-a": 1, "model-b": 1}
    assert s["squad"]["runs"][0]["kept"] == 1 and s["squad"]["runs"][0]["rejected"] == 1
    # a run that changes nothing isn't listed
    db.apply_verified({0x401000: "MATCH"})
    assert len(req(base, "GET", "/api/stats")[1]["squad"]["runs"]) == 1
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


def test_reported_function_not_claimable_until_verify_or_expiry(srv):
    base, db = srv
    a, b = make_user(db, "alice"), make_user(db, "bob")
    req(base, "POST", "/api/claim", {"n": 1}, token=a)
    req(base, "POST", "/api/report", {"addr": "0x00401000", "status": "MATCH", "model": "m"}, token=a)
    # the queue skips it and so does an explicit claim (what `c5d task next` sends)
    _, j = req(base, "POST", "/api/claim", {"n": 1}, token=b)
    assert j["claims"][0]["addr"] == "0x00401010"
    code, j = req(base, "POST", "/api/claim", {"addr": "0x00401000"}, token=b)
    assert code == 409 and "reported" in j["error"]
    # a report that never gets verified lapses back to the pool
    db.conn.execute("UPDATE functions SET updated=? WHERE addr=?", (time.time() - 15 * 86400, 0x401000))
    assert req(base, "POST", "/api/claim", {"addr": "0x00401000"}, token=b)[0] == 200


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
    assert code == 200 and j == {"received": 3, "changed": 2, "closed": 0, "credited": 0, "owned": 1, "ready_changed": 0,
                                 "requeued": 0, "resized": 0, "merged_away": 0, "added": 0,
                                 "milestones": ["First function matched"] + [
                                     f"{p} of the code matched (20 of 245 bytes, 1 functions)"
                                     for p in ("0.1%", "1%", "5%")]}
    f = {r["addr"]: r["status"] for r in db.q("SELECT addr, status FROM functions")}
    assert f[0x401000] == "matched" and f[0x401010] == "diff"
    assert req(base, "POST", "/api/admin/verify", {"statuses": {"zz": "MATCH"}}, token=boss)[0] == 400
    assert req(base, "POST", "/api/admin/verify", {"statuses": []}, token=boss)[0] == 400


def test_auto_milestones_once_each(tmp_path):
    import db as dbmod
    db = dbmod.DB(tmp_path / "m.sqlite")
    # 200 functions of 100 bytes: 20,000 bytes, so 1% = 2 functions and 5% = 10
    db.import_functions([{"addr": 0x500000 + i * 0x100, "size": 100, "name": "", "conv": "stack",
                          "depth": 0, "cluster": 0, "ready": 1, "queue_pos": i} for i in range(200)])

    def match(n):
        db.apply_verified({0x500000 + i * 0x100: "MATCH" for i in range(n)})
        return db.check_milestones("2026-11-15")
    assert match(0) == []
    assert match(1) == ["First function matched", "0.1% of the code matched (100 of 20,000 bytes, 1 functions)"]
    assert match(1) == []                                        # logged once
    new = match(30)          # 30 functions, 15%: 10 functions, then 1%, 5%, 10%, 15%
    assert new[0] == "10 functions matched" and [t.split("%")[0] for t in new[1:]] == ["1", "5", "10", "15"]
    assert len(match(200)) == len(dbmod.FUNCTION_MILESTONES[2:4]) + 17   # 50, 100; 20%..100%
    keys = [r["key"] for r in db.q("SELECT key FROM milestones")]
    assert len(keys) == len(set(keys)) and "bytes:100" in keys
    db.add_milestone("2026-11-15", "hand-written")               # manual ones have no key
    assert db.check_milestones() == []


def test_admin_milestone(srv):
    base, db = srv
    boss, alice = make_user(db, "boss"), make_user(db, "alice")
    body = {"text": "Site launched", "day": "2026-11-14"}
    assert req(base, "POST", "/api/admin/milestone", body)[0] == 401
    assert req(base, "POST", "/api/admin/milestone", body, token=alice)[0] == 403
    code, j = req(base, "POST", "/api/admin/milestone", body, token=boss)
    assert code == 200 and j["day"] == "2026-11-14"
    assert req(base, "POST", "/api/admin/milestone", {"text": ""}, token=boss)[0] == 400
    assert req(base, "POST", "/api/admin/milestone", {"text": "x", "day": "14/11"}, token=boss)[0] == 400
    _, s = req(base, "GET", "/api/stats")
    assert {"day": "2026-11-14", "text": "Site launched"} in s["log"]


def test_admin_verify_model_credits(srv):
    base, db = srv
    boss, alice = make_user(db, "boss"), make_user(db, "alice")
    # 0x401000: matched earlier with no report ("unspecified"); 0x401010: alice reported it
    req(base, "POST", "/api/admin/verify", {"statuses": {"0x00401000": "MATCH"}}, token=boss)
    assert db.one("SELECT model FROM functions WHERE addr=?", (0x401000,))["model"] == ""
    _, s = req(base, "GET", "/api/stats")
    assert [r["model"] for r in s["squad"]["all"]] == ["unspecified"]
    assert {r["model"] for r in s["trend_by_model"]} == {"unspecified"}
    req(base, "POST", "/api/claim", {"addr": "0x00401010"}, token=alice)
    req(base, "POST", "/api/report", {"addr": "0x00401010", "status": "MATCH", "model": "m-alice"},
        token=alice)
    models = {"0x00401000": "claude-opus-5-5", "0x00401010": "claude-opus-5-5",
              "0x00401020": "claude-opus-5-5"}                       # 0x401020 isn't matched
    code, j = req(base, "POST", "/api/admin/verify",
                  {"statuses": {"0x00401010": "MATCH"}, "models": models}, token=boss)
    assert code == 200 and j["credited"] == 1
    m = {r["addr"]: r["model"] for r in db.q("SELECT addr, model FROM functions")}
    assert m[0x401000] == "claude-opus-5-5"          # retroactive: replaces "unspecified"
    assert m[0x401010] == "m-alice"                  # a contributor's own report wins
    assert m[0x401020] == ""
    _, j = req(base, "POST", "/api/admin/verify", {"statuses": {}, "models": models}, token=boss)
    assert j["credited"] == 0
    assert req(base, "POST", "/api/admin/verify", {"statuses": {}, "models": ["x"]}, token=boss)[0] == 400


def test_manage_read_models(tmp_path, monkeypatch):
    import manage
    (tmp_path / "src").mkdir()
    (tmp_path / "src" / "a.cpp").write_text("// c5d-cflags: +/Oy-\n// c5d-model: claude-opus-5-5\nint x;\n")
    (tmp_path / "src" / "b.cpp").write_text("int y;\n")
    monkeypatch.setattr(manage, "ROOT", tmp_path)
    st = tmp_path / "status.csv"
    st.write_text("address,symbol,status,bytes,source,since\n"
                  "0x00401000,a,MATCH,1,src/a.cpp,2026-11-15\n"
                  "0x00401010,b,MATCH,1,src/b.cpp,2026-11-15\n"
                  "0x00401020,c,DIFF,1,src/a.cpp,2026-11-15\n")
    assert manage.read_models(st) == {0x401000: "claude-opus-5-5"}


def test_admin_verify_boundary_merges(srv):
    base, db = srv
    boss, alice = make_user(db, "boss"), make_user(db, "alice")
    # 0x401010 is the split-off tail of 0x401000 and alice holds a claim on it; 0x401020 is
    # matched (kept), 0x00999999 is unknown (ignored)
    req(base, "POST", "/api/claim", {"addr": "0x00401010"}, token=alice)
    with db.tx():
        db.conn.execute("UPDATE functions SET status='matched' WHERE addr=?", (0x401020,))
    merges = [{"addr": "0x00401000", "size": 60, "absorbed": ["0x00401010", "0x00401020"]},
              {"addr": "0x00999999", "size": 10, "absorbed": []}]
    code, j = req(base, "POST", "/api/admin/verify", {"statuses": {}, "merges": merges}, token=boss)
    assert code == 200 and j["resized"] == 1 and j["merged_away"] == 1
    f = {r["addr"]: r["size"] for r in db.q("SELECT addr, size FROM functions")}
    assert f[0x401000] == 60 and 0x401010 not in f and 0x401020 in f
    assert db.one("SELECT COUNT(*) c FROM claims WHERE addr=?", (0x401010,))["c"] == 0
    assert db.one("SELECT COUNT(*) c FROM events WHERE kind='merge'")["c"] == 1
    # pushing the same fixes again changes nothing
    _, j = req(base, "POST", "/api/admin/verify", {"statuses": {}, "merges": merges}, token=boss)
    assert j["resized"] == 0 and j["merged_away"] == 0
    for bad in ([{"addr": "0x00401000"}], [{"addr": "0x00401000", "size": 0, "absorbed": []}], "x"):
        assert req(base, "POST", "/api/admin/verify", {"statuses": {}, "merges": bad}, token=boss)[0] == 400


def test_admin_verify_merge_into_unknown_function_still_drops_pieces(srv):
    # a `new` function (Ghidra missed it) reaches the server only with the next import,
    # but the bogus entries inside it should stop being handed out on push
    base, db = srv
    boss = make_user(db, "boss")
    merges = [{"addr": "0x00401038", "size": 40, "absorbed": ["0x00401040", "0x00401050"]}]
    code, j = req(base, "POST", "/api/admin/verify", {"statuses": {}, "merges": merges}, token=boss)
    assert code == 200 and j["resized"] == 0 and j["merged_away"] == 2
    f = {r["addr"] for r in db.q("SELECT addr FROM functions")}
    assert 0x401038 not in f and 0x401040 not in f and 0x401050 not in f and 0x401060 in f
    assert j["added"] == 0                          # not marked `new`: not added


def test_admin_verify_adds_new_function(srv):
    # `<entry> <end> new` in boundary_overrides.txt: the push adds the function (not ready,
    # last in the queue) and a readiness flag in the same push applies to it
    base, db = srv
    boss = make_user(db, "boss")
    last = db.one("SELECT MAX(queue_pos) p FROM functions")["p"]
    merges = [{"addr": "0x00401038", "size": 40, "absorbed": ["0x00401040"], "new": True}]
    code, j = req(base, "POST", "/api/admin/verify", {"statuses": {}, "merges": merges}, token=boss)
    assert code == 200 and j["added"] == 1 and j["merged_away"] == 1 and j["resized"] == 0
    f = db.one("SELECT * FROM functions WHERE addr=?", (0x401038,))
    assert (f["size"], f["name"], f["ready"], f["status"], f["queue_pos"]) == (
        40, "FUN_00401038", 0, "todo", last + 1)
    _, j = req(base, "POST", "/api/admin/verify",
               {"statuses": {}, "merges": merges, "ready": {"0x00401038": 1}}, token=boss)
    assert j["added"] == 0 and j["ready_changed"] == 1   # pushing again adds nothing
    assert db.one("SELECT ready FROM functions WHERE addr=?", (0x401038,))["ready"] == 1


def test_admin_verify_accepts_large_body_others_dont(srv):
    base, db = srv
    boss, alice = make_user(db, "boss"), make_user(db, "alice")
    big = {"statuses": {f"0x{0x500000 + i * 16:08x}": "MATCH" for i in range(20000)}}   # ~550 KB
    assert req(base, "POST", "/api/admin/verify", big, token=boss)[0] == 200
    assert req(base, "POST", "/api/display", {"display": "x" * 20000}, token=alice)[0] == 413


def test_admin_verify_credits_direct_commits_to_pusher(srv):
    base, db = srv
    boss, alice = make_user(db, "boss"), make_user(db, "alice")
    db.set_display(db.one("SELECT id FROM users WHERE login='boss'")["id"], "Boss")
    # 0x401000 was committed straight to the repo; 0x401010 alice reported herself
    req(base, "POST", "/api/claim", {"addr": "0x00401010"}, token=alice)
    req(base, "POST", "/api/report", {"addr": "0x00401010", "status": "MATCH"}, token=alice)
    _, j = req(base, "POST", "/api/admin/verify",
               {"statuses": {"0x00401000": "MATCH", "0x00401010": "MATCH"}}, token=boss)
    assert j["owned"] == 1
    by = {r["addr"]: r["by_user"] for r in db.q("SELECT addr, by_user FROM functions WHERE status='matched'")}
    ids = {r["login"]: r["id"] for r in db.q("SELECT id, login FROM users")}
    assert by == {0x401000: ids["boss"], 0x401010: ids["alice"]}
    s = req(base, "GET", "/api/stats")[1]
    assert sum(r["bytes"] for r in s["leaderboard"]) == s["matched_bytes"]
    assert sum(r["functions"] for r in s["leaderboard"]) == s["matched"]
    for r in s["leaderboard"]:                       # hover breakdown adds up to the row
        assert [b["label"] for b in r["bands"]] == [t["label"] for t in s["tiers"] if t["module"] == "all"]
        assert sum(b["functions"] for b in r["bands"]) == r["functions"]
        assert sum(b["bytes"] for b in r["bands"]) == r["bytes"]
        assert "uid" not in r
    assert sum(t["new_functions"] for t in s["trend"]) == s["trend"][-1]["functions"]
    assert req(base, "POST", "/api/admin/verify", {"statuses": {}}, token=boss)[1]["owned"] == 0


def on_build_2026(db):
    """A server already switched to the 2026 exe (manage.py push sends the exe's build)."""
    with db.tx():
        db.conn.execute("INSERT OR REPLACE INTO meta(key,value) VALUES ('exe_build','2026')")


def test_manage_push(srv, tmp_path):
    base, db = srv
    import argparse
    import manage
    boss = make_user(db, "boss")
    on_build_2026(db)            # the repo's config.json names the exe build: 2026
    csvp = tmp_path / "status.csv"
    csvp.write_text("address,symbol,status,bytes,source,since\n"
                    "0x00401020,?F2@@YAXXZ,MATCH,22,src/auto/f.cpp,2026-11-15\n")
    queue = tmp_path / "queue.csv"           # F8 (0x401080) is not ready on the server; now it is
    queue.write_text("entry,size,name,status,conv,entry_regs,depth,callees,pending_callees,callers,"
                     "cluster,cluster_size\n"
                     "0x00401080,28,F8,todo,stack,,0,1,0,0,0x00401080,1\n"
                     "0x00401000,20,F0,todo,stack,,0,1,1,0,0x00401000,1\n")
    manage.cmd_push(None, argparse.Namespace(status=str(csvp), queue=str(queue), server=base, token=boss,
                                             callgraph=str(tmp_path / "none.csv")))
    ready = {r["addr"]: r["ready"] for r in db.q("SELECT addr, ready FROM functions")}
    assert ready[0x401080] == 1 and ready[0x401000] == 0 and ready[0x401090] == 0   # unlisted untouched
    assert db.one("SELECT status FROM functions WHERE addr=?", (0x401020,))["status"] == "matched"


def test_manage_push_readiness_from_callgraph(srv, tmp_path):
    # what CI does: no queue.csv (no game), readiness from the committed call graph
    base, db = srv
    import argparse
    import manage
    boss = make_user(db, "boss")
    on_build_2026(db)            # the repo's config.json names the exe build: 2026
    csvp = tmp_path / "status.csv"
    csvp.write_text("address,symbol,status,bytes,source,since\n"
                    "0x00401020,?F2@@YAXXZ,MATCH,22,src/auto/f.cpp,2026-11-15\n")
    cg = tmp_path / "callgraph.csv"      # F8 calls only F2 (matched): ready; F0 calls F2 and F1
    cg.write_text("entry,callees\n0x00401000,0x00401010 0x00401020\n0x00401080,0x00401020\n"
                  "0x00401010,\n")
    assert manage.ready_from_callgraph(cg, csvp) == {"0x00401000": 0, "0x00401080": 1, "0x00401010": 1}
    with db.tx():
        db.conn.execute("UPDATE functions SET ready=1 WHERE addr=?", (0x401000,))
    manage.cmd_push(None, argparse.Namespace(status=str(csvp), queue=str(tmp_path / "none.csv"),
                                             callgraph=str(cg), server=base, token=boss))
    ready = {r["addr"]: r["ready"] for r in db.q("SELECT addr, ready FROM functions")}
    assert ready[0x401080] == 1 and ready[0x401000] == 0 and ready[0x401010] == 1


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


# ------------------------------------------------------------ queue upkeep

def test_stale_reports_return_to_pool(srv):
    base, db = srv
    import db as dbmod
    a, b = make_user(db, "alice"), make_user(db, "bob")
    req(base, "POST", "/api/claim", {"addr": "0x00401000"}, token=a)
    req(base, "POST", "/api/report", {"addr": "0x00401000", "status": "MATCH", "model": "m1"}, token=a)
    # a fresh report is not handed out again
    _, j = req(base, "POST", "/api/claim", {"n": 1}, token=b)
    assert j["claims"][0]["addr"] == "0x00401010"
    # 15 days later with no verify: back in the pool, ahead in queue order
    with db.tx():
        db.conn.execute("UPDATE functions SET updated=? WHERE addr=?",
                        (time.time() - dbmod.REPORTED_SECONDS - 86400, 0x401000))
    _, j = req(base, "POST", "/api/claim", {"n": 1}, token=b)
    assert j["claims"][0]["addr"] == "0x00401000"
    f = db.one("SELECT status, by_user, model FROM functions WHERE addr=?", (0x401000,))
    assert f["status"] == "todo" and f["model"] == "m1"            # credit kept for a late merge
    assert db.one("SELECT COUNT(*) c FROM events WHERE kind='unreport'")["c"] == 1


def test_admin_verify_readiness_and_requeue(srv):
    base, db = srv
    import db as dbmod
    boss, a = make_user(db, "boss"), make_user(db, "alice")
    req(base, "POST", "/api/claim", {"addr": "0x00401000"}, token=a)
    req(base, "POST", "/api/report", {"addr": "0x00401000", "status": "MATCH"}, token=a)
    with db.tx():
        db.conn.execute("UPDATE functions SET updated=0 WHERE addr=?", (0x401000,))
    code, j = req(base, "POST", "/api/admin/verify",
                  {"statuses": {}, "ready": {"0x00401080": 1, "0x00401090": True, "0x00401010": 0}}, token=boss)
    assert code == 200 and j["ready_changed"] == 3 and j["requeued"] == 1
    assert req(base, "POST", "/api/admin/verify", {"statuses": {}, "ready": [1]}, token=boss)[0] == 400
    # newly ready functions are handed out
    _, j = req(base, "POST", "/api/claim", {"n": 25}, token=a)
    got = {c["addr"] for c in j["claims"]}
    assert {"0x00401080", "0x00401090", "0x00401000"} <= got and "0x00401010" not in got


def test_old_maintainer_credit_becomes_unspecified(srv, tmp_path):
    _base, db = srv
    db.conn.execute("UPDATE functions SET status='matched', model='maintainer' WHERE addr=?", (0x401000,))
    db.log("verify", None, 0x401000, "MATCH", model="maintainer")
    import db as dbmod
    again = dbmod.DB(tmp_path / "t.sqlite")                 # reopening migrates
    assert again.one("SELECT model FROM functions WHERE addr=?", (0x401000,))["model"] == ""
    assert not again.q("SELECT 1 FROM events WHERE model='maintainer'")


def test_report_without_model_uses_claim_model(srv):
    base, db = srv
    a = make_user(db, "alice")
    req(base, "POST", "/api/claim", {"addr": "0x00401000", "model": "model-c"}, token=a)
    assert req(base, "POST", "/api/report", {"addr": "0x00401000", "status": "MATCH"}, token=a)[0] == 200
    assert db.one("SELECT model FROM functions WHERE addr=?", (0x401000,))["model"] == "model-c"
    # a model given at report time wins over the claim's
    req(base, "POST", "/api/claim", {"addr": "0x00401010", "model": "model-c"}, token=a)
    req(base, "POST", "/api/report", {"addr": "0x00401010", "status": "MATCH", "model": "model-d"}, token=a)
    assert db.one("SELECT model FROM functions WHERE addr=?", (0x401010,))["model"] == "model-d"


def test_verify_credits_and_closes_open_claims(srv):
    base, db = srv
    boss, alice = make_user(db, "boss"), make_user(db, "alice")
    # alice claims two, merges both before reporting; one has no model on the claim
    req(base, "POST", "/api/claim", {"addr": "0x00401000", "model": "model-c"}, token=alice)
    req(base, "POST", "/api/claim", {"addr": "0x00401010"}, token=alice)
    req(base, "POST", "/api/claim", {"addr": "0x00401020", "model": "model-c"}, token=alice)
    _, j = req(base, "POST", "/api/admin/verify",
               {"statuses": {"0x00401000": "MATCH", "0x00401010": "MATCH", "0x00401020": "DIFF"}},
               token=boss)
    assert j["closed"] == 2 and j["owned"] == 0
    ids = {r["login"]: r["id"] for r in db.q("SELECT id, login FROM users")}
    f = {r["addr"]: (r["status"], r["by_user"], r["model"]) for r in db.q("SELECT * FROM functions")}
    assert f[0x401000] == ("matched", ids["alice"], "model-c")
    assert f[0x401010] == ("matched", ids["alice"], "")
    # still-diffing work stays claimed
    held = [c["addr"] for c in req(base, "GET", "/api/claims", token=alice)[1]]
    assert held == [0x401020]
    s = req(base, "GET", "/api/stats")[1]
    assert s["leaderboard"][0]["who"] == "alice" and s["leaderboard"][0]["functions"] == 2
    assert {r["model"] for r in s["squad"]["all"]} == {"model-c", "unspecified"}
    # a second verify finds nothing left to close
    assert req(base, "POST", "/api/admin/verify", {"statuses": {"0x00401000": "MATCH"}},
               token=boss)[1]["closed"] == 0


# ------------------------------------------------------------ modules (exe / db / loc)

def add_dll(db, module="db", n=4, ready=1):
    """n functions at the same addresses in a DLL (both DLLs load at 0x10000000)."""
    db.import_functions([{"addr": 0x10001000 + i * 0x10, "size": 100 + i, "name": f"D{i}", "conv": "thiscall",
                          "depth": 0, "cluster": 0x10001000 + i * 0x10, "ready": ready, "queue_pos": i}
                         for i in range(n)], module=module)


OLD_SCHEMA = """
CREATE TABLE functions (addr INTEGER PRIMARY KEY, size INTEGER NOT NULL, name TEXT NOT NULL DEFAULT '',
    conv TEXT NOT NULL DEFAULT '', depth INTEGER NOT NULL DEFAULT 0, cluster INTEGER NOT NULL DEFAULT 0,
    ready INTEGER NOT NULL DEFAULT 0, queue_pos INTEGER NOT NULL DEFAULT 0,
    status TEXT NOT NULL DEFAULT 'todo', by_user INTEGER, updated REAL);
CREATE INDEX ix_functions_queue ON functions(status, ready, queue_pos);
CREATE TABLE users (id INTEGER PRIMARY KEY, login TEXT UNIQUE NOT NULL, display TEXT NOT NULL DEFAULT '',
    token_hash TEXT UNIQUE, accepted_terms REAL, created REAL NOT NULL);
CREATE TABLE claims (addr INTEGER PRIMARY KEY REFERENCES functions(addr),
    user_id INTEGER NOT NULL REFERENCES users(id), worker TEXT NOT NULL DEFAULT '',
    claimed REAL NOT NULL, expires REAL NOT NULL);
CREATE TABLE events (id INTEGER PRIMARY KEY, ts REAL NOT NULL, user_id INTEGER, addr INTEGER,
    kind TEXT NOT NULL, status TEXT NOT NULL DEFAULT '', detail TEXT NOT NULL DEFAULT '');
INSERT INTO users(id, login, created) VALUES (1, 'alice', 0);
INSERT INTO functions(addr, size, status, ready, queue_pos) VALUES (4198400, 20, 'matched', 1, 0),
    (4198416, 30, 'todo', 1, 1);
INSERT INTO claims VALUES (4198416, 1, 'w1', 0, 9e12);
INSERT INTO events(ts, user_id, addr, kind) VALUES (0, 1, 4198416, 'claim');
"""


def test_old_schema_migrates_to_module_keys(tmp_path):
    """A DB from before modules (addr alone as the key) opens with every row in the exe,
    claims and all, and keeps working."""
    import sqlite3
    import db as dbmod
    p = tmp_path / "old.sqlite"
    c = sqlite3.connect(p)
    c.executescript(OLD_SCHEMA)
    c.commit()
    c.close()
    db = dbmod.DB(p)
    assert db.columns("functions")[:2] == ["module", "addr"]
    rows = db.q("SELECT module, addr, status, model, tried FROM functions ORDER BY addr")
    assert [tuple(r) for r in rows] == [("exe", 0x401000, "matched", "", 0), ("exe", 0x401010, "todo", "", 0)]
    assert [tuple(r) for r in db.q("SELECT module, addr, user_id, model FROM claims")] == [("exe", 0x401010, 1, "")]
    assert db.one("SELECT module FROM events")["module"] == "exe"
    assert not db.q("PRAGMA foreign_key_check")
    assert db.one("PRAGMA foreign_keys")[0] == 1
    # the same address can now exist in another module, and reopening doesn't migrate again
    add_dll(db, n=1)
    db.import_functions([{"addr": 0x401000, "size": 9, "name": "", "conv": "", "depth": 0, "cluster": 0,
                          "ready": 1, "queue_pos": 0}], module="loc")
    again = dbmod.DB(p)
    assert again.one("SELECT COUNT(*) c FROM functions")["c"] == 4
    assert again.my_claims(1)[0]["module"] == "exe"


def test_same_address_in_two_dlls_is_two_functions(srv):
    base, db = srv
    add_dll(db, "db")
    add_dll(db, "loc")
    a, b = make_user(db, "alice"), make_user(db, "bob")
    code, j = req(base, "POST", "/api/claim", {"addr": "db:0x10001000"}, token=a)
    assert code == 200 and j["claims"] == [{"module": "db", "addr": "0x10001000", "worker": "w1"}]
    # loc's 0x10001000 is a different function, free for someone else
    code, j = req(base, "POST", "/api/claim", {"addr": "0x10001000", "module": "loc"}, token=b)
    assert code == 200 and j["claims"][0]["module"] == "loc"
    assert req(base, "POST", "/api/claim", {"addr": "db:0x10001000"}, token=b)[0] == 409
    # report and release name the module too; the other module's claim isn't yours
    assert req(base, "POST", "/api/report", {"addr": "loc:0x10001000", "status": "MATCH"}, token=a)[0] == 403
    assert req(base, "POST", "/api/report", {"addr": "db:0x10001000", "status": "MATCH", "model": "m"},
               token=a)[0] == 200
    assert req(base, "POST", "/api/release", {"addr": "0x10001000", "module": "loc"}, token=b)[0] == 200
    f = {(r["module"], r["addr"]): r["status"] for r in db.q("SELECT module, addr, status FROM functions")}
    assert f[("db", 0x10001000)] == "reported" and f[("loc", 0x10001000)] == "todo"
    assert db.one("SELECT module FROM events WHERE kind='report'")["module"] == "db"


def test_clients_without_module_only_get_exe(srv):
    """Older clients (no module field) treat every address as the exe's: never hand them
    a DLL function, even when the exe queue is empty."""
    base, db = srv
    add_dll(db, "db")
    tok = make_user(db, "alice")
    _, j = req(base, "POST", "/api/claim", {"n": 25}, token=tok)
    assert len(j["claims"]) == 8 and {c["module"] for c in j["claims"]} == {"exe"}
    _, j = req(base, "POST", "/api/claim", {"n": 25}, token=tok)
    assert j["claims"] == []
    _, j = req(base, "POST", "/api/claim", {"n": 25, "module": "db"}, token=tok)
    assert [c["addr"] for c in j["claims"]] == ["0x10001000", "0x10001010", "0x10001020", "0x10001030"]
    assert len(req(base, "GET", "/api/claims", token=tok)[1]) == 12     # one limit across modules


def test_module_validation(srv):
    base, db = srv
    tok = make_user(db, "alice")
    for body in ({"addr": "0x10001000"},                    # the exe's range ends below the DLLs
                 {"addr": "db:0x00401000"},                 # and the DLLs' starts at 0x10000000
                 {"addr": "dll:0x10001000"}, {"n": 1, "module": "dll"}):
        assert req(base, "POST", "/api/claim", body, token=tok)[0] == 400, body
    assert req(base, "POST", "/api/claim", {"addr": "db:0x10009990"}, token=tok)[0] == 404


def test_admin_verify_across_modules(srv):
    base, db = srv
    add_dll(db, "db")
    add_dll(db, "loc")
    boss, alice = make_user(db, "boss"), make_user(db, "alice")
    req(base, "POST", "/api/claim", {"addr": "loc:0x10001010", "model": "m-loc"}, token=alice)
    runs = db.one("SELECT COUNT(*) c FROM runs")["c"]
    payload = {"module": "db",                               # unqualified keys are db's
               "statuses": {"0x10001000": "MATCH", "loc:0x10001010": "MATCH", "exe:0x00401000": "MATCH",
                            "0x10001020": "DIFF"},
               "ready": {"0x10001030": 0, "loc:0x10001030": 0},
               "merges": [{"addr": "loc:0x10001000", "size": 32, "absorbed": ["0x10001020"]}],
               "models": {"0x10001000": "model-x"}}
    code, j = req(base, "POST", "/api/admin/verify", payload, token=boss)
    assert code == 200, j
    assert (j["received"], j["changed"], j["closed"], j["credited"], j["ready_changed"], j["merged_away"]) == \
        (4, 4, 1, 1, 2, 1)
    f = {(r["module"], r["addr"]): (r["status"], r["model"]) for r in db.q("SELECT * FROM functions")}
    assert f[("db", 0x10001000)] == ("matched", "model-x")
    assert f[("loc", 0x10001010)] == ("matched", "m-loc")           # the closed claim credits its model
    assert f[("exe", 0x401000)][0] == "matched"
    assert f[("db", 0x10001020)][0] == "diff"                       # absorbed in loc, not in db
    assert ("loc", 0x10001020) not in f
    assert db.one("SELECT COUNT(*) c FROM runs")["c"] == runs + 1    # one push, one run
    bad = {"statuses": {}, "merges": [{"addr": "db:0x10001000", "size": 8, "absorbed": ["loc:0x10001010"]}]}
    assert req(base, "POST", "/api/admin/verify", bad, token=boss)[0] == 400
    assert req(base, "POST", "/api/admin/verify", {"statuses": {}, "module": "nope"}, token=boss)[0] == 400


def test_stats_per_module(srv):
    base, db = srv
    s = req(base, "GET", "/api/stats")[1]
    assert list(s["modules"]) == ["exe", "db", "loc"]                 # always all three
    assert s["modules"]["db"]["functions"] == 0 and s["modules"]["db"]["joined"] is None
    add_dll(db, "db")
    boss, alice = make_user(db, "boss"), make_user(db, "alice")
    req(base, "POST", "/api/claim", {"addr": "db:0x10001010"}, token=alice)
    req(base, "POST", "/api/report", {"addr": "db:0x10001010", "status": "MATCH", "model": "m"}, token=alice)
    req(base, "POST", "/api/admin/verify",
        {"statuses": {"exe:0x00401000": "MATCH", "db:0x10001010": "MATCH"}}, token=boss)
    s = req(base, "GET", "/api/stats")[1]
    # headline numbers are the combined totals; the modules add up to them
    for k in ("functions", "bytes", "matched", "matched_bytes", "todo", "todo_bytes", "claimed", "ready",
              "matched_today"):
        assert s[k] == sum(m[k] for m in s["modules"].values()), k
    d = s["modules"]["db"]
    assert (d["functions"], d["matched"], d["matched_bytes"]) == (4, 1, 101)
    assert d["joined"] and d["file"].startswith("CvGameDatabase")
    assert any(m["text"].startswith("CvGameDatabase") for m in s["log"])
    # tiers: "all" first, then each module, each set adding up to that module's totals
    for m in ["all", "exe", "db", "loc"]:
        ts = [t for t in s["tiers"] if t["module"] == m]
        want = s if m == "all" else s["modules"][m]
        assert len(ts) == 5 and sum(t["total"] for t in ts) == want["functions"]
        assert sum(t["matched_bytes"] for t in ts) == want["matched_bytes"]
    lb = {r["who"]: r for r in s["leaderboard"]}
    assert lb["alice"]["modules"] == [{"module": "db", "functions": 1, "bytes": 101}]
    assert lb["boss"]["modules"] == [{"module": "exe", "functions": 1, "bytes": 20}]
    p = s["trend"][-1]
    assert p["modules"] == {"exe": {"functions": 1, "bytes": 20}, "db": {"functions": 1, "bytes": 101}}
    assert p["functions"] == 2 and p["new_functions"] == 2 and len(s["trend"]) == 1
    sq = {r["model"]: r for r in s["squad"]["all"]}
    assert sq["m"]["modules"] == {"db": {"functions": 1, "bytes": 101}}


def test_dll_join_milestone_once(tmp_path):
    import db as dbmod
    db = dbmod.DB(tmp_path / "j.sqlite")
    db.import_functions([{"addr": 0x401000, "size": 9, "name": "", "conv": "", "depth": 0, "cluster": 0,
                          "ready": 1, "queue_pos": 0}])
    assert db.q("SELECT * FROM milestones") == []                     # the exe doesn't "join"
    add_dll(db, "loc", n=3)
    add_dll(db, "loc", n=5)                                           # re-import: no second entry
    rows = db.q("SELECT key, text FROM milestones")
    assert [r["key"] for r in rows] == ["module:loc"] and "(3 functions)" in rows[0]["text"]


def test_manage_import_and_push_with_module(srv, tmp_path):
    base, db = srv
    import argparse
    import manage
    boss = make_user(db, "boss")
    queue = tmp_path / "queue.csv"
    queue.write_text("entry,size,name,status,conv,entry_regs,depth,callees,pending_callees,callers,"
                     "cluster,cluster_size\n"
                     "0x10001000,28,D0,todo,stack,,0,0,0,0,0x10001000,1\n")
    status = tmp_path / "status.csv"
    status.write_text("address,symbol,status,bytes,source,since\n")
    manage.cmd_import(db, argparse.Namespace(queue=str(queue), status=str(status), module="db"))
    assert db.one("SELECT module FROM functions WHERE addr=?", (0x10001000,))["module"] == "db"
    status.write_text("address,symbol,status,bytes,source,since\n0x10001000,?D0@@YAXXZ,MATCH,28,,2026-11-16\n")
    manage.cmd_push(None, argparse.Namespace(status=str(status), queue=str(queue), callgraph=str(tmp_path / "x"),
                                             server=base, token=boss, module="db"))
    assert db.one("SELECT status FROM functions WHERE module='db' AND addr=?", (0x10001000,))["status"] == "matched"


def test_manage_push_several_modules_is_one_run(srv, tmp_path, monkeypatch):
    base, db = srv
    import argparse
    import manage
    monkeypatch.setattr(manage, "read_merges", lambda module="exe": [])
    boss = make_user(db, "boss")
    on_build_2026(db)            # the repo's config.json names the exe build: 2026
    row = {"size": 16, "name": "F", "conv": "stack", "depth": 0, "ready": 1, "queue_pos": 0}
    db.import_functions([{**row, "addr": 0x401000, "cluster": 0x401000}])
    db.import_functions([{**row, "addr": 0x10001000, "cluster": 0x10001000}], module="db")
    db.import_functions([{**row, "addr": 0x10001000, "cluster": 0x10001000}], module="loc")
    for mid, addr in (("exe", 0x401000), ("db", 0x10001000)):
        (tmp_path / mid).mkdir()
        (tmp_path / mid / "status.csv").write_text(
            f"address,symbol,status,bytes,source,since\n0x{addr:08x},F,MATCH,16,,2026-11-17\n")
    runs = db.one("SELECT COUNT(*) c FROM runs")["c"]
    manage.cmd_push(None, argparse.Namespace(modules="exe,db", status_pattern=str(tmp_path / "{module}" / "status.csv"),
                                             server=base, token=boss, module="exe"))
    st = {(r["module"], r["addr"]): r["status"] for r in db.q("SELECT module, addr, status FROM functions")}
    assert st[("exe", 0x401000)] == "matched" and st[("db", 0x10001000)] == "matched"
    assert st[("loc", 0x10001000)] == "todo"                          # same address, other module
    assert db.one("SELECT COUNT(*) c FROM runs")["c"] == runs + 1     # one push, one run


def test_claim_in_module_not_imported_yet(srv):
    _base, db = srv
    uid = db.conn.execute("INSERT INTO users(login,display,created) VALUES ('dllfan','',0)").lastrowid
    with pytest.raises(LookupError, match="isn't on this server yet"):
        db.claim(uid, addr=0x10001000, module="db")
    db.import_functions([{"addr": 0x10002000, "size": 16, "name": "D", "conv": "thiscall", "depth": 0,
                          "cluster": 0x10002000, "ready": 1, "queue_pos": 0}], module="db")
    with pytest.raises(LookupError, match="out-of-scope"):
        db.claim(uid, addr=0x10001000, module="db")


# ---------------------------------------------------------------- exe build switch (2014 -> 2026)

QUEUE_HEAD = "entry,size,name,status,conv,entry_regs,depth,callees,pending_callees,callers,cluster,cluster_size\n"


def build_2014_history(base, db):
    """In the fixture's (2014) exe: alice reports and gets 0x401000 verified, 0x401010 is
    committed directly (credited to boss, the pusher), bob holds a claim on 0x401020."""
    alice, bob, boss = make_user(db, "alice"), make_user(db, "bob"), make_user(db, "boss")
    assert req(base, "POST", "/api/claim", {"addr": "0x401000", "model": "m-a"}, token=alice)[0] == 200
    assert req(base, "POST", "/api/report", {"addr": "0x401000", "status": "MATCH"}, token=alice)[0] == 200
    code, _ = req(base, "POST", "/api/admin/verify",
                  {"statuses": {"0x401000": "MATCH", "0x401010": "MATCH"}}, token=boss)
    assert code == 200
    assert req(base, "POST", "/api/claim", {"addr": "0x401020"}, token=bob)[0] == 200
    db.conn.execute("UPDATE functions SET matched_day='2026-01-02' WHERE module='exe' AND addr=0x401010")
    return alice, bob, boss


def switch(db, tmp_path, monkeypatch, mapping=None):
    """manage.py switch-build against the fixture's DB: a 2026 queue of three functions,
    twinned with 0x401000 / 0x401010 / 0x401020."""
    import argparse
    import manage
    monkeypatch.setenv("C5D_DB", db.path)
    (tmp_path / "queue26.csv").write_text(
        QUEUE_HEAD + "".join(f"0x{0x402000 + i * 0x10:08x},{s},G{i},todo,stack,,0,0,0,0,0x{0x402000 + i * 0x10:08x},1\n"
                             for i, s in enumerate((20, 21, 40))))
    (tmp_path / "addrmap.csv").write_text(mapping or (
        "kind,addr_2026,addr_2014\nfunc,0x00402000,0x00401000\nfunc,0x00402010,0x00401010\n"
        "func,0x00402020,0x00401020\ndata,0x00c00000,0x00b00000\n"))
    manage.cmd_switch_build(None, argparse.Namespace(
        map=str(tmp_path / "addrmap.csv"), queue=str(tmp_path / "queue26.csv"), build="2026",
        from_build="2014", backup_dir=str(tmp_path / "bk"), keep=3))


def test_switch_build_moves_exe_and_carries_credit(srv, tmp_path, monkeypatch):
    base, db = srv
    alice, bob, boss = build_2014_history(base, db)
    milestones = db.one("SELECT COUNT(*) c FROM milestones")["c"]
    daily = [tuple(r) for r in db.q("SELECT day, matched, matched_bytes FROM daily")]
    assert db.exe_build() == "2014" and list(db.views()) == ["2014"]
    switch(db, tmp_path, monkeypatch)
    assert len(list((tmp_path / "bk").glob("c5d-*.sqlite"))) == 1           # backed up first
    assert db.exe_build() == "2026" and list(db.views()) == ["2026", "2014"]
    assert db.views()["2014"] == ["exe-2014", "db", "loc"]
    # the 2014 rows, claims and events all moved; the 2026 queue is the exe now
    assert db.one("SELECT COUNT(*) c FROM functions WHERE module='exe-2014'")["c"] == 10
    assert {r["module"] for r in db.q("SELECT module FROM claims")} == {"exe-2014"}
    assert db.one("SELECT COUNT(*) c FROM events WHERE module='exe' AND kind<>'switch'")["c"] == 0
    rows = {r["addr"]: r for r in db.q("SELECT * FROM functions WHERE module='exe'")}
    assert sorted(rows) == [0x402000, 0x402010, 0x402020]
    assert {a: r["twin_addr"] for a, r in rows.items()} == {0x402000: 0x401000, 0x402010: 0x401010,
                                                            0x402020: 0x401020}
    uid = {r["login"]: r["id"] for r in db.q("SELECT id, login FROM users")}
    g0, g1, g2 = rows[0x402000], rows[0x402010], rows[0x402020]
    assert (g0["by_user"], g0["model"], g0["tried"], g0["status"]) == (uid["alice"], "m-a", 1, "todo")
    assert (g1["by_user"], g1["matched_day"], g1["status"]) == (uid["boss"], "2026-01-02", "todo")
    assert g2["by_user"] is None and g2["matched_day"] is None            # its twin wasn't matched
    # no milestone fired; the daily history is the 2014 view's and was copied for 2026
    assert db.one("SELECT COUNT(*) c FROM milestones")["c"] == milestones
    for view in ("2014", "2026"):
        assert [tuple(r) for r in db.q("SELECT day, matched, matched_bytes FROM daily WHERE view=?",
                                       (view,))] == daily
    assert not db.q("PRAGMA foreign_key_check")
    # running it twice is refused
    with pytest.raises(SystemExit, match="already on the 2026 build"):
        switch(db, tmp_path, monkeypatch)


def test_switch_build_rejects_bad_map(srv, tmp_path, monkeypatch):
    _base, db = srv
    with pytest.raises(SystemExit, match="paired twice"):
        switch(db, tmp_path, monkeypatch,
               "kind,addr_2026,addr_2014\nfunc,0x00402000,0x00401000\nfunc,0x00402010,0x00401000\n")
    with pytest.raises(SystemExit, match="header"):
        switch(db, tmp_path, monkeypatch, "a,b\n1,2\n")
    assert db.exe_build() == "2014"


def test_verify_keeps_carried_over_credit(srv, tmp_path, monkeypatch):
    base, db = srv
    alice, bob, boss = build_2014_history(base, db)
    switch(db, tmp_path, monkeypatch)
    uid = {r["login"]: r["id"] for r in db.q("SELECT id, login FROM users")}
    day0 = db.one("SELECT matched_day d FROM functions WHERE module='exe' AND addr=0x402000")["d"]
    other = make_user(db, "other")                                        # another admin pushes
    code, j = req(base, "POST", "/api/admin/verify",
                  {"build": {"exe": "2026", "exe-2014": "2014"},
                   "statuses": {"0x402000": "MATCH", "0x402010": "MATCH", "exe-2014:0x401000": "MATCH"},
                   "models": {"0x402000": "from-a-c5d-model-line", "0x402010": "tool-x"}}, token=other)
    assert code == 200, j
    rows = {r["addr"]: r for r in db.q("SELECT * FROM functions WHERE module='exe'")}
    assert rows[0x402000]["status"] == rows[0x402010]["status"] == "matched"
    assert rows[0x402000]["matched_day"] == day0 and rows[0x402010]["matched_day"] == "2026-01-02"
    assert rows[0x402000]["by_user"] == uid["alice"]                      # not the pusher
    assert rows[0x402010]["by_user"] == uid["boss"]
    assert rows[0x402000]["model"] == "m-a"        # alice reported it (at its 2014 address)
    assert rows[0x402010]["model"] == "tool-x"     # nobody reported it: a model line may credit it
    run = db.one("SELECT kept, kept_bytes FROM runs ORDER BY id DESC LIMIT 1")
    assert (run["kept"], run["kept_bytes"]) == (0, 0)                     # carried over, not new work
    # a new 2026 match is new work, dated today
    carol = make_user(db, "carol")
    assert req(base, "POST", "/api/claim", {"addr": "0x402020", "build": "2026"}, token=carol)[0] == 200
    assert req(base, "POST", "/api/report", {"addr": "0x402020", "status": "MATCH", "build": "2026"},
               token=carol)[0] == 200
    assert req(base, "POST", "/api/admin/verify", {"build": "2026", "statuses": {"0x402020": "MATCH"}},
               token=boss)[0] == 200
    g2 = db.one("SELECT * FROM functions WHERE module='exe' AND addr=0x402020")
    import db as dbmod
    carol_id = db.one("SELECT id FROM users WHERE login='carol'")["id"]
    assert g2["by_user"] == carol_id and g2["matched_day"] == dbmod.utc_day()
    assert db.one("SELECT kept FROM runs ORDER BY id DESC LIMIT 1")["kept"] == 1


def test_claim_on_carried_over_function_keeps_credit(srv, tmp_path, monkeypatch):
    """Someone claims a 2026 function whose 2014 twin was matched; its ported source
    reaches verify while the claim is open: the original author keeps it."""
    base, db = srv
    alice, bob, boss = build_2014_history(base, db)
    switch(db, tmp_path, monkeypatch)
    carol = make_user(db, "carol")
    assert req(base, "POST", "/api/claim", {"addr": "0x402000", "build": "2026"}, token=carol)[0] == 200
    assert req(base, "POST", "/api/admin/verify", {"build": "2026", "statuses": {"0x402000": "MATCH"}},
               token=boss)[0] == 200
    g0 = db.one("SELECT by_user FROM functions WHERE module='exe' AND addr=0x402000")
    assert g0["by_user"] == db.one("SELECT id FROM users WHERE login='alice'")["id"]
    assert not db.q("SELECT * FROM claims WHERE module='exe'")


def test_legacy_module_is_view_only(srv, tmp_path, monkeypatch):
    base, db = srv
    alice, bob, boss = build_2014_history(base, db)
    switch(db, tmp_path, monkeypatch)
    code, j = req(base, "POST", "/api/claim", {"addr": "exe-2014:0x401030", "build": "2014"}, token=bob)
    assert code == 400 and "view-only" in j["error"]
    code, j = req(base, "POST", "/api/claim", {"module": "exe-2014", "n": 2}, token=bob)
    assert code == 400
    code, j = req(base, "POST", "/api/report", {"addr": "exe-2014:0x401020", "status": "MATCH"}, token=bob)
    assert code == 400
    with pytest.raises(PermissionError):
        db.claim(db.one("SELECT id FROM users WHERE login='bob'")["id"], module="exe-2014")
    # bob's moved 2014 claim doesn't count toward his limit
    import db as dbmod
    assert db.one("SELECT COUNT(*) c FROM claims WHERE module='exe-2014'")["c"] == 1
    monkeypatch.setattr(dbmod, "MAX_ACTIVE_CLAIMS", 1)
    assert req(base, "POST", "/api/claim", {"addr": "0x402020", "build": "2026"}, token=bob)[0] == 200


def test_build_mismatch_refused_after_switch(srv, tmp_path, monkeypatch):
    base, db = srv
    alice, bob, boss = build_2014_history(base, db)
    switch(db, tmp_path, monkeypatch)
    for body in ({"n": 1}, {"addr": "0x402020"}, {"addr": "0x402020", "build": "2014"}):
        code, j = req(base, "POST", "/api/claim", body, token=alice)
        assert code == 409 and j["error"] == "git pull: the project moved to the 2026 build"
    for path in ("/api/release", "/api/report"):
        code, j = req(base, "POST", path, {"addr": "0x402020", "status": "MATCH"}, token=alice)
        assert code == 409 and "git pull" in j["error"]
    # the DLLs don't care which exe build a client is on
    add_dll(db)
    assert req(base, "POST", "/api/claim", {"addr": "db:0x10001000"}, token=alice)[0] == 200
    # verify: the exe needs build 2026; exe-2014, if named, must be 2014
    for body in ({"statuses": {"0x402020": "MATCH"}},
                 {"build": "2014", "statuses": {"0x402020": "MATCH"}},
                 {"build": {"exe": "2026", "exe-2014": "2026"}, "statuses": {"exe-2014:0x401020": "MATCH"}},
                 {"build": {"exe": "2014"}, "statuses": {"db:0x10001000": "MATCH"}, "ready": {"0x402020": 1}}):
        code, j = req(base, "POST", "/api/admin/verify", body, token=boss)
        assert code == 409, body
    assert db.one("SELECT status FROM functions WHERE module='exe' AND addr=0x402020")["status"] == "todo"
    assert db.one("SELECT status FROM functions WHERE module='db' AND addr=0x10001000")["status"] == "todo"
    assert req(base, "POST", "/api/admin/verify", {"statuses": {"db:0x10001000": "MATCH"}}, token=boss)[0] == 200
    assert req(base, "POST", "/api/admin/verify", {"build": 7, "statuses": {}}, token=boss)[0] == 400


def test_before_switch_behaviour_unchanged(srv):
    base, db = srv
    alice, boss = make_user(db, "alice"), make_user(db, "boss")
    assert db.exe_build() == "2014"
    assert req(base, "POST", "/api/claim", {"addr": "0x401000"}, token=alice)[0] == 200
    assert req(base, "POST", "/api/release", {"addr": "0x401000"}, token=alice)[0] == 200
    assert req(base, "POST", "/api/claim", {"addr": "0x401000", "build": "2014"}, token=alice)[0] == 200
    assert req(base, "POST", "/api/report", {"addr": "0x401000", "status": "MATCH"}, token=alice)[0] == 200
    # a checkout already on 2026 can't push 2026 addresses into the 2014 rows
    code, j = req(base, "POST", "/api/claim", {"addr": "0x401010", "build": "2026"}, token=alice)
    assert code == 409 and "still on the 2014" in j["error"]
    code, _ = req(base, "POST", "/api/admin/verify", {"build": {"exe": "2026"}, "statuses": {"0x401000": "MATCH"}},
                  token=boss)
    assert code == 409
    assert req(base, "POST", "/api/admin/verify", {"statuses": {"0x401000": "MATCH"}}, token=boss)[0] == 200
    code, s = req(base, "GET", "/api/stats")
    assert list(s["views"]) == ["2014"] and s["exe_build"] == "2014"
    assert s["matched"] == 1 and s["modules"]["exe"]["build"] == "2014" and "exe-2014" not in s["modules"]
    assert [r["view"] for r in db.q("SELECT view FROM daily")] == ["2014"]


def test_old_daily_table_migrates_to_views(tmp_path):
    import sqlite3
    import db as dbmod
    p = tmp_path / "d.sqlite"
    c = sqlite3.connect(p)
    c.execute("CREATE TABLE daily (day TEXT PRIMARY KEY, matched INTEGER NOT NULL, matched_bytes INTEGER NOT NULL)")
    c.execute("INSERT INTO daily VALUES ('2026-11-01', 5, 500)")
    c.commit()
    c.close()
    db = dbmod.DB(p)
    assert [tuple(r) for r in db.q("SELECT day, view, matched, matched_bytes FROM daily")] == \
           [("2026-11-01", "2014", 5, 500)]
    assert "twin_addr" in db.columns("functions")
    dbmod.DB(p)                                                    # reopening is a no-op


def test_stats_views_after_switch(srv, tmp_path, monkeypatch):
    base, db = srv
    alice, bob, boss = build_2014_history(base, db)
    add_dll(db)
    assert req(base, "POST", "/api/admin/verify", {"statuses": {"db:0x10001000": "MATCH"}}, token=boss)[0] == 200
    _, before = req(base, "GET", "/api/stats")
    switch(db, tmp_path, monkeypatch)
    assert req(base, "POST", "/api/admin/verify", {"build": "2026", "statuses": {"0x402000": "MATCH",
               "0x402010": "MATCH"}}, token=boss)[0] == 200
    code, s = req(base, "GET", "/api/stats")
    assert code == 200 and s["exe_build"] == "2026" and list(s["views"]) == ["2026", "2014"]
    v26, v14 = s["views"]["2026"], s["views"]["2014"]
    assert list(v26["modules"]) == ["exe", "db", "loc"] and list(v14["modules"]) == ["exe-2014", "db", "loc"]
    assert v14["modules"]["exe-2014"]["label"] == "exe" and v14["modules"]["exe-2014"]["build"] == "2014"
    assert v26["modules"]["exe"]["build"] == "2026" and "build" not in v26["modules"]["db"]
    # 2026: 3 exe functions (2 carried over) + 4 db; 2014: as before the switch
    assert (v26["functions"], v26["matched"], v26["matched_bytes"]) == (7, 3, 20 + 21 + 100)
    for k in ("functions", "matched", "matched_bytes", "trend", "trend_by_model"):
        assert v14[k] == {**before, "trend": [{**p, "modules": {("exe-2014" if m == "exe" else m): x
                                                               for m, x in p["modules"].items()}}
                                             for p in before["trend"]]}[k], k
    assert [p["functions"] for p in v26["trend"]] == [p["functions"] for p in before["trend"]]
    assert [(r["who"], r["functions"], r["bytes"]) for r in v26["leaderboard"]] == \
           [(r["who"], r["functions"], r["bytes"]) for r in before["leaderboard"]]
    assert [(r["who"], r["functions"]) for r in v14["leaderboard"]] == \
           [(r["who"], r["functions"]) for r in before["leaderboard"]]
    assert {m["module"] for r in v14["leaderboard"] for m in r["modules"]} == {"exe-2014", "db"}
    for v in (v26, v14):
        assert sum(t["total"] for t in v["tiers"] if t["module"] == "all") == v["functions"]
        assert {t["module"] for t in v["tiers"]} == {"all", *v["modules"]}
    for k, val in v26.items():                                    # old pages read the top level
        assert s[k] == val, k
    assert s["claimed"] == 0 and v14["claimed"] == 1              # bob's moved claim is in 2014


def test_manage_push_legacy_build_with_builds(srv, tmp_path, monkeypatch):
    """CI's push: exe (2026) and exe-2014 in one payload, each with its build; exe-2014
    sends no readiness (view-only)."""
    base, db = srv
    import argparse
    import manage
    from remote import Remote
    alice, bob, boss = build_2014_history(base, db)
    switch(db, tmp_path, monkeypatch)
    monkeypatch.setattr(manage, "read_merges", lambda module="exe": [])
    sent = []
    real_call = Remote.call
    monkeypatch.setattr(Remote, "call", lambda self, m, path, body=None: (sent.append(body), real_call(self, m, path, body))[1])
    for mid, rows in (("exe", "0x00402020,G2,MATCH,40,,2026-11-19\n"),
                      ("exe-2014", "0x00401030,F3,MATCH,23,,2026-11-19\n")):
        (tmp_path / mid).mkdir()
        (tmp_path / mid / "status.csv").write_text("address,symbol,status,bytes,source,since\n" + rows)
    manage.cmd_push(None, argparse.Namespace(modules="exe,exe-2014", status_pattern=str(tmp_path / "{module}" / "status.csv"),
                                             server=base, token=boss, module="exe"))
    body = sent[-1]
    assert body["build"] == {"exe": "2026", "exe-2014": "2014"}
    assert set(body["statuses"]) == {"0x00402020", "exe-2014:0x00401030"}
    assert not any(k.startswith("exe-2014:") for k in body.get("ready", {}))
    st = {(r["module"], r["addr"]): r["status"] for r in db.q("SELECT module, addr, status FROM functions")}
    assert st[("exe", 0x402020)] == "matched" and st[("exe-2014", 0x401030)] == "matched"
    assert manage.module_build("db") is None and manage.module_build("exe-2014") == "2014"


def test_switch_build_carries_credit_only_for_same_code(srv, tmp_path, monkeypatch):
    """addrmap.csv's `same` column: 0 = placed by its callers, code changed. The pair still
    sets twin_addr, but the 2014 match's credit doesn't carry over."""
    base, db = srv
    build_2014_history(base, db)
    switch(db, tmp_path, monkeypatch, "kind,addr_2026,addr_2014,same\nfunc,0x00402000,0x00401000,1\n"
                                      "func,0x00402010,0x00401010,0\nfunc,0x00402020,0x00401020,0\n")
    rows = {r["addr"]: r for r in db.q("SELECT * FROM functions WHERE module='exe'")}
    assert rows[0x402010]["twin_addr"] == 0x401010
    assert rows[0x402000]["by_user"] is not None and rows[0x402000]["matched_day"]
    assert rows[0x402010]["by_user"] is None and rows[0x402010]["matched_day"] is None
