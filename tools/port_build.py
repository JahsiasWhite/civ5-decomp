"""Move a module onto a new build of its binary, keeping the old one as a legacy view (maintainers, one-off).

    python tools/port_build.py --module exe --legacy 2014 --addrmap <buildmap output>
                               --functions <Ghidra export of the new build> [--dry-run]

Run it once, with config.json still describing the OLD build, then:
  1. the old build's data, boundary fixes and results move to modules/<id>/legacy/<build>/
     (git mv), with the address map beside them;
  2. the new build's function list goes to modules/<id>/data/functions.csv, and the
     boundary fixes and scope overrides of identical functions are carried over;
  3. every matched function with an identical twin is renamed to its new address
     (src/auto/f_<new>.cpp, symbols/auto/f_<new>.txt) and its symbol file rewritten;
     the rest (no twin, or code that changed) move to legacy/<build>/src|symbols;
  4. symbols.txt, the other symbol files and names/sdk_vtables.csv are rewritten.
Symbol names keep any old address they contain; no tool reads addresses out of names.

Afterwards: update config.json (build_hash/build of the new build, the old one under
"legacy"), then `c5d fingerprint`, `c5d queue` and `c5d boundaries`, and check with a full
`c5d match` and `c5d --build <legacy> match`. port_report.txt lists anything that needs a look.
"""
import argparse
import bisect
import csv
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import config  # noqa: E402

ROOT = config.ROOT
NEAR = 64
HEX = re.compile(r"0x[0-9a-fA-F]{8}")


class Forward:
    """old (legacy) address -> new address."""

    def __init__(self, path):
        self.funcs, self.data, self.same = {}, {}, set()
        with open(path, newline="") as fh:
            for r in csv.DictReader(fh):
                new, old = int(r["addr_2026"], 16), int(r["addr_2014"], 16)
                if r["kind"] == "func":
                    self.funcs[old] = new
                    if r.get("same", "1") == "1":
                        self.same.add(old)
                else:
                    self.data[old] = new
        self.keys = sorted(self.data)

    def write(self, path):
        with open(path, "w", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(["kind", "addr_2026", "addr_2014", "same"])
            for o, n in sorted(self.funcs.items(), key=lambda kv: kv[1]):
                w.writerow(["func", f"0x{n:08x}", f"0x{o:08x}", int(o in self.same)])
            for o, n in sorted(self.data.items(), key=lambda kv: kv[1]):
                w.writerow(["data", f"0x{n:08x}", f"0x{o:08x}", 1])

    def __call__(self, old):
        if old in self.funcs:
            return self.funcs[old]
        if old in self.data:
            return self.data[old]
        i = bisect.bisect_right(self.keys, old) - 1
        if i >= 0 and old - self.keys[i] < NEAR:
            return self.data[self.keys[i]] + (old - self.keys[i])
        return None


STAGE = ".porting"          # renames go through here: a new address can be another function's old one
staged = []


def mv(src, dst, dry):
    """Move a file. Plain renames (git sees them as renames once added, see main);
    everything goes through a staging folder first so no move lands on a file that
    hasn't been moved away yet."""
    src, dst = Path(src), Path(dst)
    if not src.exists():
        return
    if dry:
        print(f"mv {src.relative_to(ROOT).as_posix()} -> {dst.relative_to(ROOT).as_posix()}")
        return
    tmp = ROOT / "build" / STAGE / f"{len(staged):06d}_{dst.name}"
    tmp.parent.mkdir(parents=True, exist_ok=True)
    src.rename(tmp)
    staged.append((tmp, dst))


def finish_moves():
    for tmp, dst in staged:
        if dst.exists():
            raise SystemExit(f"{dst} already exists; staged copy left at {tmp}")
        dst.parent.mkdir(parents=True, exist_ok=True)
        tmp.rename(dst)
    staged.clear()


def translate_symbol_lines(text, fwd):
    """Rewrite the address of each `0x<addr> <name>` line. Returns (text, untranslated names)."""
    out, missing = [], []
    for line in text.splitlines():
        body, hash_, comment = line.partition("#")
        parts = body.split(None, 1)
        if len(parts) == 2 and parts[0].lower().startswith("0x"):
            new = fwd(int(parts[0], 16))
            if new is None:
                missing.append(parts[1].strip())
                out.append(line)
                continue
            line = f"0x{new:08x} {parts[1].rstrip()}" + (f" {hash_}{comment}" if hash_ else "")
        out.append(line)
    return "\n".join(out) + ("\n" if text.endswith("\n") else ""), missing


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    p.add_argument("--module", default="exe")
    p.add_argument("--legacy", required=True, help="name for the old build, e.g. 2014")
    p.add_argument("--addrmap", required=True)
    p.add_argument("--functions", required=True, help="the new build's function list (Ghidra export)")
    p.add_argument("--matched-new", required=True,
                   help="new-build addresses that matched in a trial run against the new exe "
                        "(one per line); only these carry over, the rest move to legacy/")
    p.add_argument("--dry-run", action="store_true")
    a = p.parse_args(argv)
    dry = a.dry_run
    ok_new = {int(x, 16) for x in Path(a.matched_new).read_text().split()}

    m = config.Module(a.module, __import__("json").loads(config.SHARED.read_text())["modules"][a.module])
    leg = m.root / "legacy" / a.legacy
    fwd = Forward(a.addrmap)
    report = []

    # a match in the trial run is proof the code is the same: record those pairs as
    # identical even where buildmap only placed them by their callers (or not at all)
    confirmed = 0
    for src in (m.src / "auto").glob("f_*.cpp"):
        old = int(src.stem[2:], 16)
        new = fwd(old)
        if new in ok_new and (old not in fwd.same or fwd.funcs.get(old) != new):
            fwd.funcs[old] = new
            fwd.same.add(old)
            confirmed += 1
    report.append(f"pairs confirmed by the trial match (not identical in the map): {confirmed}")

    # 1. the old build's own files
    for f in ("functions.csv", "callgraph.csv", "fingerprints.csv", "fingerprints.json"):
        mv(m.data / f, leg / "data" / f, dry)
    mv(m.boundary_overrides, leg / "boundary_overrides.txt", dry)
    mv(m.status_csv, leg / "progress" / "status.csv", dry)
    finish_moves()
    if not dry:
        leg.mkdir(parents=True, exist_ok=True)
        fwd.write(leg / "addrmap.csv")
        m.data.mkdir(parents=True, exist_ok=True)
        (m.data / "functions.csv").write_bytes(Path(a.functions).read_bytes())

    # 2. boundary fixes and scope overrides of identical functions
    old_bo = leg / "boundary_overrides.txt" if not dry else m.boundary_overrides
    bo_out = ["# Function boundary fixes for the current build; see tools/config.py read_boundary_overrides.",
              f"# Carried over from legacy/{a.legacy}/boundary_overrides.txt where the function is unchanged.", ""]
    with open(a.functions, newline="") as fh:
        listed = {int(r["entry"], 16) for r in csv.DictReader(fh)}
    for entry, end, note, _new in config.read_boundary_overrides(old_bo):
        if entry in fwd.same:
            ne = fwd.funcs[entry]
            # `new` says the function list has no start there: decided by the new list
            bo_out.append(f"0x{ne:08x} 0x{ne + end - entry:08x}" + ("" if ne in listed else " new")
                          + (f"  # {note}" if note else ""))
        else:
            report.append(f"boundary fix 0x{entry:08x}-0x{end:08x} not carried over (function changed or not placed)")
    if not dry:
        m.boundary_overrides.write_text("\n".join(bo_out) + "\n")

    if m.scope_overrides.exists():
        lines = []
        for line in m.scope_overrides.read_text().splitlines():
            body, _h, note = line.partition("#")
            parts = body.split()
            if len(parts) == 3 and parts[0].startswith("0x"):
                s, e = int(parts[0], 16), int(parts[1], 16)
                ns = fwd.funcs.get(s)
                if ns is None:
                    report.append(f"scope override {line.strip()!r}: start not placed; dropped")
                    lines.append(f"# (2014, not placed) {line.strip()}")
                    continue
                # a block of library code: its end moves with the last function inside it
                inside = [o for o in fwd.funcs if s <= o < e]
                last = max(inside)
                ne = fwd.funcs[last] + (e - last)
                if ne - ns != e - s:
                    report.append(f"scope override {line.strip()!r}: size changed ({e - s} -> {ne - ns}); check it")
                lines.append(f"0x{ns:08x} 0x{ne:08x} {parts[2]}" + (f"  #{note}" if note else ""))
            else:
                lines.append(line)
        if not dry:
            m.scope_overrides.write_text("\n".join(lines) + "\n")

    # 3. matched functions
    moved_legacy = renamed = 0
    writes = []                         # (path, text), written once every move has landed
    for src in sorted((m.src / "auto").glob("f_*.cpp")):
        old = int(src.stem[2:], 16)
        sym = m.symbols_dir / "auto" / f"{src.stem}.txt"
        text = sym.read_text() if sym.exists() else ""
        new_text, missing = translate_symbol_lines(text, fwd)
        if old in fwd.same and not missing and fwd.funcs[old] in ok_new:
            new = fwd.funcs[old]
            mv(src, m.src / "auto" / f"f_{new:08x}.cpp", dry)
            if sym.exists():
                dst = m.symbols_dir / "auto" / f"f_{new:08x}.txt"
                mv(sym, dst, dry)
                writes.append((dst, new_text))
            renamed += 1
        else:
            why = "code changed" if old in fwd.funcs else "no twin found"
            if old in fwd.same and missing:
                why = "symbols with no twin: " + ", ".join(missing[:4])
            elif old in fwd.same:
                why = f"twin 0x{fwd.funcs[old]:08x} didn't match in the trial run"
            report.append(f"0x{old:08x} -> legacy ({why})")
            mv(src, leg / "src" / "auto" / src.name, dry)
            mv(sym, leg / "symbols" / "auto" / sym.name, dry)
            moved_legacy += 1
    finish_moves()
    if not dry:
        for path, text in writes:
            path.write_text(text)

    # 4. the other symbol files and names
    others = [m.symbols_txt] + [f for f in sorted(m.symbols_dir.rglob("*.txt"))
                                if f.parent.name != "auto" and f.name != "exports.txt"]
    for f in others:
        if not f.exists():
            continue
        new_text, missing = translate_symbol_lines(f.read_text(), fwd)
        for n in missing:
            report.append(f"{f.relative_to(ROOT).as_posix()}: {n} has no twin; left at its old address")
        if not dry:
            f.write_text(new_text)
    vt = m.names / "sdk_vtables.csv"
    if vt.exists():
        rows, kept = [], 0
        with open(vt, newline="") as fh:
            r = csv.DictReader(fh)
            fields = r.fieldnames
            for row in r:
                na = fwd.funcs.get(int(row["address"], 16))
                if na is None:
                    continue
                src_ = HEX.sub(lambda mm: f"0x{(fwd(int(mm.group(0), 16)) or 0):08x}", row["source"])
                rows.append(dict(row, address=f"0x{na:08x}", source=src_))
                kept += 1
        if not dry:
            with open(vt, "w", newline="") as fh:
                w = csv.DictWriter(fh, fieldnames=fields)
                w.writeheader()
                w.writerows(sorted(rows, key=lambda x: x["address"]))
        report.append(f"names/sdk_vtables.csv: {kept} entries carried over")

    if not dry:                         # one add: git pairs the moves up as renames
        subprocess.run(["git", "add", "-A", m.root.relative_to(ROOT).as_posix()], cwd=ROOT, check=True)
    summary = f"renamed to the new build: {renamed}; moved to legacy/{a.legacy}: {moved_legacy}"
    print(summary)
    out = ROOT / "build" / a.module / "port_report.txt"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(summary + "\n\n" + "\n".join(report) + "\n")
    print(f"details: {out.relative_to(ROOT).as_posix()}")


if __name__ == "__main__":
    main()
