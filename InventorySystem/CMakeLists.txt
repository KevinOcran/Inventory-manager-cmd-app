cmake_minimum_required(VERSION 3.14)
project(InventorySystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include header files
include_directories(include)

# Automatically find all .cpp files in src/
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Add main.cpp explicitly since it's outside src/
list(APPEND SRC_FILES main.cpp)

# Define executable
add_executable(InventorySystem ${SRC_FILES})
