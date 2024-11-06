#include "options.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

std::string mesa::usage(const std::string& prog)
{
  std::string msg = "\nUsage: ";
  return msg.append(prog).append(" [-h] [-v]\n");
}

std::string mesa::help(const std::string& prog)
{
  auto msg = mesa::usage(prog);
  std::string help_message =
      "to run the program interactively. To run using standard input: \n"
      "echo 'equation' | ./calc\n"
      "where 'equation' is a postfix notation equation, i.e. '2 2 +'\n"
      "or:\n"
      "  ./calc < input_file.txt\n"
      "where 'input_file.txt' contains postfix notation equations, one per line\n\n"
      "Options:\n"
      "  -h   Show this text\n"
      "  -v   Set a verbose output flag. Default = false.\n\n"
      "Running with no input from standard in enters 'interactive mode'.\n"
      "Equations can be entered one per line\n"
      "The program runs until 'quit' is the first word on a line or EOF is reached.\n"
      "#\n";
  return msg.append(help_message);
}

mesa::options mesa::get_options(int argc, char** argv)
{
  mesa::options option;


  for (int i = 1; i < argc; ++i)
  {
    if (std::strcmp(argv[i], "-h") == 0)
    {
      auto help_msg = help(argv[0]);
      std::cout << help_msg << std::endl;
      std::exit(0);
    }
    else if (std::strcmp(argv[i], "-v") == 0)
    {
      option.verbose = true;
    }
    else
    {
      throw std::invalid_argument("Unknown command received!. [-h] for help.\n" + mesa::usage(argv[i]));
    }
  }

  return option;
}