# civ5-decomp

A byte-matching decompilation of the *Sid Meier's Civilization V* engine
(`CivilizationV_DX11.exe`, final Steam build from Nov 2014), modelled on
the approach used by fnvdecomp.

The gameplay DLL (`CvGameCore_Expansion2.dll`) is **not** in scope here:
Firaxis published its source in the Civ V SDK. Its headers are our
starting point for the exe <-> DLL interface classes.

Live progress, the leaderboard and contributor sign-up: **[civ5decomp.com](https://civ5decomp.com)**.

## High-level flow

1. **Claim, match and report** several functions (`c5d remote claim`, `c5d match`,
   `c5d remote report`). Each report frees that claim slot (max 25 at once, 4-hour lease
   each). The site now shows them as *reported*.
2. **Put them all in one PR.** Batching is fine, since every function has its own pair of
   files (`src/auto/f_*.cpp`, `symbols/auto/f_*.txt`) and they don't conflict. CI checks
   each one on the PR.
3. **Merge.** Verify runs on `main` and the site marks them *matched* within a few minutes.

Reported functions that aren't verified within 14 days go back to the pool, so don't let a
batch sit unmerged.

**Credit:** a reported function is credited to the `--model` given to `remote report`. A
function nobody reported (the maintainer committed it directly) is credited from a
`// c5d-model: <name>` line near the top of its source file, and shows as `maintainer`
without one. Verify sends these on every run, so adding or changing the line also fixes
older matches.

## Ground rules

- **Never commit game files.** That means no exe, dll, machine code,
  disassembly dumps, Ghidra databases or assets. Only hand-written source,
  headers and tooling go in git. `.gitignore` enforces most of this.
- Everyone works from their own legally owned copy of the game.

**New contributors: start with [CONTRIBUTING.md](CONTRIBUTING.md)** (tools to install, then
`python tools/c5d.py setup`).

## Target

| | CivilizationV_DX11.exe |
|---|---|
| Linker | MSVC 9.0 (Visual C++ 2008) |
| `.text` | ~6.1 MB |
| Build date | 2014-11-19 |
| DRM wrapper | none |
| Rich header | absent (so the exact compiler build has to be found from the CRT) |

## Pipeline

```
setup ──► scope ──► queue ──► task next / agent ──► match ──► build ──► status
(paths,   (what's    (leaves-   (bundles for one     (LTCG      (hybrid    (PROGRESS.md)
 exe hash) in scope)  first)     function each)       verify)    exe)
```

| Command | What it does | Output |
|---|---|---|
| `c5d setup` | Finds the game (Steam libraries), checks the exe's SHA-256, finds Ghidra, Java and the VC++ 2008 compiler, writes `config.local.json`, builds scope + queue, runs a test match | `config.local.json` |
| `c5d analyze` | Ghidra headless import and analysis (needed for task bundles), plus function export. The shared list is `data/functions.csv`; maintainers refresh it from this export. | `ghidra_proj/`, `build/functions.csv` |
| `c5d scope` | Classifies every function: game code vs import stubs, thunks, CRT (byte signatures from the compiler's static libs), ATL/MFC names, compiler EH funclets. Manual ranges go in `scope_overrides.txt`. | `build/scope.csv` |
| `c5d boundaries [--write]` | Finds functions Ghidra split in two (an early `ret`, then a tail reached only by a jump from the first part) and adds them to `boundary_overrides.txt`. Every tool reads the function list through those fixes. | `boundary_overrides.txt` |
| `tools/sdk_vtables.py` | Names engine functions from the SDK interface headers: finds each interface's `QueryInterface` through its GUID, then its vtable | `names/sdk_vtables.csv` |
| `c5d queue` | Call graph, calling-convention guess (stack / thiscall / custom LTCG registers), call depth, LTCG clusters. Leaves first. | `build/queue.csv` |
| `c5d task next --n N` | Writes a self-contained bundle per ready function: rules, disassembly, Ghidra C, references with names/conventions/status | `build/tasks/<addr>/TASK.md` |
| `c5d task check <addr>` | Verifies one function and logs the attempt | `build/attempts.jsonl` |
| `c5d agent --n N --tries T [--remote]` | Runs `agent_cmd` from `config.local.json` on each bundle (prompt on stdin), checks, retries with the diff. Any CLI agent works, e.g. `["claude", "-p", "--permission-mode", "acceptEdits", "--output-format", "json"]`. With JSON output, the token usage it prints is summed per task (`build/tasks/<addr>/usage.json`) and sent by `remote report`. `--remote` claims from the server and reports each result. Runs one function at a time. | as above |
| `c5d match` | LTCG build of all `src/` + verification; a full run updates `progress/status.csv` | |
| `c5d build` | Hybrid exe: every function in `src/` relocated into a copy of the game exe (see "Hybrid build") | `build/hybrid/` |
| `c5d status` | Progress summary | `PROGRESS.md` |

The SDK headers come from the public Community Patch repo (sparse checkout of
`CvGameCoreDLLUtil/` into the git-ignored `third_party/`):

```bash
git clone --depth 1 --filter=blob:none --sparse https://github.com/LoneGazebo/Community-Patch-DLL.git third_party/Community-Patch-DLL
git -C third_party/Community-Patch-DLL sparse-checkout set CvGameCoreDLLUtil
```

Automated work goes in `src/auto/f_<address>.cpp`. Move it into a proper area
folder once the class it belongs to is known.

## Website and claim service (`server/`)

A coordination server written with the Python standard library only (`http.server`
+ `sqlite3`). It hosts the progress dashboard, the contribute/terms/account pages,
and the claim API. **The server never stores game bytes**: only addresses, sizes,
names, statuses, claims and activity. Code moves through GitHub pull requests.

```
contributor                      server                         maintainer (has the game)
c5d remote claim  ──────────►  hands out ready functions,      git pull
  (bundles built locally)       4 h lease, max 25 per user      python tools/c5d.py match
c5d remote report ──────────►  marks "reported"                python server/manage.py verify
  (re-checks locally first)                                       -> "matched", leaderboard, trend
open a PR with src/auto + symbols/auto
```

**Try it locally** (dev sign-in, no GitHub needed):

```bash
python server/manage.py import
python server/dev.py
```

Then open `http://127.0.0.1:8765/dev-login?login=you`. Tests: `python -m pytest tests/`.

**Deploying publicly** (a small Linux VPS; ready-made files are in `deploy/`):
1. Clone the repo to `/opt/civ5-decomp`, then install the systemd units and the env file
   as described at the top of `deploy/c5d.service`. Fill in `/etc/c5d.env` (template:
   `deploy/c5d.env.example`): `C5D_PUBLIC_URL`, a long random `C5D_SESSION_SECRET`,
   `C5D_DB=/var/lib/c5d/c5d.sqlite`, and `C5D_ADMINS=<your GitHub login>`. The server binds
   `127.0.0.1` only. Never set `C5D_DEV_AUTH` in production.
2. Install Caddy and use `deploy/Caddyfile` (change the domain). It handles HTTPS
   certificates, HSTS and the body size limit, and passes the client IP for the logs.
3. Create a GitHub OAuth app (GitHub → Settings → Developer settings → OAuth Apps)
   with the callback `https://your-domain/auth/callback`, and set `GITHUB_CLIENT_ID` /
   `GITHUB_CLIENT_SECRET`. No scopes are requested; the server only reads the public login.
4. Seed the DB once: copy `server/data/c5d.sqlite` (after `manage.py import`) to
   `/var/lib/c5d/`, or run the import there with your `build/queue.csv` (it contains
   addresses, sizes and names only). After that, never copy the DB over the live one:
   that would wipe claims and reports made since.
5. Sign in on the site, create a token on `/account`, and `c5d remote login` with it.
   Verification runs on GitHub (see "Verification without the game" below): twice a day
   and on every push to `main`, `.github/workflows/verify.yml` matches everything and pushes
   the results. Add a repository secret `C5D_ADMIN_TOKEN` with an API token of an admin login.
   Readiness (which functions are unblocked) still comes from a run on a machine with the game:
   `git pull && python tools/c5d.py match && python tools/c5d.py queue && python server/manage.py push`.
   `push` sends `progress/status.csv` and the readiness column of `build/queue.csv` to
   `POST /api/admin/verify` (only logins listed in `C5D_ADMINS`, bearer token only). That way
   functions whose callees just matched start being handed out. Reported matches that
   aren't verified within 14 days (no PR, or the PR wasn't merged) go back to the pool.
6. Automatic deploys: `.github/workflows/tests.yml` runs the server tests on every push.
   On the VPS, `c5d-deploy.timer` runs `deploy/autodeploy.py` every 2 minutes as root: when
   `origin/main` has moved and its `tests` workflow passed, it fast-forwards
   `/opt/civ5-decomp`, restarts `c5d` if anything under `server/` changed, and rolls back if
   `/healthz` doesn't answer. Nothing on GitHub can reach the server. Install once:
   `sudo cp deploy/c5d-deploy.service deploy/c5d-deploy.timer /etc/systemd/system/ &&
   sudo systemctl daemon-reload && sudo systemctl enable --now c5d-deploy.timer`.
   If the repo is private, also create `/etc/c5d-deploy.env` (root, chmod 600) with
   `C5D_GITHUB_TOKEN=` a fine-grained token for this repo with Contents: read and Actions: read.
   Logs: `journalctl -u c5d-deploy`. Changes to the systemd units, the Caddyfile or
   `/etc/c5d.env` still need installing by hand.
7. Backups: `c5d-backup.timer` runs `manage.py backup` nightly (SQLite online backup into
   `/var/backups/c5d`, keeps 14). Copy that folder off the VPS now and then.
8. Monitoring: `GET /healthz` returns `{"ok": true}` when the server and DB respond. Point
   an uptime checker at it. `/api/stats` is computed at most every 30 s (sooner after any
   write), so dashboard traffic doesn't rerun the aggregate queries.
   Sessions: users can "Sign out everywhere" on `/account`. To lock someone out, run
   `python server/manage.py revoke <login>` on the server; it ends their browser sessions and
   deletes their CLI token (`--keep-token` leaves the token working). Changing
   `C5D_SESSION_SECRET` signs everyone out.
9. Before launch: fill in the contact address and get the draft terms in
   `server/static/legal.html` reviewed.

## Verification without the game

Matching needs the original exe, which can't leave your machine. CI uses fingerprints
instead (`tools/fingerprint.py`):

- `python tools/c5d.py fingerprint` (maintainers, once; needs the exe) writes
  `data/fingerprints.csv`: per function, a SHA-256 of its original bytes and of the bytes
  up to the next function, plus `data/fingerprints.json` (import and export tables). No game
  code: hashes can't be turned back into bytes.
- `python tools/c5d.py match --fingerprints` (automatic when the exe isn't there) links as
  usual, rewrites every reference in our code to the address the original must have there
  (from the symbols files), and compares hashes. Equal hashes mean the same code and the same
  references. A DIFF can't show *where* it differs; run `match` with the exe for that. A
  function with references not in any symbols file is `UNVERIFIED`.
- `.github/workflows/verify.yml` does this on Linux: VC++ 2008 SP1 (`VCForPython27.msi`,
  fetched from Microsoft and checked against its SHA-256 by `.github/ci/vc2008.sh`) runs
  under Wine; paths are passed as `Z:\...` (`tools/config.py`). Pull requests get a check
  that fails if a function in their files doesn't match; `main` also sends the results to
  the site.

## Configuration

- `config.json` (committed): compiler flags, the target exe's SHA-256, pinned tool versions.
- `config.local.json` (git-ignored, written by `c5d setup`): this machine's game, Ghidra and
  MSVC paths, plus the server login, `model` and `agent_cmd`. Its keys override `config.json`.
- `data/functions.csv` (committed): the shared function list (addresses, sizes, Ghidra names;
  no code), so everyone uses the same addresses whatever Ghidra version they have.

Every toolchain command refuses to run until setup is done, and refuses an exe whose hash
doesn't match (the hash is cached by size + mtime, so this costs nothing).

## Hybrid build: testing as we go

We don't wait for 100% to rebuild and check the exe. `c5d build` takes our `/LTCG`-linked
code for every function in `src/` and writes it into a copy of your own exe at the original
addresses, re-pointing every call, jump, global and switch table:

- **Matched functions** are written in place, and the result must be **byte-identical** to the
  original (SHA-256 of the whole file). This proves, at every stage, that the rebuilt
  functions and the relocation from our link back to the game's addresses are right.
- **`--diff`** also patches in non-matching functions whose calls and globals all check out:
  our version goes in a new `.c5d` section and the original entry jumps to it. Functions with a
  custom LTCG register convention are skipped unless you pass `--force`. The exe then runs our C++
  for those functions (ASLR is turned off and the signature is dropped), so you can play-test
  decompiled logic before it matches byte for byte.
- **`--run`** copies the hybrid into the game folder as `CivilizationV_DX11_c5d.exe` (with a
  `steam_appid.txt` if there isn't one) and starts it. **`--clean`** removes both.

First run (2026-11-15): all 32 matched functions rebuilt into a byte-identical exe; with
`--diff`, `KindQueryObject::GetKindFlags` (equivalent, but `lea` operands in a different order)
runs from `.c5d`. The other 7 DIFFs stay original: 6 have references that don't check out yet,
and 1 is custom-convention.

The hybrid exe is built from each player's own copy and is never shared.

## Parallel workers

Each worker passes `--worker <id>`, which gives it its own build folder
(`build/work/<id>/`). `c5d task next --worker-prefix w` claims each task for its
own worker (`build/claims/`). A worker writes only `src/auto/f_<addr>.cpp` and
`symbols/auto/f_<addr>.txt`. `symbols.txt` plus every `symbols/**/*.txt` file are
merged, so workers never edit the same file. LTCG links leave out files claimed
by *other* workers, so a half-written file can't break anyone else's build.
`c5d task release <addr>` drops a claim. Twenty workers ran at once in the trial without
interfering.

### Per-file compiler flags

Firaxis's build used **different settings per source file**. Most code is
`/arch:SSE2 /fp:fast` (the default in `config.json`), but some files (for example some Lua
bindings) use x87 floating point, and the NVAPI library is unoptimised. Add a line in
the first 40 lines of a source file to change its flags:

```cpp
// c5d-cflags: -/arch:SSE2 -/fp:fast      (remove flags)
// c5d-cflags: +/Od                       (add flags)
```

### Fake matches (`c5d-review`)

A **fake match** has identical bytes, but its source uses a trick the original surely
didn't: `volatile` to pin instruction order, an array standing in for a vtable, a
`#pragma`, inline asm. They're normal early on and don't block progress. Mark them in the
first 40 lines of the file so they can be found and fixed once more of the class or file
is known:

```cpp
// c5d-review: fields are volatile only to keep the stores in order
```

`c5d status` counts them in PROGRESS.md; `git grep c5d-review` lists them.

## Trial: 20 functions, 20 parallel agents (2026-11-15)

Each fresh agent saw only its `TASK.md` bundle. Functions were taken from the queue at
20, 61 and about 202 bytes.

| | Result |
|---|---|
| Tasks | 20 (6 small, 8 medium, 6 large) |
| Matched | **18 of 20**. Of the 17 that turned out to be in scope, **16 MATCH and 1 DIFF (94%)**. The other 3 were NVAPI library code (2 matched); NVAPI is now out of scope and those files are dropped. |
| Open DIFFs | `0x46b110`: the original has `add [mem],1` where we get `inc [mem]`; cause unknown. NVAPI `0x8ae260`: unoptimised stack-slot order. |
| Time per task | 29 s to 285 s, median about 90 s |
| Tokens per task | 55k to 87k, about 63k on average (about 1.3M for the trial) |
| Iterations | 1 to 12 matcher runs; most matched in 1 or 2 |

Before the fixes below, 5 of those matches were DIFFs caused by the harness, not
by the agents' C++.

What the trial found and fixed:
- **`/arch:SSE2 /fp:fast`** is the project default (found independently by two agents).
- **Mixed per-file flags** (an x87 Lua binding), now supported with `c5d-cflags`.
- **Switch jump tables:** the compiler appends them after the code. The matcher now
  checks them separately, as offsets from the function start, and resolves
  references inside a function relative to that function.
- **NVIDIA NVAPI** is statically linked: 387 wrappers at `0x8a88c0–0x8bb02a`, now
  out of scope.
- **Review flag:** one constructor (`0x6aab90`) was matched by writing the vtable
  pointer through a declared array instead of a real virtual class. The bytes match, but
  the source should be made idiomatic once its class is known.

## Findings so far

- **Scope:** Ghidra finds 20,152 functions. **19,175 (4.53 MB) are game code
  and in scope.** Out of scope: 387 NVAPI wrappers, 231 compiler EH funclets, 211
  import stubs, 84 thunks, 43 CRT objects and 21 other library functions. The CRT (`msvcr90`), C++
  library (`msvcp90`), Lua, Miles, zlib, Steam and the game database and
  localisation code are all separate DLLs. ATL string templates are header code,
  so they stay in scope.
- **SDK names:** the GUID → `QueryInterface` → vtable method gives 390 functions
  their real interface names (`CvEngineUtilityImpl::*` via `ICvEngineUtility4` at
  `0x9ea718`, and `CvUserInterfaceImpl::*` via `ICvUserInterface2` at `0xa04240`).
- **Conventions:** 9,438 thiscall, 8,487 stack and 1,637 custom LTCG register
  conventions. About 4,980 functions are "ready" (no undecompiled callees).
- **Function sizes:** Ghidra's size counts addresses across disjoint ranges
  (switch tables). The scope step uses the real extent instead.
- **Exports give us free names:** the exe exports Firaxis engine functions
  (`FSBA*`, `FJobSet*`, `GetLogFileMgr`, ...) for the gameplay DLL to call.
- **Confirmed LTCG + `/Ob1`:** the exe was built with `/GL` + `/LTCG`, and inlining
  limited to functions marked `inline` (`/Ob1`). Evidence: `FSmallObjectAllocator::IsSmallBlock`
  (`this` in EDI, `p` in EAX, `ret 4`) matches only when linked with `/LTCG`,
  and only with `/Ob1`. With `/Ob2` the linker inlines it into its single caller.
- **Compiler/flags:** `cl 15.00.30729.01 /O2 /Ob1 /Gy /MD /EHsc /GR /arch:SSE2 /fp:fast`
  (see `config.json`), with per-file exceptions (see "Per-file compiler flags").
- **Inline helpers live in headers:** `FSBAHasAllocatorForSize` contains an
  inlined copy of the lookup that `0x81c360` performs out of line. Under `/Ob1`, that
  means an `inline` header helper (`FindAllocatorForSize`) used by both.
- **`FMalloc` is inlined everywhere:** the engine's allocation path
  (`GetSmallObjectAllocator`, then `GetAllocatorForSize`, then `Allocate`, falling back to `malloc`) is an
  inline helper. `GetSmallObjectAllocator` has 329 call sites, `GetAllocatorForSize` 187
  and `Allocate` 200. Reconstructed in `include/FMemory.h`.
- **STL built with `_SECURE_SCL=0` and `_HAS_EXCEPTIONS=0`** (2026-11-15), now in
  `config.json`. Found on `vector::_Umove` (`0x626aa0`), which only matches without the
  checked-iterator code and the try/catch in `_Uninit_copy`. Adding both project-wide
  changed no other match.
- **`new` has no EH cleanup:** the exe's `new T` sites have no unwind frame. A class
  `operator new` or std placement new adds one under `/EHsc`; a tagged placement
  new with no matching delete (`FNEW(T)` in `FMemory.h`) reproduces the original shape.
- **No PGO:** no hot/cold function splitting found (0 functions with ranges more than 64 KB apart).
- **Open problem: LTCG register choice in the allocator cluster.** Our link passes
  `this` to `GetAllocatorForSize`/`Allocate` in ECX/ESI, where the original uses EDI
  at every one of its ~190 call sites. This is the only remaining difference in 6 functions
  (`FSBAAllocate`, `FSBAHasAllocatorForSize`, the two helpers, and two `FMalloc`
  callers). What we tried:
  - adding real callers: no change
  - giving the pool callee (`0x81be80`) a real body: no change
  - other `/O` flags: no change

  The leading theory is that the choice depends on the whole set of call sites
  (hundreds of inlined `FMalloc` expansions), so it should resolve as more callers
  are decompiled. Next experiments: decompile `GetSmallObjectAllocator` (the first
  caller in the same file), and try reordering functions or files within the link.

## Phases

1. **Slice:** match one small function by hand, end to end. This proves the
   compiler and flags, and tells us whether `/LTCG` was used.
2. **Harden:** build a `match` command that ignores relocations, set up the
   class-definition library, and match 20 to 50 functions to measure the hit rate.
3. **Scale:** add the function queue, the AI agent loop and progress tracking (plus the site).

## Layout

```
config.json        shared settings: compiler flags, target exe SHA-256, tool versions
config.local.json  this machine's paths, server login, agent_cmd (git-ignored; `c5d setup`)
data/              functions.csv: the shared function list
CONTRIBUTING.md    contributor setup guide
symbols.txt        address <-> symbol map (drives `match`)
names/             readable names from other sources (SDK vtables)
progress/          status.csv: per-function match status (committed)
PROGRESS.md        generated summary
scope_overrides.txt manual scope ranges
tools/scope.py     scope classification
tools/workqueue.py call graph, conventions, leaves-first queue
tools/tasks.py     task bundles + agent loop
tools/sdk_vtables.py SDK interface names
src/auto/          agent-written functions (f_<address>.cpp)
tools/c5d.py       CLI: `setup`, `analyze`, `dump`, `match`, `build`, ... (`--help`)
tools/setup_env.py `c5d setup`: discovery, exe hash, toolchain checks
tools/config.py    config.json + config.local.json loading
tools/hybrid.py    `c5d build`: relocate our code into a copy of the exe
tools/binfmt.py    PE / COFF readers (exports, imports, base relocations)
tools/ltcg.py      /GL + /LTCG build, placeholders, linked comparison
tools/xrefs.py     find callers of an address in the exe
tools/ghidra/      Ghidra headless scripts
include/           reconstructed class declarations ("blueprints")
src/               matched function source
build/             generated output (git-ignored)
```

## Quick start

```bash
python tools/c5d.py setup     # find + check everything, write config.local.json
python tools/c5d.py analyze   # one-time Ghidra database (for task bundles)
python tools/c5d.py dump 0x00813940   # disasm + decompile to build/dump (local only)
python tools/c5d.py match             # compile src/ and compare against the exe
python tools/c5d.py build             # hybrid exe, verified byte-identical
```

## Matching a function

1. Add `<address> <decorated name>` to `symbols.txt` for the function, plus
   any functions or globals it references.
2. Write it in a `.cpp` under `src/` (one area per folder), and put class
   layouts in `include/`.
3. Run `python tools/c5d.py match` (add `-v` for detail). By default this is
   **LTCG mode**: every file in `src/` is compiled with `/GL` and linked together with
   `/LTCG` into a throwaway DLL, so the linker makes the same whole-program
   decisions as Firaxis's build. Anything not decompiled yet becomes a generated
   placeholder. Each function is then compared with the exe. Every call, jump
   and global address must point where the original does (resolved via
   `symbols.txt`, the linker map and the import tables). `--obj` is a faster
   per-file mode that is only reliable for simple leaf functions.
   `python tools/xrefs.py <addr>` lists the exe's callers of a function.
   - `MATCH`: identical, and every relocation target is verified.
   - `MATCH?`: identical bytes, but some relocation targets are unknown (add them to `symbols.txt`).
   - `DIFF`: a side-by-side disassembly with `!!` on differing lines
     (`r` = differs only in a relocation that checked out).

## License

The tooling, website and contributor-written source are under the [MIT License](LICENSE). It grants no rights to Civilization V itself: no game files are in this repository, and you need your own copy of the game to build anything.

