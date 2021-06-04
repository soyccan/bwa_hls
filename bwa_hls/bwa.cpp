#include "bwa.h"

#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "kernel.h"
#include "openbwt.h"
#include "utils.h"


void BWA::store_index_file(const std::string& filename)
{
  auto index_file = std::fstream(filename, std::ios::out);

  serialize_var(index_file, ref_size);
  serialize_var(index_file, bwt_endmark_pos);
  serialize_array(index_file, occ);
  serialize_array(index_file, sa);
  serialize_array(index_file, bwt);
}

void BWA::load_index_file(const std::string& filename)
{
  auto index_file = std::fstream(filename);

  deserialize_var(index_file, ref_size);
  deserialize_var(index_file, bwt_endmark_pos);
  deserialize_array(index_file, occ, ref_size + 1);
  deserialize_array(index_file, sa, ref_size);
  deserialize_array(index_file, bwt, ref_size);
}

void BWA::load_ref_genome(const std::string& filename)
{
  auto file = std::fstream(filename);
  std::string line;
  file.ignore(1000000, '\n');
  while (std::getline(file, line)) {
    assert(line[0] != '>');
    for (char c : line) {
      ref_genome.push_back(c);
    }
  }
  ref_size = ref_genome.size();
}

void BWA::load_reads(const std::string& filename)
{
  std::string line;

  std::fstream file(filename);
  if (!file.is_open()) {
    std::cerr << filename << " open fail\n";
    return;
  }

  file.ignore(0xffffffff, '\n');
  while (std::getline(file, line)) {
    reads.push_back(line);
    file.ignore(0xffffffff, '\n');
    file.ignore(0xffffffff, '\n');
    file.ignore(0xffffffff, '\n');
  }
}

void BWA::bw_transform()
{
  bwt.resize(ref_genome.size());
  sa.resize(ref_genome.size());

  // position of $ symbol in BWT
  bwt_endmark_pos =
      BWT((unsigned char*) &ref_genome[0], (unsigned char*) &bwt[0],
          (int*) &sa[0], ref_genome.size());
}

void BWA::calc_occ()
{
  int cum[4] = {0};
  occ.resize(ref_genome.size() + 1);
  FOR (i, 0, ref_genome.size() + 1) {
    if (i < bwt_endmark_pos) {
      int sym = symbol_map[bwt[i]];
      cum[sym]++;
    }
    else if (i > bwt_endmark_pos) {
      int sym = symbol_map[bwt[i - 1]];
      cum[sym]++;
    }

    FOR (j, 0, 4) {
      occ[i][j] = cum[j];
    }
  }
}

void BWA::read_align()
{
  int cum[4] = {1};
  FOR (j, 1, 4) {
    cum[j] = cum[j - 1] + occ[ref_size][j - 1];
  }

  for (const auto& read : reads) {
    // call kernel function
    // TODO: initilize host memory

    // result of alignment
    // TODO: initilize with sufficient size
    static int sa_itv[1000][2];

    // TODO: initilize with sufficient size
    static int buf[1000][4];

    bwa_align(sa_itv, buf, reinterpret_cast<const int(*)[4]>(&occ[0][0]), cum,
              ref_size, read.c_str(), read.size());
  }
}

// void find_mem(const FMIndex& ref_genome_fmi, const Reads& reads)
// {
//   for (const auto& read : reads) {
//     size_t step_size = 5;
//     for (size_t i = 0; i < read.size(); i += step_size) {
//       auto kmer = read.substr(i, step_size);

//       // FMIndex::match_type matches;
//       // ref_genome_fmi.find(matches, read);
//       size_t match_pos = ref_genome_fmi.findn(kmer);

//       printf("kmer=%s match=%d\n", kmer.c_str(), match_pos);
//     }
//   }
// }