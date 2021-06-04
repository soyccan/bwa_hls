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

#include "openbwt.h"



void BWA::store_index_file(const std::string& filename)
{
  auto index_file = std::fstream(filename, std::ios::out);

  serialize_var(index_file, (int) ref_genome.size());
  serialize_var(index_file, (int) bwt_endmark_pos);
  serialize_array(index_file, occ);
  serialize_array(index_file, sa);
  serialize_array(index_file, bwt);
}

void BWA::load_index_file(const std::string& filename)
{
  auto index_file = std::fstream(filename);

  deserialize_var(index_file, ref_size);
  deserialize_var(index_file, bwt_endmark_pos);
  deserialize_array(index_file, occ, ref_size);
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
}

Reads BWA::load_reads(const std::string& filename)
{
  Reads reads;
  std::string line;
  std::fstream file(filename);

  file.ignore(0xffffffff, '\n');
  while (std::getline(file, line)) {
    reads.push_back(line);
    file.ignore(0xffffffff, '\n');
    file.ignore(0xffffffff, '\n');
    file.ignore(0xffffffff, '\n');
  }

  return reads;
}

void BWA::bwt_ref_genome()
{
  bwt.resize(ref_genome.size());
  sa.resize(ref_genome.size());

  // position of $ symbol in BWT
  bwt_endmark_pos =
      BWT((unsigned char*) &ref_genome[0], (unsigned char*) &bwt[0],
          (int*) &sa[0], ref_genome.size());
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