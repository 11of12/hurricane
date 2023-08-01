#include "stdio.h"
#include "hurricane.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"


HURRICANE_WINDOW hurricane_window_create() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(500, 500, "Hurricane", NULL, NULL);
    
    if (window == NULL) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return NULL;
    }
    else {
        glfwMakeContextCurrent(window);
    }

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
