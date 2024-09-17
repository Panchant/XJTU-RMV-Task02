cmake_minimum_required(VERSION 3.10)
project(OpenCV_Project)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(OpenCV_Project src/main.cpp)
target_link_libraries(OpenCV_Project ${OpenCV_LIBS})