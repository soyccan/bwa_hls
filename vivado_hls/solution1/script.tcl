############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project vivado_hls
set_top bwa_align
add_files src/kernel.cpp
add_files -tb data/ref/1.fasta.fmi
add_files -tb data/reads/1.fastq
add_files -tb src/BWT.cpp
add_files -tb src/align.cpp
add_files -tb src/bwa.cpp
open_solution "solution1"
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
config_sdx -target none
config_export -vivado_optimization_level 2 -vivado_phys_opt place -vivado_report_level 0
set_clock_uncertainty 12.5%
#source "./vivado_hls/solution1/directives.tcl"
csim_design -argv {"G:\Repo\hls_project\data\ref\1.fasta.fmi" "G:\Repo\hls_project\data\reads\1.fastq"}
csynth_design
cosim_design -trace_level all -argv {"G:\Repo\hls_project\data\ref\1.fasta.fmi" "G:\Repo\hls_project\data\reads\1.fastq"}
export_design -rtl verilog -format ip_catalog
