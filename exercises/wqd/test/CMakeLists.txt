cmake_minimum_required(VERSION 3.6)
project(Stack)

set(PROJECT_NAME_STR Stack)
project(${PROJECT_NAME_STR} C CXX)

find_package(Threads REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
        add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

if(MSVC)
        #vc 2012 fix for vararg templates
        set(MSVC_COMPILER_DEFS "-D_VARIADIC_MAX=10")
endif()
#-------------------
# set common include folder for module
#-------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

set(CMAKE_CXX_STANDARD 11)
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
#add_definitions(-std=gnu++0x)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
set(SOURCE_FILES src/Stack.cpp)
add_executable(StackDraft main.cpp ${SOURCE_FILES})
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES} ${SOURCE_FILES})
#add_dependencies(${PROJECT_TEST_NAME} googletest)

#add_executable(runStackTestLib test/StackTestLib.cpp ${SOURCE_FILES})

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        #        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
add_subdirectory(test)

