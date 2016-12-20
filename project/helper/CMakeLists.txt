cmake_minimum_required(VERSION 3.6)
project(test_gravity)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lm")

set(SOURCE_FILES main.cpp src/IOManager.cpp IOManager.h src/Vector.cpp Vector.h)
add_executable(test_gravity ${SOURCE_FILES})