cmake_minimum_required(VERSION 3.6)
project(SmartException)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/Root.cpp src/SmartException.cpp main.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(SmartExceptionDraft ${SOURCE_FILES})