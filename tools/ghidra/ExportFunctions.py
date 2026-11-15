# Export every function Ghidra found to a CSV (entry, size, name, flags).
# Runs inside Ghidra (Jython 2.7) via analyzeHeadless -postScript.
# @category civ5decomp
import csv

args = getScriptArgs()
out_path = args[0] if args else "functions.csv"

fm = currentProgram.getFunctionManager()
mem = currentProgram.getMemory()

with open(out_path, "wb") as fh:
    w = csv.writer(fh)
    w.writerow(["entry", "size", "min", "max", "ranges", "block",
                "name", "thunk", "external"])
    count = 0
    for f in fm.getFunctions(True):
        body = f.getBody()
        entry = f.getEntryPoint()
        block = mem.getBlock(entry)
        w.writerow([
            "0x%08x" % entry.getOffset(),
            body.getNumAddresses(),
            "0x%08x" % body.getMinAddress().getOffset(),
            "0x%08x" % body.getMaxAddress().getOffset(),
            body.getNumAddressRanges(),
            block.getName() if block else "",
            f.getName(True),
            int(f.isThunk()),
            int(f.isExternal()),
        ])
        count += 1

print("ExportFunctions: wrote %d functions to %s" % (count, out_path))
