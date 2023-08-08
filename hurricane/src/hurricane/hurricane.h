#ifndef HURRICANE_H_
#define HURRICANE_H_

#ifndef HURRICANE_INTERNAL_H_
typedef void HURRICANE_WINDOW;
#endif

// hurricane.c
void hurricane_rain();

// hurricane_window.c
HURRICANE_WINDOW* hurricane_window_create();
void hurricane_window_set_background_color(HURRICANE_WINDOW* window, float r, float g, float b, float a);
void hurricane_window_destroy(HURRICANE_WINDOW* window);

int hurricane_window_should_close(HURRICANE_WINDOW* window);

void hurricane_window_update(HURRICANE_WINDOW* window);

// hurricane_io.c
void hurricane_io_process_input(HURRICANE_WINDOW* window);
#endif

// hurricane_shader.c
const char* hurricane_shader_parse_file(const char* filepath);
int hurricane_shader_compile(HURRICANE_WINDOW* window, const char** vertex_shader_source, const char** fragment_shader_source);

// hurricane_render.c
void hurricane_render_update(HURRICANE_WINDOW* window);
void hurricane_render_clear(HURRICANE_WINDOW* window);

// exersises.c
void learn_opengl_hello_triangle_setup(HURRICANE_WINDOW* window);
void learn_opengl_hello_triangle(HURRICANE_WINDOW* window);
void learn_opengl_hello_triangle_cleanup(HURRICANE_WINDOW* window);

void learn_opengl_ex1_setup(HURRICANE_WINDOW* window);
void learn_opengl_ex1(HURRICANE_WINDOW* window);
void learn_opengl_ex1_cleanup(HURRICANE_WINDOW* window);

void learn_opengl_ex2_setup(HURRICANE_WINDOW* window);
void learn_opengl_ex2(HURRICANE_WINDOW* window);
void learn_opengl_ex2_cleanup(HURRICANE_WINDOW* window);

void learn_opengl_ex3_setup(HURRICANE_WINDOW* window);
void learn_opengl_ex3(HURRICANE_WINDOW* window);
void learn_opengl_ex3_cleanup(HURRICANE_WINDOW* window);
//void learn_opengl_hello_triangle_ex1(HURRICANE_WINDOW* window);
void personal_circle_setup(HURRICANE_WINDOW* window);
void personal_circle(HURRICANE_WINDOW* window, double x_pos, double y_pos, unsigned int num_triangles);
void personal_circle_cleanup(HURRICANE_WINDOW* window);
void personal_circle_io(HURRICANE_WINDOW* window, double *x_pos, double *y_pos, unsigned int *num_triangles, double delta_time);

