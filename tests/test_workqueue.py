"""tools/workqueue.py: call cycles count as one unit for readiness."""
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "tools"))
workqueue = pytest.importorskip("workqueue")      # needs capstone


# 1 -> 2 -> 3 -> 2 (cycle {2,3}), 3 -> 4 (leaf), 5 -> 6 -> 7 -> 5 (cycle {5,6,7}), 8 -> 1
GRAPH = {1: [2], 2: [3], 3: [2, 4], 4: [], 5: [6], 6: [7], 7: [5], 8: [1]}


def test_call_cycles():
    c = workqueue.call_cycles(GRAPH)
    assert c[2] == c[3] == frozenset({2, 3})
    assert c[5] == c[6] == c[7] == frozenset({5, 6, 7})
    assert not {1, 4, 8} & set(c)


def test_call_cycles_ignores_unknown_callees_and_handles_deep_chains():
    assert workqueue.call_cycles({1: [99]}) == {}
    n = 50000                                          # no recursion limit
    chain = {i: [i + 1] for i in range(n)}
    chain[n] = [0]
    assert len(workqueue.call_cycles(chain)[0]) == n + 1


def test_cycle_waits_only_on_what_it_calls_outside_itself():
    r = workqueue.readiness(GRAPH, {})
    assert r[4] and r[5] and r[6] and r[7]             # a closed cycle is ready at once
    assert not r[2] and not r[3]                       # the cycle {2,3} waits on 4 (via 3)
    assert not r[1] and not r[8]
    r = workqueue.readiness(GRAPH, {4: "MATCH"})
    assert r[3] and r[2]                               # 4 matched: the whole cycle is ready
    assert not r[1]                                    # 1 still waits on 2
    r = workqueue.readiness(GRAPH, {4: "MATCH", 2: "MATCH", 3: "DIFF"})
    assert r[1] and not r[8]                           # outside a cycle, the usual rule
    r = workqueue.readiness({1: [2], 2: [3, 9], 3: [2], 9: []}, {3: "MATCH"})
    assert not r[2] and not r[3]                       # 3 waits on 9, which only 2 calls
