"""Maintainer commands for the coordination server's database.

  python server/manage.py import    load/refresh functions from build/queue.csv
  python server/manage.py verify    apply progress/status.csv (run `c5d match` first)
  python server/manage.py token <login> [--display NAME]
                                    create/refresh an API token (e.g. for yourself)
  python server/manage.py stats     print the dashboard numbers
  python server/manage.py push [--server URL] [--token T]
                                    send progress/status.csv to the live server
                                    (your login must be in the server's C5D_ADMINS)
  python server/manage.py backup --dir DIR [--keep 14]
                                    consistent online copy of the DB (safe while serving)

The nightly routine on the maintainer's machine (which has the game) is:
  git pull  ->  python tools/c5d.py match  ->  python server/manage.py push
(`verify` does the same against a local DB, for testing.)
"""
import argparse
import csv
import json
import os
import sqlite3
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
sys.path.insert(0, str(HERE))
from db import DB  # noqa: E402


def db_path():
    return Path(os.environ.get("C5D_DB", HERE / "data" / "c5d.sqlite"))


def open_db():
    p = db_path()
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


def read_statuses(path):
    statuses = {}
    if Path(path).exists():
        with open(path, newline="") as fh:
            for r in csv.DictReader(fh):
                statuses[int(r["address"], 16)] = r["status"]
    return statuses


def cmd_verify(db, args):
    statuses = read_statuses(args.status)
    print(f"verify: {db.apply_verified(statuses)} status changes from {args.status}")


def cmd_push(_db, args):
    """Send the local match results to the live server (POST /api/admin/verify)."""
    if not Path(args.status).exists():
        raise SystemExit(f"{args.status} not found: run `python tools/c5d.py match` first")
    statuses = {f"0x{a:08x}": s for a, s in read_statuses(args.status).items()}
    sys.path.insert(0, str(ROOT / "tools"))
    from remote import Remote
    r = Remote(args.server, args.token).call("POST", "/api/admin/verify", {"statuses": statuses})
    print(f"push: server received {r['received']} statuses, {r['changed']} status changes")


def backup_db(src, dest_dir, keep=14):
    """Online backup via SQLite's backup API (consistent even with WAL and live writers).
    Writes c5d-YYYYMMDD-HHMMSS.sqlite and keeps the newest `keep` files."""
    dest_dir = Path(dest_dir)
    dest_dir.mkdir(parents=True, exist_ok=True)
    dest = dest_dir / time.strftime("c5d-%Y%m%d-%H%M%S.sqlite", time.gmtime())
    tmp = dest.with_suffix(".tmp")
    s = sqlite3.connect(f"file:{Path(src).as_posix()}?mode=ro", uri=True)
    d = sqlite3.connect(tmp)
    try:
        s.backup(d)
    finally:
        d.close()
        s.close()
    tmp.replace(dest)
    old = sorted(dest_dir.glob("c5d-*.sqlite"))[:-keep] if keep > 0 else []
    for f in old:
        f.unlink()
    return dest, len(old)


def cmd_backup(_db, args):
    dest, pruned = backup_db(db_path(), args.dir, args.keep)
    print(f"backup: {dest} ({dest.stat().st_size:,} bytes; pruned {pruned} old)")


def cmd_token(db, args):
    uid = db.upsert_user(args.login, args.display)
    db.accept_terms(uid)
    print(db.new_token(uid))


def cmd_stats(db, _args):
    s = db.stats()
    for k in ("tiers", "trend_by_model", "leaderboard"):
        s.pop(k)
    print(json.dumps(s, indent=2))


def cmd_spend(db, args):
    db.add_spend(args.day, args.source, args.dollars, args.note)
    print("added")


def cmd_milestone(db, args):
    db.add_milestone(args.day, args.text)
    print("added")


def cmd_credit(db, args):
    """Back-fill which model/tool wrote already-matched functions (and when)."""
    addrs = [int(a, 16) for a in args.addr]
    with db.tx():
        for a in addrs:
            db.conn.execute("UPDATE functions SET model=?, matched_day=COALESCE(?, matched_day) "
                            "WHERE addr=? AND status='matched'", (args.model, args.day, a))
    print(f"credited {len(addrs)} function(s) to {args.model}")


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
    pu = sub.add_parser("push", help="send progress/status.csv to the live server")
    pu.add_argument("--status", default=str(ROOT / "progress" / "status.csv"))
    pu.add_argument("--server", default=None, help="default: server in config.local.json")
    pu.add_argument("--token", default=None, help="default: token in config.local.json")
    pu.set_defaults(fn=cmd_push, no_db=True)
    b = sub.add_parser("backup", help="online copy of the DB into --dir")
    b.add_argument("--dir", required=True)
    b.add_argument("--keep", type=int, default=14)
    b.set_defaults(fn=cmd_backup, no_db=True)
    t = sub.add_parser("token")
    t.add_argument("login")
    t.add_argument("--display", default=None)
    t.set_defaults(fn=cmd_token)
    sub.add_parser("stats").set_defaults(fn=cmd_stats)
    sp = sub.add_parser("spend", help="add a cost ledger entry")
    sp.add_argument("day")
    sp.add_argument("source")
    sp.add_argument("dollars", type=float)
    sp.add_argument("--note", default="")
    sp.set_defaults(fn=cmd_spend)
    ms = sub.add_parser("milestone", help="add a milestone to the log")
    ms.add_argument("day")
    ms.add_argument("text")
    ms.set_defaults(fn=cmd_milestone)
    cr = sub.add_parser("credit", help="set the model credited for matched functions")
    cr.add_argument("model")
    cr.add_argument("addr", nargs="+")
    cr.add_argument("--day", default=None, help="matched day YYYY-MM-DD")
    cr.set_defaults(fn=cmd_credit)
    args = p.parse_args()
    args.fn(None if getattr(args, "no_db", False) else open_db(), args)


if __name__ == "__main__":
    main()
