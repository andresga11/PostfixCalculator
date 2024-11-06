#include "Calculator.h"

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "BigInt.h"
#include "ExecuteHandler.h"
#include "Handler.h"
#include "options.h"


namespace mesa
{
  Calculator::Calculator(int argc, char** argv) : opt(get_options(argc, argv)) {}


  BigInt solve(const std::string& exp)
  {
    std::stack<BigInt> operands;
    std::stringstream ss(exp);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> tokens(begin, end);
    for (int i = 0; i < tokens.size(); ++i)
    {
      if (tokens[i].empty())
      {
        continue;
      }
      if (tokens[i].find_first_not_of("0123456789*^+") != std::string::npos)
      {
        std::cout << tokens[i] << '\n' << std::endl;
        throw std::invalid_argument("Invalid input: " + tokens[i] + "    use -h for help");  
      }

      ExecuteHandler exe_handle;
      exe_handle.execute(operands, tokens[i]);
    }
    if (operands.size() > 1)
    {
      throw std::invalid_argument("Error! could not produce a result. \n Too few operators in problem.");
    }

    return operands.top();
  }
}  // namespace mesa

void Calculator::calculate()
{
  std::string line;
  while (getline(std::cin, line))
  {
    BigInt answer;
    if (line == "quit")
    {
      break;
    }

    if (line.empty() || line[0] == '#')
    {
      continue;
    }
    auto initial_index = line.find_first_of("0123456789*^+");
    if (initial_index == std::string::npos)
    {
      continue;
    }
    else
    {
      line = line.substr(initial_index);
    }
    if (opt.verbose)
    {
      std::cout << line;
    }
    try
    {
      answer = solve(line);
      if (opt.verbose)
      {
        std::cout << " = ";
      }
    }
    catch (const std::exception& e)
    {
      std::cerr << "\nException occured.\n";
      std::cerr << "Details: " << e.what() << std::endl;
    }

    std::cout << answer << '\n';
    line.clear();
  }
}