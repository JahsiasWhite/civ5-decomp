"""Legacy builds of a module (the exe's 2014 build): paths, address translation, the
view-only guard, and file order."""
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import addrmap  # noqa: E402
import config  # noqa: E402


def test_legacy_module_paths(monkeypatch):
    monkeypatch.setenv("C5D_MODULE", "exe")
    monkeypatch.setenv("C5D_BUILD", "2014")
    m = config.module()
    assert m.legacy == "2014" and m.build_id == "2014" and m.server_id == "exe-2014"
    assert m.data == config.MODULES_DIR / "exe" / "legacy" / "2014" / "data"
    assert m.status_csv == config.MODULES_DIR / "exe" / "legacy" / "2014" / "progress" / "status.csv"
    assert m.build == config.BUILD_ROOT / "exe-2014"
    assert m.src == config.MODULES_DIR / "exe" / "src"          # sources are shared
    cfg = config.load()
    spec = __import__("json").loads(config.SHARED.read_text())["modules"]["exe"]
    assert cfg["target_build_hash"] == m.build_hash == spec["legacy"]["2014"]["build_hash"]
    assert m.build_hash != spec["build_hash"]
    assert cfg["target_legacy_build"] == "2014"


def test_current_build_is_not_legacy(monkeypatch):
    monkeypatch.setenv("C5D_MODULE", "exe")
    monkeypatch.delenv("C5D_BUILD", raising=False)
    m = config.module()
    assert m.legacy is None and m.build_id == "2026" and m.server_id == "exe"
    assert "2014" in m.legacy_builds
    monkeypatch.setenv("C5D_BUILD", "2026")          # naming the current build is fine
    assert config.module().legacy is None


def test_unknown_legacy_build(monkeypatch):
    monkeypatch.setenv("C5D_MODULE", "db")
    monkeypatch.setenv("C5D_BUILD", "2014")
    with pytest.raises(SystemExit):
        config.module()


def test_build_from_argv():
    assert config.build_from_argv(["--build", "2014", "match"]) == "2014"
    assert config.build_from_argv(["--build=2014"]) == "2014"
    assert config.build_from_argv(["match"]) is None


def _map(tmp_path, rows):
    p = tmp_path / "addrmap.csv"
    p.write_text("kind,addr_2026,addr_2014,same\n" + "".join(f"{k},0x{n:08x},0x{o:08x},{s}\n" for k, n, o, s in rows))
    return addrmap.AddrMap(__import__("csv").DictReader(p.open()))


def test_to_legacy(tmp_path):
    am = _map(tmp_path, [("func", 0x401000, 0x402000, 1), ("func", 0x401100, 0x402300, 0),
                         ("data", 0x900000, 0xa00000, 1)])
    got = am.to_legacy({"f": 0x401000, "changed": 0x401100, "g": 0x900000,
                        "g_field": 0x900010, "far": 0x900100, "gone": 0x500000})
    assert got == {"f": 0x402000, "changed": 0x402300, "g": 0xa00000, "g_field": 0xa00010}
    assert am.same == {0x401000}


def test_legacy_build_is_view_only(monkeypatch):
    import c5d
    monkeypatch.setattr(c5d, "M", type("M", (), {"legacy": "2014", "build_label": "x"})())
    with pytest.raises(SystemExit):
        c5d.require_setup("task")

    class Args:
        fingerprints = False
    a = Args()
    monkeypatch.setattr(c5d, "CFG", {"msvc_bin": "cl"})
    c5d.require_setup("match", a)
    assert a.fingerprints is True                     # always against the committed fingerprints


def test_shared_files_read_in_legacy_order(tmp_path, monkeypatch):
    # a name listed twice resolves to the file read last; legacy runs keep the legacy order
    import c5d
    sym = tmp_path / "symbols"
    (sym / "auto").mkdir(parents=True)
    leg = tmp_path / "legacy" / "symbols"
    (leg / "auto").mkdir(parents=True)
    # current-build names sort a < b, but their legacy addresses sort the other way
    (sym / "auto" / "f_00401000.txt").write_text("0x00900000 s\n")
    (sym / "auto" / "f_00402000.txt").write_text("0x00900010 s\n")
    (tmp_path / "symbols.txt").write_text("")
    am = _map(tmp_path, [("func", 0x401000, 0x405000, 1), ("func", 0x402000, 0x403000, 1),
                         ("data", 0x900000, 0xa00000, 1), ("data", 0x900010, 0xa00010, 1)])
    monkeypatch.setattr(addrmap, "load", lambda _p: am)
    m = type("M", (), dict(legacy="2014", symbols_txt=tmp_path / "symbols.txt", symbols_dir=sym,
                           legacy_symbols=leg, addrmap=tmp_path / "addrmap.csv"))()
    monkeypatch.setattr(c5d, "M", m)
    # legacy order: f_00403000 (from 0x402000) then f_00405000 (from 0x401000): last wins
    assert c5d.load_symbols()["s"] == 0xa00000
