#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "control.h"
#include "timing.h"

extern CircularBuffer global_buffer;

void *control_task(void *arg) {
    (void)arg;

    struct timespec start, end;
    uint32_t sensor_value;

    while (1) {
        clock_gettime(CLOCK_MONOTONIC, &start);

        if (buffer_pop(&global_buffer, &sensor_value) == 0) {
            uint32_t control_output = sensor_value * 2;
            printf("Control Output: %u\n", control_output);
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        print_execution_time(start, end);

        usleep(100000);
    }

    return NULL;
}
