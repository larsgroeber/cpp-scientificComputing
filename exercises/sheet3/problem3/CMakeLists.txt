cmake_minimum_required(VERSION 3.5)
project(caesar_cipher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Cipher.cpp inc/Cipher.h)
add_executable(caesar_cipher ${SOURCE_FILES})