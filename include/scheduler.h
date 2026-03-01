#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <pthread.h>

int set_realtime_priority(pthread_t thread);

#endif
