#include "stdio.h"
#include "hurricane/hurricane.h"

int main() {
    int* coordinate_buffer = hcn_get_coordinate_buffer();

    hcn_app_start();
    hcn_update();
    while (hcn_application_running())
    {

    }

    hcn_terminate();
    printf("Application has terminated\n");
}
