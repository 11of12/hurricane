add_library(
    glad 
    src/glad/glad.h
    src/glad/glad.c
    src/KHR/khrplatform.h
    )

target_include_directories(glad PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
