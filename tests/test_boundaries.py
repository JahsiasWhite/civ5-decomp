"""Function boundary fixes: boundary_overrides.txt loading and the split detector.
Neither needs the game: the detector runs on a tiny hand-assembled code image."""
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import boundaries  # noqa: E402
import config  # noqa: E402

CSV_HEAD = "entry,size,min,max,ranges,block,name,thunk,external\n"


def row(entry, size, name=None, ranges=1):
    return (f"0x{entry:08x},{size},0x{entry:08x},0x{entry + size - 1:08x},{ranges},.text,"
            f"{name or f'FUN_{entry:08x}'},0,0\n")


@pytest.fixture()
def fcsv(tmp_path):
    p = tmp_path / "functions.csv"
    p.write_text(CSV_HEAD + row(0x401000, 30) + row(0x40101e, 152) + row(0x4010b6, 10))
    return p


def test_overrides_parse(tmp_path):
    p = tmp_path / "o.txt"
    p.write_text("# comment\n\n0x00401000 0x004010b6  # why\n")
    assert config.read_boundary_overrides(p) == [(0x401000, 0x4010b6, "why")]
    p.write_text("0x00401000\n")
    with pytest.raises(ValueError):
        config.read_boundary_overrides(p)
    p.write_text("0x00401000 0x00401000\n")
    with pytest.raises(ValueError):
        config.read_boundary_overrides(p)


def test_load_functions_merges(fcsv):
    rows = config.load_functions(fcsv, overrides=[(0x401000, 0x4010b6, "")])
    assert [r["entry"] for r in rows] == ["0x00401000", "0x004010b6"]
    first = rows[0]
    assert first["size"] == "182" and first["max"] == "0x004010b5" and first["ranges"] == "1"
    assert config.boundary_merges(config._read_function_rows(fcsv), [(0x401000, 0x4010b6, "")]) == [
        {"entry": 0x401000, "end": 0x4010b6, "size": 182, "note": "", "absorbed": [0x40101e]}]
    assert len(config.load_functions(fcsv, overrides=[])) == 3


def test_load_functions_rejects_unknown_entry(fcsv):
    with pytest.raises(ValueError):
        config.load_functions(fcsv, overrides=[(0x401004, 0x401010, "")])


class FakeImage:
    image_base = 0x400000

    def __init__(self, code, pointers=()):
        self.data = bytes(code)
        self.sections = [(".text", 0x1000, len(code), 0, len(code))]
        self._ptr_slots = {}
        self._pointers = list(pointers)

    def exports(self):
        return {}

    def base_relocs(self):
        return {0x10000000 + 4 * i for i in range(len(self._pointers))}

    def read(self, va, size):
        if va >= 0x10000000:
            return self._pointers[(va - 0x10000000) // 4].to_bytes(4, "little")
        off = va - 0x401000
        if off < 0 or off + size > len(self.data):
            raise ValueError("out of range")
        return self.data[off:off + size]


# A 0x401000: test ecx,ecx; jne B; xor eax,eax; ret        (early return)
# B 0x401007: mov eax,1; ret                                (tail only A jumps to)
# C 0x40100d: test ecx,ecx; jne D; ret
# D 0x401012: ret                                           (also called by E: a real function)
# E 0x401013: call D; ret
CODE = bytes.fromhex("85c97503 31c0c3" "b801000000c3" "85c97501c3" "c3" "e8faffffffc3")
FUNCS = [(0x401000, 7), (0x401007, 6), (0x40100d, 5), (0x401012, 1), (0x401013, 6)]


def rows_of(funcs, names=None):
    names = names or {}
    return [{"entry": f"0x{a:08x}", "size": str(s), "ranges": "1",
             "name": names.get(a, f"FUN_{a:08x}")} for a, s in funcs]


def test_find_splits_merges_lone_tail_only():
    assert boundaries.find_splits(FakeImage(CODE), rows_of(FUNCS)) == [(0x401000, 0x40100d, [0x401007])]


def test_find_splits_keeps_referenced_or_named_tails():
    rows = rows_of(FUNCS)
    assert boundaries.find_splits(FakeImage(CODE, pointers=[0x401007]), rows) == []   # in a vtable
    assert boundaries.find_splits(FakeImage(CODE), rows, protected={0x401007}) == []  # has a symbol
    named = rows_of(FUNCS, {0x401007: "SomeRealName"})
    assert boundaries.find_splits(FakeImage(CODE), named) == []
