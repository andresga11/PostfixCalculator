#include "ExecuteHandler.h"

#include <string>
#include <vector>

#include "AddHandler.h"
#include "BigInt.h"
#include "Handler.h"
#include "MultiplyHandler.h"
#include "OperandPusher.h"
#include "PowerHandler.h"


ExecuteHandler::ExecuteHandler()
{
  chain.push_back(std::unique_ptr<Handler>(new add_handler));
  chain.push_back(std::unique_ptr<Handler>(new multiply_handler));
  chain.push_back(std::unique_ptr<Handler>(new power_handler));
  chain.push_back(std::unique_ptr<Handler>(new operand_pusher));
}

bool ExecuteHandler::execute(std::stack<BigInt>& operands, const std::string& token) const
{
  for (const auto& it : chain)
  {
    if (it->execute(operands, token) == true)
    {
      return true;
    }
  }

  return false;
}
