# civ5-decomp

A byte-matching decompilation of the *Sid Meier's Civilization V* engine
(`CivilizationV_DX11.exe`, final Steam build from Nov 2014), modelled on
the approach used by fnvdecomp.

The gameplay DLL (`CvGameCore_Expansion2.dll`) is **not** in scope here:
Firaxis published its source in the Civ V SDK. Its headers are our
starting point for the exe <-> DLL interface classes.

## Ground rules

- **Never commit game files.** That means no exe, dll, machine code,
  disassembly dumps, Ghidra databases or assets. Only hand-written source,
  headers and tooling go in git. `.gitignore` enforces most of this.
- Everyone works from their own legally owned copy of the game.

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
analyze ──► scope ──► queue ──► task next / agent ──► match ──► status
(Ghidra)   (what's    (leaves-   (bundles for one     (LTCG      (PROGRESS.md)
           in scope)   first)     function each)       verify)
```

| Command | What it does | Output |
|---|---|---|
| `c5d analyze` | Ghidra headless import, then function export | `build/functions.csv` |
| `c5d scope` | Classifies every function: game code vs import stubs, thunks, CRT (byte signatures from the compiler's static libs), ATL/MFC names, compiler EH funclets. Manual ranges go in `scope_overrides.txt`. | `build/scope.csv` |
| `tools/sdk_vtables.py` | Names engine functions from the SDK interface headers: finds each interface's `QueryInterface` through its GUID, then its vtable | `names/sdk_vtables.csv` |
| `c5d queue` | Call graph, calling-convention guess (stack / thiscall / custom LTCG registers), call depth, LTCG clusters. Leaves first. | `build/queue.csv` |
| `c5d task next --n N` | Writes a self-contained bundle per ready function: rules, disassembly, Ghidra C, references with names/conventions/status | `build/tasks/<addr>/TASK.md` |
| `c5d task check <addr>` | Verifies one function and logs the attempt | `build/attempts.jsonl` |
| `c5d agent --n N --tries T` | Runs `agent_cmd` from `config.json` on each bundle (prompt on stdin), checks, retries with the diff. Any CLI agent works, e.g. `["claude", "-p", "--permission-mode", "acceptEdits"]`. Runs one function at a time. | as above |
| `c5d match` | LTCG build of all `src/` + verification; a full run updates `progress/status.csv` | |
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

**Deploying publicly:**
1. Put it behind an HTTPS reverse proxy (Caddy or nginx) on a small VPS, and set
   `C5D_PUBLIC_URL=https://your-domain`, `C5D_SESSION_SECRET=<long random>` and
   `C5D_HOST=127.0.0.1` (the proxy forwards to it). Never set `C5D_DEV_AUTH` in production.
2. Create a GitHub OAuth app (GitHub → Settings → Developer settings → OAuth Apps)
   with the callback `https://your-domain/auth/callback`, and set `GITHUB_CLIENT_ID` /
   `GITHUB_CLIENT_SECRET`. No scopes are requested; the server only reads the public login.
3. Copy `server/data/c5d.sqlite` (after `manage.py import`) to the server, or run
   the import there with your `build/queue.csv` (it contains addresses, sizes and names only).
4. Nightly: `git pull && python tools/c5d.py match && python server/manage.py verify`
   on your machine, then sync the verify results (the DB, or run `verify` on the server
   with `progress/status.csv`).
5. Before launch: fill in the contact address and get the draft terms in
   `server/static/legal.html` reviewed.

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

## Progress

| Date | Functions | Matched | Notes |
|---|---|---|---|
| 2026-11-14 | 19 | 15 | 9 of 13 in the second batch matched on the first attempt. All 4 misses are in the allocator cluster (LTCG register choice). |
| 2026-11-14 | 21 | 15 | Added `FMalloc`/`FNEW` and 2 callers. EH shape fixed; the cluster is still blocked only on the EDI register choice. |

Matched: `FSBADisable`, `FSBAIsDisabled`, `FSBAGetMaxAllocatorSize`,
`FSBAPreventCreation`, `FSBAIsSmallBlock`, `FSmallObjectAllocator::IsSmallBlock`,
`GetSmallObjectAllocatorInitParams`, `FStringA/W_GetStringInitData`,
`PeekLogFileMgr`, `GetTempHeap`, `GetMemTrackerForDLL`, `FJobSetInitImpl`,
`FJobSetWaitImpl`, `FJobSetAddJobImpl`.
Not yet: `FSBAAllocate`, `FSBAHasAllocatorForSize` (1 byte off),
`FSmallObjectAllocator::Allocate`, `FSmallObjectAllocator::GetAllocatorForSize`.

## Phases

1. **Slice:** match one small function by hand, end to end. This proves the
   compiler and flags, and tells us whether `/LTCG` was used.
2. **Harden:** build a `match` command that ignores relocations, set up the
   class-definition library, and match 20 to 50 functions to measure the hit rate.
3. **Scale:** add the function queue, the AI agent loop and progress tracking (plus the site).

## Layout

```
config.json        local paths (game, Ghidra, MSVC), compiler flags, agent_cmd
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
tools/c5d.py       CLI: `env`, `analyze`, `dump`, `match`
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
python tools/c5d.py env       # check the toolchain
python tools/c5d.py analyze   # Ghidra headless import, then build/functions.csv
python tools/c5d.py dump 0x00813940   # disasm + decompile to build/dump (local only)
python tools/c5d.py match             # compile src/ and compare against the exe
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
