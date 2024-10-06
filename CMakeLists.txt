cmake_minimum_required(VERSION 3.5)

# set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_COMPILER "/usr/bin/g++-14")

cmake_policy(SET CMP0048 NEW)

project(bonus1
        VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()

add_library(Bonus extra-task-1.h extra-task-1.cpp)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Bonus)

# add_subdirectory(tests)

target_compile_options(${PROJECT_NAME} PRIVATE -g -ggdb -Werror -Wpedantic
    -Wno-parentheses)

