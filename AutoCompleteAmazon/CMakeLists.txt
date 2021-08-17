cmake_minimum_required(VERSION 3.19)
project(auto_complete)

include_directories(includes/general)


set(CMAKE_CXX_STANDARD 11)

add_executable(auto_complete main.cpp auto_complete.hpp)