cmake_minimum_required(VERSION 3.10)
project(ImageFilter)

set(CMAKE_CXX_STANDARD 17)

add_executable(image_filter main.cpp filters.cpp)
