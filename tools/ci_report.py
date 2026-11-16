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
"""
import argparse
import csv
import re
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
INCLUDE_RE = re.compile(r'^\s*#\s*include\s*"([^"]+)"', re.M)
HEADER_EXT = (".h", ".hpp", ".inl")


def _rel(p, root):
    return p.resolve().relative_to(root.resolve()).as_posix()


def include_graph(root=ROOT):
    """{file: {files it #includes "..."}} over src/ and include/, as repo-relative posix
    paths. A quoted include resolves like cl does here: next to the including file
    first, then include/ (the /I path). Unresolved ones (SDK, system) are left out."""
    root = Path(root)
    files = [p for d in ("src", "include") if (root / d).is_dir()
             for p in (root / d).rglob("*") if p.suffix in (".cpp", ".c") + HEADER_EXT]
    graph = {}
    for f in files:
        deps = set()
        for name in INCLUDE_RE.findall(f.read_text(encoding="utf-8", errors="replace")):
            for cand in (f.parent / name, root / "include" / name):
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
    base = {r["address"]: r for r in base_rows}
    bad, seen = [], set()
    for r in rows:
        if r["source"] not in affected:
            continue
        seen.add(r["address"])
        b = base.get(r["address"])
        if r["status"] != "MATCH" and (b is None or b["status"] == "MATCH"):
            bad.append((r, "was MATCH" if b else "not in the base status"))
    for b in base_rows:
        if b["source"] in affected and b["status"] == "MATCH" and b["address"] not in seen:
            bad.append((dict(b, status="missing"), "was MATCH, now not built"))
    return sorted(affected), bad


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--status", default=str(ROOT / "progress" / "status.csv"))
    p.add_argument("--changed", default=None)
    p.add_argument("--base-status", default=None,
                   help="the base branch's progress/status.csv (for header regressions)")
    args = p.parse_args()

    rows = _read_rows(args.status)
    counts = Counter(r["status"] for r in rows)
    out = ["## Match results (fingerprint mode)", "",
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
        affected, regressed = header_regressions(rows, base_rows, changed, include_graph())
        if affected:
            out += [f"### Sources including a changed header: {len(affected)} file(s), "
                    f"{len(regressed)} regression(s)", ""]
            if not base_rows:
                out += ["(no base status: every function in them has to MATCH)", ""]
            if regressed:
                out += ["| Address | Function | Status | File | Why |", "|---|---|---|---|---|"]
                out += [f"| `{r['address']}` | `{r['symbol']}` | ❌ {r['status']} | `{r['source']}` | {why} |"
                        for r, why in regressed]
                out += ["", "A header change broke these. Keep the layout they rely on (field offsets, "
                        "member order, signatures) or fix them in the same PR.", ""]
                rc = 1
            else:
                out += ["No function that matched before stopped matching.", ""]
    else:
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
