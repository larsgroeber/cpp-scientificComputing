cmake_minimum_required(VERSION 3.6)
project(roche_limit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Simulation.cpp Simulation.h Object.h helper/Vector.h helper/src/Vector.cpp helper/IOManager.h helper/src/IOManager.cpp Constants.h)
add_executable(roche_limit ${SOURCE_FILES})