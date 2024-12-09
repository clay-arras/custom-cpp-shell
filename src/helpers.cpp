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

std::string get_function_path(std::string function_name) {
  std::string path = std::getenv("PATH");
  std::vector<std::string> paths = split_string(path, ':');
  for (std::string &path: paths) {
    std::string full_path = path + "/" + function_name;
    if (std::filesystem::exists(full_path)) {
        return full_path;
    }
  }
  throw std::runtime_error("Function not found in path");
}

bool check_function_in_path(std::string function_name) {
  std::string path = std::getenv("PATH");
  std::vector<std::string> paths = split_string(path, ':');
  for (std::string &path: paths) {
    std::string full_path = path + "/" + function_name;
    if (std::filesystem::exists(full_path)) 
        return true;
  }
  return false;
}