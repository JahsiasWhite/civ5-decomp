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


def test_module_not_imported_stops():
    r = FakeRemote({"0x10001000": RemoteError("server: module db isn't on this server yet", 404)})
    with pytest.raises(SystemExit, match="haven't been imported"):
        ServerClaims(r).claim(0x10001000, "w1")


def test_unreachable_stops_instead_of_going_local():
    r = FakeRemote({"0x00401000": RemoteError("cannot reach https://x: refused")})
    with pytest.raises(SystemExit, match="stopping rather than claiming it only locally"):
        ServerClaims(r).claim(0x401000, "w1")


def test_other_server_refusal_stops():
    r = FakeRemote({"0x00401000": RemoteError("server: accept the terms first", 403)})
    with pytest.raises(SystemExit):
        ServerClaims(r).claim(0x401000, "w1")


def test_not_logged_in_stops(monkeypatch):
    monkeypatch.setattr(remote, "load_local", lambda: {})
    with pytest.raises(SystemExit, match="not logged in"):
        ServerClaims.from_config()


def test_not_logged_in_with_local_flag_warns(monkeypatch, capsys):
    monkeypatch.setattr(remote, "load_local", lambda: {})
    sc = ServerClaims.from_config(local_only=True)
    assert sc.r is None and sc.claim(0x401000, "w1")
    assert "only on this machine" in capsys.readouterr().out


def test_local_flag_skips_server(monkeypatch):
    monkeypatch.setattr(remote, "load_local", lambda: {"server": "https://x", "token": "t"})
    assert ServerClaims.from_config(local_only=True).r is None
    assert ServerClaims.from_config().r is not None


def test_release_never_stops(monkeypatch):
    monkeypatch.setattr(remote, "load_local", lambda: {})
    ServerClaims.from_config(for_release=True).release(0x401000)      # not logged in: no-op
    r = FakeRemote({"0x00401000": RemoteError("cannot reach https://x: refused")})
    sc = ServerClaims(r)
    sc.release(0x401000)                                               # warns, doesn't raise
    sc.release(0x402000)
    assert len(r.calls) == 1


def test_model_sent_with_claim():
    class Rec(FakeRemote):
        def call(self, method, path, body=None):
            self.bodies = getattr(self, "bodies", []) + [body]
            return super().call(method, path, body)
    r = Rec()
    ServerClaims(r, model="model-c").claim(0x401000, "w1")
    ServerClaims(r).claim(0x401010, "w1")
    assert r.bodies[0]["model"] == "model-c" and "model" not in r.bodies[1]
