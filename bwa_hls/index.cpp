#include <algorithm>
#include <array>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

#include "bwa.h"
#include "utils.h"

int main(int argc, char** argv)
{
  auto ref_filename = std::string(argv[1]);

  BWA bwa;

  bwa.load_ref_genome(ref_filename);

  bwa.bwt_ref_genome();

  int cum[4] = {0};
  bwa.occ.resize((bwa.ref_genome.size() + (1 << OCC_CHKPT_GAP) - 1) /
                 (1 << OCC_CHKPT_GAP));
  FOR (i, 0, bwa.bwt.size()) {
    int sym = bwa.symbol_map[bwa.bwt[i]];
    cum[sym]++;

    FOR (j, 0, 4) {
      bwa.occ[i][j] = cum[j];
    }
  }

  bwa.store_index_file(ref_filename + ".fmi");
}
