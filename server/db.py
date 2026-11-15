"""SQLite data layer for the civ5-decomp coordination server.

The server never stores game bytes: only addresses, sizes, names, statuses,
claims and contributor activity.

Status lifecycle of a function:
  todo -> (claimed) -> reported (contributor says MATCH, awaiting verify)
       -> matched (maintainer's verify run confirmed it)
  todo/reported can also become 'diff' (attempted, not matching).
"""
import hashlib
import secrets
import sqlite3
import threading
import time

SCHEMA = """
CREATE TABLE IF NOT EXISTS functions (
    addr        INTEGER PRIMARY KEY,
    size        INTEGER NOT NULL,
    name        TEXT NOT NULL DEFAULT '',
    conv        TEXT NOT NULL DEFAULT '',
    depth       INTEGER NOT NULL DEFAULT 0,
    cluster     INTEGER NOT NULL DEFAULT 0,
    ready       INTEGER NOT NULL DEFAULT 0,       -- 1: all callees done
    queue_pos   INTEGER NOT NULL DEFAULT 0,
    status      TEXT NOT NULL DEFAULT 'todo',     -- todo|reported|matched|diff
    by_user     INTEGER,
    updated     REAL
);
CREATE INDEX IF NOT EXISTS ix_functions_queue ON functions(status, ready, queue_pos);

CREATE TABLE IF NOT EXISTS users (
    id          INTEGER PRIMARY KEY,
    login       TEXT UNIQUE NOT NULL,             -- GitHub login (or dev name)
    display     TEXT NOT NULL DEFAULT '',         -- shown on the leaderboard ('' = anonymous)
    token_hash  TEXT UNIQUE,
    accepted_terms REAL,
    created     REAL NOT NULL
);

CREATE TABLE IF NOT EXISTS claims (
    addr        INTEGER PRIMARY KEY REFERENCES functions(addr),
    user_id     INTEGER NOT NULL REFERENCES users(id),
    worker      TEXT NOT NULL DEFAULT '',
    claimed     REAL NOT NULL,
    expires     REAL NOT NULL
);

CREATE TABLE IF NOT EXISTS events (
    id          INTEGER PRIMARY KEY,
    ts          REAL NOT NULL,
    user_id     INTEGER,
    addr        INTEGER,
    kind        TEXT NOT NULL,                    -- claim|release|report|verify|expire
    status      TEXT NOT NULL DEFAULT '',
    detail      TEXT NOT NULL DEFAULT ''
);
CREATE INDEX IF NOT EXISTS ix_events_ts ON events(ts);

CREATE TABLE IF NOT EXISTS daily (
    day         TEXT PRIMARY KEY,                 -- YYYY-MM-DD
    matched     INTEGER NOT NULL,
    matched_bytes INTEGER NOT NULL
);
"""

CLAIM_SECONDS = 4 * 3600          # a claim lapses if not reported within 4 h
MAX_ACTIVE_CLAIMS = 25            # per user


def hash_token(token):
    return hashlib.sha256(token.encode()).hexdigest()


class DB:
    def __init__(self, path):
        self.path = str(path)
        self.lock = threading.Lock()
        self.conn = sqlite3.connect(self.path, check_same_thread=False, isolation_level=None)
        self.conn.row_factory = sqlite3.Row
        self.conn.execute("PRAGMA journal_mode=WAL")
        self.conn.execute("PRAGMA foreign_keys=ON")
        self.conn.executescript(SCHEMA)

    # ------------------------------------------------------------ helpers
    def q(self, sql, args=()):
        return self.conn.execute(sql, args).fetchall()

    def one(self, sql, args=()):
        return self.conn.execute(sql, args).fetchone()

    def tx(self):
        """Serialise write transactions (sqlite + threads)."""
        db = self

        class _Tx:
            def __enter__(self):
                db.lock.acquire()
                db.conn.execute("BEGIN IMMEDIATE")
                return db

            def __exit__(self, exc_type, *_):
                try:
                    db.conn.execute("ROLLBACK" if exc_type else "COMMIT")
                finally:
                    db.lock.release()
        return _Tx()

    def log(self, kind, user_id=None, addr=None, status="", detail=""):
        self.conn.execute("INSERT INTO events(ts,user_id,addr,kind,status,detail) VALUES (?,?,?,?,?,?)",
                          (time.time(), user_id, addr, kind, status, detail))

    # ------------------------------------------------------------ users
    def upsert_user(self, login, display=None):
        with self.tx():
            row = self.one("SELECT * FROM users WHERE login=?", (login,))
            if row:
                return row["id"]
            cur = self.conn.execute("INSERT INTO users(login,display,created) VALUES (?,?,?)",
                                    (login, login if display is None else display, time.time()))
            return cur.lastrowid

    def new_token(self, user_id):
        token = "c5d_" + secrets.token_urlsafe(32)
        with self.tx():
            self.conn.execute("UPDATE users SET token_hash=? WHERE id=?", (hash_token(token), user_id))
        return token

    def user_by_token(self, token):
        if not token:
            return None
        return self.one("SELECT * FROM users WHERE token_hash=?", (hash_token(token),))

    def accept_terms(self, user_id):
        with self.tx():
            self.conn.execute("UPDATE users SET accepted_terms=? WHERE id=?", (time.time(), user_id))

    def set_display(self, user_id, display):
        with self.tx():
            self.conn.execute("UPDATE users SET display=? WHERE id=?", (display, user_id))

    # ------------------------------------------------------------ claims
    def expire_claims(self):
        now = time.time()
        with self.tx():
            for r in self.q("SELECT addr,user_id FROM claims WHERE expires<?", (now,)):
                self.log("expire", r["user_id"], r["addr"])
            self.conn.execute("DELETE FROM claims WHERE expires<?", (now,))

    def claim(self, user_id, n=1, addr=None, worker_prefix="w", min_size=0, max_size=None):
        """Claim specific `addr`, or the next `n` ready functions in queue order.
        Returns list of (addr, worker)."""
        self.expire_claims()
        now = time.time()
        with self.tx():
            active = self.one("SELECT COUNT(*) c FROM claims WHERE user_id=?", (user_id,))["c"]
            room = max(0, MAX_ACTIVE_CLAIMS - active)
            if room == 0:
                raise ValueError(f"you already hold {active} claims (limit {MAX_ACTIVE_CLAIMS})")
            if addr is not None:
                f = self.one("SELECT status FROM functions WHERE addr=?", (addr,))
                if not f:
                    raise LookupError("unknown or out-of-scope function")
                if f["status"] == "matched":
                    raise ValueError("already matched")
                if self.one("SELECT 1 FROM claims WHERE addr=?", (addr,)):
                    raise ValueError("already claimed by someone else")
                picks = [addr]
            else:
                sql = ("SELECT addr FROM functions f WHERE status IN ('todo','diff') AND ready=1 "
                       "AND size>=? AND (? IS NULL OR size<=?) "
                       "AND NOT EXISTS (SELECT 1 FROM claims c WHERE c.addr=f.addr) "
                       "ORDER BY queue_pos LIMIT ?")
                picks = [r["addr"] for r in self.q(sql, (min_size, max_size, max_size, min(n, room)))]
            out = []
            for i, a in enumerate(picks):
                worker = f"{worker_prefix}{i + 1}"
                self.conn.execute("INSERT INTO claims(addr,user_id,worker,claimed,expires) VALUES (?,?,?,?,?)",
                                  (a, user_id, worker, now, now + CLAIM_SECONDS))
                self.log("claim", user_id, a)
                out.append((a, worker))
            return out

    def release(self, user_id, addr):
        with self.tx():
            cur = self.conn.execute("DELETE FROM claims WHERE addr=? AND user_id=?", (addr, user_id))
            if cur.rowcount:
                self.log("release", user_id, addr)
            return cur.rowcount > 0

    def my_claims(self, user_id):
        return [dict(r) for r in self.q(
            "SELECT c.addr,c.worker,c.claimed,c.expires,f.size,f.name FROM claims c "
            "JOIN functions f ON f.addr=c.addr WHERE c.user_id=? ORDER BY c.claimed", (user_id,))]

    # ------------------------------------------------------------ results
    def report(self, user_id, addr, status, detail=""):
        """Contributor reports a local result. MATCH becomes 'reported' until verified."""
        status = status.upper()
        if status not in ("MATCH", "DIFF"):
            raise ValueError("status must be MATCH or DIFF")
        with self.tx():
            claim = self.one("SELECT user_id FROM claims WHERE addr=?", (addr,))
            if not claim or claim["user_id"] != user_id:
                raise PermissionError("you don't hold a claim on this function")
            f = self.one("SELECT status FROM functions WHERE addr=?", (addr,))
            if f["status"] != "matched":
                new = "reported" if status == "MATCH" else "diff"
                self.conn.execute("UPDATE functions SET status=?, by_user=?, updated=? WHERE addr=?",
                                  (new, user_id if new == "reported" else None, time.time(), addr))
            self.conn.execute("DELETE FROM claims WHERE addr=?", (addr,))
            self.log("report", user_id, addr, status, detail[:500])

    def apply_verified(self, statuses):
        """Maintainer verify: {addr: 'MATCH'|'DIFF'|...} from a full local match run."""
        changed = 0
        with self.tx():
            for addr, st in statuses.items():
                f = self.one("SELECT status, by_user FROM functions WHERE addr=?", (addr,))
                if not f:
                    continue
                new = "matched" if st == "MATCH" else ("diff" if st in ("DIFF", "MATCH?") else f["status"])
                if new == "matched" and f["status"] != "matched":
                    self.conn.execute("UPDATE functions SET status='matched', updated=? WHERE addr=?",
                                      (time.time(), addr))
                    self.log("verify", f["by_user"], addr, "MATCH")
                    changed += 1
                elif new == "diff" and f["status"] == "reported":
                    self.conn.execute("UPDATE functions SET status='diff', updated=? WHERE addr=?",
                                      (time.time(), addr))
                    self.log("verify", f["by_user"], addr, "DIFF", "reported match failed verification")
                    changed += 1
            day = time.strftime("%Y-%m-%d")
            m = self.one("SELECT COUNT(*) c, COALESCE(SUM(size),0) b FROM functions WHERE status='matched'")
            self.conn.execute("INSERT OR REPLACE INTO daily(day,matched,matched_bytes) VALUES (?,?,?)",
                              (day, m["c"], m["b"]))
        return changed

    # ------------------------------------------------------------ import
    def import_functions(self, rows):
        """rows: dicts with addr,size,name,conv,depth,cluster,ready,queue_pos.
        Keeps existing status/claims; adds new functions; refreshes queue info."""
        with self.tx():
            for r in rows:
                self.conn.execute(
                    "INSERT INTO functions(addr,size,name,conv,depth,cluster,ready,queue_pos) "
                    "VALUES (:addr,:size,:name,:conv,:depth,:cluster,:ready,:queue_pos) "
                    "ON CONFLICT(addr) DO UPDATE SET size=excluded.size, name=excluded.name, "
                    "conv=excluded.conv, depth=excluded.depth, cluster=excluded.cluster, "
                    "ready=excluded.ready, queue_pos=excluded.queue_pos", r)

    # ------------------------------------------------------------ stats
    def stats(self):
        tot = self.one("SELECT COUNT(*) c, COALESCE(SUM(size),0) b FROM functions")
        by = {r["status"]: (r["c"], r["b"]) for r in self.q(
            "SELECT status, COUNT(*) c, COALESCE(SUM(size),0) b FROM functions GROUP BY status")}
        claimed = self.one("SELECT COUNT(*) c FROM claims")["c"]
        buckets = []
        for lo, hi, label in [(0, 64, "< 64 B"), (64, 256, "64–255 B"), (256, 1024, "256 B–1 KB"),
                              (1024, 4096, "1–4 KB"), (4096, 10 ** 9, "≥ 4 KB")]:
            r = self.one("SELECT COUNT(*) c, SUM(status='matched') m FROM functions WHERE size>=? AND size<?",
                         (lo, hi))
            buckets.append({"label": label, "total": r["c"], "matched": r["m"] or 0})
        board = [dict(r) for r in self.q(
            "SELECT CASE WHEN u.display='' THEN 'anonymous' ELSE u.display END who, "
            "COUNT(*) functions, SUM(f.size) bytes FROM functions f JOIN users u ON u.id=f.by_user "
            "WHERE f.status='matched' GROUP BY u.id ORDER BY bytes DESC LIMIT 25")]
        recent = [dict(r) for r in self.q(
            "SELECT e.ts, e.addr, e.status, f.name, f.size, "
            "CASE WHEN u.display='' OR u.display IS NULL THEN 'anonymous' ELSE u.display END who "
            "FROM events e JOIN functions f ON f.addr=e.addr LEFT JOIN users u ON u.id=e.user_id "
            "WHERE e.kind='verify' AND e.status='MATCH' ORDER BY e.ts DESC LIMIT 20")]
        trend = [dict(r) for r in self.q("SELECT day, matched, matched_bytes FROM daily ORDER BY day")]
        return {
            "functions": tot["c"], "bytes": tot["b"],
            "matched": by.get("matched", (0, 0))[0], "matched_bytes": by.get("matched", (0, 0))[1],
            "reported": by.get("reported", (0, 0))[0], "diff": by.get("diff", (0, 0))[0],
            "claimed": claimed, "ready": self.one(
                "SELECT COUNT(*) c FROM functions WHERE ready=1 AND status IN ('todo','diff')")["c"],
            "buckets": buckets, "leaderboard": board, "recent": recent, "trend": trend,
            "contributors": self.one("SELECT COUNT(*) c FROM users WHERE accepted_terms IS NOT NULL")["c"],
        }
