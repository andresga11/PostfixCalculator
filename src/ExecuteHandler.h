#ifndef MESA_CISC187_EXECUTE_HANDLER_H
#define MESA_CISC187_EXECUTE_HANDLER_H

#include <memory>
#include <stack>
#include <string>

#include "BigInt.h"
#include "Handler.h"


class ExecuteHandler : public Handler
{
 private:
  std::vector<std::unique_ptr<Handler>> chain;

 public:
  ExecuteHandler();
  bool execute(std::stack<BigInt>& operands, const std::string& token) const override;
};

#endif