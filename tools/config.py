"""Project configuration.

config.json        shared settings (committed): compiler flags, versions, and "modules": each
                   binary (exe, db, loc) with its file name and expected build hash
config.local.json  this machine only (git-ignored): game, Ghidra and MSVC paths, server
                   login. Written by `c5d setup`; its keys override config.json.
"""
import json
import os
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SHARED = ROOT / "config.json"
LOCAL = ROOT / "config.local.json"

# keys `c5d setup` must fill in before the toolchain commands work
MACHINE_KEYS = ("game_dir", "ghidra_dir", "msvc_bin")


def load_local():
    return json.loads(LOCAL.read_text()) if LOCAL.exists() else {}


def save_local(updates):
    """Merge `updates` into config.local.json (other keys, e.g. the server token, are kept)."""
    loc = load_local()
    loc.update(updates)
    LOCAL.write_text(json.dumps(loc, indent=2) + "\n")
    return loc


def load(module_id=None):
    """config.json overlaid with config.local.json. target_exe / target_build_hash /
    target_build are filled in from the current module's entry in "modules" (see
    module()), so code written for one binary keeps working."""
    cfg = json.loads(SHARED.read_text())
    cfg.update(load_local())
    m = cfg["modules"][current_module_id(module_id, cfg)]
    cfg.setdefault("target_exe", m["file"])
    cfg.setdefault("target_build_hash", m.get("build_hash", ""))
    cfg.setdefault("target_build", m.get("build", ""))
    return cfg


# ---------------------------------------------------------------- modules
#
# Each binary is a module (config.json "modules": exe, db, loc). Its files live in
# modules/<id>/ and its local build output in build/<id>/. include/, tools/, server/ and
# third_party/ are shared, and so is build/objcache (keyed on flags and source).

MODULES_DIR = ROOT / "modules"
BUILD_ROOT = ROOT / "build"
DEFAULT_MODULE = "exe"


def current_module_id(module_id=None, cfg=None):
    """The module tools work on: `module_id`, else $C5D_MODULE, else the exe."""
    mid = module_id or os.environ.get("C5D_MODULE") or DEFAULT_MODULE
    known = (cfg or json.loads(SHARED.read_text()))["modules"]
    if mid not in known:
        raise SystemExit(f"unknown module {mid!r} (config.json has: {', '.join(known)})")
    return mid


class Module:
    """One binary's paths. Everything under the repo, so relative_to(ROOT) works."""

    def __init__(self, mid, spec):
        self.id = mid
        self.file = spec["file"]
        self.build_hash = spec.get("build_hash", "")
        self.build_label = spec.get("build", "")
        self.root = MODULES_DIR / mid
        self.src = self.root / "src"
        self.symbols_txt = self.root / "symbols.txt"
        self.symbols_dir = self.root / "symbols"
        self.boundary_overrides = self.root / "boundary_overrides.txt"
        self.scope_overrides = self.root / "scope_overrides.txt"
        self.data = self.root / "data"
        self.names = self.root / "names"
        self.progress = self.root / "progress"
        self.status_csv = self.progress / "status.csv"
        self.build = BUILD_ROOT / mid

    def rel(self, p):
        """`p` as a repo-relative posix path (how sources are named in status.csv)."""
        return Path(p).resolve().relative_to(ROOT.resolve()).as_posix()

    def __repr__(self):
        return f"Module({self.id!r})"


def module(module_id=None):
    cfg = json.loads(SHARED.read_text())
    mid = current_module_id(module_id, cfg)
    return Module(mid, cfg["modules"][mid])


def all_modules():
    cfg = json.loads(SHARED.read_text())
    return [Module(mid, spec) for mid, spec in cfg["modules"].items()]


def module_of(path):
    """The module whose directory holds `path` (repo-relative or absolute), else None."""
    p = Path(path)
    parts = (p.resolve().relative_to(ROOT.resolve()) if p.is_absolute() else p).parts
    return parts[1] if len(parts) > 2 and parts[0] == MODULES_DIR.name else None


IS_WINDOWS = os.name == "nt"


def winpath(p):
    """A path as the compiler sees it. On Linux the VC++ 2008 tools run under Wine,
    where Z: is the root of the Linux filesystem (same trick fnvdecomp's CI uses)."""
    return str(p) if IS_WINDOWS else "Z:" + str(Path(p).resolve()).replace("/", "\\")


def tool_cmd(exe):
    """Command prefix to run a Windows tool: itself on Windows, through Wine elsewhere."""
    return [str(exe)] if IS_WINDOWS else ["wine", winpath(exe)]


def tool_env(env):
    """Environment tweaks for Wine: quiet, and no Mono/Gecko install prompts."""
    if not IS_WINDOWS:
        env.setdefault("WINEDEBUG", "-all")
        env.setdefault("WINEDLLOVERRIDES", "mscoree,mshtml=")
    return env


def missing_machine_keys(cfg=None):
    cfg = cfg if cfg is not None else load()
    return [k for k in MACHINE_KEYS if not cfg.get(k)]


def functions_csv(module_id=None):
    """The shared function list (modules/<id>/data/functions.csv, committed so every
    contributor uses the same addresses); falls back to a local Ghidra export."""
    m = module(module_id)
    shared = m.data / "functions.csv"
    return shared if shared.exists() else m.build / "functions.csv"


def boundary_overrides_path(module_id=None):
    return module(module_id).boundary_overrides


def read_boundary_overrides(path=None):
    """[(entry, end_exclusive, note, new)] from boundary_overrides.txt (see that file).
    `new` is True for a line `<entry> <end> new`: a function Ghidra did not list at all."""
    path = Path(path) if path else boundary_overrides_path()
    out = []
    if not path.exists():
        return out
    for n, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        body, _, note = line.partition("#")
        if not body.strip():
            continue
        parts = body.split()
        if len(parts) not in (2, 3) or (len(parts) == 3 and parts[2] != "new"):
            raise ValueError(f"{path.name}:{n}: expected `<entry> <end-exclusive> [new]`")
        entry, end = int(parts[0], 16), int(parts[1], 16)
        if end <= entry:
            raise ValueError(f"{path.name}:{n}: end 0x{end:08x} is not after entry 0x{entry:08x}")
        out.append((entry, end, note.strip(), len(parts) == 3))
    return out


def _read_function_rows(csv_path=None):
    import csv
    csv_path = Path(csv_path) if csv_path else functions_csv()
    if not csv_path.exists():
        return []
    with open(csv_path, newline="") as fh:
        return list(csv.DictReader(fh))


def boundary_merges(rows=None, overrides=None):
    """Each override resolved against the raw function list:
    [{"entry", "end", "size", "absorbed": [entries starting inside it], "note", "new"}].
    A plain override must name an entry Ghidra listed; a `new` one must not (both catch
    typos). Overrides are (entry, end, note) or (entry, end, note, new) tuples."""
    rows = _read_function_rows() if rows is None else rows
    overrides = read_boundary_overrides() if overrides is None else overrides
    entries = sorted(int(r["entry"], 16) for r in rows)
    known = set(entries)
    out = []
    for entry, end, note, *rest in overrides:
        new = bool(rest and rest[0])
        if new and entry in known:
            raise ValueError(f"boundary_overrides.txt: 0x{entry:08x} is already listed; drop `new`")
        if not new and entry not in known:
            raise ValueError(f"boundary_overrides.txt: no function starts at 0x{entry:08x} "
                             "(add `new` if Ghidra missed it)")
        out.append({"entry": entry, "end": end, "size": end - entry, "note": note, "new": new,
                    "absorbed": [a for a in entries if entry < a < end]})
    return out


def load_functions(csv_path=None, overrides=None):
    """The function list (rows as csv.DictReader gives them) with boundary_overrides.txt
    applied: an override `<entry> <end>` makes the function at <entry> one range
    [entry, end) and drops every entry that starts inside it (the pieces Ghidra split
    off, or misread from the middle of it); `<entry> <end> new` also adds the function
    if Ghidra did not list it. Every tool reads functions through this, so a fix
    applies everywhere."""
    rows = _read_function_rows(csv_path)
    merges = boundary_merges(rows, overrides)
    if not merges:
        return rows
    fixed = {m["entry"]: m for m in merges}
    drop = {a for m in merges for a in m["absorbed"]} - set(fixed)
    out = []
    for r in rows:
        a = int(r["entry"], 16)
        if a in drop:
            continue
        m = fixed.get(a)
        if m:
            r = dict(r, size=str(m["size"]), min=f"0x{a:08x}", max=f"0x{m['end'] - 1:08x}", ranges="1")
        out.append(r)
    fields = list(rows[0].keys()) if rows else ["entry", "size", "min", "max", "ranges", "block",
                                                 "name", "thunk", "external"]
    for m in merges:
        if m["new"] and m["entry"] not in drop:
            a = m["entry"]
            r = dict.fromkeys(fields, "")
            r.update(entry=f"0x{a:08x}", size=str(m["size"]), min=f"0x{a:08x}",
                     max=f"0x{m['end'] - 1:08x}", ranges="1", block=".text", name=f"FUN_{a:08x}",
                     thunk="0", external="0")
            out.append(r)
    out.sort(key=lambda r: int(r["entry"], 16))
    return out
