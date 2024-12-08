cmake_minimum_required(VERSION 3.13)

set( EMCC_SUFFIX "" ) 
set( CMAKE_CXX_COMPILER "/usr/bin/g++" )
set( CMAKE_C_COMPILER "/usr/bin/gcc" )

project(shell-starter-cpp)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard

add_executable(shell ${SOURCE_FILES})
