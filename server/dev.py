"""Run the server locally with dev sign-in (no GitHub needed).

    python server/dev.py            -> http://127.0.0.1:8765  (/dev-login?login=you)

Never use this for a public deployment.
"""
import os
import runpy
from pathlib import Path

os.environ.setdefault("C5D_DEV_AUTH", "1")
os.environ.setdefault("C5D_HOST", "127.0.0.1")
os.environ.setdefault("C5D_PORT", "8765")
os.environ.setdefault("C5D_SESSION_SECRET", "local-dev-only")
runpy.run_path(str(Path(__file__).with_name("app.py")), run_name="__main__")
