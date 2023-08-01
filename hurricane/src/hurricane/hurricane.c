#include "stdio.h"
#include "hurricane.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

int coordinate_buffer[100];

int hcn_draw_triangle() {
    printf("drawing triangle\n");
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
}

void frame_buffer_size_callback(GLFWwindow* window, int width, int height) {
    printf("resizing\n");
    glViewport(0, 0, width, height);
}

void opengl_initialize(GLFWwindow* window) {
    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);
    glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
}

int hcn_application_running(GLFWwindow* window) {
    return !glfwWindowShouldClose(window); 
}

void hcn_update(GLFWwindow* window) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
}

void hcn_terminate() {
    glfwTerminate();
}

 GLFWwindow* hcn_app_start() {
    GLFWwindow* window;

    if (!glfwInit()) {
        printf("glfw failed to initialize\n");
        return NULL;
    }

    window = glfwCreateWindow(500, 500, "Hurricane", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return NULL;
    }

    opengl_initialize(window);

    return window;
}

int* hcn_get_coordinate_buffer() {
    return coordinate_buffer;
}

void rain() {
    printf("It's raining men!");
}
