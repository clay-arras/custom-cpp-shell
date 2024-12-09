#include "commands.hpp"

void exit_cmd(std::vector<std::string> args) {
  exit(0);
}

void echo_cmd(std::vector<std::string> args) {
  for (int i=1; i<(int)args.size(); i++) {
    std::cout << args[i] << " ";
  }
  std::cout << std::endl;
}