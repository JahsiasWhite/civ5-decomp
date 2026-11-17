"""Task bundles and the agent loop.

    c5d task next [--n N]       write bundles for the next N ready queue items
    c5d task check <addr>       run the matcher for one task and log the attempt
    c5d agent [--n N] [--tries T]
                                for each of the next N items: write the bundle,
                                run config.local.json "agent_cmd" with TASK.md on
                                stdin, check, retry up to T times with the diff

A bundle is build/tasks/<addr>/TASK.md: everything a fresh agent needs for
one function (disassembly, Ghidra's pseudo-C, callee and data references
with known names/symbols, conventions, house rules). It lives under build/,
so the game's machine code in it is never committed.
"""
import csv
import json
import subprocess
import sys
import time
from pathlib import Path

import config  # noqa: E402  (tools/ is on sys.path wherever these run)

import capstone

ATTEMPTS = "attempts.jsonl"

RULES = """\
## House rules
- Write the function in **`{src}`** (create it). Put new or extended class
  layouts in `include/` (one header per class), reusing existing headers.
  When the "Class" section below names the function's class, use and extend
  the header it points to; a new class header gets a `// c5d-vtable: 0x...`
  line near the top so later tasks on that class find it. Name a header after
  its class (`include/<ClassName>.h`). Don't change a layout other matched
  functions rely on (field offsets, member order, signatures): CI rebuilds
  everything that includes a changed header and fails if one stops matching.
- Mark every name you give (function, class, struct, field, global) on the line
  before its definition: `// src: <TAG> [0x<address>]`, TAG one of `EXE`
  (exports, RTTI, strings in the exe), `SDK` (Civ V SDK / names given below),
  `LIB` (byte-identical library code), `COMMUNITY`, or
  `GUESS (confidence: high|medium|low)` for a name you made up from what the
  code does. Keep markers already in a header; add ones for what you add.
- Never paste disassembly, hex bytes or Ghidra output into source files or
  comments. Source must be hand-written C++.
- Compiler: Visual C++ 2008 SP1, `/O2 /Ob1`, linked with `/GL` + `/LTCG`.
  Only functions marked `inline` get inlined. Use `extern "C"` only for
  functions the exe exports by plain name.
- Register every function and global you define **or reference** with its
  address in **`{symfile}`** (create it; one `0x<address> <decorated name>` per
  line). Don't edit `symbols.txt` or other symbol files; other workers are
  running in parallel. A name already listed elsewhere for the same address is
  fine to repeat. To get decorated names, run
  `python tools/c5d.py --worker {worker} match --obj {src}`; it lists
  "not in symbols.txt" names.
- Allocation: use `FMalloc`/`FNEW` from `include/FMemory.h` where the code shows
  the small-object allocator pattern.
- Check with: `python tools/c5d.py --worker {worker} match --addr {addr} -v`
  (always pass `--worker {worker}`; it isolates your build from other workers)
  (LTCG mode). `MATCH` = done. `DIFF` shows a side-by-side; iterate.
  Calls to functions that use custom register conventions (marked below) only
  match when the callee is decompiled too; if that's the only difference, stop
  and say so.
- Fake matches: if the bytes only match through a trick the original source
  surely didn't use (`volatile` to pin instruction order, an array standing in
  for a vtable or class, `#pragma`, inline asm), first try `c5d-cflags`
  variants. If you still need the trick, add `// c5d-review: <what and why>`
  near the top of the file and mention it in your summary.
- Do not edit `tools/`, `config.json`, `config.local.json` or other people's functions. Don't commit.
- Finish with a 1-3 line summary: final status, and what blocked you if not MATCH.
"""


def disasm_text(img, addr, size, names):
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    lines, refs = [], {}
    for ins in md.disasm(img.read(addr, size), addr):
        txt = f"{ins.mnemonic} {ins.op_str}".strip()
        for op in ins.operands:
            v = None
            if op.type == capstone.x86.X86_OP_IMM:
                v = op.imm & 0xFFFFFFFF
            elif op.type == capstone.x86.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
                v = op.mem.disp & 0xFFFFFFFF
            if v is not None and v >= img.image_base and not (addr <= v < addr + size):
                refs[v] = ins.mnemonic
                if v in names:
                    txt += f"    ; {names[v]}"
        lines.append(f"{ins.address:08x}  {txt}")
    return "\n".join(lines), refs


_MERGED = None


def merged_note(addr):
    """Lines warning that Ghidra's pseudo-C only covers the first piece of a function
    whose boundary was fixed in boundary_overrides.txt."""
    global _MERGED
    if _MERGED is None:
        import config
        _MERGED = {m["entry"]: m["absorbed"] for m in config.boundary_merges()}
    pieces = _MERGED.get(addr)
    if not pieces:
        return []
    return ["Ghidra split this function (fixed in `boundary_overrides.txt`), so its pseudo-C",
            "below stops before " + ", ".join(f"0x{a:08x}" for a in pieces)
            + ". The disassembly above is the whole function.", ""]


def ghidra_c(build, addr):
    for f in (build / "dump").glob(f"{addr:08x}_*.txt"):
        t = f.read_text(errors="replace")
        c = t.split("// ---- ghidra decompile ----", 1)[-1]
        return "\n".join(line for line in c.splitlines() if line.strip())
    return "(not dumped; run `python tools/c5d.py dump 0x%08x`)" % addr


def class_section(ctx, addr, queue_by_addr):
    """The bundle's "Class" section (tools/classes.py), or nothing when the function
    has no known class or the context has no class index."""
    idx = getattr(ctx, "classes", None)
    if idx is None:
        return []
    import classes
    return classes.bundle_section(idx, addr, queue_by_addr)


def write_bundle(ctx, row, queue_by_addr, names, symbols_by_addr, imports, last_diff=None,
                 worker="w1"):
    addr, size = int(row["entry"], 16), int(row["size"])
    d = ctx.build / "tasks" / f"{addr:08x}"
    d.mkdir(parents=True, exist_ok=True)
    m = config.module()
    src = m.rel(m.src / "auto" / f"f_{addr:08x}.cpp")
    asm, refs = disasm_text(ctx.image, addr, size, {**names, **imports})
    ref_lines = []
    for v in sorted(refs):
        q = queue_by_addr.get(v)
        label = symbols_by_addr.get(v) or imports.get(v) or names.get(v) or ""
        if q:
            ref_lines.append(f"| 0x{v:08x} | function | {q['conv']}"
                             f"{' (regs: ' + q['entry_regs'] + ')' if q['entry_regs'] else ''} | "
                             f"{q['status']} | {label} |")
        elif v in imports:
            ref_lines.append(f"| 0x{v:08x} | import | | | {imports[v]} |")
        else:
            ref_lines.append(f"| 0x{v:08x} | data/other | | | {label} |")
    name = names.get(addr, "")
    parts = [
        f"# Decompile {'' if m.id == config.DEFAULT_MODULE else m.id + ':'}0x{addr:08x} {name}".rstrip(),
        "",
        "Repository: civ5-decomp (byte-matching decompilation of Civilization V: the exe and its "
        "game DLLs).",
        "Read `README.md` (Findings) once for context.",
        "",
        f"- Module: **{m.id}** (`{m.file}`): this function's files go under `{m.rel(m.root)}/`, "
        "shared headers in `include/`"
        + ("" if m.id == config.DEFAULT_MODULE else
           f". Run c5d as `python tools/c5d.py --module {m.id} ...` (or write the address as `{m.id}:0x...`)"),
        f"- Address: `0x{addr:08x}`, size {size} bytes",
        f"- Known name: `{name or 'unknown (name it descriptively; keep the address in the symbol map)'}`",
        f"- Convention guess: **{row['conv']}**"
        + (f" (registers read on entry: {row['entry_regs']})" if row["entry_regs"] else ""),
        f"- Callers: {row['callers']}; callees in scope: {row['callees']}; "
        f"cluster size {row['cluster_size']}",
        "",
        RULES.format(src=src, addr=(f"0x{addr:08x}" if m.id == config.DEFAULT_MODULE
                                         else f"{m.id}:0x{addr:08x}"), worker=worker,
                     symfile=m.rel(m.symbols_dir / "auto" / f"f_{addr:08x}.txt")),
        *class_section(ctx, addr, queue_by_addr),
        "## Disassembly (reference only)",
        "```", asm, "```",
        "",
        "## Ghidra pseudo-C (reference only; types are guesses)",
        *merged_note(addr),
        "```c", ghidra_c(ctx.build, addr), "```",
        "",
        "## References",
        "| address | kind | convention | status | known name / symbol |",
        "|---|---|---|---|---|",
        *ref_lines,
    ]
    if last_diff:
        parts += ["", "## Previous attempt (matcher output)", "```", last_diff[-6000:], "```"]
    (d / "TASK.md").write_text("\n".join(parts) + "\n", encoding="utf-8")
    return d / "TASK.md", src


def log_attempt(build, rec):
    with open(build / ATTEMPTS, "a") as fh:
        fh.write(json.dumps(rec) + "\n")


def attempts_by_addr(build):
    out = {}
    p = build / ATTEMPTS
    if p.exists():
        for line in p.read_text().splitlines():
            r = json.loads(line)
            out.setdefault(r["addr"], []).append(r)
    return out


def check(ctx, addr, worker=None):
    """Run the matcher for one function; returns (status, output)."""
    statuses, out = check_many(ctx, [addr], worker)
    return statuses[addr], out


def check_many(ctx, addrs, worker=None):
    """Run the matcher once for several functions (one build and link instead of one
    per function); returns ({addr: status}, output). A function the matcher didn't
    report on gets "NONE"."""
    cmd = [sys.executable, str(ctx.root / "tools" / "c5d.py")]
    if worker:
        cmd += ["--worker", worker]
    cmd += ["match", "-v"]
    for a in addrs:
        cmd += ["--addr", f"0x{a:08x}"]
    r = subprocess.run(cmd, capture_output=True, text=True, cwd=ctx.root)
    out = r.stdout + r.stderr
    statuses = {a: "NONE" for a in addrs}
    tags = {f"@0x{a:08x}": a for a in addrs}
    for line in out.splitlines():
        s = line.strip()
        for tag, a in tags.items():
            if tag in s:
                statuses[a] = s.split()[0]
    return statuses, out
