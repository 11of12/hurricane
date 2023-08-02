#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#include "hurricane_internal.h"
#include "hurricane.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

const char* hurricane_shader_parse_file(const char* filepath) {
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return NULL;
    }
    char* file_contents = NULL;
    char* line = NULL;
    size_t length = 0;
    size_t file_length = 0;
    ssize_t return_code = 0;

    while ((return_code = getline(&line, &length, file)) != -1) {
        file_length += return_code;
        
        file_contents = realloc(file_contents, file_length + 1);
        if (file_contents == NULL) {
            printf("Failed to allocate memory\n");
            free(line);
            fclose(file);
        }

        memcpy(file_contents + file_length - return_code, line, return_code);
        file_contents[file_length] = '\0';  // Null-terminate the string
    } 

    fclose(file);
    return file_contents;
}

int hurricane_shader_compile(HURRICANE_WINDOW* window, const char** vertex_shader_source, const char** fragment_shader_source) {
    unsigned int vertex_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER); // seg faults here
    glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    int success;
    char info_log[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
        printf("Vertex Shader Compilation Failed\n");
        return success;
    }

    unsigned int fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success); 

    if(!success) {
        glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
        printf("Vertex Shader Compilation Failed\n");
        return success;
    }

    unsigned int shader_program;
    shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, 512, NULL, info_log);
        printf("Shader Program Link Failed\n");
        return success;
    }

    glUseProgram(shader_program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return shader_program;
}

