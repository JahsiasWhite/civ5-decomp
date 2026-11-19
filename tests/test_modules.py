"""Modules (exe / db / loc): picking the module, module paths, the server client, and the
hybrid DLL swap."""
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import config  # noqa: E402


@pytest.mark.parametrize("argv, want", [
    (["match", "--addr", "db:0x10001000"], "db"),
    (["match", "--addr=loc:0x10001000"], "loc"),
    (["--module", "loc", "task", "next"], "loc"),
    (["--module=db", "status"], "db"),
    (["--module", "exe", "match", "--addr", "db:0x10001000"], "exe"),   # explicit wins (addr_arg then refuses)
    (["match", "--obj", "modules/db/src/auto/f_10001000.cpp"], "db"),
    (["match", "--obj", "modules\\loc\\src\\auto\\f.cpp"], "loc"),
    (["match", "--addr", "0x00401000"], None),
    (["task", "next", "--n", "8"], None),
    (["match", "--flag", "/Imodules/loc/include", "--addr", "0x00401000"], None),   # an option value
    (["match", "--around-from", "build/modules/db/around.txt"], None),
])
def test_module_from_argv(argv, want):
    assert config.module_from_argv(argv) == want


def test_split_addr():
    assert config.split_addr("db:0x10001000") == ("db", 0x10001000)
    assert config.split_addr(" 0x00401000 ") == (None, 0x401000)
    with pytest.raises(ValueError):
        config.split_addr("db:zz")


def test_module_paths_and_selection(monkeypatch):
    monkeypatch.delenv("C5D_MODULE", raising=False)
    exe = config.module()
    assert exe.id == "exe" and exe.file == "CivilizationV_DX11.exe"
    assert exe.src == ROOT / "modules" / "exe" / "src" and exe.build == ROOT / "build" / "exe"
    assert exe.rel(exe.src / "auto" / "f.cpp") == "modules/exe/src/auto/f.cpp"
    monkeypatch.setenv("C5D_MODULE", "db")
    db = config.module()
    assert db.id == "db" and db.file.startswith("CvGameDatabase") and len(db.build_hash) == 64
    assert config.load()["target_exe"] == db.file          # code written for one binary follows
    assert config.functions_csv().parent in (db.data, db.build)
    monkeypatch.setenv("C5D_MODULE", "nope")
    with pytest.raises(SystemExit):
        config.module()
    assert [m.id for m in config.all_modules()] == ["exe", "db", "loc"]


def test_module_entry_beats_leftover_local_keys(monkeypatch):
    monkeypatch.setattr(config, "load_local", lambda: {"target_exe": "CivilizationV_DX11.exe",
                                                       "target_build_hash": "stale"})
    cfg = config.load("db")
    assert cfg["target_exe"] == config.module("db").file
    assert cfg["target_build_hash"] == config.module("db").build_hash


def test_manage_reads_each_modules_boundary_fixes():
    sys.path.insert(0, str(ROOT / "server"))
    import manage
    for mid in ("db", "loc"):
        m = config.module(mid)
        want = len(config.read_boundary_overrides(m.boundary_overrides))
        assert want and len(manage.read_merges(mid)) == want


def test_remote_adds_module_to_function_calls(monkeypatch):
    import remote
    sent = []

    class Resp:
        def __init__(self, body):
            self.body = body

        def __enter__(self):
            return self

        def __exit__(self, *a):
            return False

        def read(self):
            return b"{}"

    def fake_urlopen(req, timeout=None):
        import json
        sent.append((req.full_url, json.loads(req.data) if req.data else None))
        return Resp(req.data)
    monkeypatch.setattr(remote.urllib.request, "urlopen", fake_urlopen)
    monkeypatch.setattr(remote, "load_local", lambda: {"server": "https://x", "token": "t"})
    monkeypatch.setenv("C5D_MODULE", "db")
    r = remote.Remote()
    r.call("POST", "/api/claim", {"n": 1})
    r.call("POST", "/api/report", {"addr": "0x10001000", "status": "MATCH", "module": "loc"})  # explicit kept
    r.call("POST", "/api/admin/verify", {"statuses": {}})                                       # not a function call
    r.call("GET", "/api/me")
    assert [b for _u, b in sent] == [{"n": 1, "module": "db"},
                                     {"addr": "0x10001000", "status": "MATCH", "module": "loc"},
                                     {"statuses": {}}, None]
    monkeypatch.setenv("C5D_MODULE", "exe")
    sent.clear()
    remote.Remote().call("POST", "/api/release", {"addr": "0x00401000"})
    # the exe needs no module (older servers), but says which build this checkout targets
    assert sent[0][1] == {"addr": "0x00401000", "build": "2026"}


def test_claims_for_another_module_are_given_back(monkeypatch):
    # a server from before the modules ignores `module` and hands a db run exe functions
    import c5d
    monkeypatch.setattr(c5d, "M", config.module("db"))
    calls = []

    class FakeRemote:
        def call(self, method, path, body=None):
            calls.append((path, body))
            if path == "/api/claim":
                return {"claims": [{"addr": "0x00401000", "worker": "w1"}]}     # no module: the exe
            return {"released": True}

    with pytest.raises(SystemExit, match="gave no db functions"):
        c5d.remote_claim(FakeRemote(), {"n": 1})
    assert calls[1] == ("/api/release", {"addr": "0x00401000", "module": "exe"})


def test_hybrid_dll_swap_and_restore(tmp_path, monkeypatch):
    import hybrid
    import setup_env
    game, state = tmp_path / "game", tmp_path / "state"
    game.mkdir()
    state.mkdir()
    dll = game / "Cv.dll"
    dll.write_bytes(b"original")
    built = tmp_path / "hybrid.dll"
    built.write_bytes(b"hybrid")
    started = []
    monkeypatch.setattr(setup_env, "exe_is_target", lambda p, h: Path(p).read_bytes() == b"original")
    monkeypatch.setattr(hybrid.subprocess, "Popen", lambda cmd, cwd=None: started.append(cmd))
    hybrid.run_with_dll(built, game, "Cv.dll", "Game.exe", state, "h")
    assert dll.read_bytes() == b"hybrid" and started == [[str(game / "Game.exe")]]
    assert (state / "original" / "Cv.dll").read_bytes() == b"original"
    assert (game / "steam_appid.txt").exists()
    hybrid.run_with_dll(built, game, "Cv.dll", "Game.exe", state, "h")   # second run keeps the first backup
    assert (state / "original" / "Cv.dll").read_bytes() == b"original"
    hybrid.clean_dll(game, "Cv.dll", state, "h")
    assert dll.read_bytes() == b"original" and not (game / "steam_appid.txt").exists()
    assert not (state / "original" / "Cv.dll").exists()
    # a modified DLL and no backup: refuse rather than save the wrong file as "original"
    dll.write_bytes(b"someone else's mod")
    with pytest.raises(SystemExit):
        hybrid.run_with_dll(built, game, "Cv.dll", "Game.exe", state, "h")
    assert dll.read_bytes() == b"someone else's mod"
    # the game still has the DLL open: a clear message, not a traceback
    dll.write_bytes(b"original")

    real_copy = hybrid.shutil.copy2

    def locked(src, dst, *a, **k):
        if Path(dst) == dll:
            raise PermissionError("in use")
        return real_copy(src, dst, *a, **k)
    monkeypatch.setattr(hybrid.shutil, "copy2", locked)
    with pytest.raises(SystemExit, match="in use"):
        hybrid.run_with_dll(built, game, "Cv.dll", "Game.exe", tmp_path / "state2", "h")


def test_module_headers_are_tracked(tmp_path):
    """modules/<id>/include is on the compiler's INCLUDE after include/, so the CI include
    graph and the object cache's dependency digest must both see headers there."""
    import ci_report
    import objcache

    def write(rel, text):
        p = tmp_path / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(text)
        return p
    write("include/Shared.h", "int s;\n")
    write("modules/db/include/Private.h", '#include "Shared.h"\n')
    src = write("modules/db/src/a.cpp", '#include "Private.h"\nint x;\n')
    write("modules/loc/src/b.cpp", '#include "Private.h"\n')          # another module can't see it
    g = ci_report.include_graph(tmp_path)
    assert g["modules/db/src/a.cpp"] == {"modules/db/include/Private.h"}
    assert g["modules/db/include/Private.h"] == {"include/Shared.h"}
    assert g["modules/loc/src/b.cpp"] == set()
    before = objcache.includes_digest(tmp_path, src)
    write("modules/db/include/Private.h", '#include "Shared.h"\nint changed;\n')
    assert objcache.includes_digest(tmp_path, src) != before
