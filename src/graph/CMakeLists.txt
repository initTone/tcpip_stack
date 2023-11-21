add_library(${LIBRARY_NAME} STATIC graph.c
                                   graph.h
                                   thread.c
                                   thread.h
                                   net.c
                                   net.h
                                   utility.c
                                   utility.h)

target_include_directories(graph PUBLIC "./")
