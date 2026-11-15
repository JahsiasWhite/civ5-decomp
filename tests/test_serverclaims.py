"""ServerClaims: local task claims mirrored on the coordination server."""
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

import remote  # noqa: E402
from remote import RemoteError, ServerClaims  # noqa: E402


class FakeRemote:
    def __init__(self, errors=None):
        self.errors = errors or {}          # addr -> RemoteError raised by claim
        self.calls = []

    def call(self, method, path, body=None):
        self.calls.append((path, body["addr"]))
        err = self.errors.get(body["addr"])
        if err:
            raise err
        return {}


def test_claims_on_server():
    r = FakeRemote()
    assert ServerClaims(r).claim(0x401000, "w1")
    assert r.calls == [("/api/claim", "0x00401000")]


def test_taken_elsewhere_is_skipped():
    r = FakeRemote({"0x00401000": RemoteError("server: already claimed by someone else", 409)})
    assert not ServerClaims(r).claim(0x401000, "w1")


def test_claim_limit_stops():
    r = FakeRemote({"0x00401000": RemoteError("server: you already hold 25 claims (limit 25)", 409)})
    with pytest.raises(SystemExit):
        ServerClaims(r).claim(0x401000, "w1")


def test_unknown_on_server_stays_local():
    r = FakeRemote({"0x00401000": RemoteError("server: unknown or out-of-scope function", 404)})
    assert ServerClaims(r).claim(0x401000, "w1")


def test_unreachable_goes_local_for_the_rest_of_the_run():
    r = FakeRemote({"0x00401000": RemoteError("cannot reach https://x: refused")})
    sc = ServerClaims(r)
    assert sc.claim(0x401000, "w1")
    assert sc.claim(0x402000, "w2")
    assert len(r.calls) == 1                # no further calls once offline


def test_not_logged_in_is_local_only(monkeypatch):
    monkeypatch.setattr(remote, "load_local", lambda: {})
    sc = ServerClaims.from_config()
    assert sc.r is None and sc.claim(0x401000, "w1")


def test_local_flag_skips_server(monkeypatch):
    monkeypatch.setattr(remote, "load_local", lambda: {"server": "https://x", "token": "t"})
    assert ServerClaims.from_config(local_only=True).r is None
    assert ServerClaims.from_config().r is not None
