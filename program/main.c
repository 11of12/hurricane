#include "stdio.h"
#include "hurricane/hurricane.h"

int main() {

    HURRICANE_WINDOW* window = hurricane_window_create();

    //const char* vertex_shader = hurricane_shader_parse_file("../shaders/vertex_shader.glsl");
    //const char* fragment_shader = hurricane_shader_parse_file("../shaders/fragment_shader.glsl");
    //int success = hurricane_shader_compile(window, &vertex_shader, &fragment_shader);
    //printf("Success?%d\n", success);
    learn_opengl_ex3_setup(window);

    while(!hurricane_window_should_close(window)) {
        hurricane_io_process_input(window);
        hurricane_render_clear(window);

        learn_opengl_ex3(window);

        hurricane_render_update(window);
    }
    learn_opengl_ex3_cleanup(window);
    hurricane_window_destroy(window);

    return 0;
}
