#include <stdio.h>
#include <stdlib.h>
#include "dec.h"

void deque_create(Deque *d) {
    d->capacity = 4;
    d->size = 0;
    d->front = 0;
    d->back = 0;
    d->data = (Pointer *)malloc(d->capacity*sizeof(Pointer));
}
void deque_destroy(Deque *d) {
    free(d->data);
    d->capacity = 0;
    d->size = 0;
    d->front = 0;
    d->back = 0;
}
size_t deque_size(Deque *d) {
    return d->size;
}
void deque_push_front(Deque *d, void *elem) {
    if (d->size == d->capacity){
        d->capacity *= 2;
        d->data = (Pointer *)realloc(d->data, d->capacity * sizeof(Pointer));
        if (d->data == NULL){
            return;
        }
    }
    d->front = (d->front - 1 + d->capacity) % d->capacity;
    d->data[d->front] = elem;
    d->size++;
}
void deque_push_back(Deque *d, void *elem) {
    if (d->size == d->capacity){
        d->capacity *= 2;
        d->data = (Pointer *)realloc(d->data, d->capacity * sizeof(Pointer));
    }
    d->data[d->back] = elem;
    d->back = (d->back + 1);
    d->size++;
}
Pointer deque_pop_front(Deque *d) {
    d->front = deque_peek_front(d);
    Pointer elem = d->data[d->front];
    d->data[d->front] = NULL;
    d->front = (d->front + 1) % d->capacity;
     if (d->size > 0 && d->size == d->capacity / 4) {
        d->capacity /= 2;
        d->data = (Pointer *)realloc(d->data, d->capacity * sizeof(Pointer));
    }
    d->size--;
    return elem;
}
Pointer deque_pop_back(Deque *d) {
    d->back = deque_peek_back(d);
    Pointer elem = d->data[d->back];
    d->data[d->back] = NULL;
    d->size--;
    if (d->size > 0 && d->size == d->capacity / 4) {
        d->capacity /= 2;
        d->data = (Pointer *)realloc(d->data, d->capacity * sizeof(Pointer));
    }
    return elem;
}
Pointer deque_peek_front(Deque *d) {
    if (d->size == 0) {
        return NULL;
    }
    return d->data[d->front];
}
Pointer deque_peek_back(Deque *d) {
    if (d->size == 0) {
        return NULL;
    }
    return d->data[(d->back - 1 + d->capacity) % d->capacity];
}