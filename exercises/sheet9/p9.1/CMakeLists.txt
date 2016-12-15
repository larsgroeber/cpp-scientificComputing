cmake_minimum_required(VERSION 3.6)
project(p9_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Square.cpp Square.h Cube.cpp Cube.h)
add_executable(p9_1 ${SOURCE_FILES})