#include "stdio.h" 
#include "hurricane.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"


void _framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}

void hurricane_window_set_background_color(HURRICANE_WINDOW window, float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

HURRICANE_WINDOW hurricane_window_create() {
    int WINDOW_WIDTH = 500;
    int WINDOW_HEIGHT = 500;
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hurricane", NULL, NULL);
    
    if (window == NULL) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
       return NULL;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glfwSetFramebufferSizeCallback(window, _framebuffer_size_callback);

    hurricane_window_set_background_color(window, 1.0f, 1.0f, 1.0f, 1.0f);

    return window;
}
void hurricane_window_destroy(HURRICANE_WINDOW window) {
    glfwTerminate();
}

int hurricane_window_should_close(HURRICANE_WINDOW window) {
    return glfwWindowShouldClose(window);
}

void hurricane_window_update(HURRICANE_WINDOW window) {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

