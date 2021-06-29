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

```
cd build/Emulation-HW/
make run
```

### Build FPGA bitstream generation

```
cd build/Hardware/
make
```

The bitstream will generated as `binary_container_1.xclbin`.

Just use `make run` can load the bitstream to FPGA and run.

# Run test

## Unit test

## Integration test

