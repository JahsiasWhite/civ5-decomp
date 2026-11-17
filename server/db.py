"""SQLite data layer for the civ5-decomp coordination server.

The server never stores game bytes: only addresses, sizes, names, statuses,
claims and contributor activity.

Status lifecycle of a function:
  todo -> (claimed) -> reported (contributor says MATCH, awaiting verify)
       -> matched (maintainer's verify run confirmed it)
  todo/reported can also become 'diff' (attempted, not matching).

A function is identified by (module, addr): the binary it lives in and its address there.
Both DLLs load at 0x10000000, so an address alone is ambiguous. Anything that doesn't
name a module means the exe (the only module before the DLLs joined).
"""
import hashlib
import secrets
import sqlite3
import threading
import time

# module id -> (file, address range [lo, hi)); the order here is the display order
MODULES = {
    "exe": ("CivilizationV_DX11.exe", 0x00400000, 0x10000000),
    "db": ("CvGameDatabaseWin32Final Release.dll", 0x10000000, 0x20000000),
    "loc": ("CvLocalizationWin32Final Release.dll", 0x10000000, 0x20000000),
}
DEFAULT_MODULE = "exe"


def module_order(m):
    return list(MODULES).index(m) if m in MODULES else len(MODULES)


# functions and claims are keyed by (module, addr). {t} is the table name, so the
# migration can build the new table beside the old one.
FUNCTIONS_DDL = """
CREATE TABLE IF NOT EXISTS {t} (
    module      TEXT NOT NULL DEFAULT 'exe',
    addr        INTEGER NOT NULL,
    size        INTEGER NOT NULL,
    name        TEXT NOT NULL DEFAULT '',
    conv        TEXT NOT NULL DEFAULT '',
    depth       INTEGER NOT NULL DEFAULT 0,
    cluster     INTEGER NOT NULL DEFAULT 0,
    ready       INTEGER NOT NULL DEFAULT 0,       -- 1: all callees done
    queue_pos   INTEGER NOT NULL DEFAULT 0,       -- order within the module
    status      TEXT NOT NULL DEFAULT 'todo',     -- todo|reported|matched|diff
    by_user     INTEGER,
    updated     REAL,
    model       TEXT NOT NULL DEFAULT '',         -- model/tool credited with the match
    matched_day TEXT,                             -- YYYY-MM-DD (UTC) first verified
    tried       INTEGER NOT NULL DEFAULT 0,       -- ever attempted
    PRIMARY KEY (module, addr)
);
"""
CLAIMS_DDL = """
CREATE TABLE IF NOT EXISTS {t} (
    module      TEXT NOT NULL DEFAULT 'exe',
    addr        INTEGER NOT NULL,
    user_id     INTEGER NOT NULL REFERENCES users(id),
    worker      TEXT NOT NULL DEFAULT '',
    claimed     REAL NOT NULL,
    expires     REAL NOT NULL,
    model       TEXT NOT NULL DEFAULT '',         -- model the claimer works with
    PRIMARY KEY (module, addr),
    FOREIGN KEY (module, addr) REFERENCES functions(module, addr)
);
"""
# after the migration (they name the module column)
INDEXES = """
DROP INDEX IF EXISTS ix_functions_queue;
CREATE INDEX IF NOT EXISTS ix_functions_queue2 ON functions(module, status, ready, queue_pos);
"""

SCHEMA = FUNCTIONS_DDL.format(t="functions") + CLAIMS_DDL.format(t="claims") + """
CREATE TABLE IF NOT EXISTS users (
    id          INTEGER PRIMARY KEY,
    login       TEXT UNIQUE NOT NULL,             -- GitHub login (or dev name)
    display     TEXT NOT NULL DEFAULT '',         -- shown on the leaderboard ('' = anonymous)
    token_hash  TEXT UNIQUE,
    accepted_terms REAL,
    created     REAL NOT NULL
);

CREATE TABLE IF NOT EXISTS events (
    id          INTEGER PRIMARY KEY,
    ts          REAL NOT NULL,
    user_id     INTEGER,
    module      TEXT NOT NULL DEFAULT 'exe',
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

CREATE TABLE IF NOT EXISTS runs (                 -- verify runs (every push to main)
    id          INTEGER PRIMARY KEY,
    ts          REAL NOT NULL,
    kept        INTEGER NOT NULL,                 -- newly confirmed functions
    kept_bytes  INTEGER NOT NULL,
    rejected    INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS spend (                -- hand-entered cost ledger
    id          INTEGER PRIMARY KEY,
    day         TEXT NOT NULL,
    source      TEXT NOT NULL,
    dollars     REAL NOT NULL,
    note        TEXT NOT NULL DEFAULT ''
);

CREATE TABLE IF NOT EXISTS milestones (
    id          INTEGER PRIMARY KEY,
    day         TEXT NOT NULL,
    text        TEXT NOT NULL
);
"""

# columns added after the first release: (table, column, declaration)
MIGRATIONS = [
    ("users", "session_gen", "INTEGER NOT NULL DEFAULT 0"),      # bump to revoke all sessions
    ("functions", "model", "TEXT NOT NULL DEFAULT ''"),          # model/tool credited with the match
    ("functions", "matched_day", "TEXT"),                        # YYYY-MM-DD (UTC) first verified
    ("functions", "tried", "INTEGER NOT NULL DEFAULT 0"),        # ever attempted
    ("events", "model", "TEXT NOT NULL DEFAULT ''"),
    ("events", "tokens_in", "INTEGER NOT NULL DEFAULT 0"),
    ("events", "tokens_out", "INTEGER NOT NULL DEFAULT 0"),
    ("events", "tokens_cached", "INTEGER NOT NULL DEFAULT 0"),
    ("events", "tries", "INTEGER NOT NULL DEFAULT 0"),
    ("milestones", "key", "TEXT"),                                # set on automatic milestones
    ("claims", "model", "TEXT NOT NULL DEFAULT ''"),             # model the claimer works with
    ("events", "module", "TEXT NOT NULL DEFAULT 'exe'"),
    # functions/claims gain `module` by a table rebuild (it joins the primary key): _key_by_module
]

# automatic milestones (check_milestones): verified function counts, and percent of
# in-scope bytes (every 5%, plus two early ones)
FUNCTION_MILESTONES = [1, 10, 50, 100, 500, 1000, 2500, 5000, 10000, 15000]
BYTE_MILESTONES = [0.1, 1] + list(range(5, 101, 5))

SIZE_TIERS = [(0, 64, "< 64 B"), (64, 256, "64–255 B"), (256, 1024, "256 B–1 KB"),
              (1024, 4096, "1–4 KB"), (4096, 10 ** 9, "≥ 4 KB")]


def utc_day(ts=None):
    return time.strftime("%Y-%m-%d", time.gmtime(ts if ts is not None else time.time()))


def clean_model(m):
    m = "".join(c for c in str(m or "") if c.isalnum() or c in "-._:/ ").strip()[:48]
    return m or "unspecified"

CLAIM_SECONDS = 4 * 3600          # a claim lapses if not reported within 4 h
REPORTED_SECONDS = 14 * 86400     # a reported match not verified within 14 days goes back to the pool
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
        for table, col, decl in MIGRATIONS:
            have = {r["name"] for r in self.q(f"PRAGMA table_info({table})")}
            if col not in have:
                self.conn.execute(f"ALTER TABLE {table} ADD COLUMN {col} {decl}")
        if "module" not in self.columns("functions"):
            self._key_by_module()
        self.conn.executescript(INDEXES)
        # matches nobody reported used to be credited to "maintainer"; now they carry no
        # model and show as "unspecified" (idempotent)
        for table in ("functions", "events"):
            self.conn.execute(f"UPDATE {table} SET model='' WHERE model='maintainer'")

    def columns(self, table):
        return [r["name"] for r in self.q(f"PRAGMA table_info({table})")]

    def _key_by_module(self):
        """One-time migration of a pre-module DB: rebuild functions and claims keyed by
        (module, addr), every existing row in the exe. SQLite can't change a primary key
        in place, so each table is copied into a new one that then takes its name. Runs in
        one transaction: a failure leaves the old tables as they were."""
        self.conn.execute("PRAGMA foreign_keys=OFF")        # no effect inside a transaction
        try:
            self.conn.execute("BEGIN IMMEDIATE")
            try:
                for table, ddl in (("functions", FUNCTIONS_DDL), ("claims", CLAIMS_DDL)):
                    cols = ",".join(c for c in self.columns(table) if c != "module")
                    self.conn.execute(ddl.format(t=f"{table}__new"))
                    self.conn.execute(f"INSERT INTO {table}__new(module,{cols}) "
                                      f"SELECT '{DEFAULT_MODULE}',{cols} FROM {table}")
                    self.conn.execute(f"DROP TABLE {table}")
                    self.conn.execute(f"ALTER TABLE {table}__new RENAME TO {table}")
                bad = self.q("PRAGMA foreign_key_check")
                if bad:
                    raise sqlite3.IntegrityError(f"module migration broke {len(bad)} references")
                self.conn.execute("COMMIT")
            except BaseException:
                self.conn.execute("ROLLBACK")
                raise
        finally:
            self.conn.execute("PRAGMA foreign_keys=ON")

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

    def log(self, kind, user_id=None, addr=None, status="", detail="", model="",
            tokens_in=0, tokens_out=0, tokens_cached=0, tries=0, ts=None, module=DEFAULT_MODULE):
        self.conn.execute(
            "INSERT INTO events(ts,user_id,module,addr,kind,status,detail,model,tokens_in,tokens_out,"
            "tokens_cached,tries) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)",
            (ts or time.time(), user_id, module, addr, kind, status, detail, model,
             tokens_in, tokens_out, tokens_cached, tries))

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

    def revoke_sessions(self, user_id, token=False):
        """Invalidate every signed-in browser session of this user (and, with token=True,
        the CLI token too). Returns False if there is no such user."""
        with self.tx():
            cur = self.conn.execute(
                "UPDATE users SET session_gen=session_gen+1" + (", token_hash=NULL" if token else "") +
                " WHERE id=?", (user_id,))
        return cur.rowcount > 0

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
            for r in self.q("SELECT module,addr,user_id FROM claims WHERE expires<?", (now,)):
                self.log("expire", r["user_id"], r["addr"], module=r["module"])
            self.conn.execute("DELETE FROM claims WHERE expires<?", (now,))

    def claim(self, user_id, n=1, addr=None, worker_prefix="w", min_size=0, max_size=None, model="",
              module=DEFAULT_MODULE):
        """Claim specific `addr`, or the next `n` ready functions in queue order, both in
        `module` (a client that doesn't name one only ever gets exe functions). `model` is
        what will write them: a report without one falls back to it, and so does a match
        that reaches verify while still claimed (see credit_claims). The claim limit counts
        every module. Returns list of (module, addr, worker)."""
        model = clean_model(model) if model else ""
        self.expire_claims()
        self.expire_reports()
        now = time.time()
        with self.tx():
            active = self.one("SELECT COUNT(*) c FROM claims WHERE user_id=?", (user_id,))["c"]
            room = max(0, MAX_ACTIVE_CLAIMS - active)
            if room == 0:
                raise ValueError(f"you already hold {active} claims (limit {MAX_ACTIVE_CLAIMS})")
            if addr is not None:
                f = self.one("SELECT status FROM functions WHERE module=? AND addr=?", (module, addr))
                if not f:
                    raise LookupError("unknown or out-of-scope function")
                if f["status"] == "matched":
                    raise ValueError("already matched")
                # Someone's reported match is waiting on verify; it returns to the pool if
                # verify rejects it or expire_reports (above) lapses it after 14 days.
                if f["status"] == "reported":
                    raise ValueError("already reported, waiting on verify")
                if self.one("SELECT 1 FROM claims WHERE module=? AND addr=?", (module, addr)):
                    raise ValueError("already claimed by someone else")
                picks = [addr]
            else:
                sql = ("SELECT addr FROM functions f WHERE module=? AND status IN ('todo','diff') "
                       "AND ready=1 AND size>=? AND (? IS NULL OR size<=?) "
                       "AND NOT EXISTS (SELECT 1 FROM claims c WHERE c.module=f.module AND c.addr=f.addr) "
                       "ORDER BY queue_pos LIMIT ?")
                picks = [r["addr"] for r in self.q(sql, (module, min_size, max_size, max_size, min(n, room)))]
            out = []
            for i, a in enumerate(picks):
                worker = f"{worker_prefix}{i + 1}"
                self.conn.execute("INSERT INTO claims(module,addr,user_id,worker,claimed,expires,model) "
                                  "VALUES (?,?,?,?,?,?,?)",
                                  (module, a, user_id, worker, now, now + CLAIM_SECONDS, model))
                self.log("claim", user_id, a, model=model, module=module)
                out.append((module, a, worker))
            return out

    def release(self, user_id, addr, module=DEFAULT_MODULE):
        with self.tx():
            cur = self.conn.execute("DELETE FROM claims WHERE module=? AND addr=? AND user_id=?",
                                    (module, addr, user_id))
            if cur.rowcount:
                self.log("release", user_id, addr, module=module)
            return cur.rowcount > 0

    def my_claims(self, user_id):
        return [dict(r) for r in self.q(
            "SELECT c.module,c.addr,c.worker,c.claimed,c.expires,f.size,f.name FROM claims c "
            "JOIN functions f ON f.module=c.module AND f.addr=c.addr WHERE c.user_id=? "
            "ORDER BY c.claimed", (user_id,))]

    # ------------------------------------------------------------ results
    def expire_reports(self, now=None):
        """Reported matches whose PR never landed (not verified in REPORTED_SECONDS) go back
        to 'todo' so someone else can take them. by_user/model are kept: if the original PR
        is merged later, verify still credits them (a new report overwrites both)."""
        cutoff = (now or time.time()) - REPORTED_SECONDS
        with self.tx():
            rows = self.q("SELECT module, addr, by_user FROM functions WHERE status='reported' AND updated<?",
                          (cutoff,))
            for r in rows:
                self.log("unreport", r["by_user"], r["addr"], detail="not verified within 14 days",
                         module=r["module"])
            self.conn.execute("UPDATE functions SET status='todo', updated=? WHERE status='reported' "
                              "AND updated<?", (time.time(), cutoff))
        return len(rows)

    def set_ready(self, ready, module=DEFAULT_MODULE):
        """{addr: bool} from the maintainer's fresh `c5d queue` (all callees matched or none).
        Unknown addresses are ignored. Returns how many flags changed."""
        changed = 0
        with self.tx():
            for addr, r in ready.items():
                changed += self.conn.execute(
                    "UPDATE functions SET ready=? WHERE module=? AND addr=? AND ready<>?",
                    (int(bool(r)), module, addr, int(bool(r)))).rowcount
        return changed

    def report(self, user_id, addr, status, detail="", model="", tokens_in=0, tokens_out=0,
               tokens_cached=0, tries=0, module=DEFAULT_MODULE):
        """Contributor reports a local result. MATCH becomes 'reported' until verified.
        model/tokens describe what produced it (for the per-model and cost panels)."""
        status = status.upper()
        if status not in ("MATCH", "DIFF"):
            raise ValueError("status must be MATCH or DIFF")
        nums = [max(0, min(int(x or 0), 10 ** 10)) for x in (tokens_in, tokens_out, tokens_cached, tries)]
        key = (module, addr)
        with self.tx():
            claim = self.one("SELECT user_id, model FROM claims WHERE module=? AND addr=?", key)
            if not claim or claim["user_id"] != user_id:
                raise PermissionError("you don't hold a claim on this function")
            model = clean_model(model or claim["model"])       # no model given: the claim's
            f = self.one("SELECT status FROM functions WHERE module=? AND addr=?", key)
            if f["status"] != "matched":
                new = "reported" if status == "MATCH" else "diff"
                self.conn.execute(
                    "UPDATE functions SET status=?, by_user=?, model=?, tried=1, updated=? "
                    "WHERE module=? AND addr=?",
                    (new, user_id if new == "reported" else None, model if new == "reported" else "",
                     time.time(), *key))
            self.conn.execute("DELETE FROM claims WHERE module=? AND addr=?", key)
            self.log("report", user_id, addr, status, detail[:500], model, *nums, module=module)

    def apply_credits(self, models, module=DEFAULT_MODULE):
        """{addr: model} from `// c5d-model:` lines in the matched source files. Credits a
        matched function nobody reported (the maintainer committed it directly),
        replacing the empty ("unspecified") default, also for older matches. A contributor's
        own report always wins. Returns how many credits changed."""
        changed = 0
        with self.tx():
            for addr, model in models.items():
                model = clean_model(model)
                changed += self.conn.execute(
                    "UPDATE functions SET model=? WHERE module=? AND addr=? AND status='matched' "
                    "AND model<>? AND NOT EXISTS (SELECT 1 FROM events e WHERE e.kind='report' "
                    "AND e.status='MATCH' AND e.module=functions.module AND e.addr=functions.addr "
                    "AND e.user_id=functions.by_user)",
                    (model, module, addr, model)).rowcount
        return changed

    def credit_owner(self, user_id):
        """Puts matched functions nobody reported (by_user NULL: committed straight to the
        repo) under user_id, the maintainer pushing the verify, also for older matches, so
        they count on the leaderboard. Returns how many were credited."""
        with self.tx():
            return self.conn.execute(
                "UPDATE functions SET by_user=?, updated=? WHERE status='matched' AND by_user IS NULL",
                (user_id, time.time())).rowcount

    def credit_claims(self, statuses, module=DEFAULT_MODULE):
        """Before apply_verified: a function verify now finds matching that someone still
        holds a claim on (merged before it was reported) is credited to the claim holder
        and the claim's model, and the claim is closed, so it stops counting toward the
        holder's limit. Returns how many claims were closed."""
        closed = 0
        with self.tx():
            # walk the open claims (a few), not the statuses (every function on each push)
            for c in self.q("SELECT c.addr, c.user_id, c.model, f.status FROM claims c "
                            "JOIN functions f ON f.module=c.module AND f.addr=c.addr WHERE c.module=?",
                            (module,)):
                addr = c["addr"]
                if statuses.get(addr) != "MATCH":
                    continue
                if c["status"] not in ("matched", "reported"):
                    self.conn.execute("UPDATE functions SET by_user=?, model=?, updated=? "
                                      "WHERE module=? AND addr=?",
                                      (c["user_id"], c["model"], time.time(), module, addr))
                self.conn.execute("DELETE FROM claims WHERE module=? AND addr=?", (module, addr))
                self.log("close", c["user_id"], addr, "MATCH", "matched while claimed", c["model"],
                         module=module)
                closed += 1
        return closed

    def apply_verified(self, statuses, default_model="", module=DEFAULT_MODULE):
        """Maintainer verify: {addr: 'MATCH'|'DIFF'|...} from a full local match run of one
        module. A match nobody reported keeps no model (shown as "unspecified"): report
        with --model before the commit reaches main to credit one."""
        return self.apply_verified_modules({module: statuses}, default_model)

    def apply_verified_modules(self, by_module, default_model=""):
        """apply_verified for several modules at once: {module: {addr: status}}. One push is
        one verification run, however many modules it covers. Returns status changes."""
        changed = kept = kept_bytes = rejected = 0
        today = utc_day()
        with self.tx():
            for module, statuses in by_module.items():
                c, k, kb, r = self._verify(module, statuses, default_model, today)
                changed, kept, kept_bytes, rejected = changed + c, kept + k, kept_bytes + kb, rejected + r
            m = self.one("SELECT COUNT(*) c, COALESCE(SUM(size),0) b FROM functions WHERE status='matched'")
            self.conn.execute("INSERT OR REPLACE INTO daily(day,matched,matched_bytes) VALUES (?,?,?)",
                              (today, m["c"], m["b"]))
            self.conn.execute("INSERT INTO runs(ts,kept,kept_bytes,rejected) VALUES (?,?,?,?)",
                              (time.time(), kept, kept_bytes, rejected))
        return changed

    def _verify(self, module, statuses, default_model, today):
        """One module's statuses (inside apply_verified_modules' transaction).
        Returns (changed, kept, kept_bytes, rejected)."""
        changed = kept = kept_bytes = rejected = 0
        for addr, st in statuses.items():
            f = self.one("SELECT status, by_user, model, size FROM functions WHERE module=? AND addr=?",
                         (module, addr))
            if not f:
                continue
            new = "matched" if st == "MATCH" else ("diff" if st in ("DIFF", "MATCH?") else f["status"])
            if new == "matched" and f["status"] != "matched":
                self.conn.execute(
                    "UPDATE functions SET status='matched', tried=1, matched_day=?, model=?, updated=? "
                    "WHERE module=? AND addr=?",
                    (today, f["model"] or default_model, time.time(), module, addr))
                self.log("verify", f["by_user"], addr, "MATCH", model=f["model"] or default_model,
                         module=module)
                changed += 1
                kept += 1
                kept_bytes += f["size"]
            elif new == "diff" and f["status"] in ("reported", "todo"):
                self.conn.execute("UPDATE functions SET status='diff', tried=1, updated=? "
                                  "WHERE module=? AND addr=?", (time.time(), module, addr))
                if f["status"] == "reported":
                    self.log("verify", f["by_user"], addr, "DIFF", "reported match failed verification",
                             module=module)
                    rejected += 1
                changed += 1
        return changed, kept, kept_bytes, rejected

    # ------------------------------------------------------------ ledger
    def add_spend(self, day, source, dollars, note=""):
        with self.tx():
            self.conn.execute("INSERT INTO spend(day,source,dollars,note) VALUES (?,?,?,?)",
                              (day, clean_model(source), float(dollars), note[:200]))

    def add_milestone(self, day, text, key=None):
        with self.tx():
            self.conn.execute("INSERT INTO milestones(day,text,key) VALUES (?,?,?)", (day, text[:300], key))

    def check_milestones(self, day=None):
        """Log each progress milestone the first time it is reached (verified matches only):
        function counts in FUNCTION_MILESTONES, and every share of in-scope bytes in
        BYTE_MILESTONES. Each is keyed, so it's logged once. Returns the new texts."""
        day = day or utc_day()
        added = []
        with self.tx():
            tot = self.one("SELECT COUNT(*) c, COALESCE(SUM(size),0) b FROM functions")
            m = self.one("SELECT COUNT(*) c, COALESCE(SUM(size),0) b FROM functions WHERE status='matched'")
            have = {r["key"] for r in self.q("SELECT key FROM milestones WHERE key IS NOT NULL")}
            due = []
            for n in FUNCTION_MILESTONES:
                if m["c"] >= n:
                    due.append((f"functions:{n}", "First function matched" if n == 1 else
                                f"{n:,} functions matched"))
            for pct in BYTE_MILESTONES:
                if tot["b"] and m["b"] * 100 >= pct * tot["b"]:
                    due.append((f"bytes:{pct:g}", f"{pct:g}% of the code matched "
                                f"({m['b']:,} of {tot['b']:,} bytes, {m['c']:,} functions)"))
            for key, text in due:
                if key not in have:
                    self.conn.execute("INSERT INTO milestones(day,text,key) VALUES (?,?,?)", (day, text, key))
                    added.append(text)
        return added

    # ------------------------------------------------------------ import
    def import_functions(self, rows, module=DEFAULT_MODULE):
        """rows: dicts with addr,size,name,conv,depth,cluster,ready,queue_pos (and optionally
        module, else `module`). Keeps existing status/claims; adds new functions; refreshes
        queue info. The first import of a DLL logs a "joins" milestone (the trend charts
        mark that day)."""
        with self.tx():
            had = {r["module"] for r in self.q("SELECT DISTINCT module FROM functions")}
            got = {}
            for r in rows:
                r = {"module": module, **r}
                got[r["module"]] = got.get(r["module"], 0) + 1
                self.conn.execute(
                    "INSERT INTO functions(module,addr,size,name,conv,depth,cluster,ready,queue_pos) "
                    "VALUES (:module,:addr,:size,:name,:conv,:depth,:cluster,:ready,:queue_pos) "
                    "ON CONFLICT(module,addr) DO UPDATE SET size=excluded.size, name=excluded.name, "
                    "conv=excluded.conv, depth=excluded.depth, cluster=excluded.cluster, "
                    "ready=excluded.ready, queue_pos=excluded.queue_pos", r)
            keys = {r["key"] for r in self.q("SELECT key FROM milestones WHERE key LIKE 'module:%'")}
            for m in sorted(set(got) - had - {DEFAULT_MODULE}, key=module_order):
                if f"module:{m}" not in keys:
                    file = MODULES.get(m, (m,))[0]
                    self.conn.execute("INSERT INTO milestones(day,text,key) VALUES (?,?,?)",
                                      (utc_day(), f"{file} joins the project ({got[m]:,} functions)",
                                       f"module:{m}"))

    def apply_merges(self, merges, module=DEFAULT_MODULE):
        """Boundary fixes (boundary_overrides.txt): [{"addr", "size", "absorbed": [addr],
        "new": bool}]. The function at addr now spans `size` bytes; each absorbed entry was
        a piece Ghidra split off it (or misread from inside it), so it leaves the pool along
        with any claim on it. A piece already matched is kept (that would need a closer
        look). A `new` addr the server doesn't have (Ghidra missed the function) is added
        at the end of the queue, not ready until a readiness push says so; any other
        unknown addr is ignored. Returns (resized, removed, added)."""
        resized = removed = added = 0
        with self.tx():
            for m in merges:
                addr = m["addr"]
                if self.one("SELECT 1 FROM functions WHERE module=? AND addr=?", (module, addr)):
                    resized += self.conn.execute(
                        "UPDATE functions SET size=?, updated=? WHERE module=? AND addr=? AND size<>?",
                        (m["size"], time.time(), module, addr, m["size"])).rowcount
                elif m.get("new"):
                    pos = self.one("SELECT COALESCE(MAX(queue_pos), -1) + 1 p FROM functions WHERE module=?",
                                   (module,))["p"]
                    self.conn.execute(
                        "INSERT INTO functions(module,addr,size,name,cluster,ready,queue_pos,updated) "
                        "VALUES (?,?,?,?,?,0,?,?)",
                        (module, addr, m["size"], f"FUN_{addr:08x}", addr, pos, time.time()))
                    self.log("merge", None, addr, "", "added (function Ghidra missed)", module=module)
                    added += 1
                for a in m["absorbed"]:
                    f = self.one("SELECT status FROM functions WHERE module=? AND addr=?", (module, a))
                    if not f or f["status"] == "matched":
                        continue
                    self.conn.execute("DELETE FROM claims WHERE module=? AND addr=?", (module, a))
                    self.conn.execute("DELETE FROM functions WHERE module=? AND addr=?", (module, a))
                    self.log("merge", None, a, "", f"part of 0x{addr:08x} (boundary fix)", module=module)
                    removed += 1
        return resized, removed, added

    # ------------------------------------------------------------ stats
    def fingerprint(self):
        """Cheap value that changes whenever anything stats() shows changes (used to keep the
        server's stats cache honest when another process, e.g. manage.py, writes the DB)."""
        return tuple(self.one(
            "SELECT (SELECT MAX(rowid) FROM events), (SELECT MAX(rowid) FROM runs), "
            "(SELECT COUNT(*) FROM claims), (SELECT MAX(rowid) FROM claims), "
            "(SELECT MAX(rowid) FROM spend), (SELECT MAX(rowid) FROM milestones), "
            "(SELECT COUNT(*) FROM users), (SELECT COUNT(*) FROM functions), "
            "(SELECT MAX(updated) FROM functions)"))

    def stats(self):
        """Everything the dashboard shows. Days are UTC."""
        now = time.time()
        today = utc_day(now)
        tot = self.one("SELECT COUNT(*) c, COALESCE(SUM(size),0) b FROM functions")
        by = {r["status"]: (r["c"], r["b"]) for r in self.q(
            "SELECT status, COUNT(*) c, COALESCE(SUM(size),0) b FROM functions GROUP BY status")}
        matched, matched_b = by.get("matched", (0, 0))
        claimed = self.one("SELECT COUNT(*) c FROM claims")["c"]
        tdy = self.one("SELECT COUNT(*) c, COALESCE(SUM(size),0) b FROM functions "
                       "WHERE status='matched' AND matched_day=?", (today,))
        tok = self.one("SELECT COALESCE(SUM(tokens_in),0) i, COALESCE(SUM(tokens_out),0) o, "
                       "COALESCE(SUM(tokens_cached),0) c FROM events WHERE kind='report'")
        models_on_board = self.one("SELECT COUNT(DISTINCT model) c FROM functions "
                                   "WHERE status='matched' AND model<>''")["c"]

        # ---- per module: always every known binary (zeros until it's imported), in order
        mods = list(MODULES) + sorted({r["module"] for r in self.q("SELECT DISTINCT module FROM functions")}
                                      - set(MODULES))
        joined = {r["key"][len("module:"):]: r["day"] for r in self.q(
            "SELECT key, MIN(day) day FROM milestones WHERE key LIKE 'module:%' GROUP BY key")}
        modules = {m: {"file": MODULES.get(m, (m,))[0], "functions": 0, "bytes": 0, "matched": 0,
                       "matched_bytes": 0, "reported": 0, "diff": 0, "claimed": 0, "ready": 0,
                       "matched_today": 0, "matched_today_bytes": 0, "joined": joined.get(m)}
                   for m in mods}
        for r in self.q("SELECT module, status, COUNT(*) c, COALESCE(SUM(size),0) b FROM functions "
                        "GROUP BY module, status"):
            mm = modules[r["module"]]
            mm["functions"] += r["c"]
            mm["bytes"] += r["b"]
            if r["status"] == "matched":
                mm["matched"], mm["matched_bytes"] = r["c"], r["b"]
            elif r["status"] in ("reported", "diff"):
                mm[r["status"]] = r["c"]
        for r in self.q("SELECT module, COUNT(*) c FROM claims GROUP BY module"):
            modules[r["module"]]["claimed"] = r["c"]
        for r in self.q("SELECT module, COUNT(*) c FROM functions WHERE ready=1 AND status IN ('todo','diff') "
                        "GROUP BY module"):
            modules[r["module"]]["ready"] = r["c"]
        for r in self.q("SELECT module, COUNT(*) c, COALESCE(SUM(size),0) b FROM functions "
                        "WHERE status='matched' AND matched_day=? GROUP BY module", (today,)):
            modules[r["module"]].update(matched_today=r["c"], matched_today_bytes=r["b"])
        for mm in modules.values():
            mm["todo"], mm["todo_bytes"] = mm["functions"] - mm["matched"], mm["bytes"] - mm["matched_bytes"]

        # ---- map: what is left, per size tier; combined ("all") first, then each module
        tiers = []
        for module in ["all"] + mods:
            for lo, hi, label in SIZE_TIERS:
                r = self.one(
                    "SELECT COUNT(*) total, SUM(status='matched') matched, "
                    "SUM(status IN ('todo','diff','reported') AND tried=0) untried, "
                    "SUM(status IN ('diff','reported') OR (status='todo' AND tried=1)) open, "
                    "COALESCE(SUM(size),0) bytes, COALESCE(SUM(CASE WHEN status='matched' THEN size END),0) mbytes "
                    "FROM functions WHERE size>=? AND size<? AND (?='all' OR module=?)", (lo, hi, module, module))
                tiers.append({"module": module, "label": label, "total": r["total"],
                              "matched": r["matched"] or 0, "untried": r["untried"] or 0,
                              "open": r["open"] or 0, "bytes": r["bytes"], "matched_bytes": r["mbytes"]})

        # ---- leaderboard (verified matches only)
        board = [dict(r) for r in self.q(
            "SELECT u.id uid, CASE WHEN u.display='' THEN 'anonymous' ELSE u.display END who, "
            "COUNT(*) functions, SUM(f.size) bytes, "
            "(SELECT MIN(e.ts) FROM events e WHERE e.user_id=u.id) since "
            "FROM functions f JOIN users u ON u.id=f.by_user WHERE f.status='matched' "
            "GROUP BY u.id ORDER BY bytes DESC LIMIT 50")]
        # each contributor's matches by size tier (the dashboard's hover breakdown)
        tier_case = "CASE " + " ".join(f"WHEN f.size<{hi} THEN {i}" for i, (_lo, hi, _l) in
                                       enumerate(SIZE_TIERS)) + f" ELSE {len(SIZE_TIERS) - 1} END"
        per_band = {}
        for r in self.q(f"SELECT f.by_user uid, {tier_case} t, COUNT(*) c, SUM(f.size) b "
                        "FROM functions f WHERE f.status='matched' AND f.by_user IS NOT NULL "
                        "GROUP BY uid, t"):
            per_band[(r["uid"], r["t"])] = (r["c"], r["b"])
        per_mod = {}
        for r in self.q("SELECT by_user uid, module, COUNT(*) c, SUM(size) b FROM functions "
                        "WHERE status='matched' AND by_user IS NOT NULL GROUP BY uid, module"):
            per_mod.setdefault(r["uid"], []).append({"module": r["module"], "functions": r["c"], "bytes": r["b"]})
        for row in board:
            uid = row.pop("uid")
            row["bands"] = [{"label": label, "functions": per_band.get((uid, i), (0, 0))[0],
                             "bytes": per_band.get((uid, i), (0, 0))[1]}
                            for i, (_lo, _hi, label) in enumerate(SIZE_TIERS)]
            row["modules"] = sorted(per_mod.get(uid, []), key=lambda x: module_order(x["module"]))

        # ---- trend: cumulative by first-matched day (combined, and per module for the
        # tooltip), and new bytes per day per model
        per_day = self.q("SELECT matched_day d, module, COUNT(*) c, SUM(size) b FROM functions "
                         "WHERE status='matched' AND matched_day IS NOT NULL GROUP BY d, module ORDER BY d")
        cum_f = cum_b = 0
        trend = []
        for r in per_day:
            if not trend or trend[-1]["day"] != r["d"]:
                trend.append({"day": r["d"], "functions": cum_f, "bytes": cum_b, "new_bytes": 0,
                              "new_functions": 0, "modules": {}})
            p = trend[-1]
            cum_f += r["c"]
            cum_b += r["b"]
            p.update(functions=cum_f, bytes=cum_b, new_bytes=p["new_bytes"] + r["b"],
                     new_functions=p["new_functions"] + r["c"])
            p["new_by_module"] = {**p.get("new_by_module", {}),
                                  r["module"]: {"functions": r["c"], "bytes": r["b"]}}
        # cumulative per module as of each day (every module seen so far)
        seen = {}
        for p in trend:
            for m, v in p.pop("new_by_module", {}).items():
                prev = seen.get(m, {"functions": 0, "bytes": 0})
                seen[m] = {"functions": prev["functions"] + v["functions"], "bytes": prev["bytes"] + v["bytes"]}
            p["modules"] = {m: dict(seen[m]) for m in sorted(seen, key=module_order)}
        by_model_day = [dict(r) for r in self.q(
            "SELECT matched_day day, CASE WHEN model='' THEN 'unspecified' ELSE model END model, "
            "SUM(size) bytes FROM functions "
            "WHERE status='matched' AND matched_day IS NOT NULL GROUP BY day, model ORDER BY day")]

        # ---- squad: matches by the model that wrote them
        def squad(where="", args=()):
            rows = self.q("SELECT CASE WHEN model='' THEN 'unspecified' ELSE model END model, COUNT(*) functions, "
                          "SUM(size) bytes FROM functions WHERE status='matched' " + where +
                          " GROUP BY 1 ORDER BY bytes DESC", args)
            split = {}
            for r in self.q("SELECT CASE WHEN model='' THEN 'unspecified' ELSE model END model, module, "
                            "COUNT(*) functions, SUM(size) bytes FROM functions WHERE status='matched' " + where +
                            " GROUP BY 1, 2", args):
                split.setdefault(r["model"], {})[r["module"]] = {"functions": r["functions"], "bytes": r["bytes"]}
            total = sum(r["bytes"] for r in rows) or 1
            return [{**dict(r), "share": r["bytes"] / total,
                     "modules": dict(sorted(split.get(r["model"], {}).items(), key=lambda kv: module_order(kv[0])))}
                    for r in rows]
        day_ago = utc_day(now - 86400)
        squad_all = squad()
        squad_24h = squad("AND matched_day>=?", (day_ago,))
        tries = [dict(r) for r in self.q(
            "SELECT CASE WHEN model='' THEN 'unspecified' ELSE model END model, COUNT(*) reports, "
            "SUM(status='MATCH') matches, SUM(tries) tries FROM events WHERE kind='report' "
            "GROUP BY 1 ORDER BY reports DESC")]
        runs = [{"day": utc_day(r["ts"]), "kept": r["kept"], "kept_bytes": r["kept_bytes"],
                 "rejected": r["rejected"]} for r in self.q(
            "SELECT * FROM runs WHERE kept>0 OR rejected>0 ORDER BY ts DESC LIMIT 14")]

        # ---- cost
        ledger = [dict(r) for r in self.q(
            "SELECT CASE WHEN model='' THEN 'unspecified' ELSE model END source, SUM(tokens_in) input, "
            "SUM(tokens_out) output, SUM(tokens_cached) cached FROM events WHERE kind='report' "
            "GROUP BY 1 HAVING SUM(tokens_in)+SUM(tokens_out)+SUM(tokens_cached)>0 ORDER BY 2 DESC")]
        spend = [dict(r) for r in self.q("SELECT day, source, dollars, note FROM spend ORDER BY day DESC")]

        return {
            "updated": now,
            "functions": tot["c"], "bytes": tot["b"],
            "matched": matched, "matched_bytes": matched_b,
            "todo": tot["c"] - matched, "todo_bytes": tot["b"] - matched_b,
            "matched_today": tdy["c"], "matched_today_bytes": tdy["b"],
            "reported": by.get("reported", (0, 0))[0], "diff": by.get("diff", (0, 0))[0],
            "claimed": claimed,
            "ready": self.one("SELECT COUNT(*) c FROM functions WHERE ready=1 AND status IN ('todo','diff')")["c"],
            "contributors": self.one("SELECT COUNT(*) c FROM users WHERE accepted_terms IS NOT NULL")["c"],
            "models_on_board": models_on_board,
            "modules": modules,
            "tokens": {"input": tok["i"], "output": tok["o"], "cached": tok["c"]},
            "tiers": tiers, "leaderboard": board,
            "trend": trend, "trend_by_model": by_model_day,
            "squad": {"all": squad_all, "day": squad_24h, "tries": tries, "runs": runs},
            "cost": {"ledger": ledger, "spend": spend,
                     "total_dollars": sum(s["dollars"] for s in spend)},
            "log": [dict(r) for r in self.q("SELECT day, text FROM milestones ORDER BY day DESC, id DESC")],
        }
