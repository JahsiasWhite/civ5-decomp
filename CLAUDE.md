# civ5-decomp: notes for agents

Byte-matching decompilation of Civilization V: the engine (`CivilizationV_DX11.exe`) and its two
game DLLs. [CONTRIBUTING.md](CONTRIBUTING.md) is the source of truth for the workflow and each
`build/<module>/tasks/<addr>/TASK.md` has the house rules for that function. Read both before you
start; don't copy the workflow from git history.

## Modules

Each binary is a module with its own folder, `modules/<module>/`:

| Module | Binary | Notes |
|---|---|---|
| `exe` | `CivilizationV_DX11.exe` | the default |
| `db` | `CvGameDatabaseWin32Final Release.dll` | SQLite inside it is out of scope |
| `loc` | `CvLocalizationWin32Final Release.dll` | ICU inside it is out of scope |

A batch works on one module. For the exe, the commands below are used as written. For a DLL, put
`--module <module>` before the subcommand (`python tools/c5d.py --module db task next ...`), or write
addresses as `db:0x10001234`; the commands in a DLL's TASK.md are already written that way. Both
DLLs load at `0x10000000`, so the same address can mean a different function in each.

## A batch of matches, in order

Skip no step. If a step fails or a permission check blocks it, stop and tell the user. Don't
carry on without it.

1. **Claim:** `python tools/c5d.py task next --n 8 --model <model id>`. This claims on the
   server (recording the model on each claim) and writes the task bundles. The server allows 25
   open claims per user, across all modules. If you're at the limit, run
   `python tools/c5d.py remote status` and deal with the leftovers first.
2. **Match:** for each address, write `modules/<module>/src/auto/f_<addr>.cpp` and
   `modules/<module>/symbols/auto/f_<addr>.txt`, then run
   `python tools/c5d.py --worker w1 match --addr 0x<addr> -v` until it says `MATCH`.
3. **Report** every `MATCH` before it is committed, all in one call:
   `python tools/c5d.py --worker w1 remote report 0x<a> 0x<b> ... --model <model id> --tries <n>`
   (or `remote report --claimed --model <model id>` for every claim in the module that matches).
   This re-checks them locally in a single build, records which model wrote them, and frees the
   claims. Pass `--model` explicitly, because `config.local.json` has no default.
4. **Release** anything you gave up on: `python tools/c5d.py remote release 0x<a> 0x<b> ...`.
5. **Check:** `python tools/c5d.py remote status` should list none of this batch's addresses.
6. **Commit** only when the user has asked for it. TASK.md says "Don't commit" by default.
   Commit just `modules/<module>/src/auto/` and `modules/<module>/symbols/auto/` (plus any new
   headers in `include/` or `modules/<module>/include/`).

Verify isn't nightly: `.github/workflows/verify.yml` runs on every push to `main` (and twice a
day), so a merged function is marked matched, and its callers become ready, within minutes.

Why the order still matters: the report is what records tokens and tries, and it frees the
claims right away. If a match is merged while still claimed, verify credits it to the claim's
model and closes the claim, so nothing is lost, but the token and try counts are. Claiming
without `--model` leaves such a match "unspecified". Unreported claims count toward the 25
limit until verify or the 4-hour expiry clears them.

## Source rules

- Hand-written C++ only: no disassembly, hex bytes or Ghidra output in source or comments.
- No credit or model lines in source files (no `// c5d-model:`).
- Don't edit `tools/`, `config.json`, `config.local.json`, a module's `symbols.txt` or other
  people's functions while working a task.
- Tricks the original source wouldn't have used (`volatile`, inline asm, `#pragma`, an array
  standing in for a vtable) need a `// c5d-review:` line and a mention in your summary.
- Headers: a class more than one module uses (the DLLs' exported classes, which the exe calls)
  goes in `include/` (`include/Database/`, `include/Localization/`); one only a DLL uses goes in
  `modules/<module>/include/`. A DLL's own sources define its API macro as
  `__declspec(dllexport)` before including its headers (see `modules/db/src/database/`).
- SDK headers are a reference for names and layouts; write declarations yourself, never copy them.
