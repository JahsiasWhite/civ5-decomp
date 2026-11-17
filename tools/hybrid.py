"""Hybrid build: put the decompiled code into a copy of the real game exe.

`c5d build` takes our /LTCG-linked code for every function in src/ and writes it
into a copy of the player's own exe, relocated to the original addresses:

- MATCH functions are written in place. The relocated bytes must come out
  identical to the original, so with only matched code the whole hybrid exe is
  byte-identical to the original. That proves, end to end, that the rebuilt
  functions (and the relocation from our link back to the game's addresses)
  are right, at every stage of the project rather than only at 100%.
- With --diff, non-matching functions whose every call and global reference
  checks out are placed in a new `.c5d` section and the original entry jumps to
  them. The exe then really runs our C++ for those functions, so you can test
  them in the game. This changes the exe, so it is no longer identical: ASLR is
  turned off (fixed base) and the Authenticode signature is dropped.

The hybrid exe is built locally from the player's own copy and is never shared.
"""
import hashlib
import re
import shutil
import struct
import subprocess
from dataclasses import dataclass
from pathlib import Path

import ltcg

STEAM_APP_ID = "8930"             # Sid Meier's Civilization V
FILLER_LEA = re.compile(r"^(\w+), \[\1(?: \+ 0)?\]$")


@dataclass
class Item:
    name: str
    va: int                       # address in the original exe
    size: int                     # original size (Ghidra)
    res: dict                     # ltcg.compare result
    refs: dict                    # obj_refs (naming help for file statics)
    conv: str = ""                # calling convention guess from the queue
    src: str = ""


def _cs(detail):
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = detail
    return md


def function_body(test_img, lmap, name):
    """(our_va, bytes) of a function in the linked DLL: up to the next map symbol,
    trailing int3 padding removed. Includes any switch tables after the code."""
    our_va = lmap.by_name.get(name)
    if our_va is None:
        return None
    nxt = lmap.next_after(our_va)
    rva = our_va - test_img.image_base
    for _n, srva, vsize, _rp, rawsize in test_img.sections:
        if srva <= rva < srva + vsize:
            sec_end = test_img.image_base + srva + min(vsize, rawsize)
            nxt = sec_end if nxt is None else min(nxt, sec_end)  # last function in its section
            break
    if nxt is None:
        return None
    try:
        body = test_img.read(our_va, nxt - our_va)
    except ValueError:
        return None
    return our_va, body.rstrip(b"\xcc")


def code_length(body, our_va, relocs):
    """Where the instructions end and switch tables (absolute pointers back into
    the function, placed after a jmp/ret and alignment filler) begin."""
    md = _cs(False)
    off, stop = 0, False
    while off < len(body):
        va = our_va + off
        if stop and va % 4 == 0 and va in relocs:
            val = int.from_bytes(body[off:off + 4], "little")
            if our_va <= val < our_va + len(body):
                return off
        ins = next(md.disasm(body[off:off + 16], va, count=1), None)
        if ins is None:
            return off
        filler = ins.mnemonic in ("nop", "int3") or (
            ins.mnemonic == "lea" and FILLER_LEA.match(ins.op_str))
        stop = (stop and filler) or ins.mnemonic in ("ret", "jmp")
        off += ins.size
    return len(body)


def relocate(body, our_va, place_va, code_len, relocs, resolve):
    """Rewrite our code for address `place_va`: absolute references and branches
    that leave the function go to the original exe's addresses. Returns
    (bytes, [problems]); any problem means the function cannot be placed."""
    out, problems = bytearray(body), []
    for off in range(len(body) - 3):
        if our_va + off not in relocs:
            continue
        val = int.from_bytes(body[off:off + 4], "little")
        if our_va <= val < our_va + len(body):
            new = place_va + (val - our_va)
        else:
            label, new = resolve(val, off)
            if new is None:
                problems.append(f"+0x{off:x} {label}: address in the original unknown")
                continue
        out[off:off + 4] = (new & 0xFFFFFFFF).to_bytes(4, "little")
    for ins in _cs(True).disasm(body[:code_len], our_va):
        bi = ltcg._branch_imm(ins)
        if not bi:
            continue
        imm_off, imm_size, target = bi
        if our_va <= target < our_va + len(body):
            continue                           # internal: moves with the function
        off = ins.address - our_va
        label, exp = resolve(target)
        if exp is None:
            problems.append(f"+0x{off:x} call/jump to {label}: address in the original unknown")
            continue
        if imm_size != 4:
            problems.append(f"+0x{off:x} short jump out of the function")
            continue
        rel = (exp - (place_va + off + ins.size)) & 0xFFFFFFFF
        out[off + imm_off:off + imm_off + 4] = rel.to_bytes(4, "little")
    return bytes(out), problems


# ---------------------------------------------------------------- PE editing

def _u16(d, o):
    return struct.unpack_from("<H", d, o)[0]


def _u32(d, o):
    return struct.unpack_from("<I", d, o)[0]


def _align(x, a):
    return (x + a - 1) & ~(a - 1)


def new_section_rva(image):
    data = image.data
    pe = _u32(data, 0x3C)
    salign = _u32(data, pe + 24 + 32)
    return _align(max(rva + max(vs, rs) for _n, rva, vs, _rp, rs in image.sections), salign)


def add_code_section(data, name, rva, code):
    """Append an executable section. Drops the Authenticode signature (it could
    not stay valid), clears DYNAMICBASE (the patched entry jumps are absolute and
    have no base relocations) and zeroes the checksum."""
    pe = _u32(data, 0x3C)
    nsec, optsz = _u16(data, pe + 6), _u16(data, pe + 20)
    opt = pe + 24
    salign, falign = _u32(data, opt + 32), _u32(data, opt + 36)
    hdr = opt + optsz + 40 * nsec
    if hdr + 40 > _u32(data, opt + 60) or any(data[hdr:hdr + 40]):
        raise RuntimeError("no room for another section header")
    cert_off, cert_size = struct.unpack_from("<II", data, opt + 96 + 8 * 4)
    if cert_off and cert_off + cert_size >= len(data):
        del data[cert_off:]
        struct.pack_into("<II", data, opt + 96 + 8 * 4, 0, 0)
    raw_ptr = _align(len(data), falign)
    data.extend(b"\0" * (raw_ptr - len(data)))
    raw_size = _align(len(code), falign)
    data.extend(code + b"\0" * (raw_size - len(code)))
    struct.pack_into("<8sIIIIIIHHI", data, hdr, name.encode()[:8], len(code), rva, raw_size, raw_ptr,
                     0, 0, 0, 0, 0x60000020)                     # code | execute | read
    struct.pack_into("<H", data, pe + 6, nsec + 1)
    struct.pack_into("<I", data, opt + 56, _align(rva + len(code), salign))   # SizeOfImage
    struct.pack_into("<I", data, opt + 64, 0)                                   # CheckSum
    struct.pack_into("<H", data, opt + 70, _u16(data, opt + 70) & ~0x40)       # no DYNAMICBASE


# ---------------------------------------------------------------- build

def build(exe_path, image, test_img, lmap, syms, items, out_path, diff=False, force=False):
    data = bytearray(Path(exe_path).read_bytes())
    relocs = test_img.base_relocs()
    sec_rva = new_section_rva(image)
    sec_va = image.image_base + sec_rva
    new_code = bytearray()
    rebuilt, patched, kept, errors = [], [], [], []

    def file_off(va):
        return image._off(va - image.image_base)

    for it in items:
        status = it.res["status"]
        if status == "ERROR":
            errors.append((it, it.res.get("detail", "")))
            continue
        if status == "MATCH?":
            kept.append((it, "some references are not named yet; original bytes kept"))
            continue
        fb = function_body(test_img, lmap, it.name)
        if fb is None:
            errors.append((it, "could not find the function in the linked output"))
            continue
        our_va, body = fb
        code_len = code_length(body, our_va, relocs)
        resolve = ltcg.make_resolver(it.name, our_va, len(body), it.va, test_img, image,
                                     lmap, syms, it.refs)

        if status == "MATCH":
            new, probs = relocate(body, our_va, it.va, code_len, relocs, resolve)
            if probs:
                errors.append((it, "; ".join(probs)))
                continue
            # our body can run past the original's end (e.g. trailing data); the
            # original's own extent must agree byte for byte
            n = len(new) if image.read(it.va, len(new)) == new else min(len(new), it.size)
            if image.read(it.va, n) != new[:n]:
                errors.append((it, "relocated bytes differ from the original (relocation bug)"))
                continue
            o = file_off(it.va)
            data[o:o + n] = new[:n]
            rebuilt.append(it)
            continue

        # DIFF
        if not diff:
            kept.append((it, "not matched yet (use --diff to test it in game)"))
            continue
        reasons = []
        if any(s in ("BAD", "?") for s, *_ in it.res["relocs"]):
            reasons.append("its calls/globals don't all point where the original's do")
        if it.conv not in ("stack", "thiscall") and not force:
            reasons.append(f"calling convention '{it.conv or 'unknown'}' (use --force to try anyway)")
        if it.size < 5:
            reasons.append("original is too short for a jump")
        if reasons:
            kept.append((it, "; ".join(reasons)))
            continue
        new_code.extend(b"\xcc" * (_align(len(new_code), 16) - len(new_code)))
        place = sec_va + len(new_code)
        new, probs = relocate(body, our_va, place, code_len, relocs, resolve)
        if probs:
            kept.append((it, "; ".join(probs)))
            continue
        new_code.extend(new)
        o = file_off(it.va)
        data[o:o + 5] = b"\xe9" + ((place - (it.va + 5)) & 0xFFFFFFFF).to_bytes(4, "little")
        patched.append((it, place))

    if new_code:
        add_code_section(data, ".c5d", sec_rva, bytes(new_code))
    out_path = Path(out_path)
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_bytes(data)

    orig_hash = hashlib.sha256(image.data).hexdigest()
    new_hash = hashlib.sha256(data).hexdigest()
    return {"rebuilt": rebuilt, "patched": patched, "kept": kept, "errors": errors,
            "identical": orig_hash == new_hash, "sha256": new_hash, "out": out_path}


def report(r, root):
    lines = []
    rb = r["rebuilt"]
    lines.append(f"rebuilt from source, in place:   {len(rb)} matched functions "
                 f"({sum(i.size for i in rb):,} bytes)")
    if r["patched"]:
        lines.append(f"patched in (non-matching, test): {len(r['patched'])}")
        for it, place in r["patched"]:
            lines.append(f"    0x{it.va:08x} -> 0x{place:08x}  {it.name}")
    if r["kept"]:
        lines.append(f"left as original:               {len(r['kept'])}")
        for it, why in r["kept"]:
            lines.append(f"    0x{it.va:08x}  {it.name}: {why}")
    if r["errors"]:
        lines.append(f"ERRORS:                         {len(r['errors'])}")
        for it, why in r["errors"]:
            lines.append(f"    0x{it.va:08x}  {it.name}: {why}")
    try:
        out = r["out"].relative_to(root)
    except ValueError:
        out = r["out"]
    lines.append(f"\nwrote {out.as_posix() if hasattr(out, 'as_posix') else out}")
    if r["patched"]:
        lines.append("the exe now runs our code for the patched functions (ASLR off, signature removed)")
    elif r["identical"]:
        lines.append("VERIFIED: the hybrid exe is byte-identical to the original (SHA-256 matches)")
    else:
        lines.append("NOT identical to the original, although only matched code was written: this is a bug")
    return "\n".join(lines)


# ---------------------------------------------------------------- run in game

def run_in_game(hybrid_exe, game_dir, state_dir):
    """Copy the hybrid next to the real exe (it needs the game's files) and start
    it. steam_appid.txt stops the Steam API from relaunching the stock exe through
    Steam; it is created only if missing, and `c5d build --clean` removes both."""
    game_dir, state_dir = Path(game_dir), Path(state_dir)
    dest = game_dir / (Path(hybrid_exe).stem + "_c5d.exe")
    shutil.copy2(hybrid_exe, dest)
    appid = game_dir / "steam_appid.txt"
    if not appid.exists():
        appid.write_text(STEAM_APP_ID)
        (state_dir / "created_steam_appid").write_text(str(appid))
    print(f"starting {dest} (Steam must be running)")
    subprocess.Popen([str(dest)], cwd=str(game_dir))
    return dest


def clean_game(game_dir, target_exe, state_dir):
    game_dir, state_dir = Path(game_dir), Path(state_dir)
    removed = []
    dest = game_dir / (Path(target_exe).stem + "_c5d.exe")
    if dest.exists():
        dest.unlink()
        removed.append(dest)
    marker = state_dir / "created_steam_appid"
    if marker.exists():
        appid = Path(marker.read_text())
        if appid.exists():
            appid.unlink()
            removed.append(appid)
        marker.unlink()
    for p in removed:
        print(f"removed {p}")
    if not removed:
        print("nothing to clean")
    return 0


# ---------------------------------------------------------------- run with a DLL module
#
# The exe looks a DLL up by its file name, so a hybrid DLL can't sit beside the original
# the way the hybrid exe does: it replaces the game's copy for the run. The original is
# saved first (once, and only if it really is the targeted build) and `--clean` puts it
# back. Steam's "Verify integrity of game files" also restores it.

def _dll_backup(state_dir, dll_name):
    return Path(state_dir) / "original" / dll_name


def run_with_dll(hybrid_dll, game_dir, dll_name, exe_name, state_dir, build_hash, patched=False):
    import setup_env
    game_dir, state_dir = Path(game_dir), Path(state_dir)
    live = game_dir / dll_name
    backup = _dll_backup(state_dir, dll_name)
    if not backup.exists():
        if not setup_env.exe_is_target(live, build_hash):
            raise SystemExit(f"{live} is not the original build and there is no backup of it in "
                             f"{backup.parent}: restore it first (Steam: Verify integrity of game files)")
        backup.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(live, backup)
    if patched:
        print(f"note: the patched {dll_name} jumps to absolute addresses and has no relocations for "
              "them, so it only works if Windows loads it at its preferred base (0x10000000). Both "
              "game DLLs prefer that base, so one of them is moved; if this one is, the game crashes.")
    try:
        shutil.copy2(hybrid_dll, live)
    except PermissionError:
        raise SystemExit(f"can't replace {live}: it's in use. Close the game (an earlier "
                         "hybrid run may still be open) and try again.")
    appid = game_dir / "steam_appid.txt"
    if not appid.exists():
        appid.write_text(STEAM_APP_ID)
        (state_dir / "created_steam_appid").write_text(str(appid))
    exe = game_dir / exe_name
    print(f"replaced {live} (original saved to {backup}); starting {exe} (Steam must be running). "
          "`c5d build --clean` puts the original back.")
    subprocess.Popen([str(exe)], cwd=str(game_dir))
    return live


def has_dll_backup(state_dir, dll_name):
    """True if a DLL module's run swapped its DLL in and `--clean` hasn't put it back."""
    return _dll_backup(state_dir, dll_name).exists()


def clean_dll(game_dir, dll_name, state_dir, build_hash):
    import setup_env
    game_dir, state_dir = Path(game_dir), Path(state_dir)
    live, backup = game_dir / dll_name, _dll_backup(state_dir, dll_name)
    done = []
    if backup.exists():
        if not setup_env.exe_is_target(backup, build_hash):
            raise SystemExit(f"{backup} is not the original build; not restoring it. "
                             "Use Steam's Verify integrity of game files instead.")
        try:
            shutil.copy2(backup, live)
        except PermissionError:
            raise SystemExit(f"can't restore {live}: it's in use. Close the game and run "
                             "`--clean` again.")
        backup.unlink()
        done.append(f"restored {live}")
    marker = state_dir / "created_steam_appid"
    if marker.exists():
        appid = Path(marker.read_text())
        if appid.exists():
            appid.unlink()
            done.append(f"removed {appid}")
        marker.unlink()
    print("\n".join(done) if done else "nothing to clean")
    return 0
