cmake_minimum_required(VERSION 3.3)
project(TopSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    TopSort/hashtab.h
    TopSort/Hashtable.cpp
    TopSort/main.cpp
    TopSort/Queue.cpp
    TopSort/QueueADTbyList.h
    TopSort/Status.h
    TopSort/Vertex.cpp
    TopSort/Vertex.hpp)

add_executable(TopSort ${SOURCE_FILES})