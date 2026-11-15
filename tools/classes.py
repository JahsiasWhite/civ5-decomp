"""Group functions into classes by vtable, so task bundles can say which class a
function belongs to and hand the agent that class's layout so far.

    python tools/c5d.py classes [--top N]     classes with the most unmatched members
    python tools/c5d.py classes 0x<addr>      one class (by vtable or member address)

How classes are found (the exe has RTTI only for a few library classes):
- A vtable is a run of code pointers in .rdata that some function stores into an
  object (`mov dword ptr [reg+off], offset vtable`). Those functions are the
  class's constructors and destructors. A store at a non-zero offset is a
  secondary vtable (multiple inheritance) of the same class.
- A function in a vtable slot is a virtual member of that class. Small functions
  that the linker folded together (`return 0;`, `ret`) appear in many unrelated
  vtables; those are reported as shared rather than given one owner.
- When a constructor inlines its base's, it stores the base vtable first and its
  own last (a destructor does the reverse). The vtable with more slots is taken
  as the derived class, the other as its base.

Class names, best first: a header in include/ that claims the vtable (see below),
the SDK interface names (names/sdk_vtables.csv), RTTI, then the class most
members' committed symbols are decorated with. Otherwise `Vtbl_<address>`.

A header claims a class with a line like `// c5d-vtable: 0x00a04240` near the
top (one line per vtable; secondary vtables optional). Every bundle for a member
of that class then includes the header, so layouts grow in one place.
"""
import bisect
import csv
import re
import struct
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
INCLUDE = ROOT / "include"
VTABLE_MARK = re.compile(r"c5d-vtable:\s*(0x[0-9a-fA-F]+)")
SHARED_LIMIT = 3          # a function in more classes than this is a folded stub
HEADER_CHARS = 6000       # header text inlined into a bundle
STACK = object()          # _vtable_store: the store targets a stack object


class ClassIndex:
    def __init__(self, img, functions, symbols_by_addr, names_csv=None, include_dir=INCLUDE):
        self.img = img
        starts = sorted((int(r["entry"], 16), int(r["size"])) for r in functions)
        self._starts = [a for a, _ in starts]
        self._sizes = [s for _, s in starts]
        self.symbols_by_addr = symbols_by_addr
        self.vtables = {}          # vtable va -> [slot targets]
        self.installs = defaultdict(list)   # function -> [(store va, vtable, offset)]
        self.locals = defaultdict(set)      # function -> vtables of objects it builds on the stack
        self.class_of_vtable = {}  # vtable -> class key (primary vtable va)
        self.base_of = {}          # class key -> base class key
        self.ctors = defaultdict(set)       # class key -> functions that store its vtables
        self.slots = defaultdict(list)      # function -> [(class key, vtable, slot)]
        self.headers = {}          # vtable -> header path
        self.name_source = {}      # class key -> (name, source)
        self._find_vtables()
        self._group()
        self._read_headers(include_dir)
        self._name_classes(names_csv or ROOT / "names" / "sdk_vtables.csv")

    # ------------------------------------------------------------ discovery
    def owner(self, va):
        i = bisect.bisect_right(self._starts, va) - 1
        if i >= 0 and va < self._starts[i] + max(self._sizes[i], 1):
            return self._starts[i]
        return None

    def _section(self, name):
        for s in self.img.sections:
            if s[0] == name:
                return s
        return None

    def _code_pointer_runs(self):
        text = self._section(".text")
        t_lo = self.img.image_base + text[1]
        t_hi = t_lo + text[2]
        _n, rva, vsize, rawptr, rawsize = self._section(".rdata")
        data = self.img.data[rawptr:rawptr + min(vsize, rawsize)]
        base = self.img.image_base + rva
        # the import address table lives in .rdata; its on-disk entries are name RVAs
        # that happen to fall in .text's address range
        iat_rva, iat_size = self.img.dirs[12] if len(self.img.dirs) > 12 else (0, 0)
        iat = range(self.img.image_base + iat_rva, self.img.image_base + iat_rva + iat_size)
        run = []
        for off in range(0, len(data) - 3, 4):
            v, = struct.unpack_from("<I", data, off)
            if t_lo <= v < t_hi and base + off not in iat:
                run.append(v)
            elif run:
                yield base + off - 4 * len(run), run
                run = []
        if run:
            yield base + len(data) // 4 * 4 - 4 * len(run), run

    def _find_vtables(self):
        runs = list(self._code_pointer_runs())
        in_run = {}                      # pointer position -> (run start, index)
        for start, r in runs:
            for k in range(len(r)):
                in_run[start + 4 * k] = (start, k)
        text = self._section(".text")
        t_lo = self.img.image_base + text[1]
        t_hi = t_lo + text[2]
        tdata = self.img.data[text[3]:text[3] + min(text[2], text[4])]
        starts = set()
        for rel in sorted(self.img.base_relocs()):
            if not (t_lo + 6 <= rel < t_hi - 4):
                continue
            o = rel - t_lo
            target, = struct.unpack_from("<I", tdata, o)
            if target not in in_run:
                continue
            offset = self._vtable_store(tdata, o)
            if offset is None:
                continue
            starts.add(target)
            f = self.owner(rel)
            if f is None:
                continue
            if offset is STACK:
                self.locals[f].add(target)
            else:
                self.installs[f].append((rel, target, offset))
        # each vtable runs from its start to the next vtable start or the end of its run
        by_run = defaultdict(list)
        for s in starts:
            by_run[in_run[s][0]].append(s)
        for run_start, r in runs:
            cut = sorted(by_run.get(run_start, ()))
            for i, s in enumerate(cut):
                end = cut[i + 1] if i + 1 < len(cut) else run_start + 4 * len(r)
                k0 = (s - run_start) // 4
                self.vtables[s] = r[k0:k0 + (end - s) // 4]

    @staticmethod
    def _vtable_store(t, o):
        """Object offset written to if the imm32 at t[o] is the source of `mov dword
        ptr [base(+index)(+disp)], imm32` (C7 /0), else None. A store into a stack
        object (base esp) returns STACK: the vtable is real, but the function only
        builds a local object (often an inlined exception before a throw), so it
        isn't a constructor of that class."""
        for disp_len, mod in ((0, 0), (1, 1), (4, 2)):
            for sib in (0, 1):
                p = o - disp_len - sib - 2           # position of the C7 opcode
                if p < 0 or t[p] != 0xC7:
                    continue
                m = t[p + 1]
                if m >> 6 != mod or (m >> 3) & 7 != 0 or (m & 7 == 4) != bool(sib):
                    continue
                if mod == 0 and (m & 7 == 5 or (sib and t[p + 2] & 7 == 5)):
                    continue                         # absolute address, not an object
                if sib and t[p + 2] & 7 == 4:        # [esp+disp]: object on the stack
                    return STACK
                if disp_len == 0:
                    return 0
                if disp_len == 1:
                    d = t[o - 1]
                    return d - 256 if d > 127 else d
                return struct.unpack_from("<i", t, o - 4)[0]
        return None

    def _group(self):
        primary_votes = defaultdict(Counter)   # secondary vtable -> Counter(primary)
        for f, stores in self.installs.items():
            at0 = []
            for _rel, vt, off in stores:
                if off == 0 and vt not in at0:
                    at0.append(vt)
            if not at0:
                continue
            own = max(at0, key=lambda v: (len(self.vtables.get(v, ())), at0.index(v)))
            for vt in at0:
                if vt != own:
                    self.base_of.setdefault(own, vt)
            for _rel, vt, off in stores:
                if off != 0:
                    primary_votes[vt][own] += 1
        for vt in self.vtables:
            if vt in primary_votes and vt not in self._primaries():
                self.class_of_vtable[vt] = primary_votes[vt].most_common(1)[0][0]
            else:
                self.class_of_vtable[vt] = vt
        for f, stores in self.installs.items():
            for _rel, vt, _off in stores:
                self.ctors[self.class_of_vtable[vt]].add(f)
        for vt, targets in self.vtables.items():
            c = self.class_of_vtable[vt]
            for k, t in enumerate(targets):
                self.slots[t].append((c, vt, k))

    def _primaries(self):
        if not hasattr(self, "_prim"):
            self._prim = {vt for stores in self.installs.values()
                          for _r, vt, off in stores if off == 0}
        return self._prim

    def _read_headers(self, include_dir):
        for h in sorted(Path(include_dir).rglob("*.h")):
            for m in VTABLE_MARK.finditer(h.read_text(errors="replace")):
                self.headers[int(m.group(1), 16)] = h

    # ------------------------------------------------------------ naming
    def _rtti_name(self, vt):
        try:
            col, = struct.unpack("<I", self.img.read(vt - 4, 4))
            sig, _o, _cd, td = struct.unpack("<IIII", self.img.read(col, 16))
            if sig != 0:
                return None
            raw = self.img.read(td + 8, 256).split(b"\0", 1)[0].decode("latin-1")
        except (ValueError, struct.error):
            return None
        if not raw.startswith((".?AV", ".?AU")) or not raw.endswith("@@"):
            return None
        return "::".join(reversed(raw[4:-2].split("@")))

    @staticmethod
    def class_from_symbol(sym):
        """Class part of an MSVC member function name, or None."""
        m = re.match(r"\?\?(?:0|1|_G|_E)([A-Za-z_]\w*)@", sym)
        if m:
            return m.group(1)
        m = re.match(r"\?[A-Za-z_]\w*@([A-Za-z_]\w*)@@[QAIUMES]", sym)
        return m.group(1) if m else None

    def _name_classes(self, names_csv):
        sdk = {}
        if Path(names_csv).exists():
            with open(names_csv, newline="") as fh:
                for r in csv.DictReader(fh):
                    m = re.search(r"@(0x[0-9a-fA-F]+)$", r.get("source", ""))
                    if m and "::" in r["name"]:
                        sdk[int(m.group(1), 16)] = r["name"].split("::")[0]
        for c in set(self.class_of_vtable.values()):
            vts = self.vtables_of(c)
            header = next((self.headers[v] for v in vts if v in self.headers), None)
            if header:
                self.name_source[c] = (header.stem, f"header {header.relative_to(ROOT).as_posix()}")
                continue
            hit = next((sdk[v] for v in vts if v in sdk), None)
            if hit:
                self.name_source[c] = (hit, "SDK interface")
                continue
            hit = next((n for n in (self._rtti_name(v) for v in vts) if n), None)
            if hit:
                self.name_source[c] = (hit, "RTTI")
                continue
            votes = Counter()
            for f in self.members(c, include_shared=False):
                if self.owning_classes(f) != [c]:
                    continue                 # inherited or shared: says nothing about c
                n = self.class_from_symbol(self.symbols_by_addr.get(f, ""))
                if n:
                    votes[n] += 1
            if votes:
                self.name_source[c] = (votes.most_common(1)[0][0], "symbols of matched members")
            else:
                self.name_source[c] = (f"Vtbl_{c:08x}", "unnamed")

    # ------------------------------------------------------------ queries
    def vtables_of(self, c):
        return sorted(v for v, k in self.class_of_vtable.items() if k == c)

    def name(self, c):
        return self.name_source[c][0]

    def header(self, c):
        return next((self.headers[v] for v in self.vtables_of(c) if v in self.headers), None)

    def classes_of(self, f):
        """Distinct classes f is a virtual member of."""
        return sorted({c for c, _vt, _k in self.slots.get(f, ())})

    def is_shared(self, f):
        return len(self.classes_of(f)) > SHARED_LIMIT

    def members(self, c, include_shared=True):
        out = set(self.ctors.get(c, ()))
        for vt in self.vtables_of(c):
            for t in self.vtables[vt]:
                if include_shared or not self.is_shared(t):
                    out.add(t)
        return out

    def owning_classes(self, f):
        """Classes a function belongs to: ones whose vtable it stores, then the
        ones it is a virtual slot of (most-base first when they're related)."""
        own = [c for c, fs in self.ctors.items() if f in fs]
        if own:
            return sorted(own, key=lambda c: len(self.vtables.get(c, ())), reverse=True)[:1]
        cs = self.classes_of(f)
        if len(cs) > SHARED_LIMIT:
            return []
        # inherited without override: the most-base class among them defines it
        return [c for c in cs if self.base_of.get(c) not in cs] or cs

    def lookup(self, addr):
        """Class key for a vtable, secondary vtable or member function address."""
        if addr in self.class_of_vtable:
            return self.class_of_vtable[addr]
        own = self.owning_classes(addr)
        return own[0] if own else None


# ---------------------------------------------------------------- bundles
def bundle_section(idx, addr, queue_by_addr, status_of=None, max_rows=30):
    """Markdown lines for a task bundle, or [] when the function has no known class."""
    status_of = status_of or (lambda a: (queue_by_addr.get(a) or {}).get("status", "?"))
    cs = idx.classes_of(addr)
    if idx.is_shared(addr):
        return ["## Class", "",
                f"This function sits in the vtables of {len(cs)} different classes, so it is",
                "most likely a tiny body the linker folded together (`return 0;`, an empty",
                "virtual). Name it for what it does; no single class owns it.", ""]
    owners = idx.owning_classes(addr)
    if not owners:
        return []
    c = owners[0]
    name, source = idx.name_source[c]
    lines = ["## Class", ""]
    roles = []
    if addr in idx.ctors.get(c, ()):
        roles.append("a constructor or destructor (it stores the class's vtable)")
    for oc, vt, k in idx.slots.get(addr, ()):
        if oc == c:
            roles.append(f"virtual slot {k} (offset 0x{4 * k:x}) of vtable 0x{vt:08x}")
    lines.append(f"This function is {', and '.join(roles) or 'a member'} of **{name}** "
                 f"(name from: {source}).")
    others = [idx.name(o) for o in cs if o != c]
    if others:
        lines.append("It is also inherited by: " + ", ".join(sorted(set(others))[:8]) + ".")
    base = idx.base_of.get(c)
    if base is not None:
        lines.append(f"Base class (from an inlined base constructor): **{idx.name(base)}** "
                     f"(vtable 0x{base:08x}).")
    if (queue_by_addr.get(addr) or {}).get("conv") != "thiscall":
        lines.append("It doesn't read `this` (ecx) on entry. Write it as a member anyway; "
                     "a method that ignores `this` compiles the same.")
    lines.append("")
    h = idx.header(c)
    vts = ", ".join(f"0x{v:08x}" for v in idx.vtables_of(c))
    if h:
        text = h.read_text(errors="replace")
        lines += [f"Its layout so far is in `{h.relative_to(ROOT).as_posix()}`. Use and extend that "
                  "header (add fields, methods) instead of declaring a new struct:", "",
                  "```cpp", text[:HEADER_CHARS].rstrip(), "```" if len(text) <= HEADER_CHARS
                  else "// ... (truncated; read the file)\n```", ""]
    else:
        lines += [f"No header claims this class yet. If you work out any of its layout, put it "
                  f"in `include/{name if not name.startswith('Vtbl_') else 'Unk_' + name[5:]}.h` "
                  f"with the line `// c5d-vtable: {vts.split(', ')[0]}` near the top, so later "
                  "tasks on this class get it. Keep the vtable pointer as the first member "
                  "(declare the virtuals you know, in slot order).", ""]
    rows = [(-1, f, "ctor/dtor") for f in sorted(idx.ctors.get(c, set()))]
    for n, vt in enumerate(idx.vtables_of(c)):
        for k, t in enumerate(idx.vtables[vt]):
            rows.append((n * 10000 + k, t, f"slot {k}" + (f" of 0x{vt:08x}" if vt != c else "")))
    seen, table, skipped = set(), [], 0
    for order, t, role in rows:
        if t == addr or t in seen:
            continue
        seen.add(t)
        if t not in queue_by_addr or idx.is_shared(t):
            skipped += 1                 # library code, or a stub folded across classes
            continue
        st = status_of(t)
        table.append((st != "MATCH", order, t, role, st, idx.symbols_by_addr.get(t, "")))
    table.sort()                         # matched first (they show the names and layout), then slot order
    matched = sum(1 for r in table if not r[0])
    lines += [f"Other members ({len(table)}, {matched} matched; vtables {vts}"
              + (f"; {skipped} library or shared-stub slots left out" if skipped else "") + "):", "",
              "| address | role | status | symbol |", "|---|---|---|---|"]
    for _u, _o, t, role, st, sym in table[:max_rows]:
        lines.append(f"| 0x{t:08x} | {role} | {st} | {sym} |")
    if len(table) > max_rows:
        lines.append(f"| ... | {len(table) - max_rows} more (`python tools/c5d.py classes "
                     f"0x{c:08x}`) | | |")
    return lines + [""]


def report(idx, queue_by_addr, top=30):
    """Lines for `c5d classes`: classes by number of unmatched members."""
    rows = []
    for c in set(idx.class_of_vtable.values()):
        ms = [m for m in idx.members(c, include_shared=False) if m in queue_by_addr]
        if not ms:
            continue
        done = sum(1 for m in ms if queue_by_addr[m]["status"] == "MATCH")
        h = idx.header(c)
        rows.append((len(ms) - done, len(ms), done, c, h))
    rows.sort(key=lambda r: (-r[0], r[3]))
    named = sum(1 for r in rows if not idx.name(r[3]).startswith("Vtbl_"))
    out = [f"{len(rows)} classes with in-scope members ({named} named, "
           f"{sum(1 for r in rows if r[4])} with a header); "
           f"{len(idx.vtables)} vtables", "",
           f"{'todo':>5} {'total':>5}  {'vtable':<10}  class (name source) / header"]
    for todo, total, _done, c, h in rows[:top]:
        name, source = idx.name_source[c]
        out.append(f"{todo:>5} {total:>5}  0x{c:08x}  {name} ({source})"
                   + (f"  [{h.relative_to(ROOT).as_posix()}]" if h else ""))
    return out


def describe(idx, c, queue_by_addr):
    name, source = idx.name_source[c]
    out = [f"class {name} (name from: {source})",
           "vtables: " + ", ".join(f"0x{v:08x} ({len(idx.vtables[v])} slots)" for v in idx.vtables_of(c))]
    if idx.base_of.get(c) is not None:
        out.append(f"base: {idx.name(idx.base_of[c])} (0x{idx.base_of[c]:08x})")
    h = idx.header(c)
    out.append(f"header: {h.relative_to(ROOT).as_posix() if h else '(none)'}")
    out.append("ctors/dtors: " + ", ".join(f"0x{f:08x}" for f in sorted(idx.ctors.get(c, ()))))
    for vt in idx.vtables_of(c):
        out.append(f"vtable 0x{vt:08x}:")
        for k, t in enumerate(idx.vtables[vt]):
            q = queue_by_addr.get(t) or {}
            out.append(f"  [{k:>3}] 0x{t:08x} {q.get('status', 'out of scope'):<6} "
                       f"{'shared ' if idx.is_shared(t) else ''}"
                       f"{idx.symbols_by_addr.get(t) or q.get('name') or ''}")
    return out
