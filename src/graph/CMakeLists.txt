add_library(${LIBRARY_NAME} STATIC graph.c thread.c)

target_include_directories(graph PUBLIC "./")
