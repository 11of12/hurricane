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

void hurricane_test_draw_triangle(HURRICANE_WINDOW* window) {
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glUseProgram(window->shader_program);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
