#!/usr/bin/env bash
# Match every module against its committed fingerprints (verify.yml, "Match").
#
#   bash .github/ci/match_modules.sh full
#   bash .github/ci/match_modules.sh partial build/around.txt
#
# A module takes part once it has modules/<id>/data/fingerprints.csv (`c5d fingerprint`).
# Partial runs (pull requests) build only the sources tools/ci_plan.py listed; a module
# with none of them listed is skipped. For each module that ran, build/<id>/ gets
# match.txt and status.csv, and its id is added to build/modules_ran.txt (what Report and
# Send read). Fails if a module's run never reached its summary (compile or link failure);
# DIFFs are normal.
set -u
mode=${1:?full or partial}
around=${2:-}
mkdir -p build
: > build/modules_ran.txt
failed=""
for dir in modules/*/; do
  m=$(basename "$dir")
  if [ ! -f "$dir/data/fingerprints.csv" ]; then
    echo "$m: no data/fingerprints.csv yet, skipped"
    continue
  fi
  mkdir -p "build/$m"
  scope=""
  if [ "$mode" = "partial" ]; then
    grep "^modules/$m/" "$around" > "build/$m/around.txt" || true
    if [ ! -s "build/$m/around.txt" ]; then
      echo "$m: nothing in this change, skipped"
      continue
    fi
    scope="--around-from build/$m/around.txt"
  fi
  echo "::group::$m"
  python tools/c5d.py --module "$m" match --fingerprints $scope \
    --status-out "build/$m/status.csv" > "build/$m/match.txt" 2>&1
  tail -n 40 "build/$m/match.txt"
  echo "::endgroup::"
  if grep -q "fingerprint mode\]" "build/$m/match.txt"; then
    echo "$m" >> build/modules_ran.txt
    echo "::notice title=Match results ($m)::$(tail -n 1 "build/$m/match.txt" | sed 's/^\[[^]]*\] *//')"
    grep "pruned .* from build/objcache" "build/$m/match.txt" || true
  else
    echo "::error::$m: match run failed"
    failed="$failed $m"
  fi
  # the module's legacy builds (view-only, e.g. the 2014 exe): the same sources, checked
  # against legacy/<build>/data/fingerprints.csv; results go to build/<id>-<build>/, and
  # <id>-<build> is the name the site knows that build by
  for b in $(python -c "import json; print(' '.join(json.load(open('config.json'))['modules']['$m'].get('legacy', {})))"); do
    lid="$m-$b"
    if [ ! -f "$dir/legacy/$b/data/fingerprints.csv" ]; then
      echo "$lid: no legacy/$b/data/fingerprints.csv, skipped"
      continue
    fi
    mkdir -p "build/$lid"
    lscope=""
    if [ -n "$scope" ]; then
      lscope="--around-from build/$m/around.txt"
    fi
    echo "::group::$lid"
    python tools/c5d.py --module "$m" --build "$b" match --fingerprints $lscope \
      --status-out "build/$lid/status.csv" > "build/$lid/match.txt" 2>&1
    tail -n 40 "build/$lid/match.txt"
    echo "::endgroup::"
    if grep -q "fingerprint mode\]" "build/$lid/match.txt"; then
      echo "$lid" >> build/modules_ran.txt
      echo "::notice title=Match results ($lid)::$(tail -n 1 "build/$lid/match.txt" | sed 's/^\[[^]]*\] *//')"
    else
      echo "::error::$lid: match run failed"
      failed="$failed $lid"
    fi
  done
done
du -sh build/objcache 2>/dev/null || true
[ -z "$failed" ]
