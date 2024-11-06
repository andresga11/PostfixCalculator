#ifndef MESA_CISC187_ADD_HANDLER_H
#define MESA_CISC187_ADD_HANDLER_H

#include <stack>
#include <string>

#include "BigInt.h"
#include "Handler.h"

struct add_handler : public Handler
{
  bool execute(std::stack<BigInt>& operands, const std::string& token) const override;
};

#endif