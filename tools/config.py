"""Project configuration.

config.json        shared settings (committed): compiler flags, expected exe hash, versions
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


def load():
    cfg = json.loads(SHARED.read_text())
    cfg.update(load_local())
    return cfg


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


def functions_csv():
    """The shared function list (data/functions.csv, committed so every contributor
    uses the same addresses); falls back to a local Ghidra export."""
    shared = ROOT / "data" / "functions.csv"
    return shared if shared.exists() else ROOT / "build" / "functions.csv"


BOUNDARY_OVERRIDES = ROOT / "boundary_overrides.txt"


def read_boundary_overrides(path=None):
    """[(entry, end_exclusive, note)] from boundary_overrides.txt (see that file)."""
    path = Path(path) if path else BOUNDARY_OVERRIDES
    out = []
    if not path.exists():
        return out
    for n, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        body, _, note = line.partition("#")
        if not body.strip():
            continue
        parts = body.split()
        if len(parts) != 2:
            raise ValueError(f"{path.name}:{n}: expected `<entry> <end-exclusive>`")
        entry, end = int(parts[0], 16), int(parts[1], 16)
        if end <= entry:
            raise ValueError(f"{path.name}:{n}: end 0x{end:08x} is not after entry 0x{entry:08x}")
        out.append((entry, end, note.strip()))
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
    [{"entry", "end", "size", "absorbed": [entries starting inside it], "note"}]."""
    rows = _read_function_rows() if rows is None else rows
    overrides = read_boundary_overrides() if overrides is None else overrides
    entries = sorted(int(r["entry"], 16) for r in rows)
    known = set(entries)
    out = []
    for entry, end, note in overrides:
        if entry not in known:
            raise ValueError(f"boundary_overrides.txt: no function starts at 0x{entry:08x}")
        out.append({"entry": entry, "end": end, "size": end - entry, "note": note,
                    "absorbed": [a for a in entries if entry < a < end]})
    return out


def load_functions(csv_path=None, overrides=None):
    """The function list (rows as csv.DictReader gives them) with boundary_overrides.txt
    applied: an override `<entry> <end>` makes the function at <entry> one range
    [entry, end) and drops every entry that starts inside it (the pieces Ghidra split
    off). Every tool reads functions through this, so a fix applies everywhere."""
    rows = _read_function_rows(csv_path)
    merges = boundary_merges(rows, overrides)
    if not merges:
        return rows
    fixed = {m["entry"]: m for m in merges}
    drop = {a for m in merges for a in m["absorbed"]}
    out = []
    for r in rows:
        a = int(r["entry"], 16)
        if a in drop:
            continue
        m = fixed.get(a)
        if m:
            r = dict(r, size=str(m["size"]), min=f"0x{a:08x}", max=f"0x{m['end'] - 1:08x}", ranges="1")
        out.append(r)
    return out
