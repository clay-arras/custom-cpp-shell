#include "commands.hpp"

std::unordered_set<std::string> command_names = {"exit", "echo", "type", "pwd"};

void exit_cmd(std::vector<std::string> args) {
  exit(0);
}

void echo_cmd(std::vector<std::string> args) {
  for (int i=1; i<(int)args.size(); i++) {
    std::cout << (i == 1 ? "" : " ") << args[i];
  }
  std::cout << std::endl;
}

void type_cmd(std::vector<std::string> args) {
  if (command_names.find(args[1]) != command_names.end()) {
    std::cout << args[1] << " is a shell builtin" << std::endl;
  } else if (check_function_in_path(args[1])) {
    std::cout << args[1] << " is " + get_function_path(args[1]) << std::endl;
  } else {
    std::cout << args[1] << ": not found" << std::endl;
  }
}

void pwd_cmd(std::vector<std::string> args) {
    std::string path = std::filesystem::current_path();
    std::cout << path << std::endl;
}