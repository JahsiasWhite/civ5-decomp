"""Token usage parsing for `c5d agent` (agent CLI JSON output)."""
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import agentusage  # noqa: E402

RESULT = {"type": "result", "subtype": "success", "result": "MATCH", "total_cost_usd": 0.4,
          "usage": {"input_tokens": 10, "cache_creation_input_tokens": 5,
                    "cache_read_input_tokens": 100, "output_tokens": 7},
          "modelUsage": {
              "claude-opus-5-5": {"inputTokens": 1000, "outputTokens": 300, "cacheReadInputTokens": 50000,
                                  "cacheCreationInputTokens": 2000},
              "claude-haiku-5-5": {"inputTokens": 200, "outputTokens": 20, "cacheReadInputTokens": 0,
                                   "cacheCreationInputTokens": 0}}}


def test_parse_json_result_sums_models():
    u = agentusage.parse(json.dumps(RESULT))
    assert u == {"tokens_in": 3200, "tokens_out": 320, "tokens_cached": 50000, "model": "claude-opus-5-5"}


def test_parse_stream_json_uses_result_line():
    lines = [json.dumps({"type": "system", "subtype": "init"}),
             json.dumps({"type": "assistant", "message": {"usage": {"output_tokens": 1}}}),
             json.dumps(RESULT)]
    assert agentusage.parse("\n".join(lines))["tokens_out"] == 320


def test_parse_usage_fallback_and_plain_text():
    only_usage = {k: v for k, v in RESULT.items() if k != "modelUsage"}
    assert agentusage.parse(json.dumps(only_usage)) == {
        "tokens_in": 15, "tokens_out": 7, "tokens_cached": 100, "model": ""}
    assert agentusage.parse("Done. The function matches.") is None
    assert agentusage.parse("") is None


def test_add_sums_tries(tmp_path):
    u = {"tokens_in": 10, "tokens_out": 2, "tokens_cached": 30, "model": "m"}
    agentusage.add(tmp_path, 0x401000, u)
    agentusage.add(tmp_path, 0x401000, None)            # a try without usage still counts
    total = agentusage.add(tmp_path, 0x401000, u)
    assert total == {"tokens_in": 20, "tokens_out": 4, "tokens_cached": 60, "tries": 3, "model": "m"}
    assert agentusage.load(tmp_path, 0x401000) == total
    agentusage.reset(tmp_path, 0x401000)
    assert agentusage.load(tmp_path, 0x401000)["tries"] == 0
