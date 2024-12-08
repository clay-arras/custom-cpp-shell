#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <functional>

std::unordered_map<std::string, std::function<std::string(bool)>> function_map;

int main() {
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    std::cout << "$ ";
  
    std::string input;
    std::getline(std::cin, input);

    if (!function_map.contains(input)) {
      std::cout << input << ": command not found\n";
    }
  }
}
