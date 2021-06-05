// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "res_sa_itv"
#define AUTOTB_TVOUT_res_sa_itv  "../tv/cdatafile/c.bwa_align.autotvout_res_sa_itv.dat"
#define AUTOTB_TVIN_res_sa_itv  "../tv/cdatafile/c.bwa_align.autotvin_res_sa_itv.dat"
// wrapc file define: "buf_r"
#define AUTOTB_TVIN_buf_r  "../tv/cdatafile/c.bwa_align.autotvin_buf_r.dat"
#define AUTOTB_TVOUT_buf_r  "../tv/cdatafile/c.bwa_align.autotvout_buf_r.dat"
// wrapc file define: "occ"
#define AUTOTB_TVIN_occ  "../tv/cdatafile/c.bwa_align.autotvin_occ.dat"
// wrapc file define: "cum"
#define AUTOTB_TVIN_cum  "../tv/cdatafile/c.bwa_align.autotvin_cum.dat"
// wrapc file define: "refn"
#define AUTOTB_TVIN_refn  "../tv/cdatafile/c.bwa_align.autotvin_refn.dat"
// wrapc file define: "read_r"
#define AUTOTB_TVIN_read_r  "../tv/cdatafile/c.bwa_align.autotvin_read_r.dat"
// wrapc file define: "readn"
#define AUTOTB_TVIN_readn  "../tv/cdatafile/c.bwa_align.autotvin_readn.dat"
// wrapc file define: "ap_return"
#define AUTOTB_TVOUT_ap_return  "../tv/cdatafile/c.bwa_align.autotvout_ap_return.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "res_sa_itv"
#define AUTOTB_TVOUT_PC_res_sa_itv  "../tv/rtldatafile/rtl.bwa_align.autotvout_res_sa_itv.dat"
// tvout file define: "buf_r"
#define AUTOTB_TVOUT_PC_buf_r  "../tv/rtldatafile/rtl.bwa_align.autotvout_buf_r.dat"
// tvout file define: "ap_return"
#define AUTOTB_TVOUT_PC_ap_return  "../tv/rtldatafile/rtl.bwa_align.autotvout_ap_return.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			res_sa_itv_depth = 0;
			buf_r_depth = 0;
			occ_depth = 0;
			cum_depth = 0;
			refn_depth = 0;
			read_r_depth = 0;
			readn_depth = 0;
			ap_return_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{res_sa_itv " << res_sa_itv_depth << "}\n";
			total_list << "{buf_r " << buf_r_depth << "}\n";
			total_list << "{occ " << occ_depth << "}\n";
			total_list << "{cum " << cum_depth << "}\n";
			total_list << "{refn " << refn_depth << "}\n";
			total_list << "{read_r " << read_r_depth << "}\n";
			total_list << "{readn " << readn_depth << "}\n";
			total_list << "{ap_return " << ap_return_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int res_sa_itv_depth;
		int buf_r_depth;
		int occ_depth;
		int cum_depth;
		int refn_depth;
		int read_r_depth;
		int readn_depth;
		int ap_return_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern int bwa_align (
int res_sa_itv[1024][2],
int buf[1024][4],
const int occ[1024][4],
const int cum[4],
int refn,
const char read[1024],
int readn);

int AESL_WRAP_bwa_align (
int res_sa_itv[1024][2],
int buf[1024][4],
const int occ[1024][4],
const int cum[4],
int refn,
const char read[1024],
int readn)
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;

		int AESL_return;

		// output port post check: "res_sa_itv"
		aesl_fh.read(AUTOTB_TVOUT_PC_res_sa_itv, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_res_sa_itv, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_res_sa_itv, AESL_token); // data

			sc_bv<32> *res_sa_itv_pc_buffer = new sc_bv<32>[2048];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'res_sa_itv', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'res_sa_itv', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					res_sa_itv_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_res_sa_itv, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_res_sa_itv))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: res_sa_itv
				{
					// bitslice(31, 0)
					// {
						// celement: res_sa_itv(31, 0)
						// {
							sc_lv<32>* res_sa_itv_lv0_0_1023_1_lv1_0_1_1 = new sc_lv<32>[2048];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: res_sa_itv(31, 0)
						{
							// carray: (0) => (1023) @ (1)
							for (int i_0 = 0; i_0 <= 1023; i_0 += 1)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									if (&(res_sa_itv[0][0]) != NULL) // check the null address if the c port is array or others
									{
										res_sa_itv_lv0_0_1023_1_lv1_0_1_1[hls_map_index].range(31, 0) = sc_bv<32>(res_sa_itv_pc_buffer[hls_map_index].range(31, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: res_sa_itv(31, 0)
						{
							// carray: (0) => (1023) @ (1)
							for (int i_0 = 0; i_0 <= 1023; i_0 += 1)
							{
								// carray: (0) => (1) @ (1)
								for (int i_1 = 0; i_1 <= 1; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : res_sa_itv[i_0][i_1]
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : res_sa_itv[0][0]
									// output_left_conversion : res_sa_itv[i_0][i_1]
									// output_type_conversion : (res_sa_itv_lv0_0_1023_1_lv1_0_1_1[hls_map_index]).to_uint64()
									if (&(res_sa_itv[0][0]) != NULL) // check the null address if the c port is array or others
									{
										res_sa_itv[i_0][i_1] = (res_sa_itv_lv0_0_1023_1_lv1_0_1_1[hls_map_index]).to_uint64();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] res_sa_itv_pc_buffer;
		}

		// output port post check: "buf_r"
		aesl_fh.read(AUTOTB_TVOUT_PC_buf_r, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_buf_r, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_buf_r, AESL_token); // data

			sc_bv<32> *buf_r_pc_buffer = new sc_bv<32>[4096];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'buf_r', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'buf_r', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					buf_r_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_buf_r, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_buf_r))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: buf_r
				{
					// bitslice(31, 0)
					// {
						// celement: buf(31, 0)
						// {
							sc_lv<32>* buf_lv0_0_1023_1_lv1_0_3_1 = new sc_lv<32>[4096];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: buf(31, 0)
						{
							// carray: (0) => (1023) @ (1)
							for (int i_0 = 0; i_0 <= 1023; i_0 += 1)
							{
								// carray: (0) => (3) @ (1)
								for (int i_1 = 0; i_1 <= 3; i_1 += 1)
								{
									if (&(buf[0][0]) != NULL) // check the null address if the c port is array or others
									{
										buf_lv0_0_1023_1_lv1_0_3_1[hls_map_index].range(31, 0) = sc_bv<32>(buf_r_pc_buffer[hls_map_index].range(31, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: buf(31, 0)
						{
							// carray: (0) => (1023) @ (1)
							for (int i_0 = 0; i_0 <= 1023; i_0 += 1)
							{
								// carray: (0) => (3) @ (1)
								for (int i_1 = 0; i_1 <= 3; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : buf[i_0][i_1]
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : buf[0][0]
									// output_left_conversion : buf[i_0][i_1]
									// output_type_conversion : (buf_lv0_0_1023_1_lv1_0_3_1[hls_map_index]).to_uint64()
									if (&(buf[0][0]) != NULL) // check the null address if the c port is array or others
									{
										buf[i_0][i_1] = (buf_lv0_0_1023_1_lv1_0_3_1[hls_map_index]).to_uint64();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] buf_r_pc_buffer;
		}

		// output port post check: "ap_return"
		aesl_fh.read(AUTOTB_TVOUT_PC_ap_return, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_ap_return, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_ap_return, AESL_token); // data

			sc_bv<32> ap_return_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'ap_return', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'ap_return', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					ap_return_pc_buffer = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_ap_return, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_ap_return))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: ap_return
				{
					// bitslice(31, 0)
					// {
						// celement: return(31, 0)
						// {
							sc_lv<32> return_lv0_0_1_0;
						// }
					// }

					// bitslice(31, 0)
					{
						// celement: return(31, 0)
						{
							// carray: (0) => (1) @ (0)
							{
								if (&(AESL_return) != NULL) // check the null address if the c port is array or others
								{
									return_lv0_0_1_0.range(31, 0) = sc_bv<32>(ap_return_pc_buffer.range(31, 0));
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						// celement: return(31, 0)
						{
							// carray: (0) => (1) @ (0)
							{
								// sub                    : 
								// ori_name               : AESL_return
								// sub_1st_elem           : 
								// ori_name_1st_elem      : AESL_return
								// output_left_conversion : AESL_return
								// output_type_conversion : (return_lv0_0_1_0).to_uint64()
								if (&(AESL_return) != NULL) // check the null address if the c port is array or others
								{
									AESL_return = (return_lv0_0_1_0).to_uint64();
								}
							}
						}
					}
				}
			}
		}

		AESL_transaction_pc++;

		return AESL_return;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "res_sa_itv"
		char* tvin_res_sa_itv = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_res_sa_itv);
		char* tvout_res_sa_itv = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_res_sa_itv);

		// "buf_r"
		char* tvin_buf_r = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_buf_r);
		char* tvout_buf_r = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_buf_r);

		// "occ"
		char* tvin_occ = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_occ);

		// "cum"
		char* tvin_cum = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_cum);

		// "refn"
		char* tvin_refn = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_refn);

		// "read_r"
		char* tvin_read_r = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_read_r);

		// "readn"
		char* tvin_readn = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_readn);

		// "ap_return"
		char* tvout_ap_return = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_ap_return);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_res_sa_itv, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_res_sa_itv, tvin_res_sa_itv);

		sc_bv<32>* res_sa_itv_tvin_wrapc_buffer = new sc_bv<32>[2048];

		// RTL Name: res_sa_itv
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: res_sa_itv(31, 0)
				{
					// carray: (0) => (1023) @ (1)
					for (int i_0 = 0; i_0 <= 1023; i_0 += 1)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : res_sa_itv[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : res_sa_itv[0][0]
							// regulate_c_name       : res_sa_itv
							// input_type_conversion : res_sa_itv[i_0][i_1]
							if (&(res_sa_itv[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> res_sa_itv_tmp_mem;
								res_sa_itv_tmp_mem = res_sa_itv[i_0][i_1];
								res_sa_itv_tvin_wrapc_buffer[hls_map_index].range(31, 0) = res_sa_itv_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 2048; i++)
		{
			sprintf(tvin_res_sa_itv, "%s\n", (res_sa_itv_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_res_sa_itv, tvin_res_sa_itv);
		}

		tcl_file.set_num(2048, &tcl_file.res_sa_itv_depth);
		sprintf(tvin_res_sa_itv, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_res_sa_itv, tvin_res_sa_itv);

		// release memory allocation
		delete [] res_sa_itv_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_buf_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_buf_r, tvin_buf_r);

		sc_bv<32>* buf_r_tvin_wrapc_buffer = new sc_bv<32>[4096];

		// RTL Name: buf_r
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: buf(31, 0)
				{
					// carray: (0) => (1023) @ (1)
					for (int i_0 = 0; i_0 <= 1023; i_0 += 1)
					{
						// carray: (0) => (3) @ (1)
						for (int i_1 = 0; i_1 <= 3; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : buf[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : buf[0][0]
							// regulate_c_name       : buf
							// input_type_conversion : buf[i_0][i_1]
							if (&(buf[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> buf_tmp_mem;
								buf_tmp_mem = buf[i_0][i_1];
								buf_r_tvin_wrapc_buffer[hls_map_index].range(31, 0) = buf_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 4096; i++)
		{
			sprintf(tvin_buf_r, "%s\n", (buf_r_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_buf_r, tvin_buf_r);
		}

		tcl_file.set_num(4096, &tcl_file.buf_r_depth);
		sprintf(tvin_buf_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_buf_r, tvin_buf_r);

		// release memory allocation
		delete [] buf_r_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_occ, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_occ, tvin_occ);

		sc_bv<32>* occ_tvin_wrapc_buffer = new sc_bv<32>[4096];

		// RTL Name: occ
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: occ(31, 0)
				{
					// carray: (0) => (1023) @ (1)
					for (int i_0 = 0; i_0 <= 1023; i_0 += 1)
					{
						// carray: (0) => (3) @ (1)
						for (int i_1 = 0; i_1 <= 3; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : occ[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : occ[0][0]
							// regulate_c_name       : occ
							// input_type_conversion : occ[i_0][i_1]
							if (&(occ[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> occ_tmp_mem;
								occ_tmp_mem = occ[i_0][i_1];
								occ_tvin_wrapc_buffer[hls_map_index].range(31, 0) = occ_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 4096; i++)
		{
			sprintf(tvin_occ, "%s\n", (occ_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_occ, tvin_occ);
		}

		tcl_file.set_num(4096, &tcl_file.occ_depth);
		sprintf(tvin_occ, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_occ, tvin_occ);

		// release memory allocation
		delete [] occ_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_cum, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_cum, tvin_cum);

		sc_bv<32>* cum_tvin_wrapc_buffer = new sc_bv<32>[4];

		// RTL Name: cum
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: cum(31, 0)
				{
					// carray: (0) => (3) @ (1)
					for (int i_0 = 0; i_0 <= 3; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : cum[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : cum[0]
						// regulate_c_name       : cum
						// input_type_conversion : cum[i_0]
						if (&(cum[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> cum_tmp_mem;
							cum_tmp_mem = cum[i_0];
							cum_tvin_wrapc_buffer[hls_map_index].range(31, 0) = cum_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 4; i++)
		{
			sprintf(tvin_cum, "%s\n", (cum_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_cum, tvin_cum);
		}

		tcl_file.set_num(4, &tcl_file.cum_depth);
		sprintf(tvin_cum, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_cum, tvin_cum);

		// release memory allocation
		delete [] cum_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_refn, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_refn, tvin_refn);

		sc_bv<32> refn_tvin_wrapc_buffer;

		// RTL Name: refn
		{
			// bitslice(31, 0)
			{
				// celement: refn(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : refn
						// sub_1st_elem          : 
						// ori_name_1st_elem     : refn
						// regulate_c_name       : refn
						// input_type_conversion : refn
						if (&(refn) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> refn_tmp_mem;
							refn_tmp_mem = refn;
							refn_tvin_wrapc_buffer.range(31, 0) = refn_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_refn, "%s\n", (refn_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_refn, tvin_refn);
		}

		tcl_file.set_num(1, &tcl_file.refn_depth);
		sprintf(tvin_refn, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_refn, tvin_refn);

		// [[transaction]]
		sprintf(tvin_read_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_read_r, tvin_read_r);

		sc_bv<8>* read_r_tvin_wrapc_buffer = new sc_bv<8>[1024];

		// RTL Name: read_r
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: read(7, 0)
				{
					// carray: (0) => (1023) @ (1)
					for (int i_0 = 0; i_0 <= 1023; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : read[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : read[0]
						// regulate_c_name       : read
						// input_type_conversion : read[i_0]
						if (&(read[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<8> read_tmp_mem;
							read_tmp_mem = read[i_0];
							read_r_tvin_wrapc_buffer[hls_map_index].range(7, 0) = read_tmp_mem.range(7, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1024; i++)
		{
			sprintf(tvin_read_r, "%s\n", (read_r_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_read_r, tvin_read_r);
		}

		tcl_file.set_num(1024, &tcl_file.read_r_depth);
		sprintf(tvin_read_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_read_r, tvin_read_r);

		// release memory allocation
		delete [] read_r_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_readn, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_readn, tvin_readn);

		sc_bv<32> readn_tvin_wrapc_buffer;

		// RTL Name: readn
		{
			// bitslice(31, 0)
			{
				// celement: readn(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : readn
						// sub_1st_elem          : 
						// ori_name_1st_elem     : readn
						// regulate_c_name       : readn
						// input_type_conversion : readn
						if (&(readn) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> readn_tmp_mem;
							readn_tmp_mem = readn;
							readn_tvin_wrapc_buffer.range(31, 0) = readn_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_readn, "%s\n", (readn_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_readn, tvin_readn);
		}

		tcl_file.set_num(1, &tcl_file.readn_depth);
		sprintf(tvin_readn, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_readn, tvin_readn);

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		int AESL_return = bwa_align(res_sa_itv, buf, occ, cum, refn, read, readn);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_res_sa_itv, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_res_sa_itv, tvout_res_sa_itv);

		sc_bv<32>* res_sa_itv_tvout_wrapc_buffer = new sc_bv<32>[2048];

		// RTL Name: res_sa_itv
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: res_sa_itv(31, 0)
				{
					// carray: (0) => (1023) @ (1)
					for (int i_0 = 0; i_0 <= 1023; i_0 += 1)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : res_sa_itv[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : res_sa_itv[0][0]
							// regulate_c_name       : res_sa_itv
							// input_type_conversion : res_sa_itv[i_0][i_1]
							if (&(res_sa_itv[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> res_sa_itv_tmp_mem;
								res_sa_itv_tmp_mem = res_sa_itv[i_0][i_1];
								res_sa_itv_tvout_wrapc_buffer[hls_map_index].range(31, 0) = res_sa_itv_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 2048; i++)
		{
			sprintf(tvout_res_sa_itv, "%s\n", (res_sa_itv_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_res_sa_itv, tvout_res_sa_itv);
		}

		tcl_file.set_num(2048, &tcl_file.res_sa_itv_depth);
		sprintf(tvout_res_sa_itv, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_res_sa_itv, tvout_res_sa_itv);

		// release memory allocation
		delete [] res_sa_itv_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_buf_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_buf_r, tvout_buf_r);

		sc_bv<32>* buf_r_tvout_wrapc_buffer = new sc_bv<32>[4096];

		// RTL Name: buf_r
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: buf(31, 0)
				{
					// carray: (0) => (1023) @ (1)
					for (int i_0 = 0; i_0 <= 1023; i_0 += 1)
					{
						// carray: (0) => (3) @ (1)
						for (int i_1 = 0; i_1 <= 3; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : buf[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : buf[0][0]
							// regulate_c_name       : buf
							// input_type_conversion : buf[i_0][i_1]
							if (&(buf[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> buf_tmp_mem;
								buf_tmp_mem = buf[i_0][i_1];
								buf_r_tvout_wrapc_buffer[hls_map_index].range(31, 0) = buf_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 4096; i++)
		{
			sprintf(tvout_buf_r, "%s\n", (buf_r_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_buf_r, tvout_buf_r);
		}

		tcl_file.set_num(4096, &tcl_file.buf_r_depth);
		sprintf(tvout_buf_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_buf_r, tvout_buf_r);

		// release memory allocation
		delete [] buf_r_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_ap_return, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_ap_return, tvout_ap_return);

		sc_bv<32> ap_return_tvout_wrapc_buffer;

		// RTL Name: ap_return
		{
			// bitslice(31, 0)
			{
				// celement: return(31, 0)
				{
					// carray: (0) => (1) @ (0)
					{
						// sub                   : 
						// ori_name              : AESL_return
						// sub_1st_elem          : 
						// ori_name_1st_elem     : AESL_return
						// regulate_c_name       : return
						// input_type_conversion : AESL_return
						if (&(AESL_return) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> return_tmp_mem;
							return_tmp_mem = AESL_return;
							ap_return_tvout_wrapc_buffer.range(31, 0) = return_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_ap_return, "%s\n", (ap_return_tvout_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_ap_return, tvout_ap_return);
		}

		tcl_file.set_num(1, &tcl_file.ap_return_depth);
		sprintf(tvout_ap_return, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_ap_return, tvout_ap_return);

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "res_sa_itv"
		delete [] tvout_res_sa_itv;
		delete [] tvin_res_sa_itv;
		// release memory allocation: "buf_r"
		delete [] tvin_buf_r;
		delete [] tvout_buf_r;
		// release memory allocation: "occ"
		delete [] tvin_occ;
		// release memory allocation: "cum"
		delete [] tvin_cum;
		// release memory allocation: "refn"
		delete [] tvin_refn;
		// release memory allocation: "read_r"
		delete [] tvin_read_r;
		// release memory allocation: "readn"
		delete [] tvin_readn;
		// release memory allocation: "ap_return"
		delete [] tvout_ap_return;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);

		return AESL_return;
	}
}

