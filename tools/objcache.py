"""Content-addressed cache of compiled objects, shared by all workers.

An object is keyed on everything that can change what cl.exe writes: the compiler, the
flags, the source file's path and contents, and the project headers it reaches through
#include (followed transitively, ignoring #if, so it can over-count but not miss one).
A quoted name counts wherever it exists next to the including file, next to the source
file, or in include/; an angle-bracket name only in include/. Names found nowhere in the
project are toolchain headers, covered by the compiler path. Resolution is redone for every key, so a header added later that shadows
one is picked up. A computed `#include MACRO` or an /I or /FI flag falls back to hashing
every header in include/ and src/.
Entries are written to a temp name and renamed into place, so parallel workers can share it.
"""
import hashlib
import os
import re
import subprocess
from functools import lru_cache
from pathlib import Path

HEADER_EXTS = {".h", ".hpp", ".hh", ".inl", ".inc"}
INCLUDE_LINE = re.compile(rb"^[ \t]*#[ \t]*include\b(.*)$", re.M)
INCLUDE_NAME = re.compile(rb'^[ \t]*(?:"([^"]+)"|<([^>]+)>)')
SEARCH_FLAGS = ("/I", "-I", "/FI", "-FI")


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


def _file(path):
    """(sha256, bytes) of a project file; reread only when its mtime or size changes."""
    st = path.stat()
    return _read(path, st.st_mtime_ns, st.st_size)


@lru_cache(maxsize=None)
def _read(path, _mtime, _size):
    data = path.read_bytes()
    return hashlib.sha256(data).digest(), data


def includes_digest(root, src):
    """Digest of the project headers `src` reaches through #include, or None when they
    can't be worked out statically (a computed #include)."""
    root = Path(root).resolve()
    inc_dir = root / "include"
    src = Path(src).resolve()
    seen = {}
    todo = [src]
    while todo:
        f = todo.pop()
        _sha, data = _file(f)
        for m in INCLUDE_LINE.finditer(data):
            n = INCLUDE_NAME.match(m.group(1))
            if not n:
                return None                     # #include MACRO
            quoted = n.group(1) is not None
            name = (n.group(1) or n.group(2)).decode("utf-8", "replace")
            # cl.exe looks for a quoted name next to the including file, then next to the
            # files that included it, then on INCLUDE (include/ first). Every candidate
            # that exists counts, not just the first, so a header found by another
            # route can't be missed (worst case: a few extra rebuilds).
            dirs = ([f.parent, src.parent] if quoted else []) + [inc_dir]
            for p in {(d / name).resolve() for d in dirs}:
                if not p.is_file() or root not in p.parents or p in seen:
                    continue                    # absent, toolchain header, or done
                seen[p] = _file(p)[0]
                todo.append(p)
    h = hashlib.sha256()
    for p in sorted(seen, key=lambda q: q.relative_to(root).as_posix()):
        h.update(p.relative_to(root).as_posix().encode() + b"\0" + seen[p])
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
    deps = None
    if not any(f.upper().startswith(t.upper()) for f in flags for t in SEARCH_FLAGS):
        deps = includes_digest(root, src)
    h.update(b"inc:" + deps.encode() if deps else b"all:" + headers_digest(str(root)).encode())
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
