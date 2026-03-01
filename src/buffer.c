#include "buffer.h"

void buffer_init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
    pthread_mutex_init(&cb->mutex, NULL);
}

int buffer_push(CircularBuffer *cb, uint32_t value) {
    pthread_mutex_lock(&cb->mutex);

    if (cb->count == BUFFER_SIZE) {
        pthread_mutex_unlock(&cb->mutex);
        return -1;
    }

    cb->data[cb->head] = value;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;

    pthread_mutex_unlock(&cb->mutex);
    return 0;
}

int buffer_pop(CircularBuffer *cb, uint32_t *value) {
    pthread_mutex_lock(&cb->mutex);

    if (cb->count == 0) {
        pthread_mutex_unlock(&cb->mutex);
        return -1;
    }

    *value = cb->data[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;

    pthread_mutex_unlock(&cb->mutex);
    return 0;
}
