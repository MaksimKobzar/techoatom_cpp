cmake_minimum_required(VERSION 3.6)
project(Array)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES BoolOperation.cpp main.cpp)
add_executable(Vector ${SOURCE_FILES})