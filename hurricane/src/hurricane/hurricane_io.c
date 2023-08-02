#include "hurricane.h"
#include "hurricane_internal.h"
#include "stdio.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

void hurricane_io_process_input(HURRICANE_WINDOW window) {
    unsigned int TRUE = 1; 
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, TRUE);
    }
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}
