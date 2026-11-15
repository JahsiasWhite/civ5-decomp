"""Summarise a CI match run (progress/status.csv) as Markdown for the job summary.

    python tools/ci_report.py [--changed FILE]

--changed: a list of paths a pull request touches (one per line). Then the run fails
(exit 1) if any function defined in those files isn't a MATCH, so a PR shows a red
check for work that wouldn't be credited.
"""
import argparse
import csv
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--status", default=str(ROOT / "progress" / "status.csv"))
    p.add_argument("--changed", default=None)
    args = p.parse_args()

    with open(args.status, newline="") as fh:
        rows = list(csv.DictReader(fh))
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
