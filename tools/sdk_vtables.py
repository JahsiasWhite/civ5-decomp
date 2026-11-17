"""Name engine functions from the Civ V SDK interface headers.

The exe implements the engine-side SDK interfaces (ICvEngineUtility4,
ICvUserInterface2, ICvDLLDatabaseUtility1) that the gameplay DLL calls. Their
vtables are runs of code pointers in .rdata whose length equals the
interface's total virtual-method count. This tool parses the method order from
the headers, finds candidate vtables, and writes names.csv entries
(address -> Interface::Method) for the best candidate of each interface.

    python tools/sdk_vtables.py            # report candidates + write names
"""
import csv
import json
import re
import struct
import sys
from pathlib import Path

from binfmt import PEImage

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import config  # noqa: E402
CFG = config.load()
SDK = ROOT / "third_party" / "Community-Patch-DLL" / "CvGameCoreDLLUtil" / "include"

# (most-derived interface, header) the exe implements
TARGETS = [("ICvEngineUtility4", "ICvDLLUtility.h"),
           ("ICvUserInterface2", "ICvDLLUserInterface.h"),
           ("ICvDLLDatabaseUtility1", "ICvDLLDatabaseUtility.h")]


def parse_interfaces():
    """{class: (base, [method names in vtable order])} from all SDK headers."""
    classes = {}
    for h in SDK.glob("*.h"):
        text = h.read_text(errors="replace")
        text = re.sub(r"//[^\n]*", "", text)
        text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
        for m in re.finditer(r"class\s+(\w+)\s*(?::\s*public\s+(\w+))?\s*\{", text):
            name, base = m.group(1), m.group(2)
            depth, i = 1, m.end()
            while depth and i < len(text):
                depth += {"{": 1, "}": -1}.get(text[i], 0)
                i += 1
            body = text[m.end():i - 1]
            methods = []
            for decl in re.findall(r"virtual\s+([^;{]*?)\s*(?:=\s*0)?\s*;", body, flags=re.S):
                mm = re.search(r"(\w+)\s*\(", decl)
                if mm:
                    methods.append(mm.group(1))
            classes[name] = (base, methods)
    return classes


def flatten(classes, name):
    base, methods = classes[name]
    return (flatten(classes, base) if base in classes else []) + methods


def code_pointer_runs(img):
    """Yield (va, [targets]) for maximal runs of pointers into .text in .rdata."""
    text = next(s for s in img.sections if s[0] == ".text")
    t_lo = img.image_base + text[1]
    t_hi = t_lo + text[2]
    for name, rva, vsize, rawptr, rawsize in img.sections:
        if name != ".rdata":
            continue
        data = img.data[rawptr:rawptr + min(vsize, rawsize)]
        run, start = [], None
        for off in range(0, len(data) - 3, 4):
            v, = struct.unpack_from("<I", data, off)
            if t_lo <= v < t_hi:
                if start is None:
                    start = img.image_base + rva + off
                run.append(v)
            else:
                if len(run) >= 3:
                    yield start, run
                run, start = [], None


GUID_RE = re.compile(
    r"static\s+const\s+GUID\s+guid(\w+)\s*=\s*\{\s*(0x[0-9a-fA-F]+)\s*,\s*(0x[0-9a-fA-F]+)\s*,"
    r"\s*(0x[0-9a-fA-F]+)\s*,\s*\{([^}]*)\}\s*\}")


def parse_guids():
    guids = {}
    for h in SDK.glob("*.h"):
        for m in GUID_RE.finditer(h.read_text(errors="replace")):
            tail = [int(x, 16) for x in m.group(5).split(",")]
            guids[m.group(1)] = struct.pack("<IHH8B", int(m.group(2), 16), int(m.group(3), 16),
                                            int(m.group(4), 16), *tail)
    return guids


def load_functions():
    import bisect
    rows = []
    for r in config.load_functions():
        rows.append((int(r["entry"], 16), int(r["size"])))
    rows.sort()
    starts = [a for a, _ in rows]

    def owner(va):
        i = bisect.bisect_right(starts, va) - 1
        return rows[i][0] if i >= 0 and va < rows[i][0] + max(rows[i][1], 1) else None
    return owner


def find_query_interface(img, guid_bytes, owner):
    """Functions in .text that reference (by absolute address) a copy of the GUID."""
    found = set()
    text = next(s for s in img.sections if s[0] == ".text")
    t_va, t_raw, t_size = img.image_base + text[1], text[3], min(text[2], text[4])
    tdata = img.data[t_raw:t_raw + t_size]
    start = 0
    while True:
        off = img.data.find(guid_bytes, start)
        if off < 0:
            break
        start = off + 1
        # file offset -> VA
        for _n, rva, vsize, rawptr, rawsize in img.sections:
            if rawptr <= off < rawptr + rawsize:
                gva = img.image_base + rva + off - rawptr
                needle = struct.pack("<I", gva)
                p = 0
                while True:
                    p = tdata.find(needle, p)
                    if p < 0:
                        break
                    f = owner(t_va + p)
                    if f:
                        found.add(f)
                    p += 1
    return found


def main():
    classes = parse_interfaces()
    guids = parse_guids()
    owner = load_functions()
    img = PEImage(Path(CFG["game_dir"]) / CFG["target_exe"])
    runs = list(code_pointer_runs(img))
    rows = []
    for iface, _hdr in TARGETS:
        methods = flatten(classes, iface)
        n = len(methods)
        # QueryInterface of the implementation recognises every version's GUID
        qi = set()
        base = iface.rstrip("0123456789")
        for g, gb in guids.items():
            if g.rstrip("0123456789") == base:
                qi |= find_query_interface(img, gb, owner)
        # vtables: a run position whose entry is a QueryInterface implementation
        # and which leaves at least n entries
        hits = []
        for va, r in runs:
            for k, t in enumerate(r):
                if t in qi and len(r) - k >= n:
                    hits.append(va + 4 * k)
        print(f"{iface}: {n} methods; QueryInterface candidates {[hex(q) for q in sorted(qi)]}; "
              f"vtables {[hex(h) for h in hits]}")
        for vt_i, vt in enumerate(hits):
            impl = iface[1:].rstrip("0123456789") + "Impl" + (str(vt_i + 1) if len(hits) > 1 else "")
            for k, m in enumerate(methods):
                target, = struct.unpack_from("<I", img.read(vt + 4 * k, 4))
                rows.append((f"0x{target:08x}", f"{impl}::{m}", f"sdk:{iface}[{k}]@0x{vt:08x}"))

    out = config.module().names / "sdk_vtables.csv"
    out.parent.mkdir(exist_ok=True)
    with open(out, "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["address", "name", "source"])
        w.writerows(sorted(set(rows)))
    print(f"wrote {len(rows)} names to {out.relative_to(ROOT)}")


if __name__ == "__main__":
    sys.exit(main())
