"""Link-time-code-generation (LTCG) matching.

The original exe was built with /GL + /LTCG, so the code for a function is
only final after linking: the linker may give internal functions custom
register calling conventions, inline across files, and so on.

This mode compiles every source with /GL, links them all together with
/LTCG into a throwaway DLL (missing functions/globals become generated
placeholders), and compares each function in that DLL with the original.
Call/jump targets and absolute addresses are resolved through the linker
map file and import tables and checked against symbols.txt.
"""
import bisect
import re
import subprocess
from pathlib import Path

from binfmt import PEImage

UNRESOLVED_RE = re.compile(r'unresolved external symbol (?:"[^"]*" \((\S+)\)|(\S+))')
MAP_RE = re.compile(r"^\s*[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s+(?:f\s+)?(?:i\s+)?(\S*)")


class LinkMap:
    """Parse a VC++ 2008 /MAP file (public and static symbols).

    Note: under LTCG the map omits file-static data, so lookups near such
    data can land on an unrelated symbol; callers should treat a lookup
    into a stub with a non-zero delta as unresolved.
    """

    def __init__(self, path):
        self.by_name = {}
        self.obj_of = {}
        for line in Path(path).read_text(errors="replace").splitlines():
            m = MAP_RE.match(line)
            if m:
                self.by_name.setdefault(m.group(1), int(m.group(2), 16))
                self.obj_of.setdefault(m.group(1), m.group(3))
        items = sorted((va, n) for n, va in self.by_name.items())
        self._vas = [va for va, _ in items]
        self._names = [n for _, n in items]

    def lookup(self, va):
        """VA -> (name, delta) for the nearest symbol at or below va."""
        i = bisect.bisect_right(self._vas, va) - 1
        if i < 0:
            return None, 0
        return self._names[i], va - self._vas[i]

    def next_after(self, va):
        i = bisect.bisect_right(self._vas, va)
        return self._vas[i] if i < len(self._vas) else None


def build(ctx, sources, include_syms):
    """Compile with /GL and link with /LTCG. Returns (dll_path, map_path)."""
    out = ctx.build / "ltcg"
    out.mkdir(parents=True, exist_ok=True)
    objs = []
    for src in sources:
        obj = out / (src.stem + ".obj")
        cmd = [str(ctx.cl), *ctx.cflags, "/GL", f"/Fo{obj}", str(src)]
        r = subprocess.run(cmd, capture_output=True, text=True, env=ctx.env)
        if r.returncode:
            raise RuntimeError(f"compile failed: {src}\n{r.stdout}{r.stderr}")
        objs.append(obj)

    dll, mapf = out / "test.dll", out / "test.map"
    base = [str(ctx.link), "/nologo", "/DLL", "/NOENTRY", "/LTCG", "/OPT:REF", "/OPT:ICF",
            "/FIXED:NO", "/MACHINE:X86", f"/MAP:{mapf}", f"/OUT:{dll}",
            *[f"/LIBPATH:{p}" for p in ctx.libpaths],
            *[f"/INCLUDE:{s}" for s in include_syms],
            "kernel32.lib", "user32.lib", "msvcrt.lib"]

    stub_obj = out / "stubs.obj"
    extra = []
    missing_prev = []
    for _attempt in range(3):
        r = subprocess.run(base + [str(o) for o in objs] + extra,
                           capture_output=True, text=True, env=ctx.env)
        if r.returncode == 0:
            return dll, mapf
        missing = sorted({a or b for a, b in UNRESOLVED_RE.findall(r.stdout)} - set(missing_prev))
        missing = sorted(set(missing) | set(missing_prev))
        missing_prev = missing
        if not missing:
            raise RuntimeError(f"link failed:\n{r.stdout}{r.stderr}")
        make_stubs(ctx, missing, out / "stubs.asm", stub_obj)
        extra = [str(stub_obj)]
    raise RuntimeError(f"link still failing after stubbing:\n{r.stdout}")


def make_stubs(ctx, names, asm_path, obj_path):
    """Placeholder definitions for not-yet-decompiled symbols (4 bytes each)."""
    lines = [".386", ".model flat", "option casemap:none", ".data"]
    for i, n in enumerate(names):
        lines += [f"PUBLIC {n}", f"{n} dd 0"]
    lines.append("END")
    asm_path.write_text("\n".join(lines) + "\n")
    r = subprocess.run([str(ctx.ml), "/nologo", "/c", "/coff", f"/Fo{obj_path}", str(asm_path)],
                       capture_output=True, text=True, env=ctx.env)
    if r.returncode:
        raise RuntimeError(f"stub assembly failed:\n{r.stdout}{r.stderr}")


def _branch_imm(ins):
    """For a direct call/jmp/jcc, return (imm_offset_in_insn, imm_size, target)."""
    if ins.group(1) or ins.group(7) or ins.group(2):   # JUMP, BRANCH_RELATIVE, CALL
        ops = ins.operands
        if len(ops) == 1 and ops[0].type == 2:            # X86_OP_IMM
            b = ins.bytes
            if b[0] in (0xE8, 0xE9) or (b[0] == 0x0F and 0x80 <= b[1] <= 0x8F):
                return len(b) - 4, 4, ops[0].imm & 0xFFFFFFFF
            return len(b) - 1, 1, ops[0].imm & 0xFFFFFFFF
    return None


def _disasm(code, va):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    return list(md.disasm(code, va))


def compare(name, orig_img, orig_va, orig_size, test_img, lmap, syms, obj_refs=None):
    """Compare one function. Returns a result dict like the obj-mode matcher.

    obj_refs: {offset: (symbol, addend)} from the plain (non-/GL) compile of the
    same function; used to name references the LTCG map cannot (file statics).
    """
    obj_refs = obj_refs or {}
    our_va = lmap.by_name.get(name)
    if our_va is None:
        return {"status": "ERROR", "detail": "not emitted by the linker (inlined, or "
                "nothing references it yet; exported functions are kept automatically)"}

    nxt = lmap.next_after(our_va)
    our_len = (nxt - our_va) if nxt else orig_size
    try:
        ours = test_img.read(our_va, our_len)
    except ValueError:
        ours = test_img.read(our_va, orig_size)
    ours = ours.rstrip(b"\xcc")
    # the linker may pad with int3; keep at least up to the original size
    orig = orig_img.read(orig_va, orig_size)

    imports_t, imports_o = test_img.imports(), orig_img.imports()
    orig_iat_by_name = {v: k for k, v in imports_o.items()}
    test_relocs = test_img.base_relocs()

    def resolve(value, off=None):
        """Our absolute address -> (label, expected original address or None)."""
        if value in imports_t:
            imp = imports_t[value]
            return imp, orig_iat_by_name.get(imp)
        n, delta = lmap.lookup(value)
        # LTCG maps omit file statics, so a non-exact hit may be the wrong
        # neighbour; prefer the compiler's own name for this reference.
        unreliable = n is None or delta != 0
        if unreliable and off is not None and off in obj_refs:
            hint, addend = obj_refs[off]
            if hint in syms:
                return hint if not addend else f"{hint}+0x{addend:x}", syms[hint] + addend
            return hint, None
        if unreliable:
            return f"0x{value:08x}", None
        if n in syms:
            return (n if not delta else f"{n}+0x{delta:x}"), syms[n] + delta
        return (n if not delta else f"{n}+0x{delta:x}"), None

    masked, notes = set(), []

    # absolute references (base relocations)
    for off in range(len(ours) - 3):
        if our_va + off in test_relocs:
            masked.update(range(off, off + 4))
            val = int.from_bytes(ours[off:off + 4], "little")
            label, expected = resolve(val, off)
            actual = int.from_bytes(orig[off:off + 4], "little") if off + 4 <= len(orig) else None
            if expected is None:
                notes.append(("?", off, label, f"unknown in original; original has 0x{actual or 0:08x}"))
            elif expected == actual:
                notes.append(("ok", off, label, f"0x{actual:08x}"))
            else:
                notes.append(("BAD", off, label, f"expected 0x{expected:08x}, original has 0x{actual or 0:08x}"))

    # relative branches leaving the function
    oi = {i.address - orig_va: i for i in _disasm(orig, orig_va)}
    for ins in _disasm(ours, our_va):
        bi = _branch_imm(ins)
        if not bi:
            continue
        imm_off, imm_size, target = bi
        if our_va <= target < our_va + len(ours):
            continue                               # internal jump: bytes must match as-is
        off = ins.address - our_va
        masked.update(range(off + imm_off, off + imm_off + imm_size))
        label, expected = resolve(target)
        o = oi.get(off)
        obi = _branch_imm(o) if o is not None else None
        actual = obi[2] if obi else None
        if expected is None:
            notes.append(("?", off, label, f"unknown in original; original goes to "
                          + (f"0x{actual:08x}" if actual is not None else "?")))
        elif expected == actual:
            notes.append(("ok", off, label, f"0x{actual:08x}"))
        else:
            notes.append(("BAD", off, label, "expected 0x%08x, original goes to %s"
                          % (expected, f"0x{actual:08x}" if actual is not None else "?")))

    n = min(len(ours), len(orig))
    byte_diffs = [i for i in range(n) if i not in masked and ours[i] != orig[i]]
    size_note = "" if len(ours) == len(orig) else \
        f"size differs: ours {len(ours)} bytes, original {len(orig)} bytes"
    bad = any(s == "BAD" for s, *_ in notes)
    unknown = any(s == "?" for s, *_ in notes)
    if not byte_diffs and not bad and not size_note:
        status = "MATCH?" if unknown else "MATCH"
    else:
        status = "DIFF"
    bad_offs = {o for s, o, *_ in notes if s == "BAD"}
    return {"status": status, "va": orig_va, "our_va": our_va, "ours": ours, "orig": orig,
            "orig_full": orig, "byte_diffs": byte_diffs, "relocs": notes,
            "size_note": size_note,
            "masked": {m for m in masked if not any(b <= m < b + 4 for b in bad_offs)}}
