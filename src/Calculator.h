#ifndef MESA_CISC187_CALCULATOR_H
#define MESA_CISC187_CALCULATOR_H

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "BigInt.h"
#include "Handler.h"
#include "options.h"

namespace mesa
{
  class Calculator
  {
   private:
    options opt;

   public:
    Calculator(int argc, char** argv);
    void calculate();
  };
}  

#endif