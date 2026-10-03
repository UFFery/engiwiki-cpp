cmake_minimum_required(VERSION 3.10)
project(Task)

add_executable(task main.cpp)
target_compile_options(task PRIVATE -Wall -Wextra -O2 -std=c++17)
