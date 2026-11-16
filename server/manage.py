"""Maintainer commands for the coordination server's database.

  python server/manage.py import    load/refresh functions from build/queue.csv
  python server/manage.py verify    apply progress/status.csv (run `c5d match` first)
  python server/manage.py token <login> [--display NAME]
                                    create/refresh an API token (e.g. for yourself)
  python server/manage.py stats     print the dashboard numbers
  python server/manage.py milestone "text" [--day YYYY-MM-DD] [--remote]
                                    add a milestone (--remote: to the live site, admin token).
                                    Progress milestones (function counts, every 5% of bytes)
                                    are added automatically by verify.
  python server/manage.py push [--server URL] [--token T]
                                    send progress/status.csv to the live server
                                    (your login must be in the server's C5D_ADMINS)
  python server/manage.py revoke <login> [--keep-token]
                                    sign a user out of every browser (and kill their CLI token)
  python server/manage.py backup --dir DIR [--keep 14]
                                    consistent online copy of the DB (safe while serving)

The nightly routine on the maintainer's machine (which has the game) is:
  git pull  ->  python tools/c5d.py match  ->  python tools/c5d.py queue  ->  python server/manage.py push
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


def read_merges():
    """Boundary fixes from boundary_overrides.txt, resolved against data/functions.csv:
    [{"addr": int, "size": int, "absorbed": [int], "new": bool}]."""
    sys.path.insert(0, str(ROOT / "tools"))
    import config
    return [{"addr": m["entry"], "size": m["size"], "absorbed": m["absorbed"], "new": m["new"]}
            for m in config.boundary_merges()]


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
    resized, removed, _ = db.apply_merges(read_merges())   # import already added `new` ones
    if resized or removed:
        print(f"boundary fixes: {resized} resized, {removed} split-off pieces removed")
    cmd_verify(db, args)


def read_statuses(path):
    statuses = {}
    if Path(path).exists():
        with open(path, newline="") as fh:
            for r in csv.DictReader(fh):
                statuses[int(r["address"], 16)] = r["status"]
    return statuses


def source_model(path):
    """The model a source file credits with `// c5d-model: <name>` in its first 40 lines."""
    try:
        head = (ROOT / path.replace("\\", "/")).read_text(encoding="utf-8", errors="replace").splitlines()[:40]
    except OSError:
        return None
    for line in head:
        if "c5d-model:" in line:
            name = line.split("c5d-model:", 1)[1].split()
            return name[0] if name else None
    return None


def read_models(path):
    """{addr: model} for matched functions whose source file has a `c5d-model:` line
    (progress/status.csv says which file each match came from)."""
    models, cache = {}, {}
    if Path(path).exists():
        with open(path, newline="") as fh:
            for r in csv.DictReader(fh):
                if r["status"] != "MATCH" or not r.get("source"):
                    continue
                if r["source"] not in cache:
                    cache[r["source"]] = source_model(r["source"])
                if cache[r["source"]]:
                    models[int(r["address"], 16)] = cache[r["source"]]
    return models


def cmd_verify(db, args):
    statuses = read_statuses(args.status)
    print(f"verify: {db.apply_verified(statuses)} status changes from {args.status}")
    print(f"credits: {db.apply_credits(read_models(args.status))} changed from c5d-model lines")
    for text in db.check_milestones():
        print(f"milestone: {text}")


def read_ready(path):
    """{0x-addr: 0/1} from build/queue.csv (ready = no unmatched callees)."""
    with open(path, newline="") as fh:
        return {f"0x{int(r['entry'], 16):08x}": int(r["pending_callees"] == "0") for r in csv.DictReader(fh)}


def ready_from_callgraph(path, status_path):
    """{0x-addr: 0/1} from the committed call graph (data/callgraph.csv) and the match
    results: needs no game, so CI's push keeps readiness current."""
    sys.path.insert(0, str(ROOT / "tools"))
    import workqueue
    ready = workqueue.readiness(workqueue.read_callgraph(path), read_statuses(status_path))
    return {f"0x{a:08x}": int(r) for a, r in ready.items()}


def cmd_push(_db, args):
    """Send the match results, boundary fixes and which functions are now ready (all
    callees matched) to the live server (POST /api/admin/verify). Readiness comes from
    data/callgraph.csv when it exists, else from build/queue.csv."""
    if not Path(args.status).exists():
        raise SystemExit(f"{args.status} not found: run `python tools/c5d.py match` first")
    payload = {"statuses": {f"0x{a:08x}": s for a, s in read_statuses(args.status).items()},
               "merges": [{"addr": f"0x{m['addr']:08x}", "size": m["size"],
                           "absorbed": [f"0x{a:08x}" for a in m["absorbed"]], "new": m["new"]}
                          for m in read_merges()],
               "models": {f"0x{a:08x}": m for a, m in read_models(args.status).items()}}
    q, cg = Path(args.queue), Path(args.callgraph)
    if cg.exists():
        payload["ready"] = ready_from_callgraph(cg, args.status)
    elif q.exists():
        if q.stat().st_mtime < Path(args.status).stat().st_mtime:
            print(f"warning: {q} is older than {args.status}; run `python tools/c5d.py queue` "
                  "so newly unblocked functions are handed out", file=sys.stderr)
        payload["ready"] = read_ready(q)
    else:
        print(f"warning: neither {cg} nor {q} found; readiness not sent", file=sys.stderr)
    sys.path.insert(0, str(ROOT / "tools"))
    from remote import Remote
    r = Remote(args.server, args.token).call("POST", "/api/admin/verify", payload)
    print(f"push: server received {r['received']} statuses, {r['changed']} status changes, "
          f"{r.get('credited', 0)} credits, {r.get('owned', 0)} credited to you, "
          f"{r.get('ready_changed', 0)} readiness changes, {r.get('requeued', 0)} stale reports requeued, "
          f"{r.get('resized', 0)} resized / {r.get('merged_away', 0)} removed / "
          f"{r.get('added', 0)} added by boundary fixes")
    for text in r.get("milestones", []):
        print(f"push: new milestone: {text}")


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


def cmd_revoke(db, args):
    u = db.one("SELECT id FROM users WHERE login=?", (args.login,))
    if not u:
        raise SystemExit(f"no user {args.login!r}")
    db.revoke_sessions(u["id"], token=not args.keep_token)
    print(f"revoked sessions{'' if args.keep_token else ' and API token'} for {args.login}")


def cmd_stats(db, _args):
    s = db.stats()
    for k in ("tiers", "trend_by_model", "leaderboard"):
        s.pop(k)
    print(json.dumps(s, indent=2))


def cmd_spend(db, args):
    db.add_spend(args.day, args.source, args.dollars, args.note)
    print("added")


def cmd_milestone(_db, args):
    """Add a milestone: to the live server with --remote (admin token), else the local DB."""
    if args.remote:
        sys.path.insert(0, str(ROOT / "tools"))
        from remote import Remote
        r = Remote(args.server, args.token).call("POST", "/api/admin/milestone",
                                                 {"day": args.day, "text": args.text})
        print(f"added to the live log: {r['day']} {r['text']}")
        return
    open_db().add_milestone(args.day or time.strftime("%Y-%m-%d", time.gmtime()), args.text)
    print("added to the local DB (use --remote for the live site)")


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
    pu.add_argument("--queue", default=str(ROOT / "build" / "queue.csv"),
                    help="readiness from here when there is no call graph")
    pu.add_argument("--callgraph", default=str(ROOT / "data" / "callgraph.csv"))
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
    rv = sub.add_parser("revoke", help="sign a user out everywhere")
    rv.add_argument("login")
    rv.add_argument("--keep-token", action="store_true", help="leave their CLI token working")
    rv.set_defaults(fn=cmd_revoke)
    sub.add_parser("stats").set_defaults(fn=cmd_stats)
    sp = sub.add_parser("spend", help="add a cost ledger entry")
    sp.add_argument("day")
    sp.add_argument("source")
    sp.add_argument("dollars", type=float)
    sp.add_argument("--note", default="")
    sp.set_defaults(fn=cmd_spend)
    ms = sub.add_parser("milestone", help="add a milestone to the log (--remote: the live site)")
    ms.add_argument("text")
    ms.add_argument("--day", default=None, help="YYYY-MM-DD (UTC); default today")
    ms.add_argument("--remote", action="store_true", help="send to the live server (admin token)")
    ms.add_argument("--server", default=None, help="default: server in config.local.json")
    ms.add_argument("--token", default=None, help="default: token in config.local.json")
    ms.set_defaults(fn=cmd_milestone, no_db=True)
    cr = sub.add_parser("credit", help="set the model credited for matched functions")
    cr.add_argument("model")
    cr.add_argument("addr", nargs="+")
    cr.add_argument("--day", default=None, help="matched day YYYY-MM-DD")
    cr.set_defaults(fn=cmd_credit)
    args = p.parse_args()
    args.fn(None if getattr(args, "no_db", False) else open_db(), args)


if __name__ == "__main__":
    main()
