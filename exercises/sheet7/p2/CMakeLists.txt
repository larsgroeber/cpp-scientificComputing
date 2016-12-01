cmake_minimum_required(VERSION 3.6)
project(p2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -lm")

set(SOURCE_FILES main.c)
add_executable(p2 ${SOURCE_FILES})