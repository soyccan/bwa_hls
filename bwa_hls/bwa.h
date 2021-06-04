#ifndef _BWA_H_
#define _BWA_H_ 1

#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "openbwt.h"


// occ stores a checkpoint every 2 rows
#define OCC_CHKPT_GAP 0

// typedef std::vector<std::string> Reads;

template <typename T>
void deserialize_var(std::istream& istrm, T& var)
{
  istrm.read(reinterpret_cast<char*>(&var), sizeof(var));
}

template <typename SequenceContainer>
void deserialize_array(std::istream& istrm, SequenceContainer& arr, size_t n)
{
  arr.resize(n);
  istrm.read(reinterpret_cast<char*>(&arr[0]), sizeof(arr[0]) * n);
}

template <typename T>
void serialize_var(std::ostream& out_strm, T var)
{
  out_strm.write(reinterpret_cast<const char*>(&var), sizeof(var));
}

template <typename SequenceContainer>
void serialize_array(std::ostream& out_strm, const SequenceContainer& arr)
{
  out_strm.write(reinterpret_cast<const char*>(&arr[0]),
                 sizeof(arr[0]) * arr.size());
}


struct BWA {
  int ref_size;
  std::vector<char> ref_genome;
  std::vector<char> bwt;
  int bwt_endmark_pos;
  std::vector<std::array<int, 4>> occ;
  std::vector<int> sa;

  std::vector<std::string> reads;

  std::array<int, 256> symbol_map;

  BWA()
  {
    symbol_map['A'] = symbol_map['a'] = 0;
    symbol_map['C'] = symbol_map['c'] = 1;
    symbol_map['G'] = symbol_map['g'] = 2;
    symbol_map['T'] = symbol_map['t'] = 3;
  }

  void store_index_file(const std::string& filename);
  void load_index_file(const std::string& filename);

  void load_ref_genome(const std::string& filename);
  void load_reads(const std::string& filename);
  void bw_transform();
  void read_align();
  void calc_occ();
};

#endif