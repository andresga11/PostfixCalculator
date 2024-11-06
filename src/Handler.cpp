#include "Handler.h"

#include <stack>
#include <string>
#include <vector>

#include "BigInt.h"

void stack_error(std::stack<BigInt>& operands)
{
  if (operands.size() < 2)
  {
    throw std::invalid_argument("Sorry too few operands on stack, please try again");
  }
}
