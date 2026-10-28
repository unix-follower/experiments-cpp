#!/usr/bin/env bash

set -ex

run() {
  executable=$1
  if [[ -z $executable ]]; then
    echo "No file specfied to execute"
    exit -1
  fi
  $executable
}

run_all() {
  build/src/experiments/math/example1
  build/src/experiments/math/example2
  build/src/experiments/math/example3
}

run_all
