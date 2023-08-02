#include "stdio.h" 
#include "stdlib.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "hurricane_internal.h"
#include "hurricane.h"

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
    if (!window) {
        fprintf(stderr, "Failed to allocate memory for window.\n");
        return NULL;
    }

    int WINDOW_WIDTH = 500;
    int WINDOW_HEIGHT = 500;
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window->window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hurricane", NULL, NULL);
    
    
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


    glfwGetFramebufferSize(window->window, &WINDOW_WIDTH, &WINDOW_HEIGHT);
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    hurricane_window_set_background_color(window->window, 1.0f, 1.0f, 1.0f, 1.0f);

    glfwSetFramebufferSizeCallback(window->window, _framebuffer_size_callback);

    return window;
}
void hurricane_window_destroy(HURRICANE_WINDOW* window) {
    free(window);
    glfwTerminate();
}

int hurricane_window_should_close(HURRICANE_WINDOW* window) {
    return glfwWindowShouldClose(window->window);
}

void hurricane_window_update(HURRICANE_WINDOW* window) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window->window);
    glfwPollEvents();
}

