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
    if (!FunctionMap::getInstance().contains(args[0])) {
      std::cout << args[0] << ": command not found\n";
    } else {
      FunctionMap::getInstance().get_function(args[0])(args);
    }
  }
}
