#!/bin/bash

cd ../../src
make > /dev/null

function run_test () {
  local ori_file="$1"
  cp "$ori_file" test.fasta
  ./index test.fasta
  if diff "test.fasta.fmi" "${ori_file}.fmi" > /dev/null; then
    echo -e "\033[0;32mTest ${ori_file} pass!\033[0m"
  else
    echo -e "\033[0;31mTest ${ori_file} failed!\033[0m"
  fi
  rm test.fasta test.fasta.fmi
}

run_test ../data/1.fasta
run_test ../data/100.fasta
run_test ../data/1000.fasta

