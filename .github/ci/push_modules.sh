#!/usr/bin/env bash
# Send the modules' results to the site (verify.yml, "Send results"; main only).
#
#   C5D_ADMIN_TOKEN=... bash .github/ci/push_modules.sh https://civ5decomp.com
#
# Every module in build/modules_ran.txt goes in one `manage.py push --modules ...`, so the
# site records one verify run per CI run. The exe has to get through: if the combined push
# fails while it holds DLL results (a site that doesn't know about modules yet, or a DLL
# import that hasn't happened there), the exe's results are sent alone and the DLLs are
# only a warning.
set -u
server=${1:?server URL}
mods=$(tr -d '\r' < build/modules_ran.txt 2>/dev/null | paste -sd, -)
if [ -z "$mods" ]; then
  echo "no module results to send"
  exit 0
fi
push() {
  python server/manage.py push --modules "$1" --status-pattern "build/{module}/status.csv" \
    --server "$server" --token "$C5D_ADMIN_TOKEN"
}
if push "$mods"; then
  exit 0
fi
if [ "$mods" = "exe" ]; then
  echo "::error::exe: sending results failed"
  exit 1
fi
case ",$mods," in
  *,exe,*) ;;
  *)                                 # no exe results this run: the DLLs are only a warning
    echo "::warning::sending $mods failed (does the site have these modules yet?)"
    exit 0 ;;
esac
echo "::warning::sending $mods together failed (does the site have every module yet?); sending exe alone"
if push exe; then
  exit 0
fi
echo "::error::exe: sending results failed"
exit 1
