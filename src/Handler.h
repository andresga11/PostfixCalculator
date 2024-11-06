#ifndef MESA_CISC187_HANDLER_H
#define MESA_CISC187_HANDLER_H

#include <stack>
#include <string>
#include <vector>

#include "BigInt.h"

using namespace mesa;

struct Handler
{
  virtual ~Handler() = default;

  virtual bool execute(std::stack<BigInt>& operands, const std::string& token) const = 0;
};

void stack_error(std::stack<BigInt>& operands);

#endif