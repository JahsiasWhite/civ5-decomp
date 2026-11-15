"""civ5-decomp command-line tool.

    python tools/c5d.py env       check the toolchain
    python tools/c5d.py analyze   import and analyze the exe in Ghidra headless,
                                  then export build/functions.csv
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CFG = json.loads((ROOT / "config.json").read_text())

GAME_EXE = Path(CFG["game_dir"]) / CFG["target_exe"]
GHIDRA = Path(CFG["ghidra_dir"])
HEADLESS = GHIDRA / "support" / "analyzeHeadless.bat"
MSVC_CL = Path(CFG["msvc_bin"]) / "cl.exe"
PROJ_DIR = ROOT / CFG["ghidra_project_dir"]
PROJ_NAME = CFG["ghidra_project_name"]
BUILD = ROOT / "build"


def ok(flag, label, detail=""):
    print(f"  [{'ok' if flag else '!!'}] {label}" + (f": {detail}" if detail else ""))
    return flag


def cmd_env(_args):
    good = True
    print("Target")
    good &= ok(GAME_EXE.is_file(), "game exe", str(GAME_EXE))

    print("Ghidra")
    good &= ok(HEADLESS.is_file(), "analyzeHeadless", str(HEADLESS))
    java = shutil.which("java")
    ver = ""
    if java:
        r = subprocess.run([java, "-version"], capture_output=True, text=True)
        m = re.search(r'version "([^"]+)"', r.stderr)
        ver = m.group(1) if m else r.stderr.strip()
    major = int(ver.split(".")[0]) if ver[:2].isdigit() else 0
    good &= ok(major >= 17, "java >= 17", ver or "not found")

    print("Compiler (needs Visual C++ 2008 SP1, cl 15.00.30729)")
    if MSVC_CL.is_file():
        r = subprocess.run([str(MSVC_CL)], capture_output=True, text=True)
        banner = (r.stderr or r.stdout).splitlines()[0] if (r.stderr or r.stdout) else "?"
        good &= ok("15.00" in banner, "cl.exe", banner)
    else:
        good &= ok(False, "cl.exe", f"not found at {MSVC_CL}")

    print("\nAll good." if good else "\nSome checks failed (see [!!] above).")
    return 0 if good else 1


def cmd_analyze(args):
    if not HEADLESS.is_file():
        sys.exit(f"Ghidra not found: {HEADLESS}")
    PROJ_DIR.mkdir(exist_ok=True)
    BUILD.mkdir(exist_ok=True)
    out_csv = BUILD / "functions.csv"
    have_project = (PROJ_DIR / f"{PROJ_NAME}.gpr").exists()

    cmd = [str(HEADLESS), str(PROJ_DIR), PROJ_NAME]
    if have_project and not args.reimport:
        cmd += ["-process", CFG["target_exe"], "-noanalysis"]
    else:
        cmd += ["-import", str(GAME_EXE), "-overwrite"]
    cmd += [
        "-scriptPath", str(ROOT / "tools" / "ghidra"),
        "-postScript", "ExportFunctions.py", str(out_csv),
        "-log", str(BUILD / "ghidra_analyze.log"),
    ]
    print(" ".join(f'"{c}"' if " " in c else c for c in cmd), flush=True)
    return subprocess.call(cmd)


def cmd_dump(args):
    if not (PROJ_DIR / f"{PROJ_NAME}.gpr").exists():
        sys.exit("No Ghidra project yet; run `analyze` first.")
    out = BUILD / "dump"
    cmd = [str(HEADLESS), str(PROJ_DIR), PROJ_NAME,
           "-process", CFG["target_exe"], "-noanalysis", "-readOnly",
           "-scriptPath", str(ROOT / "tools" / "ghidra"),
           "-postScript", "DumpFunctions.py", str(out), *args.addrs]
    r = subprocess.run(cmd, capture_output=True, text=True)
    for line in r.stdout.splitlines():
        if "DumpFunctions:" in line:
            print(line.split("DumpFunctions:", 1)[1].strip())
    return r.returncode


# ---------------------------------------------------------------- match

def load_symbols():
    """symbols.txt -> {name: address}."""
    syms = {}
    for line in (ROOT / "symbols.txt").read_text().splitlines():
        line = line.split("#", 1)[0].strip()
        if line:
            addr, name = line.split(None, 1)
            syms[name.strip()] = int(addr, 16)
    return syms


def msvc_env():
    vc = Path(CFG["msvc_bin"]).parent            # .../VC
    root = vc.parent                             # .../9.0
    env = dict(os.environ)
    env["PATH"] = str(vc / "bin") + os.pathsep + env.get("PATH", "")
    env["INCLUDE"] = os.pathsep.join(
        [str(ROOT / "include"), str(vc / "include"), str(root / "WinSDK" / "Include")])
    return env


def compile_cpp(src, extra_flags=()):
    """Compile one .cpp to build/obj/<name>.obj; return the obj path."""
    out_dir = BUILD / "obj"
    out_dir.mkdir(parents=True, exist_ok=True)
    obj = out_dir / (src.stem + ".obj")
    cmd = [str(MSVC_CL), *CFG["cflags"], *extra_flags, f"/Fo{obj}", str(src)]
    r = subprocess.run(cmd, capture_output=True, text=True, env=msvc_env())
    if r.returncode != 0:
        print(r.stdout + r.stderr)
        sys.exit(f"compile failed: {src}")
    return obj


def disasm(code, va):
    try:
        import capstone
    except ImportError:
        return None
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    return [(i.address, i.size, f"{i.mnemonic} {i.op_str}".strip()) for i in md.disasm(code, va)]


def compare_function(image, syms, sym, sec, start, end):
    """Compare one compiled function against the original. Returns a result dict."""
    va = syms[sym.name]
    ours = sec.data[start:end]
    try:
        orig = image.read(va, len(ours))
    except ValueError as e:
        return {"status": "ERROR", "detail": str(e)}

    masked = set()          # byte offsets (function-relative) covered by relocations
    reloc_notes = []
    from binfmt import REL_I386_DIR32, REL_I386_REL32
    for r in sec.relocs:
        if not (start <= r.offset < end):
            continue
        off = r.offset - start
        masked.update(range(off, off + 4))
        addend = int.from_bytes(ours[off:off + 4], "little", signed=True)
        orig_val = int.from_bytes(orig[off:off + 4], "little", signed=True)
        if r.type == REL_I386_REL32:
            actual = (va + off + 4 + orig_val) & 0xFFFFFFFF
        elif r.type == REL_I386_DIR32:
            actual = orig_val & 0xFFFFFFFF
        else:
            reloc_notes.append(("?", off, r.symbol.name, f"reloc type 0x{r.type:x} not checked"))
            continue
        # where should it point?
        target_sym = r.symbol
        if target_sym.section == sec.index:          # label inside our own section
            expected = va + (target_sym.value - start) + addend
        elif target_sym.name in syms:
            expected = syms[target_sym.name] + addend
        else:
            reloc_notes.append(("?", off, target_sym.name, f"unknown symbol; original points at 0x{actual:08x}"))
            continue
        expected &= 0xFFFFFFFF
        if expected == actual:
            reloc_notes.append(("ok", off, target_sym.name, f"0x{actual:08x}"))
        else:
            reloc_notes.append(("BAD", off, target_sym.name,
                                f"we point at 0x{expected:08x}, original at 0x{actual:08x}"))

    byte_diffs = [i for i in range(len(ours)) if i not in masked and ours[i] != orig[i]]
    bad_relocs = [n for n in reloc_notes if n[0] == "BAD"]
    unknown = [n for n in reloc_notes if n[0] == "?"]

    # does the original function continue past our length?
    orig_size = FUNC_SIZES.get(va)
    size_note = ""
    if orig_size is not None and orig_size != len(ours):
        size_note = f"size differs: ours {len(ours)} bytes, original {orig_size} bytes"

    if not byte_diffs and not bad_relocs and not size_note:
        status = "MATCH" if not unknown else "MATCH?"
    else:
        status = "DIFF"
    bad_offsets = {off for state, off, _n, _t in reloc_notes if state == "BAD"}
    return {"status": status, "va": va, "ours": ours, "orig": orig,
            "masked": masked - {o + k for o in bad_offsets for k in range(4)},
            "byte_diffs": byte_diffs, "relocs": reloc_notes, "size_note": size_note,
            "orig_full": image.read(va, orig_size) if orig_size else orig}


FUNC_SIZES = {}


def load_func_sizes():
    csv_path = BUILD / "functions.csv"
    if csv_path.exists():
        import csv
        with open(csv_path, newline="") as fh:
            for row in csv.DictReader(fh):
                if row["ranges"] == "1":
                    FUNC_SIZES[int(row["entry"], 16)] = int(row["size"])


def print_diff(res):
    ours, orig_full, va = res["ours"], res["orig_full"], res["va"]
    a = disasm(ours, va)
    b = disasm(orig_full, va)
    if a is None or b is None:
        for i in res["byte_diffs"][:16]:
            print(f"      +0x{i:03x}: ours {ours[i]:02x}  orig {res['orig'][i]:02x}")
        return
    width = max((len(t) for _, _, t in a), default=10) + 2
    masked = res["masked"]
    print(f"      {'ours':<{width + 12}}original")
    for k in range(max(len(a), len(b))):
        left = f"{a[k][0] - va:04x} {a[k][2]}" if k < len(a) else ""
        right = f"{b[k][0] - va:04x} {b[k][2]}" if k < len(b) else ""
        both = k < len(a) and k < len(b)
        if both and a[k][2] == b[k][2]:
            mark = "  "
        elif (both and a[k][0] == b[k][0] and a[k][1] == b[k][1]
              and ours[a[k][0] - va:a[k][0] - va + a[k][1]] == orig_full[b[k][0] - va:b[k][0] - va + b[k][1]]
              or both and any(o in masked for o in range(a[k][0] - va, a[k][0] - va + a[k][1]))
              and all(ours[i] == orig_full[i] for i in range(a[k][0] - va, a[k][0] - va + a[k][1])
                      if i not in masked)):
            mark = " r"      # differs only in a relocation that was checked OK
        else:
            mark = "!!"
        print(f"   {mark} {left:<{width + 10}}{right}")


def cmd_match(args):
    from binfmt import PEImage, CoffObject
    load_func_sizes()
    syms = load_symbols()
    image = PEImage(GAME_EXE)
    sources = [Path(s) for s in args.sources] or sorted((ROOT / "src").rglob("*.cpp"))
    totals = {"MATCH": 0, "MATCH?": 0, "DIFF": 0, "ERROR": 0}
    results = {}

    # Compile each file normally once: gives us the list of functions it defines
    # (and is the whole comparison in --obj mode).
    per_file = []
    for src in sources:
        obj = CoffObject(compile_cpp(src, args.flag or ()))
        per_file.append((src, obj))

    test_img = lmap = None
    if not args.obj:
        import ltcg
        exports = image.exports()
        defined = {s.name for _src, o in per_file for s, *_ in o.functions()}
        keep = sorted(n for n in defined
                      if n in exports or (n.startswith("_") and n[1:] in exports))
        ctx = LinkCtx(args.flag or ())
        try:
            dll, mapf = ltcg.build(ctx, sources, keep)
            lmap = ltcg.LinkMap(mapf)
            # Targets nothing in src/ calls yet get dropped by /OPT:REF. Re-link
            # forcing just those; called functions keep their LTCG conventions.
            orphans = sorted(n for n in defined
                             if n in syms and n not in lmap.by_name and n not in keep)
            if orphans:
                dll, mapf = ltcg.build(ctx, sources, keep + orphans)
                lmap = ltcg.LinkMap(mapf)
        except RuntimeError as e:
            sys.exit(str(e))
        test_img = PEImage(dll)

    for src, obj in per_file:
        try:
            print(src.resolve().relative_to(ROOT))
        except ValueError:
            print(src)
        for sym, sec, start, end in obj.functions():
            if sym.name not in syms:
                print(f"  ----   {sym.name}  (not in symbols.txt, skipped)")
                continue
            if args.only and not any(o in sym.name for o in args.only):
                continue
            va = syms[sym.name]
            if args.addr and va not in args.addr:
                continue
            if args.obj:
                res = compare_function(image, syms, sym, sec, start, end)
            else:
                size = FUNC_SIZES.get(va, end - start)
                obj_refs = {r.offset - start: (r.symbol.name, int.from_bytes(
                                sec.data[r.offset:r.offset + 4], "little", signed=True))
                            for r in sec.relocs if start <= r.offset < end}
                res = ltcg.compare(sym.name, image, va, size, test_img, lmap, syms, obj_refs)
            totals[res["status"]] += 1
            nbytes = len(res["ours"]) if "ours" in res else end - start
            results[va] = (sym.name, res["status"], FUNC_SIZES.get(va, nbytes),
                           str(src.resolve().relative_to(ROOT)) if src.resolve().is_relative_to(ROOT) else str(src))
            print(f"  {res['status']:<6} {sym.name}  @0x{va:08x}  {nbytes} bytes")
            if res["status"] == "ERROR":
                print(f"         {res['detail']}")
                continue
            for state, off, name, note in res["relocs"]:
                if state != "ok" or args.verbose:
                    print(f"         ref +0x{off:03x} {name}: {note}")
            if res["size_note"]:
                print(f"         {res['size_note']}")
            if res["status"] == "DIFF" or args.verbose:
                print_diff(res)
    if not args.obj and not args.only and not args.addr:
        record_status(results)
    print(f"\n[{'obj' if args.obj else 'ltcg'} mode]  "
          + "  ".join(f"{k}: {v}" for k, v in totals.items()))
    return 0 if totals["DIFF"] == 0 and totals["ERROR"] == 0 else 1


STATUS_CSV = ROOT / "progress" / "status.csv"


def load_status():
    """{address: status} from progress/status.csv."""
    import csv
    out = {}
    if STATUS_CSV.exists():
        with open(STATUS_CSV, newline="") as fh:
            for r in csv.DictReader(fh):
                out[int(r["address"], 16)] = r["status"]
    return out


def record_status(results):
    """Replace progress/status.csv with the results of a full match run."""
    import csv
    import datetime
    STATUS_CSV.parent.mkdir(exist_ok=True)
    old = {}
    if STATUS_CSV.exists():
        with open(STATUS_CSV, newline="") as fh:
            old = {int(r["address"], 16): r for r in csv.DictReader(fh)}
    today = datetime.date.today().isoformat()
    with open(STATUS_CSV, "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["address", "symbol", "status", "bytes", "source", "since"])
        for va in sorted(results):
            name, status, nbytes, src = results[va]
            since = old[va]["since"] if va in old and old[va]["status"] == status else today
            w.writerow([f"0x{va:08x}", name, status, nbytes, src.replace("\\", "/"), since])


def load_names():
    """{address: best-known readable name} from all name sources."""
    import csv
    names = {}
    fcsv = BUILD / "functions.csv"
    if fcsv.exists():
        with open(fcsv, newline="") as fh:
            for r in csv.DictReader(fh):
                if not r["name"].startswith("FUN_"):
                    names[int(r["entry"], 16)] = r["name"]
    for f in sorted((ROOT / "names").glob("*.csv")):
        with open(f, newline="") as fh:
            for r in csv.DictReader(fh):
                names.setdefault(int(r["address"], 16), r["name"])
    for sym, va in load_symbols().items():
        names[va] = sym
    return names


def cmd_queue(args):
    import workqueue
    from binfmt import PEImage
    if not (BUILD / "scope.csv").exists():
        sys.exit("run `c5d scope` first")
    rows = workqueue.build(PEImage(GAME_EXE), BUILD / "scope.csv", load_status(), load_names(),
                           BUILD / "queue.csv")
    todo = [r for r in rows if r["status"] != "MATCH"]
    ready = [r for r in todo if r["pending_callees"] == 0]
    from collections import Counter
    conv = Counter(r["conv"] for r in rows)
    print(f"{len(rows)} in-scope functions, {len(rows) - len(todo)} matched, {len(todo)} to do, "
          f"{len(ready)} ready now (all callees done or none)")
    print("conventions: " + ", ".join(f"{k} {v}" for k, v in conv.most_common()))
    print(f"\nnext {args.top}:")
    for r in todo[:args.top]:
        print(f"  {r['entry']} {r['size']:>5}b {r['conv']:<8} depth {r['depth']:<3} "
              f"cluster {r['cluster_size']:<4} {r['name']}")
    return 0


def task_context():
    import csv
    import types
    from binfmt import PEImage
    qcsv = BUILD / "queue.csv"
    if not qcsv.exists():
        sys.exit("run `c5d scope` and `c5d queue` first")
    with open(qcsv, newline="") as fh:
        rows = list(csv.DictReader(fh))
    image = PEImage(GAME_EXE)
    return types.SimpleNamespace(
        root=ROOT, build=BUILD, image=image, rows=rows,
        by_addr={int(r["entry"], 16): r for r in rows},
        names=load_names(), imports=image.imports(),
        symbols_by_addr={va: n for n, va in load_symbols().items()})


def pick_tasks(ctx, n, tries, min_size=5):
    import tasks
    tried = tasks.attempts_by_addr(BUILD)
    status = load_status()
    out = []
    for r in ctx.rows:
        a = int(r["entry"], 16)
        if status.get(a) == "MATCH" or int(r["pending_callees"]) or int(r["size"]) < min_size:
            continue
        if len(tried.get(a, [])) >= tries:
            continue
        out.append(r)
        if len(out) >= n:
            break
    return out


def prefetch_dumps(addrs):
    missing = [f"0x{a:08x}" for a in addrs if not list((BUILD / "dump").glob(f"{a:08x}_*.txt"))]
    if missing:
        print(f"dumping {len(missing)} function(s) with Ghidra...", flush=True)
        cmd_dump(type("A", (), {"addrs": missing})())


def cmd_task(args):
    import tasks
    ctx = task_context()
    if args.action == "next":
        rows = pick_tasks(ctx, args.n, args.tries, args.min_size)
        prefetch_dumps([int(r["entry"], 16) for r in rows])
        for r in rows:
            path, src = tasks.write_bundle(ctx, r, ctx.by_addr, ctx.names, ctx.symbols_by_addr, ctx.imports)
            print(f"{r['entry']}  {r['size']:>5}b  {r['conv']:<8} -> {path.relative_to(ROOT)}")
    else:                                   # check
        a = int(args.addr, 16)
        status, out = tasks.check(ctx, a)
        tasks.log_attempt(BUILD, {"addr": f"0x{a:08x}", "status": status, "agent": "manual",
                                  "time": __import__("time").time()})
        print(out if args.verbose else status)
    return 0


def cmd_agent(args):
    import tasks
    import time
    agent_cmd = CFG.get("agent_cmd")
    if not agent_cmd:
        sys.exit('set "agent_cmd" in config.json (a command that reads the task prompt on stdin), '
                 "or use `c5d task next` / `c5d task check` with any agent")
    ctx = task_context()
    rows = pick_tasks(ctx, args.n, args.tries, args.min_size)
    prefetch_dumps([int(r["entry"], 16) for r in rows])
    summary = []
    for r in rows:
        a = int(r["entry"], 16)
        diff = None
        for t in range(args.tries):
            path, _src = tasks.write_bundle(ctx, r, ctx.by_addr, ctx.names, ctx.symbols_by_addr,
                                            ctx.imports, last_diff=diff)
            t0 = time.time()
            try:
                p = subprocess.run(agent_cmd, input=path.read_text(encoding="utf-8"), text=True,
                                   capture_output=True, cwd=ROOT, timeout=args.timeout)
                (path.parent / f"agent_{t}.log").write_text(p.stdout + p.stderr, encoding="utf-8")
            except subprocess.TimeoutExpired:
                pass
            status, diff = tasks.check(ctx, a)
            tasks.log_attempt(BUILD, {"addr": r["entry"], "try": t, "status": status,
                                      "agent": agent_cmd[0], "seconds": round(time.time() - t0),
                                      "size": int(r["size"]), "time": time.time()})
            print(f"{r['entry']} try {t + 1}: {status}", flush=True)
            if status == "MATCH":
                break
        summary.append((r["entry"], status))
    ok = sum(1 for _a, s in summary if s == "MATCH")
    print(f"\nagent run: {ok}/{len(summary)} matched")
    return 0


def cmd_status(_args):
    """Write PROGRESS.md from scope, status and attempts."""
    import csv
    import tasks
    from collections import Counter
    scope_rows = list(csv.DictReader(open(BUILD / "scope.csv", newline="")))
    game = {int(r["entry"], 16): int(r["size"]) for r in scope_rows if r["category"] == "game"}
    status = load_status()
    matched = {a for a, s in status.items() if s == "MATCH" and a in game}
    mb, tb = sum(game[a] for a in matched), sum(game.values())
    att = [x for v in tasks.attempts_by_addr(BUILD).values() for x in v]
    by_status = Counter(s for a, s in status.items() if a in game)
    lines = [
        "# Progress", "",
        "Generated by `python tools/c5d.py status`. Do not edit by hand.", "",
        f"- **Matched:** {len(matched):,} / {len(game):,} in-scope functions "
        f"({100 * len(matched) / len(game):.2f}%)",
        f"- **Bytes:** {mb:,} / {tb:,} ({100 * mb / tb:.3f}%)",
        f"- **Attempted, not matched:** {by_status.get('DIFF', 0) + by_status.get('MATCH?', 0)}",
    ]
    if att:
        ok = sum(1 for x in att if x["status"] == "MATCH")
        lines.append(f"- **Agent attempts logged locally:** {len(att)}, {ok} matched "
                     f"({100 * ok / len(att):.0f}%)")
    lines += ["", "Scope: see `python tools/c5d.py scope` (library, linker and compiler "
              "generated code are excluded).", ""]
    (ROOT / "PROGRESS.md").write_text("\n".join(lines), encoding="utf-8")
    print("\n".join(lines))
    return 0


def cmd_scope(_args):
    import scope
    scope.run(LinkCtx(), ROOT, BUILD, GAME_EXE)
    return 0


class LinkCtx:
    """Tool paths and flags for the LTCG build."""

    def __init__(self, extra_flags=()):
        vc = Path(CFG["msvc_bin"]).parent
        self.cl = MSVC_CL
        self.lib = vc / "bin" / "lib.exe"
        self.link = vc / "bin" / "link.exe"
        self.ml = vc / "bin" / "ml.exe"
        self.cflags = [f for f in CFG["cflags"] if f != "/c"] + ["/c", *extra_flags]
        self.env = msvc_env()
        self.libpaths = [vc / "lib", vc.parent / "WinSDK" / "Lib"]
        self.build = BUILD


def main():
    p = argparse.ArgumentParser(prog="c5d")
    sub = p.add_subparsers(dest="cmd", required=True)
    sub.add_parser("env", help="check the toolchain").set_defaults(fn=cmd_env)
    a = sub.add_parser("analyze", help="Ghidra headless analysis + function export")
    a.add_argument("--reimport", action="store_true",
                   help="re-import and re-analyze even if the project exists")
    a.set_defaults(fn=cmd_analyze)
    d = sub.add_parser("dump", help="dump disassembly + decompile for addresses to build/dump")
    d.add_argument("addrs", nargs="+", help="function entry addresses, e.g. 0x00813940")
    d.set_defaults(fn=cmd_dump)
    m = sub.add_parser("match", help="compile sources and compare against the original exe")
    m.add_argument("sources", nargs="*", help=".cpp files (default: all of src/)")
    m.add_argument("--only", action="append", help="only functions whose name contains this")
    m.add_argument("--addr", action="append", type=lambda s: int(s, 16),
                   help="only the function at this address (repeatable)")
    m.add_argument("--flag", action="append", help="extra cl.exe flag for this run (repeatable)")
    m.add_argument("-v", "--verbose", action="store_true", help="always show disassembly and relocations")
    m.add_argument("--obj", action="store_true",
                   help="fast per-file mode (no /GL + /LTCG link); fine for simple leaf functions")
    m.set_defaults(fn=cmd_match)
    sub.add_parser("scope", help="classify functions: game (in scope) vs library/generated"
                   ).set_defaults(fn=cmd_scope)
    q = sub.add_parser("queue", help="build the leaves-first work queue (build/queue.csv)")
    q.add_argument("--top", type=int, default=20)
    q.set_defaults(fn=cmd_queue)
    t = sub.add_parser("task", help="task bundles: `next` writes them, `check <addr>` verifies one")
    t.add_argument("action", choices=["next", "check"])
    t.add_argument("addr", nargs="?")
    t.add_argument("--n", type=int, default=5)
    t.add_argument("--tries", type=int, default=3)
    t.add_argument("--min-size", type=int, default=5)
    t.add_argument("-v", "--verbose", action="store_true")
    t.set_defaults(fn=cmd_task)
    ag = sub.add_parser("agent", help="run config.json agent_cmd over the next N tasks")
    ag.add_argument("--n", type=int, default=5)
    ag.add_argument("--tries", type=int, default=3)
    ag.add_argument("--min-size", type=int, default=5)
    ag.add_argument("--timeout", type=int, default=1800)
    ag.set_defaults(fn=cmd_agent)
    sub.add_parser("status", help="write PROGRESS.md").set_defaults(fn=cmd_status)
    args = p.parse_args()
    sys.exit(args.fn(args))


if __name__ == "__main__":
    os.chdir(ROOT)
    main()
