cmake_minimum_required(VERSION 3.16)
project(fcm-example)

SET (CMAKE_BUILD_TYPE "Release")
#SET (CMAKE_BUILD_TYPE "Debug")

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++17")
SET (CMAKE_CXX_FLAGS_RELEASE "-O3")
SET (CMAKE_CXX_FLAGS_DEBUG "-g3 -fsanitize=address")

SET (BASE_DIR ${CMAKE_SOURCE_DIR} )
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BASE_DIR}/../fcm-example-bin)

add_executable (fcm_test fcm_test.cpp)

add_executable (lang lang.cpp)

add_executable (findlang findlang.cpp)

add_executable (locatelang locatelang.cpp)