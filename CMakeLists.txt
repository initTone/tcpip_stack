cmake_minimum_required(VERSION 3.22.1)

project(test VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD  11)

set(LIBRARY_NAME graph)
set(EXECUTABLE_NAME test1)

add_subdirectory(src)

add_subdirectory(tests)
