#include "helpers.hpp"

std::vector<std::string> split_string(std::string input) {
  std::vector<std::string> result;
  std::stringstream ss(input);
  std::string token;
  while (ss >> token) {
    result.push_back(token);
  }
  return result;
}