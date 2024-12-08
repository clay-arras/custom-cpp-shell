#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <functional>
#include <sstream>


// maybe use a struct with function pointers
std::unordered_map<std::string, std::function<void(std::string)>> function_map;

std::vector<std::string> split_string(std::string input) {
  std::vector<std::string> result;
  std::stringstream ss(input);
  std::string token;
  while (ss >> token) {
    result.push_back(token);
  }
  return result;
}

void exit_cmd(std::string input) {
  exit(0);
}

int main() {
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  function_map["exit"] = exit_cmd;

  while (true) {
    std::cout << "$ ";
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> args = split_string(input);
    if (!function_map.contains(args[0])) {
      std::cout << args[0] << ": command not found\n";
    } else {
      function_map[args[0]]("");
    }
  }
}
