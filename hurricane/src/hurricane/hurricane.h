#ifndef HURRICANE_H_
#define HURRICANE_H_

#include "hurricane_internal.h"

typedef struct {
} HURRICANE_COLOR_RGBA;

typedef struct {
    unsigned int window_property;
    unsigned int ip;
} HURRICANE_WINDOW_PROPERTIES;

// hurricane.c
void hurricane_rain();

// hurricane_window.c
HURRICANE_WINDOW hurricane_window_create();
void hurricane_window_set_background_color(HURRICANE_WINDOW window, float r, float g, float b, float a);
void hurricane_window_destroy(HURRICANE_WINDOW window);

int hurricane_window_should_close(HURRICANE_WINDOW window);


void hurricane_window_update(HURRICANE_WINDOW window);

// hurricane_io.c
void hurricane_io_process_input(HURRICANE_WINDOW window);
#endif

