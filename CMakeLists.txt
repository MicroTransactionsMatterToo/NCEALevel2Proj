cmake_minimum_required(VERSION 3.3)
project(NCEA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES UmbrellaOrder.cpp)
add_executable(NCEA ${SOURCE_FILES})