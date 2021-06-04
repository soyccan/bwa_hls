#include <algorithm>
#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

#include "openbwt.h"

#define FOR(i, a, n) for (size_t i = a; i != n; i++)

#ifndef NDEBUG
#define debug(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)
#else
#define debug(...)
#endif

// occ stores a checkpoint every 2 rows
#define OCC_CHKPT_GAP 0

std::vector<char> ref_genome;
std::vector<char> bwt;
size_t bwt_endmark_pos;
std::vector<std::array<int, 4>> occ;
std::array<int, 4> cum;

std::array<int, 256> symbol_map;

void read_ref_genome(std::istream& in_strm)
{
  std::string line;
  in_strm.ignore(1000000, '\n');
  while (std::getline(in_strm, line)) {
    assert(line[0] != '>');
    for (char c : line) {
      ref_genome.push_back(c);
    }
  }
}

template <typename SequenceContainer>
void serialize_array(std::ostream& out_strm, const SequenceContainer& arr)
{
  out_strm.write(reinterpret_cast<const char*>(&arr[0]),
                 sizeof(arr[0]) * arr.size());
}

void bwt_ref_genome()
{
  auto tmp = std::make_unique<char[]>(ref_genome.size());

  // position of $ symbol in BWT
  bwt_endmark_pos = BWT((unsigned char*) &ref_genome[0],
                        (unsigned char*) &tmp[0], ref_genome.size());

  bwt.reserve(ref_genome.size());
  FOR (i, 0, ref_genome.size()) {
    bwt.push_back(tmp[i]);
  }
}

int main(int argc, char** argv)
{
  auto ref_filename = std::string(argv[1]);
  auto ref_file = std::fstream(ref_filename);

  auto index_filename = ref_filename + ".fmi";
  auto index_file = std::fstream(index_filename, std::ios::out);

  read_ref_genome(ref_file);

  bwt_ref_genome();

  symbol_map['A'] = symbol_map['a'] = 0;
  symbol_map['T'] = symbol_map['t'] = 1;
  symbol_map['C'] = symbol_map['c'] = 2;
  symbol_map['G'] = symbol_map['g'] = 3;

  occ.resize((ref_genome.size() + (1 << OCC_CHKPT_GAP) - 1) /
             (1 << OCC_CHKPT_GAP));
  FOR (i, 0, bwt.size()) {
    int sym = symbol_map[bwt[i]];
    cum[sym]++;

    if ((i & ((1 << OCC_CHKPT_GAP) - 1)) == 0) {
      FOR (j, 0, 4) {
        occ[i >> OCC_CHKPT_GAP][j] = cum[j];
      }
    }
  }

  FOR (i, 0, bwt.size()) {
    FOR (j, 0, 4)
      printf("%d ", occ[i][j]);
    puts("");
  }

  // write to file
  auto index_file_oi = std::ostreambuf_iterator<char>(index_file);
  serialize_array(index_file, cum);
  serialize_array(index_file, bwt);
}
