#include "stdio.h"
#include "hurricane/hurricane.h"

int main() {

    HURRICANE_WINDOW* window = hurricane_window_create();

    const char* shader = hurricane_load_shader("../shaders/vertex_shader.glsl");

    while(!hurricane_window_should_close(window)) {
        hurricane_io_process_input(window);

        hurricane_window_update(window);
    }

    hurricane_window_destroy(window);

    return 0;
}
