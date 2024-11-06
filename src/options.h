#ifndef MESA_CISC187_PROJECT2_POSTFIX_CALC_H
#define MESA_CISC187_PROJECT2_POSTFIX_CALC_H

#include <string>

#include "BigInt.h"

namespace mesa
{
  struct options
  {
    bool verbose = false;
  };
  options get_options(int argc, char** argv);

  std::string usage(const std::string& prog);

  std::string help(const std::string& prog);

}  // namespace mesa


#endif