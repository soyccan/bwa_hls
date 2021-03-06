# Before include this makefile, you must define these variable:
# HOST_OPTS = -O0 -g
# VPP_OPTS = --target sw_emu -g

TESTCASE = 1
SRC_DIR = $(abspath ../../src)
DATA_DIR = $(abspath ../../data)
INDEX_AND_READS = $(DATA_DIR)/$(TESTCASE).fasta.fmi $(DATA_DIR)/$(TESTCASE).fastq

# compiler tools
XILINX_VITIS ?= /home/xilinx/tools/Xilinx/Vitis/2019.2
XILINX_XRT ?= /opt/xilinx/xrt
XILINX_VIVADO ?= /home/xilinx/tools/Xilinx/Vivado/2019.2
XILINX_VIVADO_HLS ?= $(XILINX_VITIS)/Vivado_HLS

HOST_CXX ?= g++
VPP ?= ${XILINX_VITIS}/bin/v++
EMCONFIGUTIL = ${XILINX_VITIS}/bin/emconfigutil --od .
RM = rm -f
RMDIR = rm -rf

VITIS_PLATFORM = xilinx_u50_gen3x16_xdma_201920_3
VITIS_PLATFORM_PATH = $(VITIS_PLATFORM)

# host compiler global settings
CXXFLAGS += -std=c++0x -DVITIS_PLATFORM=$(VITIS_PLATFORM) -D__USE_XOPEN2K8 -I$(XILINX_XRT)/include/ -I$(XILINX_VIVADO)/include/ $(HOST_OPTS) -Wall -fmessage-length=0
LDFLAGS += -lxilinxopencl -lpthread -lrt -lstdc++ -lmpfr -lgmp -lhlsmc++-GCC46 -lIp_floating_point_v7_0_bitacc_cmodel -lIp_xfft_v9_1_bitacc_cmodel -lIp_fir_compiler_v7_2_bitacc_cmodel -lIp_dds_compiler_v6_0_bitacc_cmodel -L$(XILINX_XRT)/lib/ -L$(XILINX_VIVADO)/lnx64/tools/fpo_v7_0 -L$(XILINX_VIVADO)/lnx64/lib/csim -L$(XILINX_VIVADO)/lnx64/tools/dds_v6_0 -L$(XILINX_VIVADO)/lnx64/tools/fir_v7_0 -L$(XILINX_VIVADO)/lnx64/tools/fft_v9_1 -Wl,-rpath-link,$(XILINX_XRT)/lib -Wl,-rpath,$(XILINX_VIVADO)/lnx64/lib/csim -Wl,-rpath,$(XILINX_VIVADO)/lnx64/tools/fpo_v7_0 -Wl,-rpath,$(XILINX_VIVADO)/lnx64/tools/fft_v9_1 -Wl,-rpath,$(XILINX_VIVADO)/lnx64/tools/fir_v7_0 -Wl,-rpath,$(XILINX_VIVADO)/lnx64/tools/dds_v6_0

#
# OpenCL kernel files
#

BINARY_CONTAINERS += binary_container_1.xclbin

BUILD_SUBDIRS += binary_container_1.build
BINARY_CONTAINER_1_OBJS += binary_container_1.build/bwa_align.xo
ALL_KERNEL_OBJS += binary_container_1.build/bwa_align.xo

ALL_MESSAGE_FILES = $(subst .xo,.mdb,$(ALL_KERNEL_OBJS)) $(subst .xclbin,.mdb,$(BINARY_CONTAINERS))

#
# host files
#

HOST_CPPS += $(SRC_DIR)/BWT.cpp
HOST_CPPS += $(SRC_DIR)/bwa.cpp
HOST_CPPS += $(SRC_DIR)/host.cpp
HOST_CPPS += $(SRC_DIR)/kernel.cpp

HOST_EXE = vts_Opt1Baseline

EMCONFIG_FILE = emconfig.json

#
# primary build targets
#

.PHONY: all clean
all: $(BINARY_CONTAINERS) $(HOST_EXE)

.NOTPARALLEL: clean

clean-host:
	-$(RM) $(HOST_EXE)

clean-accelerators:
	-$(RM) $(BINARY_CONTAINERS) $(ALL_KERNEL_OBJS) $(ALL_MESSAGE_FILES)  $(EMCONFIG_FILE)
	-$(RM) *.xclbin.sh *.xclbin.info *.xclbin.link_summary*
	-$(RMDIR) .Xil

clean: clean-host clean-accelerators

.PHONY: incremental
incremental: all

include makeemconfig.mk

nothing:

#
# binary container: binary_container_1.xclbin
#

binary_container_1.build/bwa_align.xo: $(SRC_DIR)/kernel.cpp $(SRC_DIR)/kernel.h binary_container_1-bwa_align-compile.ini common-config.ini
	-@mkdir -p $(@D)
	-@$(RM) $@
	$(VPP) $(VPP_OPTS) --compile -I"$(<D)" --config common-config.ini --config binary_container_1-bwa_align-compile.ini -o"$@" "$<"

binary_container_1.xclbin: $(BINARY_CONTAINER_1_OBJS) binary_container_1-link.ini common-config.ini
	-@echo $(VPP) $(VPP_OPTS) --link --config common-config.ini --config binary_container_1-link.ini -o"$@" $(BINARY_CONTAINER_1_OBJS) > binary_container_1.xclbin.sh
	$(VPP) $(VPP_OPTS) --link --config common-config.ini --config binary_container_1-link.ini -o"$@" $(BINARY_CONTAINER_1_OBJS)

#
# host rules
#

$(HOST_EXE): $(HOST_CPPS)
	$(HOST_CXX) -o "$@" $(+) $(CXXFLAGS) $(LDFLAGS)

#
# emulation configuration file
#

$(EMCONFIG_FILE): makeemconfig.mk
	$(EMCONFIGUTIL) --nd $(NUMBER_OF_DEVICES)  --platform $(VITIS_PLATFORM_PATH)
	-@$(RMDIR) TempConfig .Xil/configutil*

