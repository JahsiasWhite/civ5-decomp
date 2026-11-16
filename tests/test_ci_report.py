"""tools/ci_report.py: which sources a changed header reaches, and what counts as a
regression there."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tools"))
import ci_report  # noqa: E402


def write(root, rel, text):
    p = root / rel
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(text, encoding="utf-8")


def tree(tmp_path):
    write(tmp_path, "include/Base.h", "#pragma once\nstruct Base { int a; };\n")
    write(tmp_path, "include/Derived.h", '#pragma once\n#include "Base.h"\nstruct D : Base {};\n')
    write(tmp_path, "include/Other.h", "#pragma once\n")
    write(tmp_path, "src/auto/f_1.cpp", '#include "Derived.h"\n#include <windows.h>\n')
    write(tmp_path, "src/auto/f_2.cpp", '#include "Other.h"\n')
    write(tmp_path, "src/auto/f_3.cpp", '  #  include "Base.h"\n')
    write(tmp_path, "src/auto/f_4.cpp", "int x;\n")
    return ci_report.include_graph(tmp_path)


def row(addr, status, source, symbol="?f@@YAXXZ"):
    return {"address": addr, "symbol": symbol, "status": status, "source": source}


def test_include_graph_resolves_quoted_includes_only(tmp_path):
    g = tree(tmp_path)
    assert g["src/auto/f_1.cpp"] == {"include/Derived.h"}          # <windows.h> left out
    assert g["include/Derived.h"] == {"include/Base.h"}
    assert g["src/auto/f_3.cpp"] == {"include/Base.h"}             # spacing in the directive


def test_sources_including_is_transitive(tmp_path):
    g = tree(tmp_path)
    assert ci_report.sources_including({"include/Base.h"}, g) == {"src/auto/f_1.cpp", "src/auto/f_3.cpp"}
    assert ci_report.sources_including({"include/Other.h"}, g) == {"src/auto/f_2.cpp"}
    assert ci_report.sources_including(set(), g) == set()


def test_header_regressions(tmp_path):
    g = tree(tmp_path)
    base = [row("0x1", "MATCH", "src/auto/f_1.cpp"),
            row("0x3", "DIFF", "src/auto/f_3.cpp"),
            row("0x5", "MATCH", "src/auto/f_3.cpp"),       # gone from the new run
            row("0x2", "MATCH", "src/auto/f_2.cpp")]
    now = [row("0x1", "DIFF", "src/auto/f_1.cpp"),         # broke: regression
           row("0x3", "DIFF", "src/auto/f_3.cpp"),         # already DIFF: not the PR's fault
           row("0x6", "ERROR", "src/auto/f_3.cpp"),        # unknown to the base: must MATCH
           row("0x2", "DIFF", "src/auto/f_2.cpp")]         # doesn't include Base.h
    affected, bad = ci_report.header_regressions(now, base, ["include/Base.h"], g)
    assert affected == ["src/auto/f_1.cpp", "src/auto/f_3.cpp"]
    assert sorted((r["address"], r["status"], why) for r, why in bad) == [
        ("0x1", "DIFF", "was MATCH"),
        ("0x5", "missing", "was MATCH, now not built"),
        ("0x6", "ERROR", "not in the base status")]


def test_edited_sources_are_left_to_the_direct_check(tmp_path):
    g = tree(tmp_path)
    base = [row("0x1", "MATCH", "src/auto/f_1.cpp")]
    now = [row("0x1", "DIFF", "src/auto/f_1.cpp")]
    affected, bad = ci_report.header_regressions(
        now, base, ["include/Base.h", "src/auto/f_1.cpp"], g)
    assert "src/auto/f_1.cpp" not in affected and bad == []


def test_push_regressions_cover_every_file():
    base = [row("0x1", "MATCH", "src/a.cpp"),
            row("0x2", "DIFF", "src/a.cpp"),
            row("0x3", "MATCH", "src/b.cpp"),
            row("0x4", "MATCH", "src/c.cpp")]
    now = [row("0x1", "DIFF", "src/a.cpp"),              # broke
           row("0x2", "DIFF", "src/a.cpp"),              # was already DIFF
           row("0x3", "MATCH", "src/moved.cpp"),         # moved file, still matches
           row("0x7", "DIFF", "src/new.cpp")]            # new work in progress: fine on main
    bad = ci_report.regressions(now, base)                # 0x4: file gone
    assert sorted((r["address"], r["status"], why) for r, why in bad) == [
        ("0x1", "DIFF", "was MATCH"), ("0x4", "missing", "was MATCH, now not built")]


def test_push_report_exit_code(tmp_path, monkeypatch, capsys):
    import csv
    def csv_of(name, rows):
        p = tmp_path / name
        with open(p, "w", newline="") as fh:
            w = csv.DictWriter(fh, ["address", "symbol", "status", "source"])
            w.writeheader()
            w.writerows(rows)
        return str(p)
    base = csv_of("base.csv", [row("0x1", "MATCH", "src/a.cpp")])
    ok = csv_of("ok.csv", [row("0x1", "MATCH", "src/a.cpp")])
    broke = csv_of("broke.csv", [row("0x1", "DIFF", "src/a.cpp")])
    for status, rc in ((ok, 0), (broke, 1)):
        monkeypatch.setattr(sys, "argv", ["ci_report", "--status", status, "--base-status", base])
        assert ci_report.main() == rc
    monkeypatch.setattr(sys, "argv", ["ci_report", "--status", broke])     # no baseline: not checked
    assert ci_report.main() == 0
    assert "Regressions since the previous results: 1" in capsys.readouterr().out


def test_no_header_changed(tmp_path):
    g = tree(tmp_path)
    assert ci_report.header_regressions([], [], ["src/auto/f_4.cpp"], g) == ([], [])
