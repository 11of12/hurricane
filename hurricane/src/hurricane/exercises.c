#include "hurricane_internal.h"
#include "hurricane.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stdio.h"

void learn_opengl_hello_triangle_setup(HURRICANE_WINDOW* window) {
    float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
    };

    unsigned int indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    glGenVertexArrays(1, &window->vertex_array_objects[0]);
    glGenBuffers(1, &window->vertex_buffer_objects[0]);
    glGenBuffers(1, &window->element_buffer_objects[0]);

    glBindVertexArray(window->vertex_array_objects[0]);

    glBindBuffer(GL_ARRAY_BUFFER, window->vertex_buffer_objects[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, window->element_buffer_objects[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void learn_opengl_hello_triangle(HURRICANE_WINDOW* window) {

// this is what needs to loop
    glUseProgram(window->shader_programs[0]);
    glBindVertexArray(window->vertex_array_objects[0]);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void learn_opengl_hello_triangle_cleanup(HURRICANE_WINDOW* window) {
    glDeleteVertexArrays(1, &window->vertex_array_objects[0]);
    glDeleteBuffers(1, &window->vertex_buffer_objects[0]);
    glDeleteBuffers(1, &window->element_buffer_objects[0]);
}

//******************************************************************//
void learn_opengl_ex1_setup(HURRICANE_WINDOW* window) {
    float left_triangle[] = {
        -0.9f,  -0.4f, 0.0f,  // bottom left 
        -0.1f, -0.4f, 0.0f,  // bottom righ 
        -0.5f,   0.4f, 0.0f,  // top 

         0.1f,  -0.4f, 0.0f,  // bottom left 
         0.9f, -0.4f, 0.0f,  // bottom righ 
         0.5f,   0.4f, 0.0f,  // top 
    };

    float right_triangle[] = {
         0.1f,  -0.4f, 0.0f,  // bottom left 
         0.9f, -0.4f, 0.0f,  // bottom righ 
         0.5f,   0.4f, 0.0f,  // top 
    };

    unsigned int indices[] = {
        0, 1, 2,  // first Triangle
    };

    glGenVertexArrays(1, &window->vertex_array_objects[0]);
    glGenBuffers(1, &window->vertex_buffer_objects[0]);
    glGenBuffers(1, &window->element_buffer_objects[0]);

    glBindBuffer(GL_ARRAY_BUFFER, window->vertex_buffer_objects[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(left_triangle), left_triangle, GL_STATIC_DRAW);

    glBindVertexArray(window->vertex_array_objects[0]);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, window->element_buffer_objects[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void learn_opengl_ex1(HURRICANE_WINDOW* window) {

// this is what needs to loop
    glUseProgram(window->shader_programs[0]);
    glBindVertexArray(window->vertex_array_objects[0]);

    //glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 6); //works
}

void learn_opengl_ex1_cleanup(HURRICANE_WINDOW* window) {
    glDeleteVertexArrays(1, &window->vertex_array_objects[0]);
    glDeleteBuffers(1, &window->vertex_buffer_objects[0]);
    glDeleteBuffers(1, &window->element_buffer_objects[0]);
}

//******************************************************************//
void learn_opengl_ex2_setup(HURRICANE_WINDOW* window) {
    float left_triangle[] = {
        -0.9f,  -0.4f, 0.0f,  // bottom left 
        -0.1f, -0.4f, 0.0f,  // bottom righ 
        -0.5f,   0.4f, 0.0f,  // top 
    };

    float right_triangle[] = {
         0.1f,  -0.4f, 0.0f,  // bottom left 
         0.9f, -0.4f, 0.0f,  // bottom righ 
         0.5f,   0.4f, 0.0f,  // top 
    };

    unsigned int indices[] = {
        0, 1, 2,  // first Triangle
    };

    glGenVertexArrays(1, &window->vertex_array_objects[0]);
    glGenBuffers(1, &window->vertex_buffer_objects[0]);
    glBindBuffer(GL_ARRAY_BUFFER, window->vertex_buffer_objects[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(left_triangle), left_triangle, GL_STATIC_DRAW);
    glBindVertexArray(window->vertex_array_objects[0]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glGenVertexArrays(1, &window->vertex_array_objects[1]);
    glGenBuffers(1, &window->vertex_buffer_objects[1]);
    glBindBuffer(GL_ARRAY_BUFFER, window->vertex_buffer_objects[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(right_triangle), right_triangle, GL_STATIC_DRAW);
    glBindVertexArray(window->vertex_array_objects[1]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // really this is an unbinding
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void learn_opengl_ex2(HURRICANE_WINDOW* window) {

// this is what needs to loop
    glUseProgram(window->shader_programs[0]);
    glBindVertexArray(window->vertex_array_objects[0]);

    //glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3); //works

    glBindVertexArray(window->vertex_array_objects[1]);

    //glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3); //works
}

void learn_opengl_ex2_cleanup(HURRICANE_WINDOW* window) {
    glDeleteVertexArrays(1, &window->vertex_array_objects[0]);
    glDeleteBuffers(1, &window->vertex_buffer_objects[0]);
    glDeleteVertexArrays(1, &window->vertex_array_objects[1]);
    glDeleteBuffers(1, &window->vertex_buffer_objects[1]);
}

//******************************************************************//
void learn_opengl_ex3_setup(HURRICANE_WINDOW* window) {
    float left_triangle[] = {
        -0.9f,  -0.4f, 0.0f,  // bottom left 
        -0.1f, -0.4f, 0.0f,  // bottom righ 
        -0.5f,   0.4f, 0.0f,  // top 
    };

    float right_triangle[] = {
         0.1f,  -0.4f, 0.0f,  // bottom left 
         0.9f, -0.4f, 0.0f,  // bottom righ 
         0.5f,   0.4f, 0.0f,  // top 
    };

    unsigned int indices[] = {
        0, 1, 2,  // first Triangle
    };

    glGenVertexArrays(1, &window->vertex_array_objects[0]);
    glGenBuffers(1, &window->vertex_buffer_objects[0]);
    glBindBuffer(GL_ARRAY_BUFFER, window->vertex_buffer_objects[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(left_triangle), left_triangle, GL_STATIC_DRAW);
    glBindVertexArray(window->vertex_array_objects[0]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glGenVertexArrays(1, &window->vertex_array_objects[1]);
    glGenBuffers(1, &window->vertex_buffer_objects[1]);
    glBindBuffer(GL_ARRAY_BUFFER, window->vertex_buffer_objects[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(right_triangle), right_triangle, GL_STATIC_DRAW);
    glBindVertexArray(window->vertex_array_objects[1]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // really this is an unbinding
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    const char* vertex_shader = hurricane_shader_parse_file("../shaders/learn_opengl_triangle2_vertex_shader.glsl");
    const char* fragment_shader = hurricane_shader_parse_file("../shaders/learn_opengl_triangle2_fragment_shader.glsl");
    window->shader_programs[1] = hurricane_shader_compile(window, &vertex_shader, &fragment_shader);
}

void learn_opengl_ex3(HURRICANE_WINDOW* window) {

    glUseProgram(window->shader_programs[0]);
    glBindVertexArray(window->vertex_array_objects[0]);

    glDrawArrays(GL_TRIANGLES, 0, 3); //works

    glUseProgram(window->shader_programs[1]);
    glBindVertexArray(window->vertex_array_objects[1]);

    glDrawArrays(GL_TRIANGLES, 0, 3); //works
}

void learn_opengl_ex3_cleanup(HURRICANE_WINDOW* window) {
    glDeleteVertexArrays(1, &window->vertex_array_objects[0]);
    glDeleteBuffers(1, &window->vertex_buffer_objects[0]);
    glDeleteVertexArrays(1, &window->vertex_array_objects[1]);
    glDeleteBuffers(1, &window->vertex_buffer_objects[1]);
}
