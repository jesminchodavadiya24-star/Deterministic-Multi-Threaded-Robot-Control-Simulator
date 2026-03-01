#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>
#include <pthread.h>

#define BUFFER_SIZE 32

typedef struct {
    uint32_t data[BUFFER_SIZE];
    int head;
    int tail;
    int count;
    pthread_mutex_t mutex;
} CircularBuffer;

void buffer_init(CircularBuffer *cb);
int buffer_push(CircularBuffer *cb, uint32_t value);
int buffer_pop(CircularBuffer *cb, uint32_t *value);

#endif
