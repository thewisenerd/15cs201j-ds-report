#!/bin/bash

set -euo pipefail

for folder in $(ls src/)
do
  for file in $(ls src/${folder}/*.c)
  do
    echo "deleting ${file%.*}"
    rm ${file%.*}
  done
done
