cmake_minimum_required(VERSION 3.10)
project(ImageFilter)

set(CMAKE_CXX_STANDARD 17)

# Set the output directory for the executable to the root directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(image_filter main.cpp filters.cpp)


