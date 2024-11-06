#include <iostream>
#include <vector>

#include "BigInt.h"
#include "Calculator.h"
#include "Handler.h"

int main(int argc, char** argv)
{
  Calculator calculator(argc, argv);
  calculator.calculate();

  return 0;
}
