/*******************************************************************************
** HOST Code
*******************************************************************************/
// clang-format off

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>

using namespace std;

#include <CL/cl.h>

#include "bwa.h"
#include "utils.h"
#include "kernel.h"

#define ALL_MESSAGES

// =========================================
// Helper Function: Loads program to memory
// =========================================
int loadFile2Memory(const char *filename, char **result) {

    int size = 0;

    std::ifstream stream(filename, std::ifstream::binary);
    if (!stream) {
        return -1;
    }

    stream.seekg(0, stream.end);
    size = stream.tellg();
    stream.seekg(0, stream.beg);

    *result = new char[size + 1];
    stream.read(*result, size);
    if (!stream) {
        return -2;
    }
    stream.close();
    (*result)[size] = 0;
    return size;
}

// ********************************************************************************** //
// ---------------------------------------------------------------------------------- //
//                          M A I N    F U N C T I O N                                //
// ---------------------------------------------------------------------------------- //
// ********************************************************************************** //

int main(int argc, char* argv[])
{
  cout << endl;


  // ============================================================================
  // Step 1: Check Command Line Arguments
  // ============================================================================
  //    o) argv[1] Platfrom Vendor
  //    o) argv[2] Device Name
  //    o) argv[3] XCLBIN file
  //    o) argv[4] index_filename
  //    o) argv[5] reads file
  // ============================================================================
  #ifdef ALL_MESSAGES
  cout << "HOST-Info: ============================================================= " << endl;
  cout << "HOST-Info: (Step 1) Check Command Line Arguments                      " << endl;
  cout << "HOST-Info: ============================================================= " << endl;
  #endif

  if (argc != 6)
  {
    cout << "HOST-Error: Incorrect command line syntax " << endl;
    cout << "HOST-Info:  Usage: " << argv[0] << " <Platform_Vendor> <Device_Name> <XCLBIN_File> <index_file> <reads_file>" << endl << endl;
    return EXIT_FAILURE;
  } 
 
  const char* Target_Platform_Vendor   = argv[1];
  const char* Target_Device_Name       = argv[2];
  const char* xclbinFilename           = argv[3];
  auto index_filename = std::string(argv[4]);
  auto reads_filename = std::string(argv[5]);
  cout << "HOST-Info: Platform_Vendor   : " << Target_Platform_Vendor << endl;
  cout << "HOST-Info: Device_Name       : " << Target_Device_Name << endl;
  cout << "HOST-Info: XCLBIN_file       : " << xclbinFilename << endl;
  cout << "HOST-Info: index_filename    : " << index_filename << endl;
  cout << "HOST-Info: reads_filename    : " << reads_filename << endl;

  BWA bwa;

  bwa.load_index_file(index_filename);

  debug("ref_size %d", bwa.ref_size);
  debug("endmark %d", bwa.bwt_endmark_pos);
  debug("sa bwt occ[0:3]");
  FOR (i, 0, bwa.ref_size) {
    debugn("%d %c ", bwa.sa[i], bwa.bwt[i]);
    FOR (j, 0, 4) {
      debugn("%d ", bwa.occ[i][j]);
    }
    debug("");
  }

  bwa.load_reads(reads_filename);

  // ============================================================================
  // Step 2: Detect Target Platform and Target Device in a system. 
  //         Create Context and Command Queue.
  // ============================================================================
  // Variables:
  //   o) Target_Platform_Vendor[] - defined as main() input argument 
  //   o) Target_Device_Name[]     - defined as main() input argument
  // 
  // After that
  //   o) Create a Context
  //   o) Create a Command Queue
  // ============================================================================
  cout << endl;
  #ifdef ALL_MESSAGES
  cout << "HOST-Info: ============================================================= " << endl;
  cout << "HOST-Info: (Step 2) Detect Target Platform and Target Device in a system " << endl;
  cout << "HOST-Info:          Create Context and Command Queue                     " << endl;
  cout << "HOST-Info: ============================================================= " << endl;
  #endif

  cl_uint         ui;

  cl_platform_id      *Platform_IDs;
  cl_uint             Nb_Of_Platforms;
  cl_platform_id      Target_Platform_ID;
  bool                Platform_Detected;
  char                *platform_info;

  cl_device_id        *Device_IDs;
  cl_uint             Nb_Of_Devices;
  cl_device_id        Target_Device_ID;
  bool                Device_Detected;
  char                *device_info;

  cl_context          Context;
  cl_command_queue    Command_Queue;

  cl_int              errCode;
  size_t              size;

  // ------------------------------------------------------------------------------------
  // Step 2.1: Get All PLATFORMS, then search for Target_Platform_Vendor (CL_PLATFORM_VENDOR)
  // ------------------------------------------------------------------------------------
  
  // Get the number of platforms
  // ..................................................
  errCode = clGetPlatformIDs(0, NULL, &Nb_Of_Platforms);
  if (errCode != CL_SUCCESS || Nb_Of_Platforms <= 0) {
    cout << endl << "HOST-Error: Failed to get the number of available platforms" << endl << endl;
    return EXIT_FAILURE;
  }

  #ifdef ALL_MESSAGES
  cout << "HOST-Info: Number of detected platforms : " << Nb_Of_Platforms << endl;
  #endif

  // Allocate memory to store platforms
  // ..................................................
  Platform_IDs = new cl_platform_id[Nb_Of_Platforms];
  if (!Platform_IDs) {
    cout << endl << "HOST-Error: Out of Memory during memory allocation for Platform_IDs" << endl << endl;
    return EXIT_FAILURE;
  }

  // Get and store all PLATFORMS
  // ..................................................
  errCode = clGetPlatformIDs(Nb_Of_Platforms, Platform_IDs, NULL);
  if (errCode != CL_SUCCESS) {
    cout << endl << "HOST-Error: Failed to get the available platforms" << endl << endl;
    return EXIT_FAILURE;
  }
 
  // Search for Platform (ex: Xilinx) using: CL_PLATFORM_VENDOR = Target_Platform_Vendor
  // ....................................................................................
  Platform_Detected = false;
  for (ui = 0; ui < Nb_Of_Platforms; ui++) {

    errCode = clGetPlatformInfo(Platform_IDs[ui], CL_PLATFORM_VENDOR, 0, NULL, &size);
    if (errCode != CL_SUCCESS) {
      cout << endl << "HOST-Error: Failed to get the size of the Platofrm parameter " << "CL_PLATFORM_VENDOR" << " value " << endl << endl;
      return EXIT_FAILURE;
    }

    platform_info = new char[size];
    if (!platform_info) {
      cout << endl << "HOST-Error: Out of Memory during memory allocation for Platform Parameter " << "CL_PLATFORM_VENDOR" << endl << endl;
      return EXIT_FAILURE;
    }

    errCode = clGetPlatformInfo(Platform_IDs[ui], CL_PLATFORM_VENDOR, size, platform_info , NULL);
    if (errCode != CL_SUCCESS) {
      cout << endl << "HOST-Error: Failed to get the " << "CL_PLATFORM_VENDOR" << " platform info" << endl << endl;
      return EXIT_FAILURE;
    }

    // Check if the current platform matches Target_Platform_Vendor
    // .............................................................
    if (strcmp(platform_info, Target_Platform_Vendor) == 0) {
      Platform_Detected        = true;
      Target_Platform_ID       = Platform_IDs[ui];
      #ifdef ALL_MESSAGES
      cout << "HOST-Info: Selected platform            : " << Target_Platform_Vendor << endl << endl;
      #endif
    }
  }

  if (Platform_Detected == false) {
    cout << endl << "HOST-Error: Failed to get detect " << Target_Platform_Vendor << " platform" << endl << endl;
    return EXIT_FAILURE;
  }


  // ------------------------------------------------------------------------------------
  // Step 2.2:  Get All Devices for selected platform Target_Platform_ID
  //            then search for Xilinx platform (CL_DEVICE_NAME = Target_Device_Name)
  // ------------------------------------------------------------------------------------

  // Get the Number of Devices
  // ............................................................................
  errCode = clGetDeviceIDs(Target_Platform_ID, CL_DEVICE_TYPE_ALL, 0, NULL, &Nb_Of_Devices);
  if (errCode != CL_SUCCESS) {
    cout << endl << "HOST-Error: Failed to get the number of available Devices" << endl << endl;
    return EXIT_FAILURE;
  }
  #ifdef ALL_MESSAGES
  cout << "HOST-Info: Number of available devices  : " << Nb_Of_Devices << endl;
  #endif

  Device_IDs = new cl_device_id[Nb_Of_Devices];
  if (!Device_IDs) {
    cout << endl << "HOST-Error: Out of Memory during memory allocation for Device_IDs" << endl << endl;
    return EXIT_FAILURE;
  }

  errCode = clGetDeviceIDs(Target_Platform_ID, CL_DEVICE_TYPE_ALL, Nb_Of_Devices, Device_IDs, NULL);
  if (errCode != CL_SUCCESS) {
    cout << endl << "HOST-Error: Failed to get available Devices" << endl << endl;
    return EXIT_FAILURE;
  }

  // Search for CL_DEVICE_NAME = Target_Device_Name
  // ............................................................................
  Device_Detected = false;
  for (ui = 0; ui < Nb_Of_Devices; ui++) {
    errCode = clGetDeviceInfo(Device_IDs[ui], CL_DEVICE_NAME, 0, NULL, &size);
    if (errCode != CL_SUCCESS) {
      cout << endl << "HOST-Error: Failed to get the size of the Device parameter value " << "CL_DEVICE_NAME" << endl << endl;
      return EXIT_FAILURE;
    }
        
    device_info = new char[size];
    if (!device_info) {
      cout << endl << "HOST-Error: Out of Memory during memory allocation for Device parameter " << "CL_DEVICE_NAME" << " value " << endl << endl;
      return EXIT_FAILURE;
    }
        
    errCode = clGetDeviceInfo(Device_IDs[ui], CL_DEVICE_NAME, size, device_info, NULL);
    if (errCode != CL_SUCCESS) {
      cout << endl << "HOST-Error: Failed to get the " << "CL_DEVICE_NAME" << " device info" << endl << endl;
      return EXIT_FAILURE;
    }

    // Check if the current device matches Target_Device_Name
    // ............................................................................
    if (strcmp(device_info, Target_Device_Name) == 0) {
      Device_Detected        = true;
      Target_Device_ID       = Device_IDs[ui];
    }
  }

  if (Device_Detected == false) {
    cout << endl << "HOST-Error: Failed to get detect " << Target_Device_Name << " device" << endl << endl;
    return EXIT_FAILURE;
  } else {
    #ifdef ALL_MESSAGES
    cout << "HOST-Info: Selected device              : " << Target_Device_Name << endl << endl;
    #endif
  }

  // ------------------------------------------------------------------------------------
  // Step 2.3: Create Context
  // ------------------------------------------------------------------------------------
  #ifdef ALL_MESSAGES
  cout << "HOST-Info: Creating Context ... " << endl;
  #endif
  Context = clCreateContext(0, 1, &Target_Device_ID, NULL, NULL, &errCode);
  if (errCode != CL_SUCCESS) {
    cout << endl << "HOST-Error: Failed to create a Context" << endl << endl;
    return EXIT_FAILURE;
  }

  // ------------------------------------------------------------------------------------
  // Step 2.4: Create Command Queue (commands are executed in-order)
  // ------------------------------------------------------------------------------------
  #ifdef ALL_MESSAGES
  cout << "HOST-Info: Creating Command Queue ... " << endl;
  #endif
  Command_Queue = clCreateCommandQueue(Context, Target_Device_ID, CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE | CL_QUEUE_PROFILING_ENABLE, &errCode);
  if (errCode != CL_SUCCESS) {
    cout << endl << "HOST-Error: Failed to create a Command Queue" << endl << endl;
    return EXIT_FAILURE;
  }

  // ============================================================================
  // Step 3: Create Program and Kernel
  // ============================================================================
  //   o) Create a Program from a Binary File and Build it
  //   o) Create a Kernel
  // ============================================================================
  #ifdef ALL_MESSAGES
  cout << endl;
  cout << "HOST-Info: ============================================================= " << endl;
  cout << "HOST-Info: (Step 3) Create Program and Kernels                           " << endl;
  cout << "HOST-Info: ============================================================= " << endl;
  #endif

  // ------------------------------------------------------------------
  // Step 3.1: Load Binary File from a disk to Memory
  // ------------------------------------------------------------------
  unsigned char *xclbin_Memory;
  int program_length;
  
  #ifdef ALL_MESSAGES
  cout << "HOST-Info: Loading " << xclbinFilename << " binary file to memory ..." << endl;
  #endif

  program_length = loadFile2Memory(xclbinFilename, (char **) &xclbin_Memory);
  if (program_length < 0) {
    cout << endl << "HOST-Error: Failed to load " << xclbinFilename << " binary file to memory" << endl << endl;
    return EXIT_FAILURE;
  }

  // ------------------------------------------------------------
  // Step 3.2: Create a program using a Binary File
  // ------------------------------------------------------------
  size_t     Program_Length_in_Bytes;
  cl_program Program;
  cl_int     Binary_Status;
  
  #ifdef ALL_MESSAGES
  cout << "HOST-Info: Creating Program with Binary ..." << endl;
  #endif
  Program_Length_in_Bytes = program_length;
  Program = clCreateProgramWithBinary(Context, 1, &Target_Device_ID, &Program_Length_in_Bytes, 
                                        (const unsigned char **) &xclbin_Memory, &Binary_Status, &errCode);
  if (errCode != CL_SUCCESS) {
    cout << endl << "HOST-Error: Failed to create a Program from a Binary" << endl << endl;
    return EXIT_FAILURE;
  }

  // ----------------------------------------------------------------------
  // Step 3.3: Build (compiles and links) a program executable from binary
  // ----------------------------------------------------------------------
  #ifdef ALL_MESSAGES
  cout << "HOST-Info: Building the Program ..." << endl;
  #endif

  errCode = clBuildProgram(Program, 1, &Target_Device_ID, NULL, NULL, NULL);
  if (errCode != CL_SUCCESS) {
    cout << endl << "HOST-Error: Failed to build a Program Executable" << endl << endl;
    return EXIT_FAILURE;
  }

  // -------------------------------------------------------------
  // Step 3.4: Create a Kernels
  // -------------------------------------------------------------
  cl_kernel K_bwa;

  #ifdef ALL_MESSAGES
  cout << "HOST-Info: Creating a Kernel: K_bwa ..." << endl;
  #endif
  K_bwa = clCreateKernel(Program, "bwa_align", &errCode);
  if (errCode != CL_SUCCESS) {
    cout << endl << "HOST-Error: Failed to create K_bwa" << endl << endl;
    return EXIT_FAILURE;
  }

  // ================================================================
  // Step 4: Prepare Data to Run Kernel
  // ================================================================
  //   o) Allocate Memory to store the results: RES array
  //   o) Create Buffers in Global Memory to store data
  // ================================================================
#define MAX_NUM_READ 2

  const size_t res_sa_itv_size = MAX_NUM_READ*BUF_SIZE*2;
  const size_t buf_size = MAX_NUM_READ*BUF_SIZE*4;
  const size_t occ_size = MAX_NUM_READ*BUF_SIZE*4;

  // TODO: all reads
  // char reads[MAX_NUM_READ][READ_MAX_LEN];
  // FOR (i, 0, bwa.reads.size()) {
  //   memcpy(reads[i],  bwa.reads.at(i).c_str(), bwa.reads.at(i).size());
  //   debug("reads[%d]=%s len=%d", i, reads[i], bwa.reads.at(i).size());
  // }

  #ifdef ALL_MESSAGES
  cout << endl;
  cout << "HOST-Info: ============================================================= " << endl;
  cout << "HOST-Info: (Step 4) Prepare Data to Run Kernels                           " << endl;
  cout << "HOST-Info: ============================================================= " << endl;
  #endif

  // ------------------------------------------------------------------
  // Step 4.1: Allocate Memory to store the results: res_sa_itv array
  // ------------------------------------------------------------------
  int cum[4] = {1};
  FOR (j, 1, 4) {
    cum[j] = cum[j - 1] + bwa.occ[bwa.ref_size][j - 1];
    debug("cum[%d]=%d",j,cum[j]);
  }

  cl_uint CONST_refn = bwa.ref_size;
  debug("refn=%d", CONST_refn);

  vector<cl_uint> CONST_read_len(bwa.reads.size());
  FOR (i, 0, bwa.reads.size()) {
    CONST_read_len[i] = bwa.reads.at(i).size();
    debug("read_len[%d]=%d",i,CONST_read_len[i]);
  }

  int res_sa_itv[MAX_NUM_READ][BUF_SIZE][2];
  int res_sa_len[MAX_NUM_READ];

#define ALLOC_MEM_ALIGN(ptr, size) { \
  void *p; \
  cout << "HOST-Info: Allocating memory for " #ptr " ..."; \
  if (posix_memalign(&p,4096,size)) { \
    cout << endl << "HOST-Error: Out of Memory during memory allocation for res_sa_itv array" << endl << endl; \
    return EXIT_FAILURE; \
  } \
  cout << "Allocated" << endl; \
  ptr = reinterpret_cast<decltype(ptr)>(p); \
}

  cout << endl;

  // ------------------------------------------------------------------
  // Iterate each input
  // ------------------------------------------------------------------

  // ping-pong buffer
  cl_mem GlobMem_BUF_res_sa_len[2];
  cl_mem GlobMem_BUF_res_sa_itv[2];
  cl_mem GlobMem_BUF_buf       [2];       
  cl_mem GlobMem_BUF_occ       [2];
  cl_mem GlobMem_BUF_cum       [2];    
  cl_mem GlobMem_BUF_read      [2];    

  const size_t Nb_Of_Mem_r_Events = 2;
  const size_t Nb_Of_Mem_w_Events = 6;
  const size_t Nb_Of_Exe_Events = 1;
  cl_event Mem_r_event[2][Nb_Of_Mem_r_Events];
  cl_event Mem_w_event[Nb_Of_Mem_w_Events];
  cl_event K_exe_event[2][Nb_Of_Exe_Events];

  // Iterate each read
  FOR (read_id, 0, bwa.reads.size()) {
    int flag = read_id % 2;

    if (read_id >= 2) {
      errCode = clWaitForEvents(1, Mem_r_event[flag]);
      if (errCode != CL_SUCCESS) {
        cout << endl << "Host-Error: Failed to wait for read events" << endl << endl;
        return EXIT_FAILURE;
      }
    }

    // ------------------------------------------------------------------
    // Step 4.2: Create Buffers in Global Memory to store data
    //             o) GlobMem_BUF_res_sa_itv (W)
    //             o) GlobMem_BUF_buf      - (R/W)
    //             o) GlobMem_BUF_occ      - (R)
    //             o) GlobMem_BUF_cum      - (R)
    //             o) GlobMem_BUF_read     - (R)
    //             o) GlobMem_BUF_res_sa_len (W)
    //             o) GlobMem_BUF_read_len - (R)
    // ------------------------------------------------------------------
    #ifdef ALL_MESSAGES
    cout << "HOST-Info: Allocating buffers in Global Memory to store Input and Output Data ..." << endl;
    #endif

#define COMMA ,
#define SEMICOLON ;
#define MY_BUF(BUF_F, SEP) \
  BUF_F(GlobMem_BUF_res_sa_len[flag], CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, sizeof(int)                       , &res_sa_len[read_id]) SEP \
  BUF_F(GlobMem_BUF_res_sa_itv[flag], CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, sizeof(res_sa_itv[0])             , &res_sa_itv[read_id]) SEP \
  BUF_F(GlobMem_BUF_buf       [flag], CL_MEM_READ_WRITE                      , buf_size*sizeof(int)              , NULL                ) SEP \
  BUF_F(GlobMem_BUF_occ       [flag], CL_MEM_READ_ONLY  | CL_MEM_USE_HOST_PTR, bwa.occ.size()*sizeof(bwa.occ[0]) , &bwa.occ[0][0]      ) SEP \
  BUF_F(GlobMem_BUF_cum       [flag], CL_MEM_READ_ONLY  | CL_MEM_USE_HOST_PTR, sizeof(cum)                       , cum                 ) SEP \
  BUF_F(GlobMem_BUF_read      [flag], CL_MEM_READ_ONLY  | CL_MEM_USE_HOST_PTR, bwa.reads[read_id].size()         , (void*)bwa.reads[read_id].c_str())

    // Allocate Global Memory for GlobMem_BUF
    // .......................................................
#define ALLOCATE_BUF(NAME, FLAG, SIZE, PTR) \
  NAME = clCreateBuffer(Context, FLAG, SIZE, PTR, &errCode); \
  if (errCode != CL_SUCCESS) { \
    cout << endl << "Host-Error: Failed to allocate Global Memory for " #NAME << endl << endl; \
    return EXIT_FAILURE; \
  }

    MY_BUF(ALLOCATE_BUF, SEMICOLON);
#undef ALLOCATE_BUF

    // ============================================================================
    // Step 5: Set Kernel Arguments and Run the Application
    //         o) Set Kernel Arguments
    //        ----------------------------------------------------
    //         Kernel       Argument Nb   Description
    //        ----------------------------------------------------
    //         K_bwa              0       GlobMem_BUF_res_sa_itv
    //         K_bwa              1       GlobMem_BUF_buf
    //         K_bwa              2       GlobMem_BUF_occ
    //         K_bwa              3       GlobMem_BUF_cum
    //         K_bwa              4       CONST_refn
    //         K_bwa              5       GlobMem_BUF_read
    //         K_bwa              6       CONST_readn
    //         K_bwa              7       GlobMem_BUF_res_sa_len
    //         K_bwa              8       GlobMem_BUF_read_len
    //        ----------------------------------------------------
    //         o) Copy Input Data from Host to Global Memory
    //         o) Submit Kernels for Execution
    //         o) Copy Results from Global Memory to Host
    // ============================================================================


    #ifdef ALL_MESSAGES
    cout << endl;
    cout << "HOST-Info: ============================================================= " << endl;
    cout << "HOST-Info: (Step 5) Run Application                                      " << endl;
    cout << "HOST-Info: ============================================================= " << endl;
    #endif


    // ----------------------------------------
    // Step 5.1: Set Kernel Arguments
    // ----------------------------------------
    #ifdef ALL_MESSAGES
    cout << "HOST-Info: Setting Kernel arguments ..." << endl;
    #endif
    errCode  = false;

    errCode |= clSetKernelArg(K_bwa,  0, sizeof(cl_mem),  &GlobMem_BUF_res_sa_len);
    errCode |= clSetKernelArg(K_bwa,  1, sizeof(cl_mem),  &GlobMem_BUF_res_sa_itv);
    errCode |= clSetKernelArg(K_bwa,  2, sizeof(cl_mem),  &GlobMem_BUF_buf);
    errCode |= clSetKernelArg(K_bwa,  3, sizeof(cl_mem),  &GlobMem_BUF_occ);
    errCode |= clSetKernelArg(K_bwa,  4, sizeof(cl_mem),  &GlobMem_BUF_cum);
    errCode |= clSetKernelArg(K_bwa,  5, sizeof(cl_uint), &CONST_refn);
    errCode |= clSetKernelArg(K_bwa,  6, sizeof(cl_mem),  &GlobMem_BUF_read);
    errCode |= clSetKernelArg(K_bwa,  7, sizeof(cl_uint), &CONST_read_len[read_id]);

    if (errCode != CL_SUCCESS) {
      cout << endl << "Host-ERROR: Failed to set Kernel arguments" << endl << endl;
      return EXIT_FAILURE;
    }


    // ------------------------------------------------------
    // Step 5.2: Copy Input data from Host to Global Memory
    // ------------------------------------------------------
#ifdef ALL_MESSAGES
    cout << "HOST_Info: Copy Input data to Global Memory ..." << endl;
#endif

    int index = 0;

#define MY_MEM(BUF_F) \
  BUF_F(GlobMem_BUF_res_sa_len[flag], 0                                      ); \
  BUF_F(GlobMem_BUF_res_sa_itv[flag], 0                                      ); \
  BUF_F(GlobMem_BUF_buf       [flag], CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED); \
  BUF_F(GlobMem_BUF_occ       [flag], 0                                      ); \
  BUF_F(GlobMem_BUF_cum       [flag], 0                                      ); \
  BUF_F(GlobMem_BUF_read      [flag], 0                                      );

#define MIGRATE_MEM(NAME, FLAG) \
  errCode = clEnqueueMigrateMemObjects(Command_Queue, 1, &NAME, FLAG, 0, NULL, &Mem_w_event[index++]); \
  if (errCode != CL_SUCCESS) { \
    cout << endl << "Host-Error: Failed to migrate to " #NAME << endl << endl; \
    return EXIT_FAILURE; \
  }

  MY_MEM(MIGRATE_MEM);
#undef MY_MEM

    assert(index == Nb_Of_Mem_w_Events);

    // ----------------------------------------
    // Step 5.3: Submit Kernels for Execution
    // ----------------------------------------

    cout << "HOST-Info: Submitting Kernel K_bwa..." << endl;

    errCode = clEnqueueTask(Command_Queue, K_bwa, Nb_Of_Mem_w_Events, Mem_w_event, &K_exe_event[flag][0]);
    if (errCode != CL_SUCCESS) {
      cout << endl << "HOST-Error: Failed to submit K_bwa" << endl << endl;
      return EXIT_FAILURE;
    }


    // ---------------------------------------------------------
    // Step 5.4: Submit Copy Results from Global Memory to Host
    // ---------------------------------------------------------
    #ifdef ALL_MESSAGES
    cout << "HOST_Info: Submitting Copy Results data from Global Memory to Host ..." << endl;
    #endif

    errCode = clEnqueueMigrateMemObjects(Command_Queue, 1, &GlobMem_BUF_res_sa_itv[flag], CL_MIGRATE_MEM_OBJECT_HOST, 1, 
                                         &K_exe_event[flag][0], &Mem_r_event[flag][0]);
    if (errCode != CL_SUCCESS) {
      cout << endl << "Host-Error: Failed to submit Copy Results from GlobMem_BUF_res_sa_itv to res_sa_itv" << endl << endl;
      return EXIT_FAILURE;
    }

    errCode = clEnqueueMigrateMemObjects(Command_Queue, 1, &GlobMem_BUF_res_sa_len[flag], CL_MIGRATE_MEM_OBJECT_HOST, 1, 
                                         &K_exe_event[flag][0], &Mem_r_event[flag][1]);
    if (errCode != CL_SUCCESS) {
      cout << endl << "Host-Error: Failed to submit Copy Results from GlobMem_BUF_res_sa_len to res_sa_len" << endl << endl;
      return EXIT_FAILURE;
    }
  }

  cout << endl << "HOST_Info: Waiting for application to be completed ..." << endl;
  clFinish(Command_Queue);


  // ============================================================================
  // Step 6: Processing Output Results
  //         o) Store output results to a RES.txt file
  //         o) Check correctness of the output results
  // ============================================================================

  #ifdef ALL_MESSAGES
  cout << endl;
  cout << "HOST-Info: ============================================================= " << endl;
  cout << "HOST-Info: (Step 6) Store and Check the Output Results                   " << endl;
  cout << "HOST-Info: ============================================================= " << endl;
  #endif

  FOR(j, 0, 2) {
    debug("sa_len(%x) = %d", &res_sa_len, res_sa_len[j]);
    debug("sa_itv(%x)", &res_sa_itv[j]);
    FOR (i, 0, 10) {
      debug("found SA interval [%d, %d]", res_sa_itv[j][i][0], res_sa_itv[j][i][1]);
    }
  }

#if 0
  // ------------------------------------------------------
  // Step 6.1: Store output Result to the RES.txt file
  // ------------------------------------------------------
  char Output_File_Name[] = "RES.txt";
  cout << "HOST_Info: Store output results in: " << Output_File_Name << endl;

  fstream RES_File;


  RES_File.open(Output_File_Name,ios::out);
  if (! RES_File.is_open()) {
    cout << endl << "HOST-Error: Failed to open the " << Output_File_Name << " file for write" << endl << endl;
    return EXIT_FAILURE;
  }

  for (int i=0; i < SIZE_RES; i++) {
    RES_File << RES[i] << endl;
  }
  RES_File.close();

  // ------------------------------------------------------
  // Step 6.2: Check correctness of the output results
  // ------------------------------------------------------
  bool error_detected = false;
  error_detected = check_output_results (DataIn_1, DataIn_2, DataIn_3, CONST_arg, RES);

  if (error_detected == false) {
    cout << "Host-Info: Test Successful" << endl;
  } else {
    cout << "Host-Error: Test Failed" << endl;  
  }

  // ============================================================================
  // Step 7: Custom Profiling
  // ============================================================================
  cout << "HOST-Info: ============================================================= " << endl;
  cout << "HOST-Info: (Step 7) Custom Profiling                                     " << endl;
  cout << "HOST-Info: ============================================================= " << endl;
  int Nb_Of_Kernels = Nb_Of_Exe_Events;
  int Nb_Of_Memory_Tranfers = Nb_Of_Mem_Events;

  string list_of_kernel_names[Nb_Of_Kernels]={"K_KVConstAdd","K_KpB","K_KA","K_KB","K_KCalc"};
  run_custom_profiling (Nb_Of_Kernels,Nb_Of_Memory_Tranfers,K_exe_event,Mem_op_event,list_of_kernel_names);
#endif

  // ============================================================================
  // Step 8: Release Allocated Resources
  // ============================================================================
  clReleaseDevice(Target_Device_ID); // Only available in OpenCL >= 1.2

  for (int i=0; i<Nb_Of_Mem_w_Events; i++) clReleaseEvent(Mem_w_event[i]);
  FOR(j, 0, 2) {
    for (int i=0; i<Nb_Of_Mem_r_Events; i++) clReleaseEvent(Mem_r_event[j][i]);
    for (int i=0; i<Nb_Of_Exe_Events; i++) clReleaseEvent(K_exe_event[j][i]);
  }

  FOR(i, 0, 2) {
    clReleaseMemObject(GlobMem_BUF_res_sa_len[i]);
    clReleaseMemObject(GlobMem_BUF_res_sa_itv[i]);
    clReleaseMemObject(GlobMem_BUF_buf       [i]);       
    clReleaseMemObject(GlobMem_BUF_occ       [i]);
    clReleaseMemObject(GlobMem_BUF_cum       [i]);    
    clReleaseMemObject(GlobMem_BUF_read      [i]);    
  }

  clReleaseKernel(K_bwa);

  clReleaseProgram(Program);
  clReleaseCommandQueue(Command_Queue);
  clReleaseContext(Context);

  free(Platform_IDs);
  free(Device_IDs);

  cout << endl << "HOST-Info: DONE" << endl << endl;

  return EXIT_SUCCESS;
}
