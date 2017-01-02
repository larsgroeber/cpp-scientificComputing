cmake_minimum_required(VERSION 3.6)
project(roche_limit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp helper/src/Simulation.cpp helper/include/Simulation.h helper/include/Body.h helper/include/Vector.h helper/src/Vector.cpp helper/include/IOManager.h helper/src/IOManager.cpp helper/include/Constants.h)
add_executable(roche_limit ${SOURCE_FILES})