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
