cmake_minimum_required(VERSION 3.16)
project(opencv-example)

find_package(OpenCV REQUIRED)

SET (CMAKE_BUILD_TYPE "Release")
#SET (CMAKE_BUILD_TYPE "Debug")

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++17 -pthread")
SET (CMAKE_CXX_FLAGS_RELEASE "-O3")
SET (CMAKE_CXX_FLAGS_DEBUG "-g3 -fsanitize=address")

SET (BASE_DIR ${CMAKE_SOURCE_DIR} )
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BASE_DIR}/../opencv-example-bin)


add_executable (ex1 ex1.cpp)
target_link_libraries(ex1 ${OpenCV_LIBS})

add_executable (ex2 ex2.cpp)
target_link_libraries(ex2 ${OpenCV_LIBS})

add_executable(testAudioCodec tests/testAudioCodec.cpp)
target_link_libraries(testAudioCodec sndfile)

add_executable (testImageCodec tests/testImageCodec.cpp)
target_link_libraries(testImageCodec ${OpenCV_LIBS})

