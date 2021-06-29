HOST_OPTS = -O0 -g
VPP_OPTS = --target sw_emu -g

include ../common.mk

run: $(BINARY_CONTAINERS) $(HOST_EXE) $(EMCONFIG_FILE)
	XCL_EMULATION_MODE=sw_emu ./$(HOST_EXE) Xilinx $(VITIS_PLATFORM) ./binary_container_1.xclbin $(INDEX_AND_READS)
