"""`c5d setup`: find and check everything a contributor needs, then write config.local.json.

Checks, in order:
  1. Python packages (requirements.txt)
  2. The game: found through Steam's library folders, and the exe must be the exact
     build this project targets (build hash in config.json)
  3. Ghidra (+ Java 17 or newer)
  4. Visual C++ 2008 SP1 compiler (cl 15.00.30729.01) + Windows SDK headers
  5. Civ V SDK headers (third_party/, optional)
  6. Shared function list, scope and work queue
  7. A test match of a function that is known to match
"""
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

import config

ROOT = config.ROOT
GAME_FOLDER = "Sid Meier's Civilization V"
HOME = Path.home()
HELP = "see CONTRIBUTING.md"


# ---------------------------------------------------------------- output

class Report:
    def __init__(self):
        self.failed = []

    def ok(self, label, detail=""):
        print(f"  [ok] {label}" + (f": {detail}" if detail else ""))

    def bad(self, label, detail="", fix=""):
        print(f"  [!!] {label}" + (f": {detail}" if detail else ""))
        if fix:
            for line in fix.splitlines():
                print(f"       -> {line}")
        self.failed.append(label)

    def note(self, text):
        print(f"       {text}")


# ---------------------------------------------------------------- exe identity

# Steam hands every account (and every re-download) a differently stamped exe: the
# per-user DRM rewrites a block of .rdata, the resources, the Rich header and the
# signature, while the code and data the project works from stay byte-identical.
# A whole-file SHA-256 therefore differs between contributors on the same build, so
# the build is identified by the parts that cannot change without moving addresses.
BUILD_SECTIONS = (".text", ".data", ".reloc")
BUILD_HASH_VERSION = b"c5d-build1"


def build_hash(path):
    """SHA-256 over the exe's image base, entry point, section layout and the raw
    bytes of BUILD_SECTIONS. Equal for every Steam download of one build, different
    for any other build. Raises ValueError if `path` is not a 32-bit PE."""
    d = Path(path).read_bytes()
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    if d[pe:pe + 4] != b"PE\0\0":
        raise ValueError(f"{path}: not a PE file")
    nsec, = struct.unpack_from("<H", d, pe + 6)
    opt_size, = struct.unpack_from("<H", d, pe + 20)
    opt = pe + 24
    entry, = struct.unpack_from("<I", d, opt + 16)
    image_base, = struct.unpack_from("<I", d, opt + 28)
    h = hashlib.sha256(BUILD_HASH_VERSION)
    h.update(struct.pack("<II", image_base, entry))
    found = set()
    for i in range(nsec):
        o = opt + opt_size + 40 * i
        name = d[o:o + 8].rstrip(b"\0").decode("ascii", "replace")
        vsize, rva, rawsize, rawptr = struct.unpack_from("<IIII", d, o + 8)
        h.update(d[o:o + 8] + struct.pack("<III", rva, vsize, rawsize))
        if name in BUILD_SECTIONS:
            h.update(d[rawptr:rawptr + rawsize])
            found.add(name)
    if found != set(BUILD_SECTIONS):
        raise ValueError(f"{path}: missing sections {sorted(set(BUILD_SECTIONS) - found)}")
    return h.hexdigest()


def exe_is_target(path, expected):
    """True if `path`'s build_hash is `expected`. Cached by size + mtime in build/ so
    the check costs nothing on every run."""
    path = Path(path)
    if not path.is_file():
        return False
    st = path.stat()
    stamp = f"{path}|{st.st_size}|{st.st_mtime_ns}|{expected}"
    cache = ROOT / "build" / f".verified_{path.name}"         # one per binary
    if cache.exists() and cache.read_text() == stamp:
        return True
    try:
        if build_hash(path) != expected:
            return False
    except (ValueError, struct.error):
        return False
    cache.parent.mkdir(exist_ok=True)
    cache.write_text(stamp)
    return True


# ---------------------------------------------------------------- discovery

def steam_libraries():
    roots = []
    try:
        import winreg
        for hive, key, val in ((winreg.HKEY_CURRENT_USER, r"Software\Valve\Steam", "SteamPath"),
                               (winreg.HKEY_LOCAL_MACHINE, r"SOFTWARE\WOW6432Node\Valve\Steam", "InstallPath"),
                               (winreg.HKEY_LOCAL_MACHINE, r"SOFTWARE\Valve\Steam", "InstallPath")):
            try:
                with winreg.OpenKey(hive, key) as k:
                    roots.append(Path(winreg.QueryValueEx(k, val)[0]))
            except OSError:
                pass
    except ImportError:
        pass
    roots += [Path(os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)")) / "Steam"]
    libs = []
    for r in roots:
        vdf = r / "steamapps" / "libraryfolders.vdf"
        if vdf.exists():
            for m in re.finditer(r'"path"\s+"([^"]+)"', vdf.read_text(errors="replace")):
                libs.append(Path(m.group(1).replace("\\\\", "\\")))
        libs.append(r)
    out = []
    for p in libs:
        if p.exists() and p.resolve() not in [o.resolve() for o in out]:
            out.append(p)
    return out


def find_games(target_exe):
    return [lib / "steamapps" / "common" / GAME_FOLDER for lib in steam_libraries()
            if (lib / "steamapps" / "common" / GAME_FOLDER / target_exe).is_file()]


def ghidra_version(d):
    props = Path(d) / "Ghidra" / "application.properties"
    if props.exists():
        m = re.search(r"^application\.version=(\S+)", props.read_text(errors="replace"), re.M)
        if m:
            return m.group(1)
    return None


def is_ghidra(d):
    return (Path(d) / "support" / "analyzeHeadless.bat").is_file()


def find_ghidra():
    found = []
    roots = [HOME, HOME / "Desktop", HOME / "Downloads", HOME / "Documents", HOME / "tools",
             Path("C:/"), Path("C:/tools"), Path(os.environ.get("ProgramFiles", r"C:\Program Files")),
             Path("D:/")]
    if os.environ.get("GHIDRA_INSTALL_DIR"):
        found.append(Path(os.environ["GHIDRA_INSTALL_DIR"]))
    for r in roots:
        try:
            for d in r.iterdir():
                if d.is_dir() and d.name.lower().startswith("ghidra"):
                    found.append(d)
                    # zips often extract to ghidra_X_PUBLIC_<date>/ghidra_X_PUBLIC
                    found += [s for s in d.iterdir() if s.is_dir() and s.name.lower().startswith("ghidra")]
        except OSError:
            continue
    return [d for d in found if is_ghidra(d)]


def java_info():
    cands = []
    if os.environ.get("JAVA_HOME"):
        cands.append(Path(os.environ["JAVA_HOME"]) / "bin" / "java.exe")
    if shutil.which("java"):
        cands.append(Path(shutil.which("java")))
    for j in cands:
        try:
            r = subprocess.run([str(j), "-version"], capture_output=True, text=True, timeout=30)
        except (OSError, subprocess.TimeoutExpired):
            continue
        m = re.search(r'version "([^"]+)"', r.stderr + r.stdout)
        if m:
            ver = m.group(1)
            major = int(ver.split(".")[1] if ver.startswith("1.") else re.split(r"[.+-]", ver)[0])
            return j, ver, major
    return None, None, 0


def msvc_candidates():
    pf86 = Path(os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)"))
    cpf86 = Path(os.environ.get("CommonProgramFiles(x86)", r"C:\Program Files (x86)\Common Files"))
    local = Path(os.environ.get("LOCALAPPDATA", HOME / "AppData" / "Local"))
    vcpy = Path("Microsoft") / "Visual C++ for Python" / "9.0" / "VC" / "bin"
    return [local / "Programs" / "Common" / vcpy, cpf86 / vcpy,
            pf86 / "Microsoft Visual Studio 9.0" / "VC" / "bin"]


def cl_banner(bin_dir):
    cl = Path(bin_dir) / "cl.exe"
    if not cl.is_file():
        return None
    r = subprocess.run([str(cl)], capture_output=True, text=True)
    text = (r.stderr or r.stdout).strip()
    return text.splitlines()[0] if text else "?"


def normalise_msvc(p):
    """Accept the bin folder, the VC folder or the 9.0 folder."""
    p = Path(p)
    for cand in (p, p / "bin", p / "VC" / "bin"):
        if (cand / "cl.exe").is_file():
            return cand
    return p


def find_winsdk(msvc_bin):
    own = Path(msvc_bin).parent.parent / "WinSDK"          # Visual C++ for Python layout
    if (own / "Include" / "windows.h").is_file():
        return own, False
    for pf in (os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)"),
               os.environ.get("ProgramFiles", r"C:\Program Files")):
        for v in ("v6.0A", "v7.0A", "v7.0", "v7.1", "v7.1A"):
            d = Path(pf) / "Microsoft SDKs" / "Windows" / v
            if (d / "Include" / "windows.h").is_file():
                return d, True
    return None, False


# ---------------------------------------------------------------- steps

def step_python(rep, install):
    print("Python")
    rep.ok("python", sys.version.split()[0]) if sys.version_info >= (3, 10) else \
        rep.bad("python", sys.version.split()[0], "install Python 3.10 or newer")
    try:
        import capstone  # noqa: F401
        rep.ok("capstone", capstone.__version__)
    except ImportError:
        if install:
            print("       installing requirements.txt ...", flush=True)
            r = subprocess.run([sys.executable, "-m", "pip", "install", "-r", str(ROOT / "requirements.txt")])
            if r.returncode == 0:
                rep.ok("capstone", "installed")
                return
        rep.bad("capstone", "not installed", f"{sys.executable} -m pip install -r requirements.txt")


def step_game(rep, cfg, arg):
    print("Game")
    target, want = cfg["target_exe"], cfg["target_build_hash"]
    cands = [Path(arg)] if arg else []
    if not arg and cfg.get("game_dir"):
        cands.append(Path(cfg["game_dir"]))
    if not arg:
        cands += find_games(target)
    seen = []
    for d in cands:
        exe = d / target
        if exe in seen or not exe.is_file():
            continue
        seen.append(exe)
        if exe_is_target(exe, want):
            rep.ok(target, f"{d} (build hash matches {cfg.get('target_build', 'the target build')})")
            check_other_modules(rep, cfg, d, target)
            return {"game_dir": d.as_posix()}
        try:
            full = build_hash(exe)
            got = full[:16] + "..."
        except (ValueError, struct.error) as e:
            full, got = "", str(e)
        legacy = [b for m in cfg["modules"].values() if m["file"] == target
                  for b, spec in m.get("legacy", {}).items() if spec.get("build_hash") == full]
        if legacy:
            rep.note(f"{exe}: this is the {legacy[0]} build, which the project no longer works on "
                     "(it moved to the current Steam build; the old one is view-only)")
        else:
            rep.note(f"{exe}: different build (build hash {got})")
    if seen:
        rep.bad(target, "found, but not the build this project targets",
                "the project matches one exact build: " + cfg.get("target_build", "") +
                "\nlet Steam update the game and verify its files (Properties > Installed Files)")
    else:
        rep.bad(target, "Civilization V not found in any Steam library",
                "install it through Steam, or pass --game \"<folder containing the exe>\"")
    return {}


def check_other_modules(rep, cfg, game_dir, done):
    """The other binaries in config.json "modules" (the DLLs) must be the same build too
    before anyone works on them. A mismatch only matters for that module, so it's a note."""
    for mid, spec in cfg.get("modules", {}).items():
        f = spec["file"]
        if f == done:
            continue
        path = Path(game_dir) / f
        if exe_is_target(path, spec.get("build_hash", "")):
            rep.ok(f"{mid}: {f}", "build hash matches")
        else:
            rep.note(f"{mid}: {path} is missing or a different build; `--module {mid}` won't work "
                     "until Steam verifies the game files")


def step_ghidra(rep, cfg, arg):
    print("Ghidra")
    want = cfg.get("ghidra_version")
    cands = [Path(arg)] if arg else ([Path(cfg["ghidra_dir"])] if cfg.get("ghidra_dir") else []) + find_ghidra()
    cands = [d for d in cands if is_ghidra(d)]
    # prefer the pinned version
    cands.sort(key=lambda d: ghidra_version(d) != want)
    found = {}
    if cands:
        d, ver = cands[0], ghidra_version(cands[0])
        if ver == want:
            rep.ok("Ghidra", f"{ver} at {d}")
        else:
            rep.ok("Ghidra", f"{ver} at {d}")
            rep.note(f"the project uses {want}; other versions usually work (the function list is shared)")
        found = {"ghidra_dir": d.as_posix()}
    else:
        rep.bad("Ghidra", "not found",
                f"download Ghidra {want} from https://github.com/NationalSecurityAgency/ghidra/releases,\n"
                "unzip it, and pass --ghidra \"<unzipped folder>\" (or set GHIDRA_INSTALL_DIR)")
    j, ver, major = java_info()
    if major >= 17:
        rep.ok("Java", f"{ver} ({j})")
    else:
        rep.bad("Java 17+", ver or "not found",
                "install a JDK 17 (e.g. Eclipse Temurin 17) and make sure `java` is on PATH or JAVA_HOME is set")
    return found


def step_msvc(rep, cfg, arg):
    print("Compiler (Visual C++ 2008 SP1)")
    want = cfg["msvc_version"]
    cands = [normalise_msvc(arg)] if arg else \
        ([Path(cfg["msvc_bin"])] if cfg.get("msvc_bin") else []) + msvc_candidates()
    wrong = []
    for b in cands:
        banner = cl_banner(b)
        if banner is None:
            continue
        if f"Version {want} for 80x86" not in banner:
            wrong.append(f"{b}: {banner}")
            continue
        missing = [t for t in ("link.exe", "lib.exe", "ml.exe") if not (b / t).is_file()]
        if missing:
            wrong.append(f"{b}: missing {', '.join(missing)}")
            continue
        rep.ok("cl.exe", f"{banner.split('Compiler ')[-1]} at {b}")
        out = {"msvc_bin": b.as_posix()}
        sdk, separate = find_winsdk(b)
        if sdk:
            rep.ok("Windows SDK headers", str(sdk))
            out["winsdk_dir"] = sdk.as_posix() if separate else ""
        else:
            rep.bad("Windows SDK headers", "windows.h not found",
                    "install the Windows SDK 7.0/7.1 or use the Visual C++ for Python package (it includes them)")
        return out
    for w in wrong:
        rep.note(w)
    rep.bad("cl.exe", f"no {want} compiler found",
            f"this exact compiler version is required (byte matching depends on it): {HELP}\n"
            "if it is installed somewhere else, pass --msvc \"<folder containing cl.exe>\"")
    return {}


def step_sdk_headers(rep, clone):
    print("Civ V SDK headers (optional: only `tools/sdk_vtables.py` uses them)")
    inc = ROOT / "third_party" / "Community-Patch-DLL" / "CvGameCoreDLLUtil" / "include"
    if inc.is_dir():
        rep.ok("SDK headers", str(inc.relative_to(ROOT)))
        return
    if not clone or not shutil.which("git"):
        print("  [--] not present (run setup with --sdk-headers to fetch them)")
        return
    dest = ROOT / "third_party" / "Community-Patch-DLL"
    print("       fetching (sparse checkout) ...", flush=True)
    r1 = subprocess.run(["git", "clone", "--depth", "1", "--filter=blob:none", "--sparse",
                         "https://github.com/LoneGazebo/Community-Patch-DLL.git", str(dest)])
    r2 = r1.returncode or subprocess.run(["git", "-C", str(dest), "sparse-checkout", "set",
                                          "CvGameCoreDLLUtil"]).returncode
    if r2 == 0 and inc.is_dir():
        rep.ok("SDK headers", "fetched")
    else:
        rep.bad("SDK headers", "fetch failed", "see the git commands in README.md")


def c5d(*args, capture=True):
    cmd = [sys.executable, str(ROOT / "tools" / "c5d.py"), *args]
    return subprocess.run(cmd, cwd=ROOT, capture_output=capture, text=True)


def step_data(rep):
    """Scope and work queue for every module (build/<id>/scope.csv, queue.csv). A DLL
    whose binary isn't the targeted build is only a note: that module can't be set up."""
    print("Function list, scope and work queue")
    game_dir = config.load().get("game_dir")
    for m in config.all_modules():
        fcsv = config.functions_csv(m.id)
        label = f"{m.id}: function list"
        if fcsv.parent != m.data:
            rep.bad(label, f"{m.rel(m.data / 'functions.csv')} is missing", "git pull (it is committed)")
            return
        rep.ok(label, f"{sum(1 for _ in open(fcsv)) - 1:,} functions ({m.rel(fcsv)})")
        if m.id != config.DEFAULT_MODULE and not (
                game_dir and exe_is_target(Path(game_dir) / m.file, m.build_hash)):
            rep.note(f"{m.id}: {m.file} isn't the targeted build; skipped its scope and queue")
            continue
        for name, args in (("scope", ("scope",)), ("queue", ("queue", "--top", "0"))):
            out = m.build / f"{name}.csv"
            shown = m.rel(out)
            inputs = [fcsv] + [p for p in (m.boundary_overrides,) if p.exists()]
            if out.exists() and out.stat().st_mtime >= max(p.stat().st_mtime for p in inputs):
                rep.ok(shown, "up to date")
                continue
            print(f"       running c5d --module {m.id} {name} ...", flush=True)
            r = c5d("--module", m.id, *args)
            if r.returncode == 0 and out.exists():
                rep.ok(shown, "generated")
            else:
                rep.bad(f"c5d --module {m.id} {name}", "failed", (r.stdout + r.stderr).strip()[-600:])
                return


def step_test_match(rep):
    print("Test match")
    status = config.module().status_csv
    import csv
    rows = [r for r in csv.DictReader(open(status, newline=""))] if status.exists() else []
    known = next((r for r in rows if r["status"] == "MATCH"), None)
    if not known:
        print("  [--] no matched function yet to test against")
        return
    r = c5d("match", "--addr", known["address"])
    line = next((ln for ln in r.stdout.splitlines() if known["symbol"] in ln and "@0x" in ln), "")
    if r.returncode == 0 and line.split()[:1] == ["MATCH"]:
        rep.ok("LTCG build + compare", f"{known['address']} matches")
    else:
        rep.bad("LTCG build + compare", f"{known['address']} should match but did not",
                (r.stdout + r.stderr).strip()[-800:])


def run(args):
    rep = Report()
    cfg = config.load()
    print(f"civ5-decomp setup ({ROOT})\n")
    step_python(rep, not args.no_install)
    found = {}
    found.update(step_game(rep, cfg, args.game))
    found.update(step_ghidra(rep, cfg, args.ghidra))
    found.update(step_msvc(rep, cfg, args.msvc))
    if found:
        config.save_local(found)
        print(f"\n  saved {', '.join(k for k in found)} to config.local.json\n")
    step_sdk_headers(rep, args.sdk_headers)

    if rep.failed:
        print(f"\nNot ready: fix the [!!] items above, then run `python tools/c5d.py setup` again.")
        return 1
    step_data(rep)
    if not args.skip_test and not rep.failed:
        step_test_match(rep)

    proj = ROOT / cfg["ghidra_project_dir"] / f"{cfg['ghidra_project_name']}.gpr"
    if rep.failed:
        print("\nAlmost: fix the [!!] items above and run setup again.")
        return 1
    print("\nAll set.")
    if not proj.exists():
        print("One more one-time step before claiming work: build your local Ghidra database\n"
              "(it supplies the pseudo-C in task bundles; takes about 5-15 minutes):\n"
              "    python tools/c5d.py analyze")
    print("Then see CONTRIBUTING.md: sign in on the site, `c5d remote login`, `c5d remote claim`.")
    return 0
