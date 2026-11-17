"""Summarise a CI match run (progress/status.csv) as Markdown for the job summary.

    python tools/ci_report.py [--changed FILE [--base-status FILE]]

--changed: a list of paths a pull request touches (one per line). Then the run fails
(exit 1) if any function defined in those files isn't a MATCH, so a PR shows a red
check for work that wouldn't be credited.

A changed header also affects every source that includes it (directly or through other
headers). Those sources weren't edited by the PR, so they only fail on a regression: a
function that isn't a MATCH now although --base-status (the base branch's
progress/status.csv) doesn't list it as anything else. That is what stops a layout
change in include/ from silently breaking functions that already match.

Without --changed (main), --base-status is the results before the push: every function
it had as MATCH must still MATCH, in any file, or the run fails.
"""
import argparse
import csv
import re
import sys
from collections import Counter
from pathlib import Path

import config  # noqa: E402  (tools/ is on sys.path wherever these run)

ROOT = Path(__file__).resolve().parent.parent
INCLUDE_RE = re.compile(r'^\s*#\s*include\s*"([^"]+)"', re.M)
HEADER_EXT = (".h", ".hpp", ".inl")


def _rel(p, root):
    return p.resolve().relative_to(root.resolve()).as_posix()


def include_graph(root=ROOT):
    """{file: {files it #includes "..."}} over every module's src/ (modules/<id>/src) and
    include/, as repo-relative posix paths. A quoted include resolves like cl does here:
    next to the including file first, then include/ (the /I path). Unresolved ones (SDK,
    system) are left out."""
    root = Path(root)
    dirs = ([root / "include"] + sorted((root / "modules").glob("*/src"))
            + sorted((root / "modules").glob("*/include")))
    files = [p for d in dirs if d.is_dir()
             for p in d.rglob("*") if p.suffix in (".cpp", ".c") + HEADER_EXT]
    graph = {}
    for f in files:
        deps = set()
        for name in INCLUDE_RE.findall(f.read_text(encoding="utf-8", errors="replace")):
            rel = f.resolve().relative_to(root.resolve()).parts
            mod_inc = [root / rel[0] / rel[1] / "include" / name] if rel[0] == "modules" else []
            for cand in (f.parent / name, root / "include" / name, *mod_inc):
                if cand.is_file():
                    deps.add(_rel(cand, root))
                    break
        graph[_rel(f, root)] = deps
    return graph


def sources_including(headers, graph):
    """Sources (.cpp/.c) that include any of `headers`, directly or transitively."""
    headers = set(headers)
    out = set()
    for f in graph:
        if f.endswith(HEADER_EXT):
            continue
        seen, stack = set(), [f]
        while stack:
            for d in graph.get(stack.pop(), ()):
                if d not in seen:
                    seen.add(d)
                    stack.append(d)
        if seen & headers:
            out.add(f)
    return out


def _read_rows(path):
    with open(path, newline="") as fh:
        return list(csv.DictReader(fh))


def header_regressions(rows, base_rows, changed, graph):
    """(affected sources, [(row, why)]) for sources the PR didn't edit but that include a
    changed header: each function there must still MATCH unless the base status already
    had it as something else; one the base matched that is gone now (file no longer
    defines it) counts too."""
    headers = {c for c in changed if c.endswith(HEADER_EXT)}
    affected = sources_including(headers, graph) - set(changed)
    return sorted(affected), regressions(rows, base_rows, affected, strict_unknown=True)


def regressions(rows, base_rows, sources=None, strict_unknown=False):
    """[(row, why)]: functions the base status had as MATCH that aren't now, by address
    (a function that only moved to another file is fine), including ones no file
    defines any more. sources: only judge these files (None: all). strict_unknown: a
    function the base doesn't list must MATCH too."""
    def judged(src):
        return sources is None or src in sources
    base = {r["address"]: r for r in base_rows}
    bad, seen = [], set()
    for r in rows:
        seen.add(r["address"])
        if not judged(r["source"]) or r["status"] == "MATCH":
            continue
        b = base.get(r["address"])
        if b is not None and b["status"] == "MATCH":
            bad.append((r, "was MATCH"))
        elif b is None and strict_unknown:
            bad.append((r, "not in the base status"))
    for b in base_rows:
        if judged(b["source"]) and b["status"] == "MATCH" and b["address"] not in seen:
            bad.append((dict(b, status="missing"), "was MATCH, now not built"))
    return bad


def _regression_table(regressed):
    return (["| Address | Function | Status | File | Why |", "|---|---|---|---|---|"]
            + [f"| `{r['address']}` | `{r['symbol']}` | ❌ {r['status']} | `{r['source']}` | {why} |"
               for r, why in regressed])


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--status", default=str(config.module().status_csv))
    p.add_argument("--changed", default=None)
    p.add_argument("--base-status", default=None,
                   help="progress/status.csv before the change: the PR's base (header "
                        "regressions) or, without --changed, before the push (all regressions)")
    args = p.parse_args()

    m = config.module()                     # C5D_MODULE / default exe: one module per report
    rows = _read_rows(args.status)
    counts = Counter(r["status"] for r in rows)
    out = [f"## Match results: {m.id} (fingerprint mode)", "",
           " · ".join(f"**{k}** {counts[k]}" for k in ("MATCH", "DIFF", "UNVERIFIED", "ERROR", "MATCH?")
                      if counts[k]) or "no functions", ""]

    rc = 0
    if args.changed:
        changed = {l.strip() for l in Path(args.changed).read_text().splitlines() if l.strip()}
        mine = [r for r in rows if r["source"] in changed]
        bad = [r for r in mine if r["status"] != "MATCH"]
        out += [f"### This pull request: {len(mine) - len(bad)} of {len(mine)} functions match", ""]
        if mine:
            out += ["| Address | Function | Status | File |", "|---|---|---|---|"]
            out += [f"| `{r['address']}` | `{r['symbol']}` | {'✅' if r['status'] == 'MATCH' else '❌'} "
                    f"{r['status']} | `{r['source']}` |" for r in mine]
            out.append("")
        if bad:
            out.append("Run `python tools/c5d.py match --addr <address> -v` locally to see the differences "
                       "(UNVERIFIED: a referenced function or global isn't in a symbols file yet).")
            rc = 1
        base_path = Path(args.base_status) if args.base_status else None
        base_rows = _read_rows(base_path) if base_path and base_path.is_file() else []
        # only this module's sources: another module's includers get their own report
        own = (m.rel(m.root) + "/", "include/")
        graph = {f: d for f, d in include_graph().items() if f.startswith(own)}
        affected, regressed = header_regressions(rows, base_rows, changed, graph)
        if affected:
            out += [f"### Sources including a changed header: {len(affected)} file(s), "
                    f"{len(regressed)} regression(s)", ""]
            if not base_rows:
                out += ["(no base status: every function in them has to MATCH)", ""]
            if regressed:
                out += _regression_table(regressed)
                out += ["", "A header change broke these. Keep the layout they rely on (field offsets, "
                        "member order, signatures) or fix them in the same PR.", ""]
                rc = 1
            else:
                out += ["No function that matched before stopped matching.", ""]
    else:
        # main: anything that matched before and doesn't now is a regression, whoever
        # pushed it (the commit is already in, so this turns a silent break into a red run)
        if args.base_status:
            base_path = Path(args.base_status)
            if base_path.is_file():
                regressed = regressions(rows, _read_rows(base_path))
                out += [f"### Regressions since the previous results: {len(regressed)}", ""]
                if regressed:
                    out += _regression_table(regressed)
                    out += ["", "These matched before this push. See what changed with "
                            "`python tools/c5d.py match --addr <address> -v`.", ""]
                    rc = 1
            else:
                out += ["(no previous results to compare against: regressions not checked)", ""]
        notmatch = [r for r in rows if r["status"] != "MATCH"]
        if notmatch:
            out += ["| Address | Function | Status | File |", "|---|---|---|---|"]
            out += [f"| `{r['address']}` | `{r['symbol']}` | {r['status']} | `{r['source']}` |"
                    for r in notmatch]
    sys.stdout.reconfigure(encoding="utf-8")
    print("\n".join(out))
    return rc


if __name__ == "__main__":
    sys.exit(main())
