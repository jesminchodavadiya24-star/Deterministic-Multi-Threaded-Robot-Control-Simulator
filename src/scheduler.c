#include <sched.h>
#include "scheduler.h"

int set_realtime_priority(pthread_t thread) {
    struct sched_param param;
    param.sched_priority = 80;

    return pthread_setschedparam(thread, SCHED_FIFO, &param);
}
