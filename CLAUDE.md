# civ5-decomp: notes for agents

Byte-matching decompilation of `CivilizationV_DX11.exe`. [CONTRIBUTING.md](CONTRIBUTING.md)
is the source of truth for the workflow and each `build/tasks/<addr>/TASK.md` has the house
rules for that function. Read both before you start; don't copy the workflow from git history.

## A batch of matches, in order

Skip no step. If a step fails or a permission check blocks it, stop and tell the user. Don't
carry on without it.

1. **Claim:** `python tools/c5d.py task next --n 8`. This claims on the server and writes the
   task bundles. The server allows 25 open claims per user. If you're at the limit, run
   `python tools/c5d.py remote status` and deal with the leftovers first.
2. **Match:** for each address, write `src/auto/f_<addr>.cpp` and `symbols/auto/f_<addr>.txt`,
   then run `python tools/c5d.py --worker w1 match --addr 0x<addr> -v` until it says `MATCH`.
3. **Report** every `MATCH` before it is committed, all in one call:
   `python tools/c5d.py --worker w1 remote report 0x<a> 0x<b> ... --model <model id> --tries <n>`
   (or `remote report --claimed --model <model id>` for every claim that matches). This
   re-checks them locally in a single build, records which model wrote them, and frees the
   claims. Pass `--model` explicitly, because `config.local.json` has no default.
4. **Release** anything you gave up on: `python tools/c5d.py remote release 0x<a> 0x<b> ...`.
5. **Check:** `python tools/c5d.py remote status` should list none of this batch's addresses.
6. **Commit** only when the user has asked for it. TASK.md says "Don't commit" by default.
   Commit just `src/auto/` and `symbols/auto/` (plus any new `include/` headers).

Why the order matters: merging or pushing never tells the server anything. Verify marks merged
functions matched, but it never clears claims, and once a function is verified, a late report
no longer sets its model, so the site shows "unspecified". Unreported claims also count toward
the 25 limit until they expire after 4 hours.

## Source rules

- Hand-written C++ only: no disassembly, hex bytes or Ghidra output in source or comments.
- No credit or model lines in source files (no `// c5d-model:`).
- Don't edit `tools/`, `config.json`, `config.local.json`, `symbols.txt` or other people's
  functions while working a task.
- Tricks the original source wouldn't have used (`volatile`, inline asm, `#pragma`, an array
  standing in for a vtable) need a `// c5d-review:` line and a mention in your summary.
