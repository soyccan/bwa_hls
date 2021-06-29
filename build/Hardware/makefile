HOST_OPTS = -O2
VPP_OPTS = --target hw -j 1

include ../common.mk

run: $(BINARY_CONTAINERS) $(HOST_EXE)
	unset XCL_EMULATION_MODE; ./$(HOST_EXE) Xilinx $(VITIS_PLATFORM) ./binary_container_1.xclbin $(INDEX_AND_READS)
