cmake_minimum_required(VERSION 3.22.1)

project(test VERSION 1.0.0 LANGUAGES C)

add_subdirectory(src)

add_executable(test testapp.c topo.c)

target_link_libraries(test PUBLIC graph)
