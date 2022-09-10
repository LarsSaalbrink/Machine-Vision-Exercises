cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(Segment)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Segment Segment.cpp)

target_link_libraries(Segment ${OpenCV_LIBS})

