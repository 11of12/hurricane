#include "hurricane_internal.h"
#include "hurricane.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stdio.h"

void hurricane_render_update(HURRICANE_WINDOW* window) {
    //glUseProgram(window->shader_program);
    glfwSwapBuffers(window->window);
    glfwPollEvents();
}

void hurricane_render_clear(HURRICANE_WINDOW* window) {
    glClear(GL_COLOR_BUFFER_BIT);
}
