cmake_minimum_required(VERSION 3.6)
project(p1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Square.cpp Square.h)
add_executable(p1 ${SOURCE_FILES})