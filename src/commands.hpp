#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

extern std::unordered_set<std::string> command_names;

void exit_cmd(std::vector<std::string> args);
void echo_cmd(std::vector<std::string> args);
void type_cmd(std::vector<std::string> args);

#endif