# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.5)

# Set the compiler to gcc/g++
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# Set the project name
project(Versuch-07)

# Include the 'include' directory
include_directories(include)

# Set the build type to Release
set(CMAKE_BUILD_TYPE Debug)

# Create a list of source files
file(GLOB SOURCES src/*.cpp)

# Create the executable
add_executable(main ${SOURCES})
