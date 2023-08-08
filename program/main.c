#include "stdio.h"
#include "hurricane/hurricane.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "unistd.h"


int main() {

    HURRICANE_WINDOW* window = hurricane_window_create();

    //const char* vertex_shader = hurricane_shader_parse_file("../shaders/vertex_shader.glsl");
    //const char* fragment_shader = hurricane_shader_parse_file("../shaders/fragment_shader.glsl");
    //int success = hurricane_shader_compile(window, &vertex_shader, &fragment_shader);
    //printf("Success?%d\n", success);


    double x_pos = 0.0;
    double y_pos = 0.0;
    unsigned int num_triangles = 3;

    double previous_time = glfwGetTime();
    
    while(!hurricane_window_should_close(window)) {
        double current_time = glfwGetTime();
        double delta_time = current_time - previous_time;
        previous_time = current_time;

        hurricane_io_process_input(window);
        personal_circle_io(window, &x_pos, &y_pos, &num_triangles, delta_time);
        hurricane_render_clear(window);

        personal_circle(window, x_pos, y_pos, num_triangles);

        hurricane_render_update(window);

    }
    hurricane_window_destroy(window);

    return 0;
}
