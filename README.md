# Introduction

This is HLS (High-Level Synthesis) Final Project for NTU CSIE 2021 ACA course

Our topic is "DNA Sequence Analysis Acceleration".
We implement BWA (Burrows-Wheeler Aligner) algorithm using HLS, and try to optimize this kernel on U50 FPGA.

We use OpenBWT doing BWT (Burrow-Wheeler’s Transform) to offline generate reference genome FM-index and load the FM-index at runtime.

The BWA algorithm use recursion. But since the HLS is not support recursive function, we modify the algorithm from DFS search to BFS search. We use a buffer for queuing the recording states, and successfully synthesis our kernel code to hardware.

# Major Optimizations

## Highlight area of optimization

### Multiple Kernel Instances

### Optimize Data Transfer

## Result as compare with the original

## Other Optimizations

### PLRAM may provide lower latency: PLRAM_USAGE

![](https://i.imgur.com/Qvro2Yi.png)

Since PLRAM is not supported on u50, we have not doing this optimization:

![](https://i.imgur.com/JlrWxVm.png)

# Folder structure

```
.
├── build                   # Makefile and Compiled files
│   ├── Emulation-HW/       # Hardware Emulation makefiles
│   ├── Emulation-SW/       # Software Emulation makefiles
│   └── Hardware/           # Hardware makefiles
├── data                    # Genome and Reads files
├── docs                    # Documentation files
├── impl_result             # Collection of implementation result files
├── src                     # Source files
├── test                    # Automated tests
├── LICENSE
└── README.md
```

# Documentation

- Slides
  - [Proposal](https://docs.google.com/presentation/d/1PVWVsknsaioNPbYWh62bN30pQL_089gKeKPHn81Inqg/edit?usp=sharing)
  - [Final Report](https://docs.google.com/presentation/d/1CI_IRIDlEs1lFRY2dtP2rDVo_mjuy3RFSBR_ktLUV2k/edit?usp=sharing)
- [Reference Resources](docs/References.md)

# Build Setup

## Prepare

You must install Vitis and XRT, and use their script to setup environment variable:

```
source /opt/Xilinx/Vitis/2019.2/settings64.sh
source /opt/xilinx/xrt/setup.sh
```

## Tool versions

- Vitis 2019.2 for hls
```
****** v++ v2019.2 (64-bit)
  **** SW Build 2708876 on Wed Nov  6 21:39:14 MST 2019
```

- GCC for host code
```
g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
```

## Steps to build

### Software Emulation

```
cd build/Emulation-SW/
make run
```

### Hardware Emulation

In order to successfully reproduce our result, please use our bitstream file
from GitHub release ([v0.1](https://github.com/soyccan/hls_project/releases/tag/v0.1))
while also saving 20+ minutes of synthesis process

Two files should be downloaded:
- Kernel intermediate file:
[bwa_align.xo](https://github.com/soyccan/hls_project/releases/download/v0.1/bwa_align.xo)
- Bitstream file:
[binary_container_1.xclbin](https://github.com/soyccan/hls_project/releases/download/v0.1/binary_container_1.xclbin):

```
cd build/Emulation-HW/
mkdir binary_container_1.build
wget https://github.com/soyccan/hls_project/releases/download/v0.1/bwa_align.xo -P binary_container_1.build
wget https://github.com/soyccan/hls_project/releases/download/v0.1/binary_container_1.xclbin
touch binary_container_1.build/bwa_align.xo
touch binary_container_1.xclbin
make run TESTCASE=1 2>/dev/null
```

The above will run with input `data/1.fasta.fmi` and `data/1.fastq`
To run different testcase, modify the word after `TESTCASE`

### Build FPGA bitstream generation

```
cd build/Hardware/
make
```

The bitstream will generated as `binary_container_1.xclbin`.

Just use `make run` can load the bitstream to FPGA and run.

# Run test

## Test by host code

At the end of host code, result check is performed by comparing software result and hardward result
of the same kernel (kernel.cpp)

Just use `make run` and incorrect result would be showed if there exists, or a successful message would 
be printed.

## Unit test

Go to the unit test dir: `cd test/unit/`

There two scripts:
- bwt.sh  
  Test BWT implementation
- bwa.sh  
  Test BWA implementation

Just run the script, such as:
```
$ ./bwt.sh
Test ../data/1.fasta pass!
Test ../data/100.fasta pass!
Test ../data/1000.fasta pass!
```

## Integration test

Go to the unit test dir: `cd test/integration/`

- emulation-sw.sh  
  Test Software Emulation
- emulation-hw.sh  
  Test Hardware Emulation
- hardware.sh  
  Test on FPGA

Just run the script, such as:
```
$ ./emulation-sw.sh
// ...
// ... some execution logs ...
// ...
Test ../../data/1 pass!
```
