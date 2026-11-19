"""Address map between two builds of the same binary (maintainers).

    python tools/buildmap.py --old <old exe> --old-functions <csv> [--old-overrides <txt>]
                             --new <new exe> --new-functions <csv>
                             --out addrmap.csv [--report report.txt] [--matched-dir modules/exe/src/auto]

Steam rebuilt CivilizationV_DX11.exe in 2026 with the same compiler, so most functions
are the same code at a new address. This pairs them up:

1. Each function is cut to its old size (boundary overrides applied) and "normalised":
   absolute addresses (base relocations) and rel32 call/jump operands that leave the
   function are blanked; ones that point back inside it become offsets, so they still
   have to agree. An old function pairs with a new function start whose bytes, cut to
   the same size, normalise to the same thing.
2. A function whose normalised bytes are unique in both builds is paired outright.
3. Every pair then votes for the pairs it implies: the targets of its calls and jumps,
   and the values of its absolute references (globals, strings, vtables, jump tables).
   Functions whose code exists more than once (small thunks, duplicated helpers) are
   settled by those votes, over several passes. Functions whose code changed can still
   be placed this way when their callers agree; they're written with same=0.
4. Finally each pair is checked against the whole map: every reference it makes must
   land where the map says. Pairs that disagree are dropped and listed in the report.

Output CSV columns: kind (func|data), addr_2026, addr_2014, same (1 = identical code,
0 = placed by its callers only; always 1 for data), votes.
"""
import argparse
import bisect
import collections
import csv
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import config  # noqa: E402
from binfmt import PEImage  # noqa: E402

try:
    import capstone
except ImportError:                       # pragma: no cover
    sys.exit("buildmap needs capstone (pip install -r requirements.txt)")


class Build:
    """One binary plus its function starts and sizes."""

    def __init__(self, exe, functions):
        self.img = PEImage(exe)
        self.relocs = self.img.base_relocs()
        self.funcs = functions                     # {entry: size or None}
        self.starts = sorted(functions)
        self.md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
        self.md.skipdata = True

    def rough(self):
        """The .text section with relocated dwords and anything after an E8/E9 byte
        blanked: a cheap, over-eager mask used only to find candidates."""
        if getattr(self, "_rough", None) is None:
            name, rva, vsize, rawptr, rawsize = next(s for s in self.img.sections if s[0] == ".text")
            t = bytearray(self.img.data[rawptr:rawptr + min(vsize, rawsize)])
            start = self.img.image_base + rva
            for r in self.relocs:
                i = r - start
                if 0 <= i < len(t) - 3:
                    t[i:i + 4] = b"\0\0\0\0"
            for i in range(len(t) - 4):
                if t[i] in (0xE8, 0xE9):
                    t[i + 1:i + 5] = b"\0\0\0\0"
            self._rough, self._text0 = bytes(t), start
        return self._rough, self._text0

    def code(self, va, size):
        try:
            return self.img.read(va, size)
        except ValueError:
            return None

    def refs(self, va, size):
        """[(offset, kind, target)] for the references in [va, va+size): kind is 'abs'
        (a base-relocated dword) or 'rel' (a rel32 call/jmp/jcc operand)."""
        b = self.code(va, size)
        if b is None:
            return None, []
        out = []
        for r in range(va, va + size - 3):
            if r in self.relocs:
                out.append((r - va, "abs", int.from_bytes(b[r - va:r - va + 4], "little")))
        relocated = {o + k for o, _k, _t in out for k in range(4)}
        for ins in self.md.disasm(b, va):
            ib = ins.bytes
            if (ib[0] in (0xE8, 0xE9) and ins.size == 5) or \
               (len(ib) == 6 and ib[0] == 0x0F and 0x80 <= ib[1] <= 0x8F):
                off = ins.address - va + ins.size - 4
                if off in relocated:
                    continue
                rel = int.from_bytes(ib[-4:], "little", signed=True)
                out.append((off, "rel", (ins.address + ins.size + rel) & 0xFFFFFFFF))
        return b, out

    def shape(self, va, size):
        """(digest of the normalised bytes, refs) or (None, [])."""
        b, refs = self.refs(va, size)
        if b is None:
            return None, []
        t = bytearray(b)
        for off, _kind, target in refs:
            inside = va <= target < va + size
            t[off:off + 4] = (target - va).to_bytes(4, "little") if inside else b"\xff\xff\xff\xff"
        return hashlib.sha1(bytes(t)).digest(), refs

    def string_at(self, va):
        """The C string at `va` if it lies in .rdata and looks like text, else None."""
        if not hasattr(self, "_rdata"):
            self._rdata = [(self.img.image_base + s[1], self.img.image_base + s[1] + s[2])
                           for s in self.img.sections if s[0] == ".rdata"]
        if not any(lo <= va < hi for lo, hi in self._rdata):
            return None
        try:
            b = self.img.read(va, 48)
        except ValueError:
            return None
        end = b.find(b"\0")
        s = b[:end] if end >= 0 else b
        if len(s) >= 2 and all(32 <= c < 127 for c in s):
            return s
        return None


def read_functions(csv_path, overrides=None):
    """{entry: size} for single-range .text functions, with boundary overrides applied."""
    rows = config.load_functions(csv_path, config.read_boundary_overrides(overrides)
                                 if overrides else [])
    out = {}
    for r in rows:
        if r.get("block", ".text") != ".text":
            continue
        a, size = int(r["entry"], 16), int(r["size"] or 0)
        out[a] = size if r.get("ranges", "1") == "1" and size > 0 else None
    return out


def build_map(old, new, log=print):
    # 1. shapes of every old function, and of every new start cut to each size we need
    old_shape, old_refs = {}, {}
    sizes = collections.defaultdict(set)
    for a, size in old.funcs.items():
        if size:
            h, refs = old.shape(a, size)
            if h:
                old_shape[a], old_refs[a] = h, refs
                sizes[size].add(h)
    # candidates: new starts whose rough bytes agree over the first K bytes, then the
    # precise shape decides
    K = 16
    ort, o0 = old.rough()
    nrt, n0 = new.rough()
    by_prefix = collections.defaultdict(list)
    for b in new.starts:
        if 0 <= b - n0 < len(nrt):
            by_prefix[nrt[b - n0:b - n0 + K]].append(b)
    short = {}                                          # length -> {prefix: [starts]}
    new_by_shape = collections.defaultdict(list)       # (size, digest) -> new starts
    cache = {}
    for a, h in old_shape.items():
        size = old.funcs[a]
        if not (0 <= a - o0 < len(ort)):
            continue
        rough_old = ort[a - o0:a - o0 + size]
        if size >= K:
            cands = by_prefix.get(rough_old[:K], ())
        else:
            if size not in short:
                d = collections.defaultdict(list)
                for b in new.starts:
                    if 0 <= b - n0 < len(nrt):
                        d[nrt[b - n0:b - n0 + size]].append(b)
                short[size] = d
            cands = short[size].get(rough_old, ())
        for b in cands:
            if nrt[b - n0:b - n0 + size] != rough_old:
                continue
            key = (b, size)
            if key not in cache:
                cache[key] = new.shape(b, size)[0]
                if cache[key] is not None:
                    new_by_shape[(size, cache[key])].append(b)
    old_by_shape = collections.defaultdict(list)
    for a, h in old_shape.items():
        old_by_shape[(old.funcs[a], h)].append(a)
    log(f"old functions with code: {len(old_shape)}; "
        f"found in the new build: {sum(1 for a in old_shape if new_by_shape.get((old.funcs[a], old_shape[a])))}")

    # 2. unique on both sides
    fmap = {}
    for key, olds in old_by_shape.items():
        news = new_by_shape.get(key, [])
        if len(olds) == 1 and len(news) == 1:
            fmap[olds[0]] = news[0]
    log(f"pass 0: {len(fmap)} unique pairs")

    # 3. votes
    def implied(a, b):
        size = old.funcs[a]
        _nb, nrefs = new.refs(b, size)
        nmap = {(o, k): t for o, k, t in nrefs}
        for off, kind, target in old_refs.get(a, ()):
            nt = nmap.get((off, kind))
            if nt is not None and not (a <= target < a + size):
                yield target, nt

    votes = collections.defaultdict(collections.Counter)
    ranked = False
    for _ in range(40):
        votes = collections.defaultdict(collections.Counter)
        for a, b in fmap.items():
            for t_old, t_new in implied(a, b):
                votes[t_old][t_new] += 1
        taken = set(fmap.values())
        added = 0
        for key, olds in old_by_shape.items():
            news = set(new_by_shape.get(key, ())) - taken
            for a in olds:
                if a in fmap or not news:
                    continue
                v = votes.get(a)
                if not v:
                    continue
                (best, n), *rest = v.most_common(2) + [(None, 0)]
                if best in news and n > rest[0][1]:
                    fmap[a] = best
                    news.discard(best)
                    taken.add(best)
                    added += 1
        # outgoing: of the remaining look-alikes (same code apart from what they call),
        # take the candidate whose calls and references land where the map says
        known = dict(fmap)
        for t_old, v in votes.items():
            if t_old not in known:
                (best, n), *rest = v.most_common(2) + [(None, 0)]
                if n > rest[0][1]:
                    known[t_old] = best
        for key, olds in old_by_shape.items():
            news = set(new_by_shape.get(key, ())) - taken
            for a in olds:
                if a in fmap or not news:
                    continue
                scores = []
                for b in news:
                    agree = clash = 0
                    for t_old, t_new in implied(a, b):
                        if t_old in known:
                            if known[t_old] == t_new:
                                agree += 1
                            else:
                                clash += 1
                        else:
                            # look-alikes that differ only in which string they pass
                            # (Lua glue registering "Event", "Game", ...): the text decides
                            so, sn = old.string_at(t_old), new.string_at(t_new)
                            if so and sn:
                                if so == sn:
                                    agree += 1
                                else:
                                    clash += 1
                    # true copies (same code, own copies of the same strings) can only be
                    # told apart by position: the linker keeps an object's functions
                    # together, so prefer the candidate whose neighbours line up
                    i = bisect.bisect_left(old.starts, a)
                    j = bisect.bisect_left(new.starts, b)
                    for di in (-1, 1):
                        if 0 <= i + di < len(old.starts) and 0 <= j + di < len(new.starts):
                            if fmap.get(old.starts[i + di]) == new.starts[j + di]:
                                agree += 1
                    scores.append((agree - 4 * clash, agree, clash, b))
                scores.sort(reverse=True)
                top = scores[0]
                second = scores[1][0] if len(scores) > 1 else -1
                if top[1] >= 1 and top[2] == 0 and top[0] > second:
                    fmap[a] = top[3]
                    news.discard(top[3])
                    taken.add(top[3])
                    added += 1
        log(f"pass: +{added} by votes and outgoing references ({len(fmap)} paired)")
        if not added and not ranked:
            # last resort for true copies: when a group has as many unplaced copies on
            # each side, pair them in address order (the linker keeps the order), then
            # run the votes again so their strings and globals follow
            ranked = True
            for key, olds in old_by_shape.items():
                rest_old = sorted(a for a in olds if a not in fmap)
                rest_new = sorted(set(new_by_shape.get(key, ())) - taken)
                if rest_old and len(rest_old) == len(rest_new):
                    for a, b in zip(rest_old, rest_new):
                        fmap[a] = b
                        taken.add(b)
                        added += 1
            log(f"paired in address order: {added}")
        if not added:
            break

    # identical code at exactly one place in the new build that Ghidra didn't list as a
    # function start (the port adds a boundary fix for it)
    nrt_starts = set(new.starts)
    extra = 0
    for a, h in old_shape.items():
        if a in fmap or len(old_by_shape[(old.funcs[a], h)]) != 1:
            continue
        size = old.funcs[a]
        pat = ort[a - o0:a - o0 + size]
        if size < 8:
            continue
        hits, j = [], nrt.find(pat)
        while j >= 0 and len(hits) < 3:
            hits.append(n0 + j)
            j = nrt.find(pat, j + 1)
        exact = [b for b in hits if new.shape(b, size)[0] == h]
        if len(exact) == 1 and exact[0] not in taken and exact[0] not in nrt_starts:
            fmap[a] = exact[0]
            taken.add(exact[0])
            extra += 1
    log(f"identical code where the new function list has no start: {extra}")
    same = set(fmap)

    # functions whose code changed: placed by callers when the vote is clear
    new_starts = set(new.starts)
    taken = set(fmap.values())
    changed = {}
    for a in old.funcs:
        if a in fmap:
            continue
        v = votes.get(a)
        if not v:
            continue
        (best, n), *rest = v.most_common(2) + [(None, 0)]
        if best in new_starts and best not in taken and ((n >= 2 and n >= 3 * rest[0][1]) or (n == 1 and rest[0][1] == 0)):
            changed[a] = best
            taken.add(best)
    fmap.update(changed)
    log(f"placed by callers only (code changed): {len(changed)}")

    # 4. consistency: every reference of an identical pair must agree with the map
    dropped = {}
    for a in sorted(same):
        b = fmap[a]
        for t_old, t_new in implied(a, b):
            if t_old in fmap and fmap[t_old] != t_new:
                dropped[a] = f"calls 0x{t_old:08x}, mapped to 0x{fmap[t_old]:08x}, but its twin calls 0x{t_new:08x}"
                break
    for a in dropped:
        del fmap[a]
        same.discard(a)
    log(f"dropped as inconsistent: {len(dropped)}")

    # data: absolute references that aren't functions, by majority vote
    dmap = {}
    old_text_end = max(a + (s or 0) for a, s in old.funcs.items())
    for t_old, v in votes.items():
        if t_old in old.funcs or t_old in fmap:
            continue
        (best, n), *rest = v.most_common(2) + [(None, 0)]
        if n > rest[0][1]:
            dmap[t_old] = (best, n)
    # import slots pair by name, whatever the votes say
    new_imports = {name: va for va, name in new.img.imports().items()}
    n_imp = 0
    for va, name in old.img.imports().items():
        if name in new_imports:
            dmap[va] = (new_imports[name], 0)
            n_imp += 1
    log(f"data addresses: {len(dmap)} (import slots by name: {n_imp})")
    func_votes = {a: sum(votes[a].values()) for a in fmap}
    return fmap, same, dmap, dropped, func_votes, old_text_end


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    p.add_argument("--old", required=True)
    p.add_argument("--old-functions", required=True)
    p.add_argument("--old-overrides")
    p.add_argument("--new", required=True)
    p.add_argument("--new-functions", required=True)
    p.add_argument("--out", required=True)
    p.add_argument("--report")
    p.add_argument("--matched-dir", help="src/auto of the old build: report which matches aren't placed")
    a = p.parse_args(argv)

    old = Build(a.old, read_functions(a.old_functions, a.old_overrides))
    new = Build(a.new, read_functions(a.new_functions))
    fmap, same, dmap, dropped, fvotes, _ = build_map(old, new)

    with open(a.out, "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["kind", "addr_2026", "addr_2014", "same", "votes"])
        for o, n in sorted(fmap.items(), key=lambda kv: kv[1]):
            w.writerow(["func", f"0x{n:08x}", f"0x{o:08x}", int(o in same), fvotes.get(o, 0)])
        for o, (n, votes) in sorted(dmap.items(), key=lambda kv: kv[1][0]):
            w.writerow(["data", f"0x{n:08x}", f"0x{o:08x}", 1, votes])
    print(f"wrote {a.out}: {len(fmap)} functions ({len(same)} identical), {len(dmap)} data addresses")

    if a.report:
        lines = []
        if a.matched_dir:
            matched = sorted(int(f.stem[2:], 16) for f in Path(a.matched_dir).glob("f_*.cpp"))
            missing = [m for m in matched if m not in fmap]
            changed = [m for m in matched if m in fmap and m not in same]
            lines.append(f"matched functions: {len(matched)}; placed with identical code: "
                         f"{len(matched) - len(missing) - len(changed)}; placed but changed: "
                         f"{len(changed)}; not placed: {len(missing)}")
            lines.append("")
            lines.append("# placed, code changed (need new work in the new build)")
            lines += [f"0x{m:08x} -> 0x{fmap[m]:08x}" for m in changed]
            lines.append("")
            lines.append("# not placed")
            for m in missing:
                why = dropped.get(m) or ("not in the old function list" if m not in old.funcs
                                         else "no identical code and no clear vote from callers")
                lines.append(f"0x{m:08x}  {why}")
        lines.append("")
        lines.append("# dropped as inconsistent")
        lines += [f"0x{k:08x}  {v}" for k, v in sorted(dropped.items())]
        Path(a.report).write_text("\n".join(lines) + "\n")
        print(f"wrote {a.report}")


if __name__ == "__main__":
    main()
