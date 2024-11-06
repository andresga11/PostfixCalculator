#include "MultiplyHandler.h"

#include <string>
#include <vector>

#include "BigInt.h"
#include "Handler.h"


bool multiply_handler::execute(std::stack<BigInt>& operands, const std::string& token) const
{
  if (token == "*")
  {
    stack_error(operands);
    BigInt operand_ = operands.top();
    operands.pop();
    BigInt operand2_ = operands.top();
    operands.pop();
    operands.push(operand_ * operand2_);
    return true;
  }
  return false;
}