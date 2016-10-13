#!/bin/bash

set -euo pipefail

for folder in $(ls src/)
do
  for file in $(ls src/${folder}/*.c)
  do
    echo "processing ${file}"
    gcc -Wall -lm -o "${file%.*}" "${file}"
    ${file%.*} > ${file%.*}.output
  done
done
