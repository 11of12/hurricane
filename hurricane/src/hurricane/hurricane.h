#ifndef HURRICANE_H_
#define HURRICANE_H_

typedef void* HURRICANE_WINDOW;

HURRICANE_WINDOW hurricane_window_create();
void hurricane_window_destroy(HURRICANE_WINDOW window);

int hurricane_window_should_close(HURRICANE_WINDOW window);

void hurricane_window_update(HURRICANE_WINDOW window);
#endif

