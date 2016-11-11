cmake_minimum_required(VERSION 3.6)
project(play_go)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lncurses")

set(SOURCE_FILES src/main.cpp src/Game.cpp src/Board.cpp inc/Game.h inc/Board.h inc/Error.h)
add_executable(play_go ${SOURCE_FILES})