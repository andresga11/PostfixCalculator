#ifndef MESA_CISC187_POWER_HANDLER_H
#define MESA_CISC187_POWER_HANDLER_H

#include <stack>
#include <string>

#include "BigInt.h"
#include "Handler.h"

struct power_handler : public Handler
{
  bool execute(std::stack<BigInt>& operands, const std::string& token) const override;
};

#endif