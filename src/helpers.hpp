#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <vector>
#include <string>
#include <sstream>
#include <filesystem>
#include <stdexcept>

std::vector<std::string> split_string(std::string input, char delim);
std::string get_function_path(std::string function_name);
bool check_function_in_path(std::string function_name);

#endif