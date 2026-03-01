#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "buffer.h"
#include "control.h"
#include "scheduler.h"

CircularBuffer global_buffer;

void *sensor_task(void *arg) {
    (void)arg;
    uint32_t value = 0;

    while (1) {
        buffer_push(&global_buffer, value++);
        usleep(100000);
    }

    return NULL;
}

int main() {
    pthread_t sensor_thread;
    pthread_t control_thread;

    buffer_init(&global_buffer);

    pthread_create(&sensor_thread, NULL, sensor_task, NULL);
    pthread_create(&control_thread, NULL, control_task, NULL);

    set_realtime_priority(control_thread);

    pthread_join(sensor_thread, NULL);
    pthread_join(control_thread, NULL);

    return 0;
}
