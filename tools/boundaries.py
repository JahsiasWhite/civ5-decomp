"""Find functions Ghidra split in two (see boundary_overrides.txt).

    python tools/c5d.py boundaries [--write]

A function B is taken to be the split-off tail of the function A just before it when:
  - B starts on the byte right after A ends (no padding between them),
  - A branches to B's first byte,
  - nothing else reaches B: no call to it anywhere, no jump to it from outside A,
    no pointer to it in the exe's data (base relocations), not exported,
  - B has no real name or symbol yet (only Ghidra's FUN_ placeholder).
Chains (A, B, C, ...) merge into one function. The checks for outside references
scan raw bytes, so a stray false hit only ever makes us skip a candidate.
"""
import struct
from collections import defaultdict

import capstone
from capstone import x86


def _text(img):
    name, rva, vsize, rawptr, rawsize = next(s for s in img.sections if s[0] == ".text")
    return img.image_base + rva, img.data[rawptr:rawptr + min(vsize, rawsize)]


def _incoming(img):
    """(call targets, {jump target: set of source VAs}, pointer targets) over the exe."""
    base, text = _text(img)
    calls, jumps = set(), defaultdict(set)
    n = len(text)
    for i in range(n - 5):
        op = text[i]
        if op == 0xE8 or op == 0xE9:
            rel, = struct.unpack_from("<i", text, i + 1)
            t = (base + i + 5 + rel) & 0xFFFFFFFF
            (calls.add(t) if op == 0xE8 else jumps[t].add(base + i))
        elif op == 0x0F and i + 6 <= n and 0x80 <= text[i + 1] <= 0x8F:
            rel, = struct.unpack_from("<i", text, i + 2)
            jumps[(base + i + 6 + rel) & 0xFFFFFFFF].add(base + i)
    pointers = set()
    for va in img.base_relocs():
        try:
            pointers.add(struct.unpack("<I", img.read(va, 4))[0])
        except ValueError:
            pass
    return calls, jumps, pointers


def _branch_targets(img, md, addr, size):
    try:
        code = img.read(addr, size)
    except ValueError:
        return set()
    out = set()
    for ins in md.disasm(code, addr):
        if ins.group(capstone.CS_GRP_JUMP) and ins.operands and ins.operands[0].type == x86.X86_OP_IMM:
            out.add(ins.operands[0].imm & 0xFFFFFFFF)
    return out


def find_splits(img, rows, protected=()):
    """rows: the function list (config.load_functions()). protected: addresses that
    must stay separate (already named in symbols). -> [(entry, end, [absorbed])]."""
    funcs = sorted((int(r["entry"], 16), int(r["size"]), r["name"]) for r in rows if r["ranges"] == "1")
    exports = set(img.exports().values())
    protected = set(protected)
    calls, jumps, pointers = _incoming(img)

    def lone_tail(b, name):
        return (name.startswith("FUN_") and b not in calls and b not in pointers
                and b not in exports and b not in protected)

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    out = []
    i = 0
    while i < len(funcs):
        a, size, _ = funcs[i]
        end, absorbed, targets = a + size, [], None
        j = i + 1
        while j < len(funcs) and funcs[j][0] == end and lone_tail(funcs[j][0], funcs[j][2]):
            b, bsize, _ = funcs[j]
            if targets is None:
                targets = _branch_targets(img, md, a, size)
            new_end = b + bsize
            if b not in targets or any(not (a <= s < new_end) for s in jumps.get(b, ())):
                break
            absorbed.append(b)
            targets |= _branch_targets(img, md, b, bsize)
            end = new_end
            j += 1
        if absorbed:
            out.append((a, end, absorbed))
        i = j
    return out


def _read_upto(img, va, size):
    """Up to `size` bytes at va (fewer at the end of the section)."""
    while size:
        try:
            return img.read(va, size)
        except ValueError:
            size -= 1
    return b""


def _jump_tables(img):
    """{table VA: [case targets]} for MSVC switch tables: `jmp dword ptr [reg*4 + table]`
    (ff 24 xx with a disp32-only SIB) where the disp32 is relocated, and the table is the
    run of relocated 4-byte slots from there. The table and its case labels are pointed to
    from the exe, but neither is a function start."""
    base, text = _text(img)
    relocs = img.base_relocs()
    out = {}
    for i in range(len(text) - 7):
        if text[i] == 0xFF and text[i + 1] == 0x24 and (text[i + 2] & 0xC7) == 0x85                 and base + i + 3 in relocs:
            t, = struct.unpack_from("<I", text, i + 3)
            targets, slot = [], t
            while slot in relocs:
                try:
                    targets.append(struct.unpack("<I", img.read(slot, 4))[0])
                except ValueError:
                    break
                slot += 4
            if targets:
                out[t] = targets
    return out


def _flow_end(md, img, entry, stops, limit=0x10000, tables=None):
    """End (exclusive) of the code reached from entry by recursive descent: follows jcc/jmp
    targets inside [entry, entry+limit) that are not in `stops` (a jump to another
    function's start is a tail call) and the cases of switch tables ({table: [targets]}),
    and stops at ret, int3 and jmp. A table right after the code counts toward the end."""
    seen, work, end = set(), [entry], entry
    while work:
        a = work.pop()
        while a not in seen:
            ins = next(md.disasm(_read_upto(img, a, 16), a), None)
            if ins is None:
                return None
            seen.add(a)
            end = max(end, a + ins.size)
            if ins.mnemonic in ("ret", "retf", "int3"):
                break
            if ins.group(capstone.CS_GRP_JUMP):
                op = ins.operands[0] if ins.operands else None
                if op is not None and op.type == x86.X86_OP_IMM:
                    t = op.imm & 0xFFFFFFFF
                    if entry <= t < entry + limit and t not in stops:
                        work.append(t)
                elif op is not None and op.type == x86.X86_OP_MEM and tables:
                    t = op.mem.disp & 0xFFFFFFFF
                    cases = tables.get(t, ())
                    work.extend(c for c in cases if entry <= c < entry + limit)
                    if cases and entry <= t < entry + limit:
                        end = max(end, t + 4 * len(cases))
                if ins.mnemonic == "jmp":
                    break
            a += ins.size
    return end


def find_misplaced(img, rows, protected=()):
    """Entries Ghidra listed in the middle of another function (often mid-instruction),
    the damage a misread stretch of code leaves behind. A start is an address after int3
    padding on a 16-byte boundary, or one pointed to from data, exported or named; a start
    inside the code reached from the start before it is not a real one (a 0xcc byte in an
    operand, a jump-table target). A FUN_ entry B that is not a start and not called is
    reported when the code reached from the nearest real start A before it runs past B.
    Switch tables and their case labels are not starts; the flow follows the cases.
    -> [(A, end, [B...], A_is_listed)], for `<A> <end> [new]` overrides."""
    import bisect
    base, text = _text(img)
    calls, jumps, pointers = _incoming(img)
    listed = {int(r["entry"], 16): r["name"] for r in rows}
    padded = {base + i for i in range(1, len(text))
              if text[i - 1] == 0xCC and text[i] != 0xCC and (base + i) % 16 == 0}
    tables = _jump_tables(img)
    not_starts = set(tables) | {c for cs in tables.values() for c in cs}
    starts = sorted(padded | {a for a in (pointers - not_starts) | set(img.exports().values())
                              | set(protected) if base <= a < base + len(text)})
    stops = set(starts) | calls
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    ends = {}

    def end_of(a):
        if a not in ends:
            ends[a] = _flow_end(md, img, a, stops, tables=tables)
        return ends[a]

    groups = {}
    for b, name in sorted(listed.items()):
        if b in stops or not name.startswith("FUN_"):
            continue
        k = bisect.bisect_left(starts, b) - 1
        while k > 0 and (end_of(starts[k - 1]) or 0) > starts[k]:
            k -= 1                                  # starts[k] is inside the function before it
        if k < 0:
            continue
        a = starts[k]
        end = end_of(a)
        if end is not None and b < end:
            groups.setdefault(a, []).append(b)
    return [(a, ends[a], bs, a in listed) for a, bs in sorted(groups.items())]


# Imports the compiler knows never return (__declspec(noreturn) in the CRT/SDK headers),
# so it emits nothing after a call to them. Every other import returns: code follows.
NORETURN_IMPORTS = {"_CxxThrowException", "exit", "_exit", "abort", "longjmp", "terminate",
                    "_invoke_watson", "_amsg_exit", "ExitProcess", "ExitThread", "FatalExit",
                    "FatalAppExitA", "FatalAppExitW", "RaiseException", "__report_gsfailure",
                    "_invalid_parameter_noinfo_noreturn"}


def _import_thunks(img, text_base, text):
    """{thunk VA: import name} for `jmp dword ptr [IAT slot]` stubs, plus the IAT slots."""
    imps = img.imports()
    out = {}
    for i in range(len(text) - 6):
        if text[i] == 0xFF and text[i + 1] == 0x25:
            slot, = struct.unpack_from("<I", text, i + 2)
            if slot in imps:
                out[text_base + i] = imps[slot]
    return out, imps


def find_truncated(img, rows, protected=()):
    """Functions Ghidra cut short at a call it wrongly took as never returning (it marked
    the import thunk for lua_pushstring, lua_pushcclosure, ... noreturn). A listed
    function is reported when its last instruction is a call to an import that returns,
    the next byte isn't int3 padding, and the code reached from its entry (following
    the fall-through after calls) runs past its listed end. FUN_ entries inside the new
    range that nothing calls or points to are absorbed; any other entry there means a
    real function starts there, and the candidate is skipped.
    -> [(entry, end, [absorbed], import name)]."""
    import bisect
    base, text = _text(img)
    calls, _jumps, pointers = _incoming(img)
    thunks, imps = _import_thunks(img, base, text)
    funcs = sorted((int(r["entry"], 16), int(r["size"]), r["name"]) for r in rows if r["ranges"] == "1")
    starts = [f[0] for f in funcs]
    names = {f[0]: f[2] for f in funcs}
    protected = set(protected)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    tables = _jump_tables(img)
    out = []
    for a, size, _name in funcs:
        end = a + size
        if size < 5 or not (base <= end < base + len(text)) or text[end - base] == 0xCC:
            continue
        last = None
        for ins in md.disasm(_read_upto(img, a, size), a):
            last = ins
        if last is None or last.mnemonic != "call" or last.address + last.size != end:
            continue
        op = last.operands[0]
        if op.type == x86.X86_OP_IMM:
            imp = thunks.get(op.imm & 0xFFFFFFFF)
        elif op.type == x86.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
            imp = imps.get(op.mem.disp & 0xFFFFFFFF)
        else:
            imp = None
        if not imp or imp.split("!")[-1] in NORETURN_IMPORTS:
            continue
        stops = (calls | pointers | {s for s in starts if s != a}) - {end}
        new_end = _flow_end(md, img, a, stops, tables=tables)
        if new_end is None or new_end <= end:
            continue
        inside = starts[bisect.bisect_right(starts, a):bisect.bisect_left(starts, new_end)]
        if any(not names[b].startswith("FUN_") or b in calls or b in pointers or b in protected
               for b in inside):
            continue
        out.append((a, new_end, inside, imp.split("!")[-1]))
    return out
