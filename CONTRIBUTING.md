# Contributing to civ5-decomp

We rewrite Civilization V's engine (`CivilizationV_DX11.exe`) and its two game DLLs in C++,
one function at a time, so that it compiles back into exactly the same bytes. This guide gets
you from nothing to your first matched function.

**Ground rules:** you need your own legally owned copy of the game. Never commit or share
game files, machine code, disassembly or Ghidra output, only the C++ you write.

## 1. Install the tools

You need Windows and the following:

| Tool | Version | Notes |
|---|---|---|
| Civilization V | Steam, current build (Nov 2026) | Let Steam keep it updated. Setup checks the exact exe. |
| Python | 3.10 or newer | [python.org](https://www.python.org/downloads/). Tick "Add to PATH". |
| Git | any | [git-scm.com](https://git-scm.com/) |
| Ghidra | 10.3.2 | [GitHub releases](https://github.com/NationalSecurityAgency/ghidra/releases/tag/Ghidra_10.3.2_build). Unzip anywhere (Desktop and Downloads are searched automatically). |
| Java JDK | 17 or newer | Ghidra needs it, for example [Eclipse Temurin](https://adoptium.net/). |
| Visual C++ 2008 SP1 compiler | exactly `15.00.30729.01` | See below. |

### The compiler

Byte matching only works with the **same compiler build Firaxis used**: Visual C++ 2008 SP1,
`cl.exe` version `15.00.30729.01`. Setup refuses any other version. Each of these
Microsoft packages contains it:

- **Microsoft Visual C++ Compiler for Python 2.7** (`VCForPython27.msi`). This is what the
  project is developed with. It installs to
  `%LOCALAPPDATA%\Programs\Common\Microsoft\Visual C++ for Python\9.0` and includes the
  Windows SDK headers. Microsoft no longer lists it for download, but the Wayback Machine kept
  the original file from Microsoft's download server:
  [VCForPython27.msi (archived 2021-01-06)](https://web.archive.org/web/20210106040224/https://download.microsoft.com/download/7/9/6/796EF2E4-801B-4FC4-AB28-B59FBF6D907B/VCForPython27.msi).
  Before installing it, check that it is the genuine file:
  - SHA-256 `070474db76a2e625513a5835df4595df9324d820f9cc97eab2a596dcbc2f5cbf`
    (PowerShell: `Get-FileHash VCForPython27.msi`)
  - **signed by Microsoft Corporation** (right-click → Properties → Digital Signatures)
- **Windows SDK for Windows 7 and .NET Framework 3.5 SP1** (SDK 7.0): its "Visual C++
  Compilers" option installs the VS 2008 SP1 compilers.
- **Visual Studio 2008 with SP1** (any edition, including Express), if you have it.

Setup searches the default install folders of all three. If yours is somewhere else, pass
`--msvc "<folder containing cl.exe>"`.

## 2. Run setup

```bash
git clone https://github.com/JahsiasWhite/civ5-decomp.git civ5-decomp
cd civ5-decomp
python tools/c5d.py setup
```

Setup:
1. installs the Python packages (`requirements.txt`)
2. finds the game in your Steam libraries and checks the build hash of the exe and of both
   DLLs against `config.json`. The hash covers the code and data sections only (Steam stamps
   every download differently elsewhere in the file). A different build changes every
   address, so it has to match exactly. The project works on the November 2026 Steam build;
   the 2014 build it started on is kept as a view-only legacy build (see below).
3. finds Ghidra, Java and the compiler (plus the Windows SDK headers)
4. saves your paths in `config.local.json` (git-ignored, so it never leaves your machine)
5. builds the scope and work queue from the shared function list (`modules/exe/data/functions.csv`;
   see "The exe and the DLLs" below for the others)
6. runs a test match on a function that is known to match

Every problem shows as `[!!]` with a line telling you how to fix it. Fix those and run setup again. Options:
`--game`, `--ghidra`, `--msvc` (point at a folder), `--sdk-headers` (also fetch the
Civ V SDK headers), `--no-install`.

Then build your local Ghidra database once. It supplies the pseudo-C in your task bundles and takes
about 5–15 minutes:

```bash
python tools/c5d.py analyze
```

### The exe and the DLLs

The project covers three binaries. Each is a **module** with its own folder:

| Module | Binary | What it is | Left out of scope |
|---|---|---|---|
| `exe` | `CivilizationV_DX11.exe` | the engine | the C runtime, NVAPI, ... |
| `db` | `CvGameDatabaseWin32Final Release.dll` | the game database: SQLite access, XML loading | SQLite 3.7.17, compiled into it |
| `loc` | `CvLocalizationWin32Final Release.dll` | text lookup, plurals, number and date formatting | ICU 4.4, compiled into it |

`modules/<module>/` holds that binary's sources (`src/`), symbols (`symbols.txt`, `symbols/`),
shared function list and fingerprints (`data/`), match results (`progress/status.csv`) and
manual fixes (`boundary_overrides.txt`, `scope_overrides.txt`). Your local output goes to
`build/<module>/`. Headers that more than one module uses live in `include/`.

Every command works on the exe unless you say otherwise. To work on a DLL, put `--module`
before the subcommand, or write its addresses with the module in front:

```bash
python tools/c5d.py --module db analyze           # its Ghidra database (once, a few minutes)
python tools/c5d.py --module db task next --n 3   # claim db functions
python tools/c5d.py match --addr db:0x10007f50 -v # the module comes from the address
```

Both DLLs load at `0x10000000`, so the same address can be a different function in each:
always say which module you mean. Task bundles for a DLL already write their commands that way.

## 3. Sign in and claim work

1. Sign in with GitHub on the project site's **Account** page, accept the terms, and create an API token.
2. `python tools/c5d.py remote login --server https://<site> --token c5d_...`
3. `python tools/c5d.py remote claim --n 3 --model <model id>` reserves functions for 4 hours
   and writes `build/exe/tasks/<address>/TASK.md` for each one, with everything needed to solve it
   (with `--module db` or `loc`: functions from that DLL, under `build/<module>/tasks/`).
   The 25-claim limit counts all modules together.
   The model is kept on the claim, so the match is credited to it even if it's merged before
   you report it (verify then also closes the claim). `task next` and `agent` take `--model`
   too; without it they use `"model"` from `config.local.json`.

Claiming needs the login: `task next` and `agent` stop if you aren't logged in or the server
can't be reached, rather than claiming only on your machine where nobody else can see it.
`--local` does that on purpose, for offline work. Local-only claims are invisible to everyone
else, so claim those functions on the server (`remote claim 0x<addr>`) before you start, or
agree on them with the others first.

## 4. Match a function

Write the function in `modules/<module>/src/auto/f_<address>.cpp` and its symbol in
`modules/<module>/symbols/auto/f_<address>.txt` (the bundle explains both; for the exe that's
`modules/exe/...`), then:

```bash
python tools/c5d.py --worker w1 match --addr 0x00540240 -v
```

With `--addr`, match builds only the files connected to that function (the ones defining
what it calls, its callers, and so on outward), and unchanged files come from a shared
object cache in `build/objcache/`, so a check takes a second or two. `--all-files` builds
all of the module's `src/` instead.

- `MATCH`: identical, and every call and global points where the original's does. Done.
- `MATCH?`: identical bytes, but some references aren't named yet. Add them to the symbols file.
- `DIFF`: shows the two disassemblies side by side, with `!!` on the lines that differ.

**Inline asm is never a match.** Don't write `__asm` blocks or `__declspec(naked)`
functions. They reproduce the original bytes by construction, so a `MATCH` from one proves
nothing about the source. If C++ won't match, release the task instead of committing asm.
The only exception is code that was genuinely asm in the original (a CRT routine, for
example). Mark it with `// c5d-review:` saying why, and mention it in your pull request.

You can work by hand, with an AI agent, or both. Point the agent at the `TASK.md`, or set
`agent_cmd` in `config.local.json` and run `c5d agent`. Different `--worker` ids keep parallel
runs out of each other's way.

The whole loop, with token usage on the site: set an agent command that prints JSON, for example

```json
"agent_cmd": ["claude", "-p", "--permission-mode", "acceptEdits", "--output-format", "json"]
```

then `python tools/c5d.py agent --remote --n 3`. It claims from the server, runs the agent
(retrying with the diff), and reports each result with the tokens and model the agent
printed. If you run an agent another way, pass `--tokens-in/--tokens-out/--tokens-cached` to
`remote report` yourself.

Tips:
- Most code uses `/arch:SSE2 /fp:fast`. If a function only matches with other settings, add a
  `// c5d-cflags: -/arch:SSE2` line near the top of the file (see README).
- When only registers or instruction order differ, try a different parameter count first
  (callees often take more arguments than the code touches), then the return type, then
  `c5d-cflags` such as `+/Oy-` (frame pointers) or `+/hotpatch`.
- Known open problem: the allocator cluster (`FSBAAllocate` and friends) still differs only in which
  register the linker picks. Skip those unless you want to research it.

### Headers

Class and struct layouts go in `include/`, one header per class, named after it
(`include/<ClassName>.h`): that's how later tasks on the same class find it. Extend an
existing header instead of declaring the type again.

- The DLLs' classes are called from the exe too, so their headers are shared: `Database::`
  classes in `include/Database/`, `Localization::` classes in `include/Localization/`. They
  use an API macro (`CVGAMEDATABASE_API`, `CVLOCALIZATION_API`) that means
  `__declspec(dllimport)`; a DLL's own source files define it as `__declspec(dllexport)` before
  the `#include` (see `modules/db/src/database/Results.cpp`).
- A header only one DLL needs goes in `modules/<module>/include/` (for example
  `modules/db/include/sqlite3_api.h`, the SQLite calls the database code makes). It is searched
  after `include/`.
- The Civ V SDK has headers for both DLLs. Use them for names and layouts, and check every
  offset against the DLL's code; write the declarations yourself rather than copying them. Changing a header is safe as long as
everything that already matched still does: the `verify` check rebuilds every source that
includes a changed header and fails the pull request if one of its functions stops matching.

### Mark where a name comes from

Every name you give a function, class, struct, field or global gets a marker saying where it
came from, on the line before its definition or declaration (or at the end of its line):

```cpp
// src: GUESS 0x008e6f80 (confidence: low)
void* UnkRecord6C::GetBuffer6C()

struct CvUnit
{
    // src: SDK
    int m_iX;
```

Then a group of names can be found, and replaced or taken out, with one search
(`grep -rn "// src: GUESS"`). The address is the function's or global's own; leave it out for
types and fields.

| Tag | Where the name comes from |
|---|---|
| `EXE` | The game's own binaries: exported names (the DLLs export most of their classes), RTTI type names, strings that name the function, the Lua function tables |
| `SDK` | The Civ V SDK (`third_party/`, `modules/exe/names/sdk_vtables.csv`): interface and class names, method names, field names. Names and layouts only, never copied code |
| `LIB` | A byte-identical function in a library the game links (Lua 5.1, SQLite, ICU, the Visual C++ 2008 runtime, ...) |
| `COMMUNITY` | Community projects and documentation (modding wikis, other mods). Names only, never their code |
| `GUESS` | No source has a name: a best guess from what the code does |

A `GUESS` also rates how likely it is to be right:

| Confidence | Meaning |
|---|---|
| `high` | The code leaves one reading: a string names it, or its callers and callees make it unambiguous |
| `medium` | What it does is clear; why is inferred |
| `low` | Only the shape is known (a getter for an offset, a loop over entries): a neutral label, often with the address or offset in it (`UnkRecord6C`, `m_data6C`) |

Use the most reliable source that gives the name, in the order of the table. Renaming a
`GUESS` to a sourced name replaces the marker; a better guess keeps `GUESS` and updates
the confidence.

## 5. Report and open a pull request

```bash
python tools/c5d.py remote report 0x00540240 --model <model or "hand"> --tries 2
```

`report` re-checks the match on your machine before it reports. Give it several addresses
(`remote report 0x00540240 0x00540300 ...`) or `--claimed` (every claim that matches) to
re-check and report them all in one go. Then open a [pull request](https://github.com/JahsiasWhite/civ5-decomp/pulls) with
your `modules/exe/src/auto/f_*.cpp` and `modules/exe/symbols/auto/f_*.txt` files. Once it's merged, the verify workflow
re-runs the match on `main` (on every push, without the game) and the site marks it matched
within a few minutes.

## 6. See it work in the game (optional)

```bash
python tools/c5d.py build          # matched code -> a copy of your exe, verified identical
python tools/c5d.py build --diff   # also run non-matching (but equivalent) functions
python tools/c5d.py build --diff --run     # start the game with it (Steam must be running)
python tools/c5d.py build --clean  # remove what --run put in the game folder
```

`build` rewrites every matched function from our compiled code into a copy of your exe, at the
original addresses, and checks that the result is **byte-identical** to the original. `--diff`
redirects non-matching functions whose calls and globals all check out to our version, so you
can play the game and see whether the decompiled logic actually works. The hybrid exe is
built from your own copy and stays on your machine. Never share it.

With `--module db` or `loc`, `build` makes a hybrid DLL instead. The game loads a DLL by its
file name, so `--run` puts it in place of the game's copy, after saving the original (only if
it is the unmodified build), and `--clean` puts the original back. A `--diff` DLL only works
if Windows loads it at its preferred address, `0x10000000`; both DLLs want that address, so
one of them is moved, and if it's this one the game crashes. Steam's "Verify integrity of
game files" also restores the originals.

## Troubleshooting

| Problem | Fix |
|---|---|
| `not the build this project targets` | In Steam: let the game update, then Properties → Installed Files → Verify integrity, and make sure no beta branch is selected. Setup says so if your copy is the old 2014 build. |
| the server says `git pull` | Your checkout is older than the move to the 2026 build: `git pull`, then `python tools/c5d.py setup`. |
| `no 15.00.30729.01 compiler found` | See "The compiler" above. Banners for other versions are printed under the error. |
| `Java 17+` | Install a JDK 17 or newer and reopen the terminal, so `java` is on PATH. |
| `compile failed` while matching | The error is printed above it. Missing types go in `include/`. |
| Ghidra `analyze` is slow | That's normal the first time. Later runs reuse `ghidra_proj/`. |
| `isn't in the Ghidra project yet` | Run `analyze` once for that module: `python tools/c5d.py --module db analyze`. |
| `this run works on exe` for a `db:` address | Mixing modules in one command isn't possible; run each module's addresses separately. |
| A DLL function claims or reports as the wrong one | Give the module (`--module db` or `db:0x...`); a bare address means the exe. |

## jakedalt's token maxxing workflow

For AI-assisted batches, keep context small (tokens scale quadratically with turns):
- **1 batch of 25 per chat** (or run `/compact` between batches).
- **Skip full duplicate full doc reads** (`README.md`/`CONTRIBUTING.md`) when your workspace rules + `SKILL.md` already cover the workflow.
- **Claim past blockers** with `--min-size` (e.g. `--min-size 70`) and **pre-filter** claimed functions before dumping disassemblies.
- **Batch `match --obj` runs** (4–8 files per command, max 1–2 quick retries before releasing) and **quiet `match --fingerprints`** (`Select-String -NotMatch "^\s+MATCH "`).
- **Shortcut (`jdc <module> <min-size>`):** e.g. `jdc exe 70` means: claim 25 `<module>` functions with `--min-size <min-size>`, follow this token-maxxing workflow (pre-filter before disassembling, batch `match --obj` 4–8 at a time with max 2 retries before releasing), verify LTCG, report matches, release the rest, regenerate status quietly, and output the solved count.

