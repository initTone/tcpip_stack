add_executable(${EXECUTABLE_NAME} testapp.c topo.c)

target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})
