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
        assert [b["label"] for b in r["bands"]] == [t["label"] for t in s["tiers"]]
        assert sum(b["functions"] for b in r["bands"]) == r["functions"]
        assert sum(b["bytes"] for b in r["bands"]) == r["bytes"]
        assert "uid" not in r
    assert sum(t["new_functions"] for t in s["trend"]) == s["trend"][-1]["functions"]
    assert req(base, "POST", "/api/admin/verify", {"statuses": {}}, token=boss)[1]["owned"] == 0


def test_manage_push(srv, tmp_path):
    base, db = srv
    import argparse
    import manage
    boss = make_user(db, "boss")
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
