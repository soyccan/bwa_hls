# Introduction
# Major Optimizations
## Highlight area of optimization
## Result as compare with the original
# Folder structure
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
