#include "AddHandler.h"

#include <stack>
#include <string>

#include "BigInt.h"
#include "Handler.h"


bool add_handler::execute(std::stack<BigInt>& operands, const std::string& token) const
{
  if (token == "+")
  {
    stack_error(operands);
    BigInt operand_ = operands.top();
    operands.pop();
    BigInt operand2_ = operands.top();
    operands.pop();
    operands.push(operand_ + operand2_);
    return true;
  }
  return false;
}