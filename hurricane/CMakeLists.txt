add_library(
    hurricane
    src/hurricane/hurricane.c
    src/hurricane/hurricane.h
    )

target_include_directories(hurricane PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(hurricane PRIVATE glfw glad)
