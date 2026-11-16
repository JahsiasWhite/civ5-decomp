"""Content-addressed cache of compiled objects, shared by all workers.

An object is keyed on everything that can change what cl.exe writes: the compiler, the
flags, the source file's path and contents, and every header in include/ and src/. Any header
edit therefore invalidates the whole cache (one slow build), which is crude but never stale.
Entries are written to a temp name and renamed into place, so parallel workers can share it.
"""
import hashlib
import os
import subprocess
from functools import lru_cache
from pathlib import Path

HEADER_EXTS = {".h", ".hpp", ".hh", ".inl", ".inc"}


@lru_cache(maxsize=None)
def headers_digest(root):
    root = Path(root)
    h = hashlib.sha256()
    for d in (root / "include", root / "src"):
        if not d.exists():
            continue
        for p in sorted(d.rglob("*")):
            if p.suffix.lower() in HEADER_EXTS and p.is_file():
                h.update(p.relative_to(root).as_posix().encode() + b"\0")
                h.update(hashlib.sha256(p.read_bytes()).digest())
    return h.hexdigest()


def key(root, compiler, flags, src):
    h = hashlib.sha256()
    h.update(str(compiler).encode() + b"\0")
    h.update("\0".join(flags).encode() + b"\0")
    src = Path(src)
    try:
        rel = src.resolve().relative_to(Path(root).resolve()).as_posix()
    except ValueError:
        rel = str(src)
    h.update(rel.encode() + b"\0")
    h.update(src.read_bytes())
    h.update(headers_digest(str(root)).encode())
    return h.hexdigest()[:40]


def compile(cache_dir, root, tool_cmd, compiler, flags, src, env, winpath):
    """Return the path of an object for `src` compiled with `flags` (from the cache, or
    compiled now). Raises RuntimeError with cl.exe's output on failure."""
    cache_dir = Path(cache_dir)
    cache_dir.mkdir(parents=True, exist_ok=True)
    obj = cache_dir / f"{key(root, compiler, flags, src)}.obj"
    if obj.exists():
        return obj
    tmp = cache_dir / f"{obj.stem}.{os.getpid()}.tmp.obj"
    cmd = [*tool_cmd(compiler), *flags, f"/Fo{winpath(tmp)}", winpath(src)]
    r = subprocess.run(cmd, capture_output=True, text=True, env=env)
    if r.returncode != 0:
        tmp.unlink(missing_ok=True)
        raise RuntimeError(r.stdout + r.stderr)
    try:
        os.replace(tmp, obj)
    except OSError:                      # another worker won the race and has it open
        tmp.unlink(missing_ok=True)
        if not obj.exists():
            raise
    return obj
