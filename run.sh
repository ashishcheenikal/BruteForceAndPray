#!/bin/bash

FILE="$1"

OUT="out/${FILE#cpp/}"
OUT="${OUT%.cpp}"

mkdir -p "$(dirname "$OUT")"

g++ -std=c++20 "$FILE" -o "$OUT" &&
"$OUT"