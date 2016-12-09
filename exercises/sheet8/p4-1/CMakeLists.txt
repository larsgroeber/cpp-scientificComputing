cmake_minimum_required(VERSION 3.6)
project(p4_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ExoPlanets.cpp Planet.cpp)
add_executable(p4_1 ${SOURCE_FILES})