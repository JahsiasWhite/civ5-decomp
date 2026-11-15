"""Token usage from an agent CLI's output, so reports carry real numbers.

Agent CLIs that print a JSON result are understood, e.g. Claude Code's
`claude -p --output-format json` (one object) or `--output-format stream-json`
(one object per line; the last "result" line counts). The fields read are
`modelUsage` (per model: inputTokens, outputTokens, cacheReadInputTokens,
cacheCreationInputTokens), falling back to `usage` (input_tokens, output_tokens,
cache_read_input_tokens, cache_creation_input_tokens).

Counted as: tokens_in = input + cache writes, tokens_cached = cache reads,
tokens_out = output. Output that isn't such JSON gives None (nothing is guessed).

Per task, usage is summed over tries in build/tasks/<addr>/usage.json, which
`c5d remote report` sends when no --tokens-* flags are given.
"""
import json
from pathlib import Path

EMPTY = {"tokens_in": 0, "tokens_out": 0, "tokens_cached": 0, "tries": 0, "model": ""}


def _objects(text):
    """JSON objects in the output: the whole text, else one per line."""
    text = (text or "").strip()
    if not text:
        return []
    try:
        o = json.loads(text)
        return [o] if isinstance(o, dict) else [x for x in o if isinstance(x, dict)] if isinstance(o, list) else []
    except ValueError:
        pass
    out = []
    for line in text.splitlines():
        line = line.strip()
        if line.startswith("{"):
            try:
                o = json.loads(line)
            except ValueError:
                continue
            if isinstance(o, dict):
                out.append(o)
    return out


def parse(text):
    """-> {"tokens_in", "tokens_out", "tokens_cached", "model"} or None."""
    objs = [o for o in _objects(text) if "modelUsage" in o or "usage" in o]
    if not objs:
        return None
    results = [o for o in objs if o.get("type") == "result"]
    o = (results or objs)[-1]
    per_model = o.get("modelUsage")
    if isinstance(per_model, dict) and per_model:
        tin = tout = tcached = 0
        top, top_out = "", -1
        for name, u in per_model.items():
            if not isinstance(u, dict):
                continue
            i = int(u.get("inputTokens") or 0) + int(u.get("cacheCreationInputTokens") or 0)
            out = int(u.get("outputTokens") or 0)
            tin, tout, tcached = tin + i, tout + out, tcached + int(u.get("cacheReadInputTokens") or 0)
            if out > top_out:
                top, top_out = name, out
        return {"tokens_in": tin, "tokens_out": tout, "tokens_cached": tcached, "model": top}
    u = o.get("usage")
    if not isinstance(u, dict):
        return None
    return {"tokens_in": int(u.get("input_tokens") or 0) + int(u.get("cache_creation_input_tokens") or 0),
            "tokens_out": int(u.get("output_tokens") or 0),
            "tokens_cached": int(u.get("cache_read_input_tokens") or 0),
            "model": str(o.get("model") or "")}


def path_for(build, addr):
    return Path(build) / "tasks" / f"{addr:08x}" / "usage.json"


def load(build, addr):
    p = path_for(build, addr)
    try:
        d = json.loads(p.read_text(encoding="utf-8"))
        return {**EMPTY, **{k: d[k] for k in EMPTY if k in d}}
    except (OSError, ValueError):
        return dict(EMPTY)


def add(build, addr, usage):
    """Add one try (usage may be None: the try still counts) to the task's total."""
    total = load(build, addr)
    total["tries"] += 1
    if usage:
        for k in ("tokens_in", "tokens_out", "tokens_cached"):
            total[k] += usage[k]
        total["model"] = usage["model"] or total["model"]
    p = path_for(build, addr)
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(json.dumps(total, indent=1), encoding="utf-8")
    return total


def reset(build, addr):
    path_for(build, addr).unlink(missing_ok=True)
