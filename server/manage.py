"""Maintainer commands for the coordination server's database.

  python server/manage.py import    load/refresh functions from build/queue.csv
  python server/manage.py verify    apply progress/status.csv (run `c5d match` first)
  python server/manage.py token <login> [--display NAME]
                                    create/refresh an API token (e.g. for yourself)
  python server/manage.py stats     print the dashboard numbers

The nightly routine on the maintainer's machine (which has the game) is:
  git pull  ->  python tools/c5d.py match  ->  python server/manage.py verify
"""
import argparse
import csv
import json
import os
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
sys.path.insert(0, str(HERE))
from db import DB  # noqa: E402


def open_db():
    p = Path(os.environ.get("C5D_DB", HERE / "data" / "c5d.sqlite"))
    p.parent.mkdir(parents=True, exist_ok=True)
    return DB(p)


def cmd_import(db, args):
    rows = []
    with open(args.queue, newline="") as fh:
        for i, r in enumerate(csv.DictReader(fh)):
            rows.append({"addr": int(r["entry"], 16), "size": int(r["size"]), "name": r["name"],
                         "conv": r["conv"], "depth": int(r["depth"]),
                         "cluster": int(r["cluster"], 16), "ready": int(r["pending_callees"] == "0"),
                         "queue_pos": i})
    db.import_functions(rows)
    print(f"imported {len(rows)} functions")
    cmd_verify(db, args)


def cmd_verify(db, args):
    statuses = {}
    if Path(args.status).exists():
        with open(args.status, newline="") as fh:
            for r in csv.DictReader(fh):
                statuses[int(r["address"], 16)] = r["status"]
    print(f"verify: {db.apply_verified(statuses)} status changes from {args.status}")


def cmd_token(db, args):
    uid = db.upsert_user(args.login, args.display)
    db.accept_terms(uid)
    print(db.new_token(uid))


def cmd_stats(db, _args):
    s = db.stats()
    s.pop("recent")
    print(json.dumps(s, indent=2))


def main():
    p = argparse.ArgumentParser()
    sub = p.add_subparsers(dest="cmd", required=True)
    i = sub.add_parser("import")
    i.add_argument("--queue", default=str(ROOT / "build" / "queue.csv"))
    i.add_argument("--status", default=str(ROOT / "progress" / "status.csv"))
    i.set_defaults(fn=cmd_import)
    v = sub.add_parser("verify")
    v.add_argument("--status", default=str(ROOT / "progress" / "status.csv"))
    v.set_defaults(fn=cmd_verify)
    t = sub.add_parser("token")
    t.add_argument("login")
    t.add_argument("--display", default=None)
    t.set_defaults(fn=cmd_token)
    sub.add_parser("stats").set_defaults(fn=cmd_stats)
    args = p.parse_args()
    args.fn(open_db(), args)


if __name__ == "__main__":
    main()
