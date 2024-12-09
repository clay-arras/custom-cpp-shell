#include "helpers.hpp"

std::vector<std::string> split_string(std::string input, char delim) {
  std::vector<std::string> result;
  std::stringstream ss(input);
  std::string token;
  while (std::getline(ss, token, delim)) {
    result.push_back(token);
  }
  return result;
}