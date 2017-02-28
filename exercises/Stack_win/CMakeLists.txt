cmake_minimum_required(VERSION 3.6)
project(Stack_win)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-std=gnu++0x)

#set(SOURCE_FILES test/StackTestLib.cpp src/Stack.cpp)
set(SOURCE_FILES main.cpp src/Stack.cpp)
add_executable(Stack_win ${SOURCE_FILES})

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
add_subdirectory(test)

#target_link_libraries(runStackTestLib StackTestLib)

