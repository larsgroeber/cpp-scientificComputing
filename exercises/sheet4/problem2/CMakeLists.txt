cmake_minimum_required(VERSION 3.6)
project(problem2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES LarsRobertHendrik_problem2.cpp)
add_executable(problem2 ${SOURCE_FILES})