"""Build the work queue: in-scope functions ordered leaves-first.

    python tools/c5d.py queue [--top N]   -> build/queue.csv

For every game function (build/scope.csv) we disassemble the body, collect
direct callees, and guess the calling convention from which registers are
read before being written:
  stack     arguments on the stack only (cdecl/stdcall)
  thiscall  ECX read on entry (member function, standard convention)
  custom    EAX/EDX/EBX/ESI/EDI read on entry: an LTCG custom convention, so
            the function's callers must be linked with it to match

Ordering (lower = sooner): functions whose callees are all done or out of
scope come first ("ready"), then by call depth from the leaves, then size.
Custom-convention functions are grouped with their callers' cluster id so a
worker can take a whole cluster at once.

Functions that call each other (a call cycle) can't wait on each other: a cycle is one
unit, ready once everything it calls outside itself is matched, and one cluster.

The call graph (in-scope callees of every in-scope function, addresses only) is also
written to data/callgraph.csv, which is committed: with it and progress/status.csv,
readiness can be worked out without the game, so CI's `manage.py push` keeps it current.
"""
import csv
from collections import defaultdict
from pathlib import Path

import capstone
from capstone import x86

ARG_REGS = {x86.X86_REG_EAX: "eax", x86.X86_REG_ECX: "ecx", x86.X86_REG_EDX: "edx",
            x86.X86_REG_EBX: "ebx", x86.X86_REG_ESI: "esi", x86.X86_REG_EDI: "edi"}
SUBREG = {x86.X86_REG_AL: x86.X86_REG_EAX, x86.X86_REG_AX: x86.X86_REG_EAX,
          x86.X86_REG_CL: x86.X86_REG_ECX, x86.X86_REG_CX: x86.X86_REG_ECX,
          x86.X86_REG_DL: x86.X86_REG_EDX, x86.X86_REG_DX: x86.X86_REG_EDX,
          x86.X86_REG_BL: x86.X86_REG_EBX, x86.X86_REG_BX: x86.X86_REG_EBX,
          x86.X86_REG_SI: x86.X86_REG_ESI, x86.X86_REG_DI: x86.X86_REG_EDI}


def analyse(img, addr, size, md):
    """-> (callees set, convention, regs read on entry)"""
    try:
        code = img.read(addr, size)
    except ValueError:
        return set(), "stack", ""
    callees, written, read_first = set(), set(), []
    straight = True                        # only track until the first branch
    for ins in md.disasm(code, addr):
        if ins.id == x86.X86_INS_CALL and ins.operands and ins.operands[0].type == x86.X86_OP_IMM:
            callees.add(ins.operands[0].imm & 0xFFFFFFFF)
        elif ins.id == x86.X86_INS_JMP and ins.operands and ins.operands[0].type == x86.X86_OP_IMM:
            t = ins.operands[0].imm & 0xFFFFFFFF
            if not (addr <= t < addr + size):
                callees.add(t)             # tail call
        if straight:
            if ins.id in (x86.X86_INS_PUSH,) and ins.operands and ins.operands[0].type == x86.X86_OP_REG \
                    and ins.operands[0].reg in (x86.X86_REG_EBX, x86.X86_REG_ESI, x86.X86_REG_EDI, x86.X86_REG_EBP):
                pass                       # callee-saved register spill, not a use
            elif ins.id == x86.X86_INS_XOR and len(ins.operands) == 2 and \
                    ins.operands[0].type == ins.operands[1].type == x86.X86_OP_REG and \
                    ins.operands[0].reg == ins.operands[1].reg:
                written.add(SUBREG.get(ins.operands[0].reg, ins.operands[0].reg))
            else:
                regs_read, regs_write = ins.regs_access()
                for r in regs_read:
                    r = SUBREG.get(r, r)
                    if r in ARG_REGS and r not in written and r not in read_first:
                        read_first.append(r)
                for r in regs_write:
                    written.add(SUBREG.get(r, r))
            if ins.group(capstone.CS_GRP_JUMP) or ins.group(capstone.CS_GRP_RET) \
                    or ins.id == x86.X86_INS_CALL:
                straight = False
    names = [ARG_REGS[r] for r in read_first]
    if any(n != "ecx" for n in names):
        conv = "custom"
    elif "ecx" in names:
        conv = "thiscall"
    else:
        conv = "stack"
    return callees, conv, "+".join(names)


def write_callgraph(callees, path):
    """callees: {addr: set of in-scope callee addrs} -> `entry,callees` rows (callees
    space-separated), sorted, LF line endings, so an unchanged graph gives an unchanged file."""
    with open(path, "w", newline="") as fh:
        fh.write("entry,callees\n")
        for a in sorted(callees):
            fh.write(f"0x{a:08x}," + " ".join(f"0x{c:08x}" for c in sorted(callees[a])) + "\n")


def read_callgraph(path):
    """{addr: [callee addrs]} from data/callgraph.csv."""
    out = {}
    with open(path, newline="") as fh:
        for r in csv.DictReader(fh):
            out[int(r["entry"], 16)] = [int(c, 16) for c in r["callees"].split()]
    return out


def call_cycles(callgraph):
    """{addr: frozenset of its cycle} for every function in a call cycle (functions that
    call each other, directly or through others: a strongly connected component of 2+).
    Iterative Tarjan; callees missing from the graph are ignored."""
    index, low, on, stack, out = {}, {}, set(), [], {}
    counter = 0
    for root in callgraph:
        if root in index:
            continue
        index[root] = low[root] = counter
        counter += 1
        stack.append(root)
        on.add(root)
        work = [(root, iter(callgraph[root]))]
        while work:
            v, it = work[-1]
            for w in it:
                if w not in callgraph:
                    continue
                if w not in index:
                    index[w] = low[w] = counter
                    counter += 1
                    stack.append(w)
                    on.add(w)
                    work.append((w, iter(callgraph[w])))
                    break
                if w in on:
                    low[v] = min(low[v], index[w])
            else:
                work.pop()
                if work:
                    low[work[-1][0]] = min(low[work[-1][0]], low[v])
                if low[v] == index[v]:
                    comp = []
                    while True:
                        w = stack.pop()
                        on.discard(w)
                        comp.append(w)
                        if w == v:
                            break
                    if len(comp) > 1:
                        group = frozenset(comp)
                        out.update((a, group) for a in comp)
    return out


def pending(addr, callgraph, done, cycles):
    """Callees `addr` still waits for. A call cycle is one unit: each member waits on
    the unmatched functions any member calls outside the cycle, not on the other members
    (otherwise each would wait on another forever, and so would everything calling in)."""
    group = cycles.get(addr)
    if group is None:
        return [c for c in callgraph[addr] if c not in done]
    return sorted({c for m in group for c in callgraph.get(m, ())
                   if c not in done and c not in group})


def readiness(callgraph, status):
    """{addr: bool}: ready when every callee is matched (or there are none), a call cycle
    as one unit (see pending). Same rule as pending_callees == 0 in the queue."""
    done = {a for a, s in status.items() if s == "MATCH"}
    cycles = call_cycles(callgraph)
    return {a: not pending(a, callgraph, done, cycles) for a in callgraph}


def build(img, scope_csv, status, names, out_csv, callgraph_csv=None):
    game = {}
    with open(scope_csv, newline="") as fh:
        for r in csv.DictReader(fh):
            if r["category"] == "game":
                game[int(r["entry"], 16)] = int(r["size"])

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    info = {}
    for a, size in game.items():
        callees, conv, regs = analyse(img, a, size, md)
        info[a] = {"size": size, "callees": {c for c in callees if c in game and c != a},
                   "conv": conv, "regs": regs}
    if callgraph_csv:
        write_callgraph({a: d["callees"] for a, d in info.items()}, callgraph_csv)
    callers = defaultdict(set)
    for a, d in info.items():
        for c in d["callees"]:
            callers[c].add(a)

    # depth from leaves (iterative; cycles cut by treating in-progress as 0)
    depth = {}
    for root in info:
        if root in depth:
            continue
        stack = [(root, iter(info[root]["callees"]))]
        on = {root}
        while stack:
            node, it = stack[-1]
            nxt = next((c for c in it if c not in depth and c not in on), None)
            if nxt is not None:
                on.add(nxt)
                stack.append((nxt, iter(info[nxt]["callees"])))
                continue
            stack.pop()
            on.discard(node)
            depth[node] = 1 + max((depth.get(c, 0) for c in info[node]["callees"]), default=-1)

    # clusters: custom-convention callees join their callers (union-find)
    parent = {a: a for a in info}

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x
    for a, d in info.items():
        if d["conv"] == "custom":
            for c in callers[a]:
                parent[find(c)] = find(a)
    # a call cycle is handed out as one unit too
    graph = {a: d["callees"] for a, d in info.items()}
    cycles = call_cycles(graph)
    for a, group in cycles.items():
        parent[find(a)] = find(min(group))
    clusters = defaultdict(list)
    for a in info:
        clusters[find(a)].append(a)

    done = {a for a, s in status.items() if s == "MATCH"}
    rows = []
    for a, d in info.items():
        pending_callees = pending(a, graph, done, cycles)
        cid = find(a)
        rows.append({
            "entry": f"0x{a:08x}", "size": d["size"], "name": names.get(a, ""),
            "status": status.get(a, "todo"), "conv": d["conv"], "entry_regs": d["regs"],
            "depth": depth.get(a, 0), "callees": len(d["callees"]),
            "pending_callees": len(pending_callees), "callers": len(callers[a]),
            "cluster": f"0x{cid:08x}", "cluster_size": len(clusters[cid]),
        })
    rows.sort(key=lambda r: (r["status"] == "MATCH", r["pending_callees"] > 0, r["depth"],
                             r["cluster_size"] > 1, r["size"]))
    with open(out_csv, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()))
        w.writeheader()
        w.writerows(rows)
    return rows
