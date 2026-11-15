# Dump disassembly + Ghidra decompiler output for the given function
# entry addresses into an output directory (local reference only; the
# output lives under build/ and must never be committed).
# Usage (via analyzeHeadless -postScript): DumpFunctions.py <outdir> <addr> [addr ...]
# @category civ5decomp
import os
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

args = getScriptArgs()
out_dir = args[0]
if not os.path.isdir(out_dir):
    os.makedirs(out_dir)

decomp = DecompInterface()
decomp.openProgram(currentProgram)
listing = currentProgram.getListing()
fm = currentProgram.getFunctionManager()

for a in args[1:]:
    addr = toAddr(a)
    f = fm.getFunctionAt(addr)
    if f is None:
        # a function Ghidra missed (`new` in boundary_overrides.txt): create it in memory
        # (the project is opened -readOnly, so nothing is saved)
        disassemble(addr)
        f = createFunction(addr, None)
    if f is None:
        print("DumpFunctions: no function at %s" % a)
        continue
    lines = ["// %s @ %s, %d bytes" % (f.getName(True), addr, f.getBody().getNumAddresses()),
             "// calling convention: %s" % f.getCallingConventionName(),
             "", "// ---- disassembly ----"]
    for ins in listing.getInstructions(f.getBody(), True):
        raw = " ".join("%02x" % (b & 0xff) for b in ins.getBytes())
        lines.append("%s  %-30s %s" % (ins.getAddress(), raw, ins))
    res = decomp.decompileFunction(f, 60, ConsoleTaskMonitor())
    lines += ["", "// ---- ghidra decompile ----"]
    lines.append(res.getDecompiledFunction().getC() if res.decompileCompleted()
                 else "// decompile failed: " + str(res.getErrorMessage()))
    path = os.path.join(out_dir, "%s_%s.txt" % (str(addr), f.getName().replace(":", "_")))
    with open(path, "w") as fh:
        fh.write("\n".join(lines))
    print("DumpFunctions: wrote " + path)
