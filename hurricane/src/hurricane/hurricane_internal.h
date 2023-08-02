#ifndef HURRICANE_INTERNAL_H_
#define HURRICANE_INTERNAL_H_

#include "stdint.h"

typedef struct {
    float r;
    float g;
    float b;
    float a;
} HURRICANE_RGBA;

typedef struct {
    void* window;
    const char* title;
    HURRICANE_RGBA background_color;
    uint32_t screen_width;
    uint32_t screen_height;

    unsigned int shader_program;

    const char* vertex_shader;
    const char* fragment_shader;
} HURRICANE_WINDOW;



#endif
