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
  # files the PR adds or edits; a file that was only moved (a rename) isn't new work, so its
  # functions needn't all MATCH here (main's regression check still covers them)
  git diff --name-only -M --diff-filter=ACMT "$base" HEAD > build/changed.txt
fi
rc=0
for m in $(tr -d '\r' < build/modules_ran.txt 2>/dev/null); do
  prev="build/$m/base_status.csv"
  git show "$base:modules/$m/progress/status.csv" > "$prev" 2>/dev/null ||
    { [ "$m" = "exe" ] && git show "$base:progress/status.csv" > "$prev" 2>/dev/null; } ||
    rm -f "$prev"
  if [ "$kind" = "pr" ]; then
    C5D_MODULE="$m" python tools/ci_report.py --status "build/$m/status.csv" \
      --changed build/changed.txt --base-status "$prev" || rc=1
  else
    C5D_MODULE="$m" python tools/ci_report.py --status "build/$m/status.csv" --base-status "$prev" || rc=1
  fi
  echo
done
exit $rc
