cmake_minimum_required(VERSION 3.22.1)

project(test C)

add_executable(test testapp.c 
					topo.c 
					graph.c
					thread.c)


