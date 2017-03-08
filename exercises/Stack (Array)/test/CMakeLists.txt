cmake_minimum_required(VERSION 3.6)
project(Stack_win)

#-------------------
# Google Test
#-------------------
add_subdirectory(gtest)

add_definitions(${MSVC_COMPILER_DEFS})
enable_testing()
#set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})

#set(BUILD_GTEST)
#file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
#add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
#add_dependencies(${PROJECT_TEST_NAME} googletest)

#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Stack Unit Test Library
#add_executable(runStackTestLib StackTestLib.cpp)

#target_link_libraries(runStackTestLib gtest gtest_main)
#target_link_libraries(runStackTestLib include src)


