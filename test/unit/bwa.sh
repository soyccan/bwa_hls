#!/bin/bash

cd ../../src
make > /dev/null

function run_test () {
  local file="$1"
	grep --no-filename "sa_len\|found SA interval" "${file}.out" "${file}.log" > ans.txt

  ./align "${file}.fasta.fmi" "${file}.fastq" |& grep "sa_len\|found SA interval" > output.txt

  if diff output.txt ans.txt > /dev/null; then
    echo -e "\033[0;32mTest ${file} pass!\033[0m"
  else
    echo -e "\033[0;31mTest ${file} failed!\033[0m"
  fi
  rm output.txt ans.txt
}

run_test ../data/1
run_test ../data/100
run_test ../data/1000
