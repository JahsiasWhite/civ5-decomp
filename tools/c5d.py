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

import config

ROOT = config.ROOT
CFG = config.load()        # config.json overlaid with config.local.json (see tools/config.py)

GAME_EXE = Path(CFG.get("game_dir") or "<run c5d setup>") / CFG["target_exe"]
GHIDRA = Path(CFG.get("ghidra_dir") or "<run c5d setup>")
HEADLESS = GHIDRA / "support" / "analyzeHeadless.bat"
MSVC_CL = Path(CFG.get("msvc_bin") or "<run c5d setup>") / "cl.exe"
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


def run_headless(cmd, **kwargs):
    """Run Ghidra's analyzeHeadless.bat. Python's default way of starting a .bat
    mangles the quoting of any argument with parentheses, and the script's argument
    loop then fails on it ("\Steam\steamapps\common\Sid was unexpected at this
    time" for a game under C:\Program Files (x86)). So build cmd's command line
    here: /s strips only the outer quotes, and every argument stays quoted."""
    if os.name != "nt":
        return subprocess.run(cmd, **kwargs)
    for a in cmd:
        if '"' in a or "%" in a or "!" in a:
            sys.exit(f"can't pass this path to Ghidra's launcher (it contains \", % or !): {a}")
    line = '"' + " ".join(f'"{a}"' for a in cmd) + '"'
    return subprocess.run(f'{os.environ.get("COMSPEC", "cmd.exe")} /d /s /c {line}', **kwargs)


def cmd_analyze(args):
    if not HEADLESS.is_file():
        sys.exit(f"Ghidra not found: {HEADLESS}")
    PROJ_DIR.mkdir(exist_ok=True)
    BUILD.mkdir(exist_ok=True)
    # Ghidra's own export. Everyone works from the committed data/functions.csv so
    # addresses agree across Ghidra versions; maintainers refresh it from this file.
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
    return run_headless(cmd).returncode


def cmd_dump(args):
    if not (PROJ_DIR / f"{PROJ_NAME}.gpr").exists():
        sys.exit("No Ghidra project yet; run `analyze` first.")
    out = BUILD / "dump"
    cmd = [str(HEADLESS), str(PROJ_DIR), PROJ_NAME,
           "-process", CFG["target_exe"], "-noanalysis", "-readOnly",
           "-scriptPath", str(ROOT / "tools" / "ghidra"),
           "-postScript", "DumpFunctions.py", str(out), *args.addrs]
    r = run_headless(cmd, capture_output=True, text=True)
    for line in r.stdout.splitlines():
        if "DumpFunctions:" in line:
            print(line.split("DumpFunctions:", 1)[1].strip())
    return r.returncode


# ---------------------------------------------------------------- match

def load_symbols():
    """symbols.txt + symbols/**/*.txt -> {name: address}.

    Workers each write their own symbols/auto/f_<addr>.txt so parallel tasks
    never edit the same file."""
    syms = {}
    files = [ROOT / "symbols.txt"] + sorted((ROOT / "symbols").rglob("*.txt"))
    for f in files:
        if not f.exists():
            continue
        for line in f.read_text().splitlines():
            line = line.split("#", 1)[0].strip()
            if line:
                addr, name = line.split(None, 1)
                syms[name.strip()] = int(addr, 16)
    return syms


# ---------------------------------------------------------------- workers

WORKER = None            # set by --worker; isolates build output per worker
CLAIMS = BUILD / "claims"


def work_dir():
    return BUILD / "work" / WORKER if WORKER else BUILD


def claims():
    """{address: worker} for functions currently being worked on."""
    out = {}
    if CLAIMS.exists():
        for f in CLAIMS.glob("*.txt"):
            out[int(f.stem, 16)] = f.read_text().strip()
    return out


def claim(addr, worker):
    CLAIMS.mkdir(parents=True, exist_ok=True)
    (CLAIMS / f"{addr:08x}.txt").write_text(worker)


def release(addr):
    p = CLAIMS / f"{addr:08x}.txt"
    if p.exists():
        p.unlink()


def default_sources():
    """All of src/, minus agent files other workers are still editing (a
    half-written file must not break everyone else's LTCG link)."""
    held = claims()
    out = []
    for p in sorted((ROOT / "src").rglob("*.cpp")):
        if p.parent.name == "auto" and p.stem.startswith("f_"):
            try:
                owner = held.get(int(p.stem[2:], 16))
            except ValueError:
                owner = None
            if owner and owner != WORKER:
                continue
        out.append(p)
    return out


def winsdk_dir():
    """Windows SDK headers/libs: next to the compiler in the Visual C++ for Python
    layout, or wherever `c5d setup` found one (config.local.json "winsdk_dir")."""
    if CFG.get("winsdk_dir"):
        return Path(CFG["winsdk_dir"])
    return Path(CFG["msvc_bin"]).parent.parent / "WinSDK"


def msvc_env():
    vc = Path(CFG["msvc_bin"]).parent            # .../VC
    env = dict(os.environ)
    env["PATH"] = str(vc / "bin") + os.pathsep + env.get("PATH", "")
    env["INCLUDE"] = ";".join(config.winpath(p) for p in
                              [ROOT / "include", vc / "include", winsdk_dir() / "Include"])
    return config.tool_env(env)


def flags_for(src, base):
    """Apply per-file overrides: a line `// c5d-cflags: -/arch:SSE2 +/Od` in the
    first 40 lines removes (-) or adds (+) flags. The exe was built with
    different settings per source file (e.g. some without /arch:SSE2)."""
    flags = list(base)
    try:
        head = Path(src).read_text(errors="replace").splitlines()[:40]
    except OSError:
        return flags
    for line in head:
        if "c5d-cflags:" in line:
            for tok in line.split("c5d-cflags:", 1)[1].split():
                if tok.startswith("-") and tok[1:] in flags:
                    flags.remove(tok[1:])
                elif tok.startswith("+"):
                    flags.append(tok[1:])
    return flags


def compile_cpp(src, extra_flags=()):
    """Compile one .cpp to build/obj/<name>.obj; return the obj path."""
    out_dir = work_dir() / "obj"
    out_dir.mkdir(parents=True, exist_ok=True)
    obj = out_dir / (src.stem + ".obj")
    cmd = [*config.tool_cmd(MSVC_CL), *flags_for(src, CFG["cflags"]), *extra_flags,
           f"/Fo{config.winpath(obj)}", config.winpath(src)]
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
    for row in config.load_functions():
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


def compile_all(sources, flags):
    """Compile each file normally once: gives the list of functions it defines
    (and is the whole comparison in --obj mode)."""
    from binfmt import CoffObject
    return [(src, CoffObject(compile_cpp(src, flags))) for src in sources]


def ltcg_link(image, syms, sources, per_file, flags):
    """/GL + /LTCG link of `sources` into a throwaway DLL. Returns (test_img, lmap)."""
    import ltcg
    from binfmt import PEImage
    exports = image.exports()
    defined = {s.name for _src, o in per_file for s, *_ in o.functions()}
    keep = sorted(n for n in defined
                  if n in exports or (n.startswith("_") and n[1:] in exports))
    ctx = LinkCtx(flags)
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
    return PEImage(dll), lmap


def obj_refs_of(sec, start, end):
    """{function offset: (symbol, addend)} from a plain compile, for naming references."""
    return {r.offset - start: (r.symbol.name, int.from_bytes(
                sec.data[r.offset:r.offset + 4], "little", signed=True))
            for r in sec.relocs if start <= r.offset < end}


def fingerprint_mode(args):
    """Fingerprint mode: on request, or automatically when there's no game exe
    (CI). See tools/fingerprint.py."""
    return getattr(args, "fingerprints", False) or not GAME_EXE.is_file()


def cmd_match(args):
    from binfmt import PEImage
    load_func_sizes()
    syms = load_symbols()
    fp_mode = fingerprint_mode(args)
    if fp_mode:
        if args.obj:
            sys.exit("--obj needs the game exe; fingerprint mode only runs the LTCG link")
        from fingerprint import FingerprintImage
        image = FingerprintImage()
        if image.build_hash != CFG["target_build_hash"]:
            sys.exit("data/fingerprints.csv was made from a different exe than config.json targets")
        print("fingerprint mode (no game exe): checking against data/fingerprints.csv")
    else:
        image = PEImage(GAME_EXE)
    sources = [Path(s) for s in args.sources] or default_sources()
    totals = {"MATCH": 0, "MATCH?": 0, "DIFF": 0, "ERROR": 0, "UNVERIFIED": 0}
    results = {}

    per_file = compile_all(sources, args.flag or ())
    test_img = lmap = None
    if not args.obj:
        import ltcg
        test_img, lmap = ltcg_link(image, syms, sources, per_file, args.flag or ())

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
            elif fp_mode:
                res = ltcg.compare_fp(sym.name, image, va, test_img, lmap, syms,
                                      obj_refs_of(sec, start, end))
            else:
                size = FUNC_SIZES.get(va, end - start)
                res = ltcg.compare(sym.name, image, va, size, test_img, lmap, syms,
                                   obj_refs_of(sec, start, end))
            totals[res["status"]] += 1
            nbytes = len(res["ours"]) if "ours" in res else end - start
            results[va] = (sym.name, res["status"], FUNC_SIZES.get(va, nbytes),
                           str(src.resolve().relative_to(ROOT)) if src.resolve().is_relative_to(ROOT) else str(src))
            print(f"  {res['status']:<6} {sym.name}  @0x{va:08x}  {nbytes} bytes")
            if res["status"] == "ERROR":
                print(f"         {res['detail']}")
                continue
            if res.get("detail"):
                print(f"         {res['detail']}")
            for state, off, name, note in res["relocs"]:
                if state != "ok" or args.verbose:
                    print(f"         ref +0x{off:03x} {name}: {note}")
            if res["size_note"]:
                print(f"         {res['size_note']}")
            if (res["status"] == "DIFF" or args.verbose) and not fp_mode:
                print_diff(res)
    if not args.obj and not args.only and not args.addr:
        record_status(results)
    print(f"\n[{'obj' if args.obj else 'ltcg'}{' fingerprint' if fp_mode else ''} mode]  "
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
    for r in config.load_functions():
        if not r["name"].startswith("FUN_"):
            names[int(r["entry"], 16)] = r["name"]
    for f in sorted((ROOT / "names").glob("*.csv")):
        with open(f, newline="") as fh:
            for r in csv.DictReader(fh):
                names.setdefault(int(r["address"], 16), r["name"])
    for sym, va in load_symbols().items():
        names[va] = sym
    return names


def cmd_fingerprint(_args):
    """Write data/fingerprints.csv + .json from the game exe (see tools/fingerprint.py)."""
    import fingerprint
    from binfmt import PEImage
    n = fingerprint.export(PEImage(GAME_EXE), config.load_functions(), CFG["target_build_hash"])
    print(f"wrote {n} fingerprints to {fingerprint.CSV_PATH.relative_to(ROOT)} "
          f"(+ {fingerprint.META_PATH.relative_to(ROOT)})")
    return 0


def cmd_queue(args):
    import workqueue
    from binfmt import PEImage
    if not (BUILD / "scope.csv").exists():
        sys.exit("run `c5d scope` first")
    rows = workqueue.build(PEImage(GAME_EXE), BUILD / "scope.csv", load_status(), load_names(),
                           BUILD / "queue.csv", callgraph_csv=ROOT / "data" / "callgraph.csv")
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
    import classes
    image = PEImage(GAME_EXE)
    symbols_by_addr = {va: n for n, va in load_symbols().items()}
    return types.SimpleNamespace(
        root=ROOT, build=BUILD, image=image, rows=rows,
        by_addr={int(r["entry"], 16): r for r in rows},
        names=load_names(), imports=image.imports(),
        symbols_by_addr=symbols_by_addr,
        classes=classes.ClassIndex(image, config.load_functions(), symbols_by_addr))


def cmd_classes(args):
    """Classes found from vtables (tools/classes.py): the ones with the most unmatched
    members, or one class in full."""
    import classes
    ctx = task_context()
    if args.addr:
        c = ctx.classes.lookup(int(args.addr, 16))
        if c is None:
            sys.exit(f"{args.addr}: not a vtable or a member of a known class")
        print("\n".join(classes.describe(ctx.classes, c, ctx.by_addr)))
    else:
        print("\n".join(classes.report(ctx.classes, ctx.by_addr, args.top)))
    return 0


def pick_tasks(ctx, n, tries, min_size=5, max_size=None):
    import tasks
    tried = tasks.attempts_by_addr(BUILD)
    status = load_status()
    held = claims()
    out = []
    for r in ctx.rows:
        a = int(r["entry"], 16)
        if status.get(a) == "MATCH" or int(r["pending_callees"]) or int(r["size"]) < min_size:
            continue
        if (max_size and int(r["size"]) > max_size) or a in held:
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
        jobs = pick_and_claim(ctx, args.n, args.tries, args.min_size, args.max_size,
                              lambda i: f"{args.worker_prefix}{i + 1}" if args.worker_prefix
                              else (WORKER or "w1"), args.local)
        prefetch_dumps([int(r["entry"], 16) for r, _w in jobs])
        for r, worker in jobs:
            path, src = tasks.write_bundle(ctx, r, ctx.by_addr, ctx.names, ctx.symbols_by_addr,
                                           ctx.imports, worker=worker)
            print(f"{r['entry']}  {r['size']:>5}b  {r['conv']:<8} {worker:<5} -> {path.relative_to(ROOT)}")
    elif args.action == "check":
        a = int(args.addr, 16)
        status, out = tasks.check(ctx, a, claims().get(a))
        tasks.log_attempt(BUILD, {"addr": f"0x{a:08x}", "status": status, "agent": "manual",
                                  "time": __import__("time").time()})
        print(out if args.verbose else status)
    else:                                   # release
        import remote
        a = int(args.addr, 16)
        remote.ServerClaims.from_config(args.local).release(a)
        release(a)
    return 0


def pick_and_claim(ctx, n, tries, min_size, max_size, worker_for, local_only=False):
    """Pick up to `n` tasks from the local queue and claim each one locally and, when logged
    in, on the server. Functions the server says someone else holds (or that are matched
    there) are skipped for the next candidate. -> [(queue row, worker)]"""
    import remote
    server = remote.ServerClaims.from_config(local_only)
    out = []
    for r in pick_tasks(ctx, n * 4 + 10, tries, min_size, max_size):
        a = int(r["entry"], 16)
        worker = worker_for(len(out))
        if not server.claim(a, worker):
            continue
        claim(a, worker)
        out.append((r, worker))
        if len(out) >= n:
            break
    return out


def cmd_agent(args):
    """Run agent_cmd on N tasks with retries. With --remote, the tasks are claimed from the
    server and each result is reported back, with the token usage the agent printed."""
    import agentusage
    import tasks
    import time
    agent_cmd = CFG.get("agent_cmd")
    if not agent_cmd:
        sys.exit('set "agent_cmd" in config.local.json (a command that reads the task prompt on stdin), '
                 "or use `c5d task next` / `c5d task check` with any agent")
    ctx = task_context()
    if args.remote:
        import remote
        r = remote.Remote()
        body = {"n": args.n, "worker_prefix": "w", "min_size": args.min_size}
        if args.max_size:
            body["max_size"] = args.max_size
        jobs = [(row, worker) for row, worker, _path in remote_claim(r, body, ctx)]
    else:
        jobs = pick_and_claim(ctx, args.n, args.tries, args.min_size, args.max_size,
                              lambda _i: WORKER or "w1", args.local)
        prefetch_dumps([int(row["entry"], 16) for row, _w in jobs])
    summary = []
    for row, worker in jobs:
        a = int(row["entry"], 16)
        diff = None
        status = "ERROR"
        for t in range(args.tries):
            path, _src = tasks.write_bundle(ctx, row, ctx.by_addr, ctx.names, ctx.symbols_by_addr,
                                            ctx.imports, last_diff=diff, worker=worker)
            t0 = time.time()
            out = ""
            try:
                p = subprocess.run(agent_cmd, input=path.read_text(encoding="utf-8"), text=True,
                                   encoding="utf-8", errors="replace",
                                   capture_output=True, cwd=ROOT, timeout=args.timeout)
                out = p.stdout or ""
                (path.parent / f"agent_{t}.log").write_text(out + (p.stderr or ""), encoding="utf-8")
            except subprocess.TimeoutExpired as e:
                out = e.stdout.decode("utf-8", "replace") if isinstance(e.stdout, bytes) else (e.stdout or "")
            usage = agentusage.parse(out)
            agentusage.add(BUILD, a, usage)
            status, diff = tasks.check(ctx, a, worker)
            rec = {"addr": row["entry"], "try": t, "status": status, "agent": agent_cmd[0],
                   "seconds": round(time.time() - t0), "size": int(row["size"]), "time": time.time()}
            if usage:
                rec.update(usage)
            tasks.log_attempt(BUILD, rec)
            tok = (f"  ({usage['tokens_in'] + usage['tokens_cached']:,} in, {usage['tokens_out']:,} out)"
                   if usage else "  (no token usage in the agent's output)")
            print(f"{row['entry']} try {t + 1}: {status}{tok}", flush=True)
            if status == "MATCH":
                break
        if args.remote:
            if status in ("MATCH", "DIFF"):
                remote_report(r, a)
            else:
                r.call("POST", "/api/release", {"addr": f"0x{a:08x}"})
                release(a)
                print(f"{row['entry']}: {status}, released back to the pool")
        summary.append((row["entry"], status))
    ok = sum(1 for _a, s in summary if s == "MATCH")
    print(f"\nagent run: {ok}/{len(summary)} matched")
    return 0


def remote_claim(r, body, ctx=None):
    """Claim from the server, mirror the claims locally and write a bundle for each.
    -> [(queue row, worker, bundle path)]."""
    import tasks
    got = r.call("POST", "/api/claim", body)["claims"]
    if not got:
        print("nothing available to claim with those filters")
        return []
    ctx = ctx or task_context()
    prefetch_dumps([int(c["addr"], 16) for c in got])
    out = []
    for c in got:
        a = int(c["addr"], 16)
        claim(a, c["worker"])                       # local claim mirrors the server's
        row = ctx.by_addr.get(a)
        if not row:
            print(f"{c['addr']}: not in your local queue (re-run `c5d queue`?)")
            continue
        path, _src = tasks.write_bundle(ctx, row, ctx.by_addr, ctx.names, ctx.symbols_by_addr,
                                        ctx.imports, worker=c["worker"])
        print(f"{c['addr']}  {row['size']:>5}b  {row['conv']:<8} {c['worker']:<5} -> {path.relative_to(ROOT)}")
        out.append((row, c["worker"], path))
    return out


def remote_report(r, a, model=None, tokens_in=None, tokens_out=None, tokens_cached=None, tries=None):
    """Re-check locally, then report. Values not given come from the task's usage.json
    (written by `c5d agent`), then config.local.json's "model"."""
    import agentusage
    import remote
    import tasks
    ctx = task_context()
    status, out = tasks.check(ctx, a, claims().get(a))
    tasks.log_attempt(BUILD, {"addr": f"0x{a:08x}", "status": status, "agent": "remote",
                              "time": __import__("time").time()})
    if status not in ("MATCH", "DIFF"):
        print(out)
        sys.exit(f"local check gave {status}; not reporting (fix the build first)")
    used = agentusage.load(BUILD, a)

    def pick(given, key):
        return used[key] if given is None else given
    model = model or used["model"] or remote.load_local().get("model", "")
    body = {"addr": f"0x{a:08x}", "status": status, "model": model,
            "tokens_in": pick(tokens_in, "tokens_in"), "tokens_out": pick(tokens_out, "tokens_out"),
            "tokens_cached": pick(tokens_cached, "tokens_cached"), "tries": pick(tries, "tries")}
    r.call("POST", "/api/report", body)
    release(a)
    agentusage.reset(BUILD, a)                  # counted once; a later re-claim starts from zero
    tok = body["tokens_in"] + body["tokens_cached"] + body["tokens_out"]
    print(f"0x{a:08x}: reported {status} ({model or 'no model'}, {tok:,} tokens, {body['tries']} tries)"
          + ("; it counts once the nightly verify confirms it" if status == "MATCH" else ""))
    return status


def review_files():
    """Source files marked `// c5d-review: <reason>` in their first 40 lines:
    {path: reason}. A marker means the bytes match but the source uses a trick
    the original surely didn't (a fake match) and should be revisited."""
    out = {}
    for src in sorted((ROOT / "src").rglob("*.cpp")):
        with open(src, encoding="utf-8", errors="replace") as f:
            for _, line in zip(range(40), f):
                if "c5d-review:" in line:
                    out[src.relative_to(ROOT).as_posix()] = line.split("c5d-review:", 1)[1].strip()
                    break
    return out


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
    review = review_files()
    if review:
        lines.append(f"- **Flagged for review (fake matches):** {len(review)} "
                     "(`// c5d-review:` in the source; see README)")
    if att:
        ok = sum(1 for x in att if x["status"] == "MATCH")
        lines.append(f"- **Agent attempts logged locally:** {len(att)}, {ok} matched "
                     f"({100 * ok / len(att):.0f}%)")
    lines += ["", "Scope: see `python tools/c5d.py scope` (library, linker and compiler "
              "generated code are excluded).", ""]
    (ROOT / "PROGRESS.md").write_text("\n".join(lines), encoding="utf-8")
    print("\n".join(lines))
    return 0


def cmd_remote(args):
    """Talk to the coordination server: login, claim, report, release, status."""
    import tasks
    import remote
    if args.action == "login":
        if not (args.server and args.token):
            sys.exit("usage: c5d remote login --server URL --token TOKEN")
        r = remote.Remote(args.server, args.token)
        me = r.call("GET", "/api/me")
        loc = remote.load_local()
        loc.update({"server": r.server, "token": r.token})
        remote.save_local(loc)
        print(f"logged in to {r.server} as {me['login']} (saved to config.local.json)")
        return 0
    r = remote.Remote()
    if args.action == "status":
        me = r.call("GET", "/api/me")
        print(f"{me['login']}  terms accepted: {me['accepted_terms']}  claims: {len(me['claims'])}")
        for c in me["claims"]:
            print(f"  0x{c['addr']:08x}  {c['worker']:<6} {c['size']:>6}b  {c['name']}")
        return 0
    if args.action == "claim":
        body = {"n": args.n, "worker_prefix": args.worker_prefix, "min_size": args.min_size}
        if args.max_size:
            body["max_size"] = args.max_size
        if args.addr:
            body["addr"] = args.addr
        remote_claim(r, body)
        return 0
    if args.action == "report":
        remote_report(r, int(args.addr, 16), args.model, args.tokens_in, args.tokens_out,
                      args.tokens_cached, args.tries)
        return 0
    if args.action == "release":
        a = int(args.addr, 16)
        r.call("POST", "/api/release", {"addr": f"0x{a:08x}"})
        release(a)
        print(f"0x{a:08x}: released")
        return 0


def cmd_scope(_args):
    import scope
    scope.run(LinkCtx(), ROOT, BUILD, GAME_EXE)
    return 0


def cmd_boundaries(args):
    """Find functions Ghidra split in two, or misread so that entries sit inside another
    function; --write adds them to boundary_overrides.txt."""
    import boundaries
    from binfmt import PEImage
    rows = config.load_functions()          # already-fixed ones aren't reported again
    img, protected = PEImage(GAME_EXE), set(load_symbols().values())
    found = [(e, x, ab, True, "tail " + ", ".join(f"0x{a:08x}" for a in ab)
              + " reached only by jumps from inside")
             for e, x, ab in boundaries.find_splits(img, rows, protected=protected)]
    done = {a for f in found for a in f[2]}
    for e, x, ab, listed in boundaries.find_misplaced(img, rows, protected=protected):
        ab = [a for a in ab if a not in done]
        if ab:
            found.append((e, x, ab, listed, ("" if listed else "start not listed; ")
                          + "entries inside it: " + ", ".join(f"0x{a:08x}" for a in ab)))
    done |= {a for f in found for a in f[2]} | {f[0] for f in found}
    for e, x, ab, imp in boundaries.find_truncated(img, rows, protected=protected):
        if e not in done and not done & set(ab):
            found.append((e, x, ab, True, f"cut short at a call to {imp}, which returns"
                          + ("; absorbs " + ", ".join(f"0x{a:08x}" for a in ab) if ab else "")))
    for entry, end, absorbed, listed, why in found:
        print(f"  0x{entry:08x} 0x{end:08x}{'' if listed else ' new'}  {why}")
    print(f"{len(found)} function(s) with wrong boundaries found")
    if args.write and found:
        path = config.BOUNDARY_OVERRIDES
        text = path.read_text(encoding="utf-8") if path.exists() else ""
        lines = [f"0x{e:08x} 0x{x:08x}{'' if listed else ' new'}  # auto (c5d boundaries): {why}\n"
                 for e, x, ab, listed, why in found]
        sep = "\n" if text and not text.endswith("\n") else ""
        path.write_text(text + sep + "".join(lines), encoding="utf-8")
        print(f"appended {len(found)} line(s) to {path.name}; now run `c5d scope`, `c5d queue` "
              "and `c5d fingerprint`")
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
        self.libpaths = [vc / "lib", winsdk_dir() / "Lib"]
        self.build = work_dir()
        self.tool = config.tool_cmd          # [exe] on Windows, [wine, Z:\\...] elsewhere
        self.wp = config.winpath

    def flags_for(self, src):
        return flags_for(src, self.cflags)


def cmd_build(args):
    """Hybrid exe: our code relocated into a copy of the game exe (tools/hybrid.py)."""
    import csv
    import hybrid
    import ltcg
    from binfmt import PEImage
    state = BUILD / "hybrid"
    if args.clean:
        return hybrid.clean_game(CFG["game_dir"], CFG["target_exe"], state)
    load_func_sizes()
    syms = load_symbols()
    image = PEImage(GAME_EXE)
    sources = default_sources()
    per_file = compile_all(sources, ())
    test_img, lmap = ltcg_link(image, syms, sources, per_file, ())
    convs = {}
    if (BUILD / "queue.csv").exists():
        with open(BUILD / "queue.csv", newline="") as fh:
            convs = {int(r["entry"], 16): r["conv"] for r in csv.DictReader(fh)}
    items = []
    for src, obj in per_file:
        for sym, sec, start, end in obj.functions():
            if sym.name not in syms:
                continue
            va = syms[sym.name]
            size = FUNC_SIZES.get(va, end - start)
            refs = obj_refs_of(sec, start, end)
            res = ltcg.compare(sym.name, image, va, size, test_img, lmap, syms, refs)
            items.append(hybrid.Item(sym.name, va, size, res, refs, convs.get(va, ""), str(src)))
    r = hybrid.build(GAME_EXE, image, test_img, lmap, syms, items, state / CFG["target_exe"],
                     diff=args.diff, force=args.force)
    text = hybrid.report(r, ROOT)
    (state / "report.txt").write_text(text + "\n", encoding="utf-8")
    print(text)
    if r["errors"] or (not r["patched"] and not r["identical"]):
        return 1
    if args.run:
        hybrid.run_in_game(r["out"], CFG["game_dir"], state)
    return 0


def cmd_setup(args):
    import setup_env
    return setup_env.run(args)


# commands that need the game exe and the toolchain from `c5d setup`
NEEDS_SETUP = {"env", "analyze", "dump", "match", "scope", "queue", "task", "agent", "build",
               "fingerprint", "classes"}


def require_setup(cmd, args=None):
    if cmd not in NEEDS_SETUP:
        return
    if cmd == "match" and fingerprint_mode(args):
        if not CFG.get("msvc_bin"):
            sys.exit("msvc_bin not set: run `python tools/c5d.py setup` (or set it in config.local.json)")
        return                              # fingerprint mode needs only the compiler
    missing = config.missing_machine_keys(CFG)
    if missing:
        sys.exit(f"not set up yet ({', '.join(missing)} missing): run `python tools/c5d.py setup`")
    if cmd != "env":
        import setup_env
        if not setup_env.exe_is_target(GAME_EXE, CFG["target_build_hash"]):
            sys.exit(f"{GAME_EXE} is missing or is not the build this project targets "
                     f"({CFG.get('target_build', '')}); run `python tools/c5d.py setup`")


def main():
    p = argparse.ArgumentParser(prog="c5d")
    p.add_argument("--worker", default=None,
                   help="worker id: isolated build dir (build/work/<id>) so workers can run in parallel")
    sub = p.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("setup", help="find and check the game, Ghidra and VC++ 2008; write config.local.json")
    s.add_argument("--game", help="folder containing CivilizationV_DX11.exe (default: search Steam libraries)")
    s.add_argument("--ghidra", help="Ghidra install folder (default: search common places)")
    s.add_argument("--msvc", help="folder containing the VC++ 2008 cl.exe (default: search common places)")
    s.add_argument("--no-install", action="store_true", help="don't pip-install missing Python packages")
    s.add_argument("--sdk-headers", action="store_true", help="also fetch the Civ V SDK headers (git)")
    s.add_argument("--skip-test", action="store_true", help="skip the test match at the end")
    s.set_defaults(fn=cmd_setup)
    b = sub.add_parser("build", help="hybrid exe: rebuild matched functions from source into a copy "
                       "of the game exe and verify it (see README)")
    b.add_argument("--diff", action="store_true",
                   help="also patch in non-matching functions whose references all check out (experimental)")
    b.add_argument("--force", action="store_true",
                   help="with --diff: allow custom LTCG calling conventions too (may crash)")
    b.add_argument("--run", action="store_true", help="copy the hybrid exe into the game folder and start it")
    b.add_argument("--clean", action="store_true", help="remove what --run put in the game folder")
    b.set_defaults(fn=cmd_build)
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
    m.add_argument("--fingerprints", action="store_true",
                   help="check against data/fingerprints.csv instead of the exe "
                        "(automatic when the exe isn't there, e.g. in CI)")
    m.set_defaults(fn=cmd_match)
    sub.add_parser("fingerprint", help="write data/fingerprints.csv from the exe (maintainers)"
                   ).set_defaults(fn=cmd_fingerprint)
    sub.add_parser("scope", help="classify functions: game (in scope) vs library/generated"
                   ).set_defaults(fn=cmd_scope)
    bd = sub.add_parser("boundaries", help="find functions Ghidra split in two or misread "
                        "(see boundary_overrides.txt)")
    bd.add_argument("--write", action="store_true", help="append what's found to boundary_overrides.txt")
    bd.set_defaults(fn=cmd_boundaries)
    q = sub.add_parser("queue", help="build the leaves-first work queue (build/queue.csv)")
    q.add_argument("--top", type=int, default=20)
    q.set_defaults(fn=cmd_queue)
    cl = sub.add_parser("classes", help="classes found from vtables: most unmatched members first, "
                        "or `classes 0x<addr>` for one class")
    cl.add_argument("addr", nargs="?", help="a vtable or member function address")
    cl.add_argument("--top", type=int, default=30)
    cl.set_defaults(fn=cmd_classes)
    t = sub.add_parser("task", help="task bundles: `next` writes them, `check <addr>` verifies one")
    t.add_argument("action", choices=["next", "check", "release"])
    t.add_argument("addr", nargs="?")
    t.add_argument("--n", type=int, default=5)
    t.add_argument("--tries", type=int, default=3)
    t.add_argument("--min-size", type=int, default=5)
    t.add_argument("--max-size", type=int, default=None)
    t.add_argument("--worker-prefix", default=None,
                   help="claim each task for its own worker id (<prefix>1, <prefix>2, ...)")
    t.add_argument("--local", action="store_true",
                   help="don't claim/release on the server even when logged in")
    t.add_argument("-v", "--verbose", action="store_true")
    t.set_defaults(fn=cmd_task)
    ag = sub.add_parser("agent", help="run agent_cmd (config.local.json) over the next N tasks")
    ag.add_argument("--n", type=int, default=5)
    ag.add_argument("--tries", type=int, default=3)
    ag.add_argument("--min-size", type=int, default=5)
    ag.add_argument("--max-size", type=int, default=None)
    ag.add_argument("--timeout", type=int, default=1800)
    ag.add_argument("--remote", action="store_true",
                    help="claim from the server and report each result (with token usage)")
    ag.add_argument("--local", action="store_true",
                    help="without --remote: don't mirror claims on the server even when logged in")
    ag.set_defaults(fn=cmd_agent)
    sub.add_parser("status", help="write PROGRESS.md").set_defaults(fn=cmd_status)
    rm = sub.add_parser("remote", help="coordination server: login | status | claim | report | release")
    rm.add_argument("action", choices=["login", "status", "claim", "report", "release"])
    rm.add_argument("addr", nargs="?")
    rm.add_argument("--server")
    rm.add_argument("--token")
    rm.add_argument("--n", type=int, default=1)
    rm.add_argument("--worker-prefix", default="w")
    rm.add_argument("--min-size", type=int, default=0)
    rm.add_argument("--max-size", type=int, default=None)
    rm.add_argument("--model", default=None,
                    help="model/tool that wrote it (default: \"model\" in config.local.json)")
    rm.add_argument("--tokens-in", type=int, default=None,
                    help="default: what `c5d agent` recorded for this task (build/tasks/<addr>/usage.json)")
    rm.add_argument("--tokens-out", type=int, default=None)
    rm.add_argument("--tokens-cached", type=int, default=None)
    rm.add_argument("--tries", type=int, default=None, help="matcher iterations used")
    rm.set_defaults(fn=cmd_remote)
    args = p.parse_args()
    global WORKER
    WORKER = args.worker
    require_setup(args.cmd, args)
    sys.exit(args.fn(args))


if __name__ == "__main__":
    os.chdir(ROOT)
    main()
