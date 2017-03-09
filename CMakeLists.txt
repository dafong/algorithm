cmake_minimum_required(VERSION 3.5)
project(test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ReverseLinkedList.cpp)
add_executable(ReverseLinkedList ${SOURCE_FILES})

set(SOURCE_FILES ConstTest.cpp)
add_executable(ConstTest ${SOURCE_FILES})