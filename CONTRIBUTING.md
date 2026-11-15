# Contributing to civ5-decomp

We rewrite the Civilization V engine (`CivilizationV_DX11.exe`) in C++, one function at a
time, so that it compiles back into exactly the same bytes. This guide gets you from nothing to your first
matched function.

**Ground rules:** you need your own legally owned copy of the game. Never commit or share
game files, machine code, disassembly or Ghidra output, only the C++ you write.

## 1. Install the tools

You need Windows and the following:

| Tool | Version | Notes |
|---|---|---|
| Civilization V | Steam, final build (Nov 2014) | Let Steam keep it updated. Setup checks the exact exe. |
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
2. finds the game in your Steam libraries and checks the exe's SHA-256 against
   `config.json`. A different build changes every address, so it has to match exactly.
3. finds Ghidra, Java and the compiler (plus the Windows SDK headers)
4. saves your paths in `config.local.json` (git-ignored, so it never leaves your machine)
5. builds the scope and work queue from the shared function list (`data/functions.csv`)
6. runs a test match on a function that is known to match

Every problem shows as `[!!]` with a line telling you how to fix it. Fix those and run setup again. Options:
`--game`, `--ghidra`, `--msvc` (point at a folder), `--sdk-headers` (also fetch the
Civ V SDK headers), `--no-install`.

Then build your local Ghidra database once. It supplies the pseudo-C in your task bundles and can take
an hour or more:

```bash
python tools/c5d.py analyze
```

## 3. Sign in and claim work

1. Sign in with GitHub on the project site's **Account** page, accept the terms, and create an API token.
2. `python tools/c5d.py remote login --server https://<site> --token c5d_...`
3. `python tools/c5d.py remote claim --n 3` reserves functions for 4 hours and writes
   `build/tasks/<address>/TASK.md` for each one, with everything needed to solve it.

## 4. Match a function

Write the function in `src/auto/f_<address>.cpp` and its symbol in
`symbols/auto/f_<address>.txt` (the bundle explains both), then:

```bash
python tools/c5d.py --worker w1 match --addr 0x00540240 -v
```

- `MATCH`: identical, and every call and global points where the original's does. Done.
- `MATCH?`: identical bytes, but some references aren't named yet. Add them to the symbols file.
- `DIFF`: shows the two disassemblies side by side, with `!!` on the lines that differ.

You can work by hand, with an AI agent, or both. Point the agent at the `TASK.md`, or set
`agent_cmd` in `config.local.json` and run `c5d agent`. Different `--worker` ids keep parallel
runs out of each other's way.

Tips:
- Most code uses `/arch:SSE2 /fp:fast`. If a function only matches with other settings, add a
  `// c5d-cflags: -/arch:SSE2` line near the top of the file (see README).
- Known open problem: the allocator cluster (`FSBAAllocate` and friends) still differs only in which
  register the linker picks. Skip those unless you want to research it.

## 5. Report and open a pull request

```bash
python tools/c5d.py remote report 0x00540240 --model <model or "hand"> --tries 2
```

`report` re-checks the match on your machine before it reports. Then open a [pull request](https://github.com/JahsiasWhite/civ5-decomp/pulls) with
your `src/auto/f_*.cpp` and `symbols/auto/f_*.txt` files. A maintainer re-runs the match against
their own copy of the game. It counts on the site once that nightly check confirms it.

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

## Troubleshooting

| Problem | Fix |
|---|---|
| `not the build this project targets` | In Steam: Properties → Installed Files → Verify integrity, and make sure no beta branch is selected. |
| `no 15.00.30729.01 compiler found` | See "The compiler" above. Banners for other versions are printed under the error. |
| `Java 17+` | Install a JDK 17 or newer and reopen the terminal, so `java` is on PATH. |
| `compile failed` while matching | The error is printed above it. Missing types go in `include/`. |
| Ghidra `analyze` is slow | That's normal the first time. Later runs reuse `ghidra_proj/`. |
