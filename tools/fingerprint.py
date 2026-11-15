"""Function fingerprints: verify matches without the game exe.

`c5d fingerprint` (needs the exe) writes, for every function in data/functions.csv:

    data/fingerprints.csv   address, size, code hash, extent length, extent hash
    data/fingerprints.json  image base, exe SHA-256, the import table (IAT slot -> name)
                            and the export table (name -> address)

A hash is SHA-256 over the function's original bytes (salted with its address,
truncated to 128 bits). The extent covers the code plus everything up to the next
function (switch tables and padding). Neither file holds any game code: a hash
can't be turned back into bytes, and the rest is addresses and names.

To compare, the matcher rewrites every reference in our compiled function to
what the original must contain there if the reference is right (the target's
address from symbols.txt), then hashes the result. Equal hashes mean identical
code and identical references, which is what MATCH means in exe mode too.
What it can't do is show *where* a DIFF differs; use the exe locally for that.
"""
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CSV_PATH = ROOT / "data" / "fingerprints.csv"
META_PATH = ROOT / "data" / "fingerprints.json"
MAX_EXTENT = 4096          # switch tables live right after the code; cap the hashed tail
SALT = b"c5d-fp1"


def digest(va, data):
    return hashlib.sha256(SALT + va.to_bytes(4, "little") + bytes(data)).hexdigest()[:32]


def export(image, rows, exe_sha256):
    """Write fingerprints for every single-range function in `rows` (the function
    list, from config.load_functions()). Returns the row count."""
    entries = sorted(int(r["entry"], 16) for r in rows)
    nxt = {a: b for a, b in zip(entries, entries[1:])}

    out = []
    for r in rows:
        if r["ranges"] != "1":
            continue                       # split functions: extent isn't one block
        va, size = int(r["entry"], 16), int(r["size"])
        try:
            code = image.read(va, size)
        except ValueError:
            continue
        ext_len = min(nxt.get(va, va + size) - va, MAX_EXTENT)
        ext_hash = ""
        if ext_len > size:
            while ext_len > size:          # section end: shrink until readable
                try:
                    ext = image.read(va, ext_len)
                    ext_hash = digest(va, ext)
                    break
                except ValueError:
                    ext_len -= 1
        if not ext_hash:
            ext_len = size
        out.append((va, size, digest(va, code), ext_len, ext_hash))

    out.sort()
    CSV_PATH.parent.mkdir(exist_ok=True)
    with open(CSV_PATH, "w", newline="") as fh:
        w = csv.writer(fh, lineterminator="\n")
        w.writerow(["address", "size", "code", "extent", "extent_hash"])
        for va, size, code, ext_len, ext_hash in out:
            w.writerow([f"0x{va:08x}", size, code, ext_len, ext_hash])

    meta = {
        "format": 1,
        "exe_sha256": exe_sha256,
        "image_base": f"0x{image.image_base:08x}",
        "imports": {f"0x{va:08x}": name for va, name in sorted(image.imports().items())},
        "exports": {name: f"0x{va:08x}" for name, va in sorted(image.exports().items())},
    }
    META_PATH.write_text(json.dumps(meta, indent=1, sort_keys=True) + "\n", encoding="utf-8")
    return len(out)


class FingerprintImage:
    """Stands in for the exe's PEImage where the matcher only needs tables, plus
    hash lookups for the comparison itself."""

    is_fingerprint = True

    def __init__(self, csv_path=CSV_PATH, meta_path=META_PATH):
        if not Path(csv_path).exists():
            raise FileNotFoundError(f"{csv_path} not found; run `c5d fingerprint` on a machine with the game")
        meta = json.loads(Path(meta_path).read_text(encoding="utf-8"))
        self.exe_sha256 = meta["exe_sha256"]
        self.image_base = int(meta["image_base"], 16)
        self._imports = {int(k, 16): v for k, v in meta["imports"].items()}
        self._exports = {k: int(v, 16) for k, v in meta["exports"].items()}
        self.funcs = {}
        with open(csv_path, newline="") as fh:
            for r in csv.DictReader(fh):
                self.funcs[int(r["address"], 16)] = (
                    int(r["size"]), r["code"], int(r["extent"]), r["extent_hash"])

    def imports(self):
        return self._imports

    def exports(self):
        return self._exports

    def read(self, va, size):
        raise ValueError("no exe in fingerprint mode (original bytes aren't available)")
