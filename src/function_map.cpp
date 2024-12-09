#include "function_map.hpp"

std::mutex FunctionMap::map_mutex;
FunctionMap* FunctionMap::instance = nullptr;

FunctionMap& FunctionMap::getInstance() {
    if (instance == nullptr) {
        std::lock_guard<std::mutex> lock(map_mutex);
        if (instance == nullptr) {
            instance = new FunctionMap();
        }
    }
    return *instance;
}

std::function<void(std::vector<std::string>)> FunctionMap::get_function(const std::string& command) {
    std::lock_guard<std::mutex> lock(map_mutex);
    return function_map[command];
}

bool FunctionMap::contains(const std::string& command) {
    std::lock_guard<std::mutex> lock(map_mutex);
    return function_map.contains(command);
}

FunctionMap::FunctionMap() {
    function_map["exit"] = exit_cmd;
    function_map["echo"] = echo_cmd;
    function_map["type"] = type_cmd;
}
