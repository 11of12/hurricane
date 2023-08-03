add_library(
    hurricane
    src/hurricane/hurricane_window.c
    src/hurricane/hurricane_render.c
    src/hurricane/exercises.c
    src/hurricane/hurricane_io.c
    src/hurricane/hurricane_shader.c
    src/hurricane/hurricane.h
    )

target_include_directories(hurricane PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(hurricane PRIVATE glfw glad)
