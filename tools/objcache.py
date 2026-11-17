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
A cache hit refreshes the entry's mtime, so the mtime says when an entry was last used;
prune() deletes entries a full build didn't use and nobody has used for a while.
"""
import hashlib
import os
import re
import subprocess
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from functools import lru_cache
from pathlib import Path

PRUNE_GRACE = 3600          # seconds: entries used this recently are kept (other workers)
_used = set()               # cache entries returned in this process
_used_lock = threading.Lock()

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
    # a module's own headers (modules/<id>/include) come after include/ on INCLUDE
    rel = src.relative_to(root).parts if root in src.parents else ()
    mod_inc = [root / rel[0] / rel[1] / "include"] if len(rel) > 2 and rel[0] == "modules" else []
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
            dirs = ([f.parent, src.parent] if quoted else []) + [inc_dir] + mod_inc
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
        try:
            os.utime(obj)                # last used: now (see prune)
        except OSError:
            pass
        return _mark(obj)
    tmp = cache_dir / f"{obj.stem}.{os.getpid()}.{threading.get_ident()}.tmp.obj"
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
    return _mark(obj)


def _mark(obj):
    with _used_lock:
        _used.add(obj.name)
    return obj


def compile_many(cache_dir, root, tool_cmd, compiler, jobs, env, winpath, workers=None):
    """compile() for each (flags, src) in `jobs`, several at a time. Returns the object
    paths in the order of `jobs`. If any compile fails, raises RuntimeError naming the
    first failing source (in `jobs` order) with cl.exe's output."""
    jobs = list(jobs)
    workers = workers or min(len(jobs), os.cpu_count() or 1) or 1

    def one(job):
        flags, src = job
        try:
            return compile(cache_dir, root, tool_cmd, compiler, flags, src, env, winpath), None
        except RuntimeError as e:
            return None, (src, str(e))

    if workers == 1:
        results = [one(j) for j in jobs]
    else:
        with ThreadPoolExecutor(max_workers=workers) as pool:
            results = list(pool.map(one, jobs))
    for _obj, err in results:
        if err:
            src, out = err
            raise RuntimeError(f"compile failed: {src}\n{out}")
    return [obj for obj, _err in results]


def prune(cache_dir, grace=PRUNE_GRACE):
    """Delete cache entries this process didn't use and nobody used in the last `grace`
    seconds. Call only after a build that compiled every source (a full match), or the
    entries for the files it skipped go too. Returns (files removed, bytes freed)."""
    cache_dir = Path(cache_dir)
    if not cache_dir.is_dir():
        return 0, 0
    cutoff = time.time() - grace
    with _used_lock:
        used = set(_used)
    n = freed = 0
    for p in cache_dir.iterdir():
        if p.name in used or not p.name.endswith(".obj"):
            continue
        try:
            st = p.stat()
            if st.st_mtime >= cutoff:
                continue                 # recent: another worker may be using it
            p.unlink()
        except OSError:
            continue                     # gone already, or open in another process
        n += 1
        freed += st.st_size
    return n, freed
