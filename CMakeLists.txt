cmake_minimum_required(VERSION 2.6)
add_definitions(-std=c++11)

project(DisplayImage)

set(DisplayImage 1)
set(DisplayImage 0)

set(CXX_FLAGS 
-g
-Wall
-Werror
-rdynamic
)

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

message(STATUS "CMAKE_CXX_FLAGS = " ${CMAKE_CXX_FLAGS})
message(STATUS "PROJECT_SOURCE_DIR = " ${PROJECT_SOURCE_DIR})

find_package(OpenCV REQUIRED)

message(STATUS "OPENCV = " ${OpenCV_INCLUDE_DIRS})
message(STATUS "OPENCVLIST = " ${OpenCV_LIBS})

include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(sample)
