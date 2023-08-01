#ifndef HURRICANE_H_
#define HURRICANE_H_

int* hcn_app_start();
int hcn_application_running();

int hcn_draw_triangle();
void hcn_update();
void hcn_terminate();
int* hcn_get_coordinate_buffer();
void rain();

#endif

