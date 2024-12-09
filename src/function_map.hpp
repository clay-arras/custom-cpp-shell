#ifndef FUNCTION_MAP_HPP
#define FUNCTION_MAP_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <mutex>
#include <stdexcept>
#include <iostream>
#include "commands.hpp"

class FunctionMap {
public:
    FunctionMap(const FunctionMap&) = delete; 
    static FunctionMap& getInstance();
    std::function<void(std::vector<std::string>)> get_function(const std::string& command);
    bool contains(const std::string& command);

private:
    static std::mutex map_mutex;
    static FunctionMap* instance;
    std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> function_map;

    FunctionMap();
};

#endif