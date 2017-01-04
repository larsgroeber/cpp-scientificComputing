cmake_minimum_required(VERSION 3.6)
project(roche_limit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Simulation.cpp include/Simulation.h include/Body.h helper/include/Vector.h helper/src/Vector.cpp helper/include/IOManager.h helper/src/IOManager.cpp include/Constants.h)
add_executable(roche_limit ${SOURCE_FILES})