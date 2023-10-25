add_library(graph STATIC graph.c thread.c)

target_include_directories(graph PUBLIC "./")
