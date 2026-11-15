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

## Findings so far

- **Scope:** Ghidra finds 20,152 functions (about 4.6 MB). Roughly 11k of them are
  64 to 255 bytes. The CRT is dynamic (`MSVCR90.DLL`, which confirms VC++ 2008),
  and Lua lives in `lua51_Win32.dll`, so neither needs to be decompiled. MFC and
  ATL code is statically linked and will be identified and excluded.
- **Exports give us free names:** the exe exports Firaxis engine functions
  (`FSBA*`, `FJobSet*`, `GetLogFileMgr`, ...) for the gameplay DLL to call.
- **Probably LTCG:** `FSBAIsSmallBlock` calls an internal function with
  arguments in EAX/EDI instead of on the stack. Only whole-program optimisation
  produces that. Leaf functions should still match one at a time; functions
  calling LTCG-optimised callees will need those callees in the same `/GL` build.
- **Code style:** `/O2`-style output (no frame pointer), cdecl exports.
- **First matches (2026-11-14):** 4 FSBA functions match byte for byte with
  `cl 15.00.30729.01 /O2 /Gy /MD /EHsc /GR`, with all relocation targets checked.
  So the compiler and baseline flags are right, at least for leaf functions.

## Phases

1. **Slice:** match one small function by hand, end to end. This proves the
   compiler and flags, and tells us whether `/LTCG` was used.
2. **Harden:** build a `match` command that ignores relocations, set up the
   class-definition library, and match 20 to 50 functions to measure the hit rate.
3. **Scale:** add the function queue, the AI agent loop and progress tracking (plus the site).

## Layout

```
config.json        local paths (game, Ghidra, MSVC) + compiler flags
symbols.txt        address <-> symbol map (drives `match`)
tools/c5d.py       CLI: `env`, `analyze`, `dump`, `match`
tools/binfmt.py    PE / COFF readers
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
3. Run `python tools/c5d.py match src/area/File.cpp` (add `-v` for detail). The
   tool compiles with the flags in `config.json`, takes the same bytes from the
   exe, and compares them while masking relocations. Each relocation must point
   where the original does (resolved via `symbols.txt`).
   - `MATCH`: identical, and every relocation target is verified.
   - `MATCH?`: identical bytes, but some relocation targets are unknown (add them to `symbols.txt`).
   - `DIFF`: a side-by-side disassembly with `!!` on differing lines
     (`r` = differs only in a relocation that checked out).
