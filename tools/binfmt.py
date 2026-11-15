"""Minimal PE (image) and COFF (object) readers for the matching harness."""
import struct
from dataclasses import dataclass, field

# i386 relocation types we care about
REL_I386_DIR32 = 0x06
REL_I386_DIR32NB = 0x07
REL_I386_REL32 = 0x14


class PEImage:
    """Read-only view of a 32-bit PE image: map virtual addresses to bytes."""

    def __init__(self, path):
        with open(path, "rb") as fh:
            self.data = fh.read()
        d = self.data
        pe = struct.unpack_from("<I", d, 0x3C)[0]
        if d[pe:pe + 4] != b"PE\0\0":
            raise ValueError(f"{path}: not a PE file")
        nsec, = struct.unpack_from("<H", d, pe + 6)
        opt_size, = struct.unpack_from("<H", d, pe + 20)
        opt = pe + 24
        self.image_base, = struct.unpack_from("<I", d, opt + 28)
        self.sections = []
        s = opt + opt_size
        for i in range(nsec):
            o = s + 40 * i
            name = d[o:o + 8].rstrip(b"\0").decode("ascii", "replace")
            vsize, rva, rawsize, rawptr = struct.unpack_from("<IIII", d, o + 8)
            self.sections.append((name, rva, vsize, rawptr, rawsize))

    def read(self, va, size):
        rva = va - self.image_base
        for name, srva, vsize, rawptr, rawsize in self.sections:
            if srva <= rva < srva + max(vsize, rawsize):
                off = rva - srva
                if off + size > rawsize:
                    raise ValueError(f"0x{va:08x}+{size} runs past raw data of {name}")
                return self.data[rawptr + off: rawptr + off + size]
        raise ValueError(f"0x{va:08x} is not in any section")


@dataclass
class Symbol:
    index: int
    name: str
    value: int
    section: int          # 1-based; 0 = undefined/external, <0 = special
    type: int
    storage: int

    @property
    def is_function(self):
        return (self.type >> 4) == 2 and self.section > 0


@dataclass
class Reloc:
    offset: int           # offset within the section
    symbol: Symbol
    type: int


@dataclass
class Section:
    index: int            # 1-based
    name: str
    data: bytes
    characteristics: int
    relocs: list = field(default_factory=list)


class CoffObject:
    """Parse an MSVC (non-/bigobj) i386 COFF object file."""

    def __init__(self, path):
        with open(path, "rb") as fh:
            d = fh.read()
        machine, nsec, _ts, symptr, nsym, optsz, _ch = struct.unpack_from("<HHIIIHH", d, 0)
        if machine != 0x14C:
            raise ValueError(f"{path}: not an i386 COFF object (machine 0x{machine:x})")
        strtab = symptr + 18 * nsym

        def cstr(off):
            end = d.index(b"\0", strtab + off)
            return d[strtab + off:end].decode("latin-1")

        # symbols
        self.symbols = {}
        i = 0
        while i < nsym:
            o = symptr + 18 * i
            raw = d[o:o + 8]
            if raw[:4] == b"\0\0\0\0":
                name = cstr(struct.unpack_from("<I", raw, 4)[0])
            else:
                name = raw.rstrip(b"\0").decode("latin-1")
            value, secnum, typ, storage, naux = struct.unpack_from("<IhHBB", d, o + 8)
            self.symbols[i] = Symbol(i, name, value, secnum, typ, storage)
            i += 1 + naux

        # sections + relocations
        self.sections = {}
        for s in range(nsec):
            o = 20 + optsz + 40 * s
            raw = d[o:o + 8]
            name = raw.rstrip(b"\0").decode("latin-1")
            if name.startswith("/"):
                name = cstr(int(name[1:]))
            (_vs, _va, rawsize, rawptr, relptr, _lnptr,
             nrel, _nln, chars) = struct.unpack_from("<IIIIIIHHI", d, o + 8)
            sec = Section(s + 1, name, d[rawptr:rawptr + rawsize] if rawptr else b"", chars)
            for r in range(nrel):
                roff, rsym, rtype = struct.unpack_from("<IIH", d, relptr + 10 * r)
                sec.relocs.append(Reloc(roff, self.symbols[rsym], rtype))
            self.sections[s + 1] = sec

    def functions(self):
        """Yield (symbol, section, start, end) for each function defined here."""
        funcs = [s for s in self.symbols.values() if s.is_function]
        by_sec = {}
        for f in funcs:
            by_sec.setdefault(f.section, []).append(f)
        for secnum, fs in by_sec.items():
            sec = self.sections[secnum]
            fs.sort(key=lambda f: f.value)
            for j, f in enumerate(fs):
                end = fs[j + 1].value if j + 1 < len(fs) else len(sec.data)
                yield f, sec, f.value, end
