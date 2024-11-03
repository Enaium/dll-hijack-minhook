cmake_minimum_required(VERSION 3.29)
project(hook_test)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(hook_test main.cpp)
