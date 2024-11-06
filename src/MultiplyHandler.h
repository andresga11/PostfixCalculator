#ifndef MESA_CISC187_MULTPLY_HANDLER_H
#define MESA_CISC187_MULTPLY_HANDLER_H

#include <stack>
#include <string>

#include "Handler.h"

struct multiply_handler : public Handler
{
  bool execute(std::stack<BigInt>& operands, const std::string& token) const override;
};

#endif