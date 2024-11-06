#ifndef MESA_CISC187_OPERAND_PUSHER_HANDLER_H
#define MESA_CISC187_OPERAND_PUSHER_HANDLER_H

#include <stack>
#include <string>

#include "BigInt.h"
#include "Handler.h"

struct operand_pusher : public Handler
{
  bool execute(std::stack<BigInt>& operands, const std::string& token) const override;
};

#endif