cmake_minimum_required(VERSION 3.14)
project(game_techprog)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories (unit)
include_directories(buildings)
include_directories(map)
include_directories(functions)
include_directories(exceptions)


add_subdirectory (buildings ${PROJECT_SOURCE_DIR}/libs/lib_buildings)
add_subdirectory (unit ${PROJECT_SOURCE_DIR}/libs/lib_unit)
add_subdirectory (map ${PROJECT_SOURCE_DIR}/libs/lib_map)
add_subdirectory (functions ${PROJECT_SOURCE_DIR}/libs/lib_functions)
add_subdirectory (exceptions ${PROJECT_SOURCE_DIR}/libs/lib_exceptions)


add_executable(game_techprog main.cpp)


target_link_libraries (game_techprog buildings_Lib)
target_link_libraries (game_techprog unit_Lib)
target_link_libraries (game_techprog map_Lib)
target_link_libraries (game_techprog functions_Lib)
target_link_libraries (game_techprog exceptions_Lib)


target_include_directories (game_techprog PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

add_subdirectory(GoogleTestDemo)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)