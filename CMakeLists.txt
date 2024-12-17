cmake_minimum_required(VERSION 3.20)
project(console VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-std=c++20 -O0")


add_subdirectory(so)
add_subdirectory(exe)

