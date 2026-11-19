#!/usr/bin/env bash
# Markdown report for each module in build/modules_ran.txt (verify.yml, "Report"), on stdout.
#
#   bash .github/ci/report_modules.sh pr   <base sha>     pull request: its own files must MATCH,
#                                                         and header changes must not break others
#   bash .github/ci/report_modules.sh push <before sha>   main: nothing that matched may stop
#
# The comparison is each module's committed modules/<id>/progress/status.csv at that commit
# (the exe's was at progress/status.csv before the move). Fails if any module's report does.
set -u
kind=${1:?pr or push}
base=${2:?commit to compare against}
mkdir -p build
if [ "$kind" = "pr" ]; then
  # files the PR adds or edits (under their new name); a file that was only moved (an exact
  # rename, R100) isn't new work, so its functions needn't all MATCH here (main's
  # regression check still covers them), but one moved and edited is
  git diff --name-status -M "$base" HEAD | tr -d '\r' | awk -F'\t' '
    $1 ~ /^[AMT]/ { print $2 }
    $1 ~ /^C/ || ($1 ~ /^R/ && $1 != "R100") { print $3 }' > build/changed.txt
fi
rc=0
# the build each module targeted at a commit (its build hash), so a baseline from a
# different build (the commit that moved the exe to 2026) isn't compared address by address
build_at() {
  git show "$1:config.json" 2>/dev/null |
    python -c "import json,sys; print(json.load(sys.stdin)['modules']['$2'].get('build_hash', ''))" 2>/dev/null
}
for id in $(tr -d '\r' < build/modules_ran.txt 2>/dev/null); do
  m=${id%%-*}                                  # exe-2014: module exe, legacy build 2014
  b=""
  [ "$id" != "$m" ] && b=${id#*-}
  prev="build/$id/base_status.csv"
  if [ -n "$b" ]; then
    # a legacy build's results: in legacy/<b>/ now, or in the module's own place back when
    # that build was the current one
    git show "$base:modules/$m/legacy/$b/progress/status.csv" > "$prev" 2>/dev/null ||
      { [ "$(build_at "$base" "$m")" = "$(python -c "import json; print(json.load(open('config.json'))['modules']['$m']['legacy']['$b']['build_hash'])")" ] &&
        git show "$base:modules/$m/progress/status.csv" > "$prev" 2>/dev/null; } ||
      rm -f "$prev"
    export C5D_BUILD="$b"
  else
    if [ "$(build_at "$base" "$m")" = "$(build_at HEAD "$m")" ]; then
      git show "$base:modules/$m/progress/status.csv" > "$prev" 2>/dev/null ||
        { [ "$m" = "exe" ] && git show "$base:progress/status.csv" > "$prev" 2>/dev/null; } ||
        rm -f "$prev"
    else
      echo "$id: the base commit targets a different build; no baseline to compare with"
      rm -f "$prev"
    fi
    unset C5D_BUILD
  fi
  if [ "$kind" = "pr" ]; then
    C5D_MODULE="$m" python tools/ci_report.py --status "build/$id/status.csv" \
      --changed build/changed.txt --base-status "$prev" || rc=1
  else
    C5D_MODULE="$m" python tools/ci_report.py --status "build/$id/status.csv" --base-status "$prev" || rc=1
  fi
  echo
done
unset C5D_BUILD
exit $rc
