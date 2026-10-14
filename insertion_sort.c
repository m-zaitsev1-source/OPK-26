#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "insertion_sort.h"
#define EPSILON 1e-9

void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    if (temp == NULL) {
        return;
    }
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void insertion_sort(void *arr,
                    size_t n, 
                    size_t element_size, 
                    int (*compare)(const void *, const void *)) 
    {
    if (arr == NULL || n == 0 || element_size == 0 || compare == NULL) {
        return;
    }
    size_t j;
    for (size_t i = 1; i < n; i++) {
        j = i;
        while (j > 0 && compare((const char*)arr + j * element_size, (const char*)arr + (j-1) * element_size) < 0) {
            swap((void*)((const char*)arr + j * element_size), (void*)((const char*)arr + (j-1) * element_size), element_size);
            j = j - 1;
        }
    }
}