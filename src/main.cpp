#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <functional>
#include "function_map.hpp"
#include "helpers.hpp"
#include "commands.hpp"

int main() {
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    std::cout << "$ ";
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> args = split_string(input, ' ');
    if (FunctionMap::getInstance().contains(args[0])) {
      FunctionMap::getInstance().get_function(args[0])(args);
    } else if (check_function_in_path(args[0])) {
      std::string command_str = get_function_path(args[0]);
      for (int i = 1; i < (int)args.size(); i++) {
        command_str += " " + args[i];
      }
      std::system(command_str.c_str());
    } else {
      std::cout << args[0] << ": command not found\n";
    }
  }
}
