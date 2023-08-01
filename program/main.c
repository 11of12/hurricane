#include "stdio.h"
#include "hurricane/hurricane.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

int main() {
    HURRICANE_WINDOW window = hurricane_window_create();

    while(!hurricane_window_should_close(window)) {

        hurricane_window_update(window);
    }

    hurricane_window_destroy(window);
    return 0;
}
