cmake_minimum_required(VERSION 3.3)
project(TwoStackInOneArray)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    TwoStackInOneArray/main.cpp
    TwoStackInOneArray/TwoStackInOneArray.h)

add_executable(TwoStackInOneArray ${SOURCE_FILES})