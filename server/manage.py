"""Maintainer commands for the coordination server's database.

  python server/manage.py import    load/refresh functions from build/<module>/queue.csv
  python server/manage.py verify    apply modules/<module>/progress/status.csv (run `c5d match` first)
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
  python server/manage.py switch-build --map modules/exe/legacy/2014/addrmap.csv
                                    [--queue build/exe/queue.csv] [--backup-dir DIR]
                                    one-off: move the exe to the 2026 build. Backs up first,
                                    then the 2014 rows become the view-only exe-2014 module
                                    and the 2026 queue is imported as exe, matches carrying
                                    their credit over to their 2026 twins.

The verify workflow (.github/workflows/verify.yml) pushes results on every push to main and
twice a day. To do it by hand from a machine with the game:
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
from db import DB, DEFAULT_MODULE, LEGACY, MODULES, legacy_of  # noqa: E402


def db_path():
    return Path(os.environ.get("C5D_DB", HERE / "data" / "c5d.sqlite"))


def open_db():
    p = db_path()
    p.parent.mkdir(parents=True, exist_ok=True)
    return DB(p)


def tool_module(module):
    """The tools' config.Module for a server module id. A legacy one (exe-2014) is its
    binary's legacy build: data, boundary fixes and results under modules/exe/legacy/2014/."""
    sys.path.insert(0, str(ROOT / "tools"))
    import config
    mid, build = LEGACY.get(module, (module, None))
    spec = json.loads(config.SHARED.read_text())["modules"][mid]
    return config.Module(mid, spec, build)


def read_merges(module="exe"):
    """Boundary fixes from modules/<module>/boundary_overrides.txt, resolved against that
    module's data/functions.csv: [{"addr": int, "size": int, "absorbed": [int], "new": bool}]."""
    sys.path.insert(0, str(ROOT / "tools"))
    import config
    m = tool_module(module)
    fcsv = m.data / "functions.csv"
    rows = config._read_function_rows(fcsv if fcsv.exists() else m.build / "functions.csv")
    overrides = config.read_boundary_overrides(m.boundary_overrides)
    return [{"addr": x["entry"], "size": x["size"], "absorbed": x["absorbed"], "new": x["new"]}
            for x in config.boundary_merges(rows, overrides)]


def read_queue(path):
    """build/<module>/queue.csv -> rows for import_functions."""
    rows = []
    with open(path, newline="") as fh:
        for i, r in enumerate(csv.DictReader(fh)):
            rows.append({"addr": int(r["entry"], 16), "size": int(r["size"]), "name": r["name"],
                         "conv": r["conv"], "depth": int(r["depth"]),
                         "cluster": int(r["cluster"], 16), "ready": int(r["pending_callees"] == "0"),
                         "queue_pos": i})
    return rows


def cmd_import(db, args):
    module = getattr(args, "module", "exe")
    rows = read_queue(args.queue)
    db.import_functions(rows, module=module)
    print(f"imported {len(rows)} {module} functions")
    resized, removed, _ = db.apply_merges(read_merges(module), module=module)   # import added `new` ones
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
    module = getattr(args, "module", "exe")
    statuses, m = read_statuses(args.status), module
    print(f"claims: {db.credit_claims(statuses, module=m)} closed (matched while claimed)")
    print(f"verify: {db.apply_verified(statuses, module=m)} {m} status changes from {args.status}")
    print(f"credits: {db.apply_credits(read_models(args.status), module=m)} changed from c5d-model lines")
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


def module_payload(module, status, queue, callgraph, qualify=False):
    """One module's part of a push: statuses, merges, models and (when known) ready. With
    `qualify`, keys of modules other than the exe are written "db:0x..." so several
    modules can share one payload."""
    if not Path(status).exists():
        raise SystemExit(f"{status} not found: run `python tools/c5d.py match` first")
    pre = f"{module}:" if qualify and module != "exe" else ""

    def key(k):                                     # "0x..." -> "db:0x..." when qualifying
        return pre + k

    part = {"statuses": {key(f"0x{a:08x}"): s for a, s in read_statuses(status).items()},
            "merges": [{"addr": key(f"0x{m['addr']:08x}"), "size": m["size"],
                        "absorbed": [key(f"0x{a:08x}") for a in m["absorbed"]], "new": m["new"]}
                       for m in read_merges(module)],
            "models": {key(f"0x{a:08x}"): m for a, m in read_models(status).items()}}
    q, cg = Path(queue), Path(callgraph)
    if module in LEGACY:
        pass                                        # view-only: nothing is handed out
    elif cg.exists():
        part["ready"] = {key(k): v for k, v in ready_from_callgraph(cg, status).items()}
    elif q.exists():
        if q.stat().st_mtime < Path(status).stat().st_mtime:
            print(f"warning: {q} is older than {status}; run `python tools/c5d.py queue` "
                  "so newly unblocked functions are handed out", file=sys.stderr)
        part["ready"] = {key(k): v for k, v in read_ready(q).items()}
    else:
        print(f"warning: neither {cg} nor {q} found; {module} readiness not sent", file=sys.stderr)
    return part


def module_build(module):
    """The build a push's results are for (the server refuses a mismatch): the exe's
    build_id from config.json ("2026"), a legacy module's own build ("2014"); none for
    the DLLs."""
    if module in LEGACY:
        return LEGACY[module][1]
    try:
        return tool_module(module).build_id or None
    except (KeyError, OSError, ValueError):
        return None


def cmd_push(_db, args):
    """Send the match results, boundary fixes and which functions are now ready (all
    callees matched) to the live server (POST /api/admin/verify). Readiness comes from
    data/callgraph.csv when it exists, else from build/queue.csv.

    --modules exe,db,loc sends several modules in one push (one verify run on the
    server); each module's status file is --status-pattern with {module} filled in."""
    if getattr(args, "modules", None):
        payload = {"module": "exe", "statuses": {}, "merges": [], "models": {}, "build": {}}
        for mid in [m.strip() for m in args.modules.split(",") if m.strip()]:
            if mid not in MODULES:
                raise SystemExit(f"unknown module {mid!r} (one of: {', '.join(MODULES)})")
            m = tool_module(mid)
            part = module_payload(mid, args.status_pattern.format(module=mid), m.build / "queue.csv",
                                  m.data / "callgraph.csv", qualify=True)
            payload["statuses"].update(part["statuses"])
            payload["merges"] += part["merges"]
            payload["models"].update(part["models"])
            if "ready" in part:
                payload.setdefault("ready", {}).update(part["ready"])
            if module_build(mid):
                payload["build"][mid] = module_build(mid)
    else:
        module = getattr(args, "module", "exe")
        payload = {"module": module, **module_payload(module, args.status, args.queue, args.callgraph)}
        if module_build(module):
            payload["build"] = {module: module_build(module)}
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


def read_addrmap(path):
    """({new addr: old addr}, {new addrs whose code is the same}) for the functions in an
    address map (modules/exe/legacy/2014/addrmap.csv: kind,addr_2026,addr_2014[,same];
    kind is func or data, addresses 0x%08x). same=1: identical code, confirmed by a real
    match; same=0: placed by its callers, the code changed. Without the column every pair
    counts as the same. Data rows are skipped; a function paired twice is an error."""
    twins, olds, same = {}, set(), set()
    with open(path, newline="") as fh:
        rd = csv.DictReader(fh)
        need = {"kind", "addr_2026", "addr_2014"}
        if not need <= set(rd.fieldnames or ()):
            raise SystemExit(f"{path}: header must be kind,addr_2026,addr_2014")
        for n, r in enumerate(rd, 2):
            if r["kind"].strip() != "func":
                continue
            try:
                new, old = int(r["addr_2026"], 16), int(r["addr_2014"], 16)
            except ValueError:
                raise SystemExit(f"{path}:{n}: bad address")
            if new in twins or old in olds:
                raise SystemExit(f"{path}:{n}: function paired twice (0x{new:08x} / 0x{old:08x})")
            twins[new] = old
            olds.add(old)
            if (r.get("same") or "1").strip() != "0":
                same.add(new)
    return twins, same


def cmd_switch_build(_db, args):
    """Move the exe to another build (2026): see DB.switch_build. Backs up the DB first
    (refuses to go on without the copy), then does the whole move in one transaction."""
    legacy = legacy_of(DEFAULT_MODULE, args.from_build)
    if not legacy:
        raise SystemExit(f"no legacy module for the {args.from_build} exe build")
    twins, same = read_addrmap(args.map)
    rows = read_queue(args.queue)
    if not rows:
        raise SystemExit(f"{args.queue} has no functions")
    if db_path().exists():
        dest, _ = backup_db(db_path(), args.backup_dir, args.keep)
        print(f"backup: {dest}")
    db = open_db()
    try:
        moved, imported, twinned, credited = db.switch_build(args.build, legacy, rows, twins, same)
    except ValueError as e:
        raise SystemExit(f"switch-build: {e}")
    print(f"switch-build: {moved} exe functions are now {legacy} (view-only); "
          f"imported {imported} {args.build} exe functions")
    print(f"switch-build: {twinned} have a {args.from_build} twin ({len(twins) - len(same)} of the map's "
          f"with changed code), {credited} matches carried over (by_user, model, day); they show as "
          f"matched once verify confirms them")
    unknown = len(twins) - twinned
    if unknown:
        print(f"warning: {unknown} address map functions aren't in {args.queue}", file=sys.stderr)


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
    for v in (s, *s["views"].values()):
        for k in ("tiers", "trend_by_model", "leaderboard", "trend", "squad"):
            v.pop(k, None)
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
    module = getattr(args, "module", "exe")
    addrs = [int(a, 16) for a in args.addr]
    with db.tx():
        for a in addrs:
            db.conn.execute("UPDATE functions SET model=?, matched_day=COALESCE(?, matched_day) "
                            "WHERE module=? AND addr=? AND status='matched'",
                            (args.model, args.day, module, a))
    print(f"credited {len(addrs)} function(s) to {args.model}")


def main():
    p = argparse.ArgumentParser()
    sub = p.add_subparsers(dest="cmd", required=True)
    i = sub.add_parser("import")
    i.add_argument("--queue", default=None, help="default: build/<module>/queue.csv")
    i.add_argument("--status", default=None, help="default: modules/<module>/progress/status.csv")
    i.set_defaults(fn=cmd_import)
    v = sub.add_parser("verify")
    v.add_argument("--status", default=None, help="default: modules/<module>/progress/status.csv")
    v.set_defaults(fn=cmd_verify)
    pu = sub.add_parser("push", help="send a module's progress/status.csv to the live server")
    pu.add_argument("--status", default=None, help="default: modules/<module>/progress/status.csv")
    pu.add_argument("--queue", default=None,
                    help="readiness from here when there is no call graph (default: build/<module>/queue.csv)")
    pu.add_argument("--callgraph", default=None, help="default: modules/<module>/data/callgraph.csv")
    pu.add_argument("--server", default=None, help="default: server in config.local.json")
    pu.add_argument("--token", default=None, help="default: token in config.local.json")
    pu.add_argument("--modules", default=None,
                    help="comma-separated modules to send together in one push (instead of --module)")
    pu.add_argument("--status-pattern", default="modules/{module}/progress/status.csv",
                    help="with --modules: each module's status file ({module} is filled in)")
    pu.set_defaults(fn=cmd_push, no_db=True)
    b = sub.add_parser("backup", help="online copy of the DB into --dir")
    b.add_argument("--dir", required=True)
    b.add_argument("--keep", type=int, default=14)
    b.set_defaults(fn=cmd_backup, no_db=True)
    sw = sub.add_parser("switch-build", help="one-off: move the exe to the 2026 build (backs up first)")
    sw.add_argument("--map", required=True, help="address map CSV: kind,addr_2026,addr_2014")
    sw.add_argument("--queue", default=str(ROOT / "build" / "exe" / "queue.csv"),
                    help="the new build's queue (default: build/exe/queue.csv)")
    sw.add_argument("--build", default="2026", help="the exe build to move to (default 2026)")
    sw.add_argument("--from-build", default="2014", help="the build the exe is on now (default 2014)")
    sw.add_argument("--backup-dir", default=str(db_path().parent / "backups"),
                    help="where the backup goes (default: backups/ beside the DB)")
    sw.add_argument("--keep", type=int, default=14)
    sw.set_defaults(fn=cmd_switch_build, no_db=True)
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
    for sp_ in (i, v, pu, cr):
        sp_.add_argument("--module", default="exe", choices=list(MODULES),
                         help="which binary these functions belong to (default: exe)")
    args = p.parse_args()
    if hasattr(args, "module"):                     # file defaults follow the module
        m = tool_module(args.module)
        for key, path in (("status", m.status_csv), ("queue", m.build / "queue.csv"),
                          ("callgraph", m.data / "callgraph.csv")):
            if getattr(args, key, "unset") is None:
                setattr(args, key, str(path))
    args.fn(None if getattr(args, "no_db", False) else open_db(), args)


if __name__ == "__main__":
    main()
