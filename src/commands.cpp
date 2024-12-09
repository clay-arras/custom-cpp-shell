#include "commands.hpp"

std::unordered_set<std::string> command_names = {"exit", "echo", "type"};

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
    return;
  }
  std::string path = std::getenv("PATH");
  std::vector<std::string> paths = split_string(path, ':');
  for (std::string &path: paths) {
    std::string full_path = path + "/" + args[1];
    if (std::filesystem::exists(full_path)) {
        std::cout << args[1] << " is " + full_path << std::endl;
        return;
    }
  }
  std::cout << args[1] << ": not found" << std::endl;
}
