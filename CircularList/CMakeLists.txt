cmake_minimum_required(VERSION 3.3)
project(CircularList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    CircularList/CircularList.h
    CircularList/main.cpp)

add_executable(CircularList ${SOURCE_FILES})