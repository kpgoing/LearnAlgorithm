cmake_minimum_required(VERSION 3.3)
project(Dijkstra)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Dijkstra/list.cpp
    Dijkstra/list.h
    Dijkstra/main.cpp)

add_executable(Dijkstra ${SOURCE_FILES})