#!/usr/bin/env bash
# Send each module's results to the site (verify.yml, "Send results"; main only).
#
#   C5D_ADMIN_TOKEN=... bash .github/ci/push_modules.sh https://civ5decomp.com
#
# One `manage.py push --module <id>` per module in build/modules_ran.txt. The exe has to
# get through; a DLL module failing is only a warning, so a site that doesn't know about
# modules yet (or a DLL import that hasn't happened there) can't block the exe's results.
set -u
server=${1:?server URL}
rc=0
for m in $(tr -d '\r' < build/modules_ran.txt 2>/dev/null); do
  if python server/manage.py push --module "$m" --status "build/$m/status.csv" \
       --server "$server" --token "$C5D_ADMIN_TOKEN"; then
    continue
  fi
  if [ "$m" = "exe" ]; then
    echo "::error::exe: sending results failed"
    rc=1
  else
    echo "::warning::$m: sending results failed (does the site have this module yet?)"
  fi
done
exit $rc
