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

  bwa.bw_transform();

  bwa.calc_occ();

  bwa.store_index_file(ref_filename + ".fmi");
}
