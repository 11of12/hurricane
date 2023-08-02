#include "stdio.h" 
#include "stdlib.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "hurricane_internal.h"
#include "hurricane.h"

#if 0
#define HURRICANE_DEFAULT_BACKGROUND_COLOR_R 1.0f
#define HURRICANE_DEFAULT_BACKGROUND_COLOR_G 1.0f
#define HURRICANE_DEFAULT_BACKGROUND_COLOR_B 1.0f
#define HURRICANE_DEFAULT_BACKGROUND_COLOR_A 1.0f
#endif



void _window_init(HURRICANE_WINDOW* window) {
HURRICANE_RGBA default_rgba = {1.0f,1.0f,1.0f,1.0f};
uint32_t default_screen_width = 800;
uint32_t default_screen_height = 600;
const char* default_title = "Default Hurricane Window";

const char* default_vertex_shader = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char* default_fragment_shader = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

    window->background_color = default_rgba;
    window->vertex_shader = default_vertex_shader;
    window->fragment_shader = default_fragment_shader;
    window->screen_width = default_screen_width;
    window->screen_height = default_screen_height;
    window->title = default_title;

    //printf("%p\n", &window->vertex_shader);
}

void _framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}

void hurricane_window_set_background_color(HURRICANE_WINDOW* window, float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

HURRICANE_WINDOW* hurricane_window_create() {
    HURRICANE_WINDOW* window = malloc(sizeof(HURRICANE_WINDOW));
    _window_init(window);

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window->window = glfwCreateWindow(window->screen_width, window->screen_height, window->title, NULL, NULL);
    
    
    if (window->window == NULL) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window->window);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
       return NULL;
    }


    glfwGetFramebufferSize(window->window, &window->screen_width, &window->screen_height);
    glViewport(0, 0, window->screen_width, window->screen_height);

    hurricane_window_set_background_color(window->window, 1.0f, 1.0f, 1.0f, 1.0f);

    glfwSetFramebufferSizeCallback(window->window, _framebuffer_size_callback);

    window->shader_program = hurricane_shader_compile(window, &(window->vertex_shader), &(window->fragment_shader));

    return window;
}
void hurricane_window_destroy(HURRICANE_WINDOW* window) {
    free(window);
    glfwTerminate();
}

int hurricane_window_should_close(HURRICANE_WINDOW* window) {
    return glfwWindowShouldClose(window->window);
}


