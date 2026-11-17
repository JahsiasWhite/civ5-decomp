"""tools/ci_plan.py: when a pull request's verify run may build only part of src/."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tools"))
import ci_plan  # noqa: E402
import ci_report  # noqa: E402


def write(root, rel, text):
    p = root / rel
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(text, encoding="utf-8")


def graph(tmp_path):
    write(tmp_path, "include/Base.h", "#pragma once\n")
    write(tmp_path, "include/Derived.h", '#pragma once\n#include "Base.h"\n')
    write(tmp_path, "src/auto/f_1.cpp", '#include "Derived.h"\n')
    write(tmp_path, "src/auto/f_2.cpp", "int x;\n")
    write(tmp_path, "src/auto/f_3.cpp", "int y;\n")
    return ci_report.include_graph(tmp_path)


def test_new_function_is_partial_from_its_source(tmp_path):
    rows = [("A", "src/auto/f_2.cpp"), ("A", "symbols/auto/f_2.txt")]
    assert ci_plan.plan(rows, graph(tmp_path)) == ("partial", ["src/auto/f_2.cpp"])


def test_header_change_starts_from_every_includer(tmp_path):
    rows = [("M", "include/Base.h"), ("M", "src/auto/f_3.cpp")]
    assert ci_plan.plan(rows, graph(tmp_path)) == ("partial", ["src/auto/f_1.cpp", "src/auto/f_3.cpp"])


def test_markdown_is_ignored(tmp_path):
    rows = [("M", "src/auto/f_2.cpp"), ("M", "README.md")]
    assert ci_plan.plan(rows, graph(tmp_path))[0] == "partial"


def test_tools_data_and_config_force_full(tmp_path):
    g = graph(tmp_path)
    for path in ("tools/c5d.py", "data/fingerprints.csv", "config.json", ".github/workflows/verify.yml"):
        assert ci_plan.plan([("M", "src/auto/f_2.cpp"), ("M", path)], g)[0] == "full", path


def test_deleted_or_renamed_source_forces_full(tmp_path):
    g = graph(tmp_path)
    assert ci_plan.plan([("D", "src/auto/f_2.cpp")], g)[0] == "full"
    assert ci_plan.plan([("R", "src/auto/f_2.cpp"), ("R", "src/auto/f_9.cpp")], g)[0] == "full"
    assert ci_plan.plan([("D", "include/Base.h")], g)[0] == "full"


def test_symbols_only_forces_full(tmp_path):
    assert ci_plan.plan([("M", "symbols.txt")], graph(tmp_path))[0] == "full"
    assert ci_plan.plan([("A", "symbols/auto/f_9.txt")], graph(tmp_path))[0] == "full"


def test_unincluded_header_alone_forces_full(tmp_path):
    write(tmp_path, "include/Lonely.h", "#pragma once\n")
    assert ci_plan.plan([("A", "include/Lonely.h")], graph(tmp_path))[0] == "full"
