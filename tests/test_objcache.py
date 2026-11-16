"""objcache keys: a header edit invalidates only the sources that include it."""
import os
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import objcache  # noqa: E402

FLAGS = ["/c", "/O2"]


def tree(tmp_path, files):
    for rel, text in files.items():
        p = tmp_path / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(text)
    return tmp_path


def key(root, rel, flags=FLAGS):
    return objcache.key(root, "cl.exe", flags, root / rel)


def touch(p, text):
    p.write_text(text)
    st = p.stat()                       # make sure the mtime moves even on coarse clocks
    os.utime(p, ns=(st.st_atime_ns, st.st_mtime_ns + 10 ** 9))


def test_header_edit_only_invalidates_its_includers(tmp_path):
    root = tree(tmp_path, {
        "include/A.h": "struct A {};\n",
        "include/B.h": '#include "A.h"\nstruct B : A {};\n',
        "include/C.h": "struct C {};\n",
        "src/auto/uses_b.cpp": '#include "B.h"\nint f() { return 1; }\n',
        "src/auto/uses_c.cpp": "#include <C.h>\n#include <windows.h>\n",
        "src/auto/plain.cpp": "int g() { return 2; }\n",
    })
    before = {f: key(root, f"src/auto/{f}") for f in ("uses_b.cpp", "uses_c.cpp", "plain.cpp")}
    touch(root / "include/A.h", "struct A { int x; };\n")          # reached through B.h
    after = {f: key(root, f"src/auto/{f}") for f in before}
    assert after["uses_b.cpp"] != before["uses_b.cpp"]
    assert after["uses_c.cpp"] == before["uses_c.cpp"]
    assert after["plain.cpp"] == before["plain.cpp"]
    touch(root / "include/C.h", "struct C { int y; };\n")
    assert key(root, "src/auto/uses_c.cpp") != after["uses_c.cpp"]


def test_quoted_include_counts_every_copy_it_could_resolve_to(tmp_path):
    # over-counting is safe: both the local and the include/ copy are part of the key
    root = tree(tmp_path, {
        "include/X.h": "// include/ copy\n",
        "src/core/X.h": "// local copy\n",
        "src/core/f.cpp": '#include "X.h"\n',
        "src/core/g.cpp": "#include <X.h>\n",
    })
    kf, kg = key(root, "src/core/f.cpp"), key(root, "src/core/g.cpp")
    touch(root / "src/core/X.h", "// local copy, edited\n")
    assert key(root, "src/core/f.cpp") != kf
    assert key(root, "src/core/g.cpp") == kg             # <X.h> never looks next to the file
    kf = key(root, "src/core/f.cpp")
    touch(root / "include/X.h", "// include/ copy, edited\n")
    assert key(root, "src/core/f.cpp") != kf


def test_header_quoting_one_next_to_the_source_is_followed(tmp_path):
    # cl.exe finds "Local.h" next to f.cpp even though include/Outer.h is what includes it
    root = tree(tmp_path, {
        "include/Outer.h": '#include "Local.h"\n',
        "src/core/Local.h": "// local\n",
        "src/core/f.cpp": '#include "Outer.h"\n',
    })
    k = key(root, "src/core/f.cpp")
    touch(root / "src/core/Local.h", "// local, edited\n")
    assert key(root, "src/core/f.cpp") != k


def test_new_header_shadowing_a_toolchain_one_is_noticed(tmp_path):
    root = tree(tmp_path, {"src/auto/f.cpp": "#include <string>\n"})
    k = key(root, "src/auto/f.cpp")
    tree(root, {"include/string": "// now a project header\n"})
    assert key(root, "src/auto/f.cpp") != k


def test_include_cycles_terminate(tmp_path):
    root = tree(tmp_path, {
        "include/P.h": '#pragma once\n#include "Q.h"\n',
        "include/Q.h": '#pragma once\n#include "P.h"\n',
        "src/auto/f.cpp": '#include "P.h"\n',
    })
    assert key(root, "src/auto/f.cpp")


def test_computed_include_and_search_flags_fall_back_to_all_headers(tmp_path):
    root = tree(tmp_path, {
        "include/U.h": "// unrelated\n",
        "src/auto/macro.cpp": "#define H <stdio.h>\n#include H\n",
        "src/auto/plain.cpp": "int g();\n",
    })
    k_macro = key(root, "src/auto/macro.cpp")
    k_flag = key(root, "src/auto/plain.cpp", FLAGS + ["/Iextra"])
    objcache.headers_digest.cache_clear()
    touch(root / "include/U.h", "// unrelated, edited\n")
    assert key(root, "src/auto/macro.cpp") != k_macro
    assert key(root, "src/auto/plain.cpp", FLAGS + ["/Iextra"]) != k_flag
