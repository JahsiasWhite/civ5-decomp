"""Decide how much of src/ a pull request's verify run has to build.

    python tools/ci_plan.py --base <sha> [--head HEAD] [--around-out FILE]

Prints `mode=full` or `mode=partial` (append it to $GITHUB_OUTPUT). For a partial run
it writes the sources to start from to --around-out, for `c5d match --around-from`.

ci_report judges a pull request on two sets of functions: the ones in the sources it
changed, and the ones in sources that include a header it changed. A partial run
starts from exactly those sources, and `match --around` adds every file connected to
them through game symbols (callers and callees, see c5d.connected_files), so those
functions come out of the link the same as in a full build. Files outside that set
aren't judged on a pull request either way. main always runs everything.

Full run whenever the inputs aren't only sources, headers and symbol files:
- tools/, data/, config.json, .github/ or anything else outside those changed
- a source or header was deleted, renamed or copied (its functions' old rows would
  need a full status to judge)
- nothing to start from (e.g. only a symbols file changed)
"""
import argparse
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import ci_report  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
SOURCE_EXT = (".cpp", ".c")
# changed paths that don't force a full run (anything else does)
PARTIAL_OK = ("src/", "include/", "symbols/")
PARTIAL_OK_FILES = {"symbols.txt"}
IGNORED_EXT = (".md",)


def changes(base, head="HEAD", root=ROOT):
    """[(status letter, path)] from `git diff --name-status base head`. A rename or
    copy is listed under its old path and its new one."""
    out = subprocess.run(["git", "diff", "--name-status", "-M", base, head],
                         cwd=root, capture_output=True, text=True, check=True).stdout
    rows = []
    for line in out.splitlines():
        parts = line.split("\t")
        if len(parts) < 2:
            continue
        status = parts[0][0]
        rows += [(status, p) for p in parts[1:]]
    return rows


def plan(rows, graph):
    """("full", reason) or ("partial", sorted sources to start from)."""
    changed = set()
    for status, path in rows:
        if path.endswith(IGNORED_EXT):
            continue
        if not (path.startswith(PARTIAL_OK) or path in PARTIAL_OK_FILES):
            return "full", f"{path} changed"
        if path.startswith(("src/", "include/")) and status not in ("M", "A"):
            return "full", f"{path} deleted, renamed or copied"
        changed.add(path)
    headers = {p for p in changed if p.endswith(ci_report.HEADER_EXT)}
    seeds = {p for p in changed if p.startswith("src/") and p.endswith(SOURCE_EXT)}
    seeds |= ci_report.sources_including(headers, graph)
    if not seeds:
        return "full", "no changed sources or headers to start from"
    return "partial", sorted(seeds)


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--base", required=True)
    p.add_argument("--head", default="HEAD")
    p.add_argument("--around-out", default=str(ROOT / "build" / "around.txt"))
    args = p.parse_args()
    mode, detail = plan(changes(args.base, args.head), ci_report.include_graph())
    if mode == "partial":
        out = Path(args.around_out)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text("\n".join(detail) + "\n")
        print(f"partial run from {len(detail)} source(s):", *detail, sep="\n  ", file=sys.stderr)
    else:
        print(f"full run: {detail}", file=sys.stderr)
    print(f"mode={mode}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
