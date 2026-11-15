#!/usr/bin/env bash
# Download Visual C++ 2008 SP1 (cl 15.00.30729.01: Microsoft's "Visual C++ Compiler for
# Python 2.7", the package this project is developed with) and unpack it to $1 as
#   $1/VC/{bin,include,lib}   $1/WinSDK/{Include,Lib}
# Nothing is redistributed: the file comes from Microsoft (or the Wayback Machine's copy
# of Microsoft's own URL) and is checked against the SHA-256 in CONTRIBUTING.md.
set -euo pipefail
dest=${1:?usage: vc2008.sh DEST}
sha=070474db76a2e625513a5835df4595df9324d820f9cc97eab2a596dcbc2f5cbf
ms=https://download.microsoft.com/download/7/9/6/796EF2E4-801B-4FC4-AB28-B59FBF6D907B/VCForPython27.msi
wayback=https://web.archive.org/web/20210106040224id_/$ms

work=$(mktemp -d)
trap 'rm -rf "$work"' EXIT
for url in "$ms" "$wayback"; do
  if curl -fsSL --retry 4 --retry-delay 15 -o "$work/vc.msi" "$url" &&
     echo "$sha  $work/vc.msi" | sha256sum -c --quiet; then
    echo "downloaded and verified: $url"
    break
  fi
  rm -f "$work/vc.msi"
done
[ -f "$work/vc.msi" ] || { echo "could not download a verified VCForPython27.msi" >&2; exit 1; }

mkdir "$work/x"
(cd "$work/x" && msiextract ../vc.msi >/dev/null)
cl=$(find "$work/x" -type f -iname cl.exe | grep -iv amd64 | grep -i '/VC/bin/' | head -1)
[ -n "$cl" ] || { echo "cl.exe not found in the MSI" >&2; find "$work/x" -maxdepth 6 -type d | head -40 >&2; exit 1; }
root=$(dirname "$(dirname "$(dirname "$cl")")")
mkdir -p "$dest"
cp -r "$root/VC" "$dest/VC"
sdk=$(find "$root" -maxdepth 1 -type d -iname winsdk | head -1)
[ -n "$sdk" ] || { echo "WinSDK folder not found next to VC/" >&2; ls "$root" >&2; exit 1; }
cp -r "$sdk" "$dest/WinSDK"

for f in VC/bin/cl.exe VC/bin/link.exe VC/bin/ml.exe VC/bin/c1xx.dll VC/bin/c2.dll VC/bin/mspdb80.dll; do
  [ -f "$dest/$f" ] || { echo "missing $f" >&2; exit 1; }
done
find "$dest/WinSDK" -maxdepth 2 -iname kernel32.lib | grep -q . || { echo "WinSDK libs missing" >&2; exit 1; }
du -sh "$dest"
