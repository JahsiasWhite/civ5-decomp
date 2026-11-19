"""A module's map from its current build to a legacy one (modules/<id>/legacy/<build>/addrmap.csv,
written by tools/buildmap.py). Columns: kind (func|data), addr_2026, addr_2014, same, votes.

The symbol files hold current-build addresses only; a legacy run (`c5d --build 2014 ...`)
translates them through this map."""
import bisect
import csv
from pathlib import Path

# how far past a mapped data address a symbol may sit and still be translated with the
# same offset (a field of a global struct, the next string in a pool); data that moved
# as a block keeps its layout
NEAR = 64


class AddrMap:
    def __init__(self, rows):
        self.funcs, self.data, self.same = {}, {}, set()
        for r in rows:
            new, old = int(r["addr_2026"], 16), int(r["addr_2014"], 16)
            if r["kind"] == "func":
                self.funcs[new] = old
                if r.get("same", "1") == "1":
                    self.same.add(new)
            else:
                self.data[new] = old
        self._data_keys = sorted(self.data)

    def legacy(self, addr):
        """The legacy address for a current-build one, or None."""
        if addr in self.funcs:
            return self.funcs[addr]
        if addr in self.data:
            return self.data[addr]
        i = bisect.bisect_right(self._data_keys, addr) - 1
        if i >= 0 and addr - self._data_keys[i] < NEAR:
            k = self._data_keys[i]
            return self.data[k] + (addr - k)
        return None

    def to_legacy(self, syms):
        """{name: current addr} -> {name: legacy addr}, dropping names with no twin.
        (A file that matches only the current build is left out of legacy runs by
        c5d's default_sources, so its names don't need dropping here.)"""
        out = {}
        for name, addr in syms.items():
            a = self.legacy(addr)
            if a is not None:
                out[name] = a
        return out

    def current(self):
        """{legacy addr: current addr} for functions."""
        return {o: n for n, o in self.funcs.items()}


_cache = {}


def load(path):
    path = Path(path)
    if path not in _cache:
        if not path.exists():
            raise SystemExit(f"{path} is missing: the legacy build needs its address map "
                             "(tools/buildmap.py writes it)")
        with open(path, newline="") as fh:
            _cache[path] = AddrMap(csv.DictReader(fh))
    return _cache[path]
