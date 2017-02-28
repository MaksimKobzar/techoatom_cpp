cmake_minimum_required(VERSION 3.6)
project(Stack_win)

add_subdirectory(gtest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(runStackTestLib StackTestLib.cpp)

target_link_libraries(runStackTestLib gtest gtest_main)
target_link_libraries(runStackTestLib include src)


