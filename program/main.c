#include "stdio.h"
#include "hurricane/hurricane.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

int main() {
    HURRICANE_WINDOW window = hurricane_window_create();

    //hurricane_window_set_background_color(window, 0.2f, 0.3f, 0.3f, 1.0f);
    while(!hurricane_window_should_close(window)) {
        hurricane_io_process_input(window);

        hurricane_window_update(window);
    }

    hurricane_window_destroy(window);

    hurricane_rain();
    return 0;
}
