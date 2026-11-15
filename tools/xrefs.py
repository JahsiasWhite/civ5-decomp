"""Find direct callers of a function in the original exe (call/jmp rel32 scan).

    python tools/xrefs.py 0x0081c2a0
"""
import csv
import json
import struct
import sys
from bisect import bisect_right
from pathlib import Path

from binfmt import PEImage

ROOT = Path(__file__).resolve().parent.parent
CFG = json.loads((ROOT / "config.json").read_text())


def main():
    targets = [int(a, 16) for a in sys.argv[1:]]
    img = PEImage(Path(CFG["game_dir"]) / CFG["target_exe"])
    name, rva, vsize, rawptr, rawsize = next(s for s in img.sections if s[0] == ".text")
    base = img.image_base + rva
    text = img.data[rawptr:rawptr + min(vsize, rawsize)]

    funcs = []
    csv_path = ROOT / "build" / "functions.csv"
    if csv_path.exists():
        with open(csv_path, newline="") as fh:
            funcs = sorted((int(r["entry"], 16), r["name"]) for r in csv.DictReader(fh))
    starts = [f[0] for f in funcs]

    def owner(va):
        i = bisect_right(starts, va) - 1
        return f"{funcs[i][1]}+0x{va - funcs[i][0]:x}" if i >= 0 else "?"

    for t in targets:
        print(f"callers of 0x{t:08x}:")
        for i in range(len(text) - 5):
            op = text[i]
            if op in (0xE8, 0xE9):
                rel, = struct.unpack_from("<i", text, i + 1)
                if (base + i + 5 + rel) & 0xFFFFFFFF == t:
                    kind = "call" if op == 0xE8 else "jmp "
                    print(f"  {kind} at 0x{base + i:08x}  in {owner(base + i)}")


if __name__ == "__main__":
    main()
