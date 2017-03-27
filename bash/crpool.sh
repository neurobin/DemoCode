#!/bin/sh
dir=${1-apt.udeb/cache/archives}
odir=${2-.}
find "$dir" -maxdepth 1 -type f -exec sh -c '
p=$0
odir=$1
n=$(basename $p)
pn=$(echo "$n" |sed -e "s/-udeb.*$//" -e "s/[_-][0-9].*$//")
if echo "$pn" | grep -q "^lib."; then
pn1=$(echo "$pn" |sed -E "s/^(....).*/\1/")
else
pn1=$(echo "$pn" |sed -E "s/^(.).*$/\1/")
fi 
mkdir -p  "$odir/pool/main/$pn1/$pn"
cp -L "$p" "$odir/pool/main/$pn1/$pn"
' '{}' "$odir" \;
