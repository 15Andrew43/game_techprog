cmake_minimum_required(VERSION 3.14)
project(GoogleTestDemo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
set(SOURCE_FILES main_test.cpp)
add_executable(GoogleTestDemo ${SOURCE_FILES})
target_link_libraries(GoogleTestDemo gtest gtest_main)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)