#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "bwa.h"
#include "utils.h"


int main(int argc, char** argv)
{
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <index.fasta.fmi> <reads.fastq>\n";
    return 1;
  }

  auto index_filename = std::string(argv[1]);
  auto reads_filename = std::string(argv[2]);

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

  bwa.read_align();

  //   std::fstream ref_genome_file(argv[1]);
  //   std::fstream reads_file(argv[2]);

  // std::string ref_genome_index_filename = std::string(argv[1]) + ".fmi";
  // ref_genome_index_to_file(ref_genome_file, ref_genome_index_filename);

  //   FMIndex* ref_genome_fmi = ref_genome_index_from_file(argv[1]);
  //   Reads reads = read_reads(reads_file);
  //   find_mem(*ref_genome_fmi, reads);
}