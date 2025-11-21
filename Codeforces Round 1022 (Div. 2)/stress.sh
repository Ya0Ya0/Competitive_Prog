#!/usr/bin/env bash
set -eu

ITER=0
while true; do
  ((ITER++))
  # 1) generate a test
  ./gen > in.txt

  # 2) run both solutions
  ./sol1 < in.txt > out1.txt
  ./sol2 < in.txt > out2.txt

  # 3) compare
  if ! diff -q out1.txt out2.txt >/dev/null; then
    echo "❌ Mismatch found on test #$ITER"
    echo "---- input ----"
    cat in.txt
    echo "---- sol1.out ----"
    cat out1.txt
    echo "---- sol2.out ----"
    cat out2.txt
    exit 1
  fi

  # optional: print a dot every 100 iters
  if (( ITER % 100 == 0 )); then
    echo "Checked $ITER cases, still OK."
  fi
done