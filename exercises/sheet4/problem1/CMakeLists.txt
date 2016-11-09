cmake_minimum_required(VERSION 3.6)
project(problem1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES LarsRobertHendrik_problem1.cpp)
add_executable(problem1 ${SOURCE_FILES})