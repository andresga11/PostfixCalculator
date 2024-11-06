#include "OperandPusher.h"

#include <stack>
#include <string>

#include "BigInt.h"


bool operand_pusher::execute(std::stack<BigInt>& operands, const std::string& token) const
{
  operands.push(BigInt(token));
  return true;
}