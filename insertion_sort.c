#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "insertion_sort.h"
#define EPSILON 1e-9
int compare_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int compare_double(const void *a, const void *b) {
    double da = *(const double*)a;
    double db = *(const double*)b;
    if (fabs(da - db) < EPSILON) {
        return 0;
    }
    return (da > db) - (da < db);
}

int compare_char(const void *a, const void *b) {
    char ca = *(const char*)a;
    char cb = *(const char*)b;
    return (ca > cb) - (ca < cb);
}
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

void insertion_sort(const void *arr,
                    size_t n, 
                    size_t element_size, 
                    int (*compare)(const void *, const void *)) 
    {
    size_t i, j;
    const void *key;
    for (i = 2; i < n; i++) {
        key = (const char*)arr + i * element_size;
        j = i;
        while (j > 0 && compare((const char*)arr + j * element_size, (const char*)arr + (j-1) * element_size) < 0) {
            swap((void*)((const char*)arr + j * element_size), (void*)((const char*)arr + (j-1) * element_size), element_size);
            j = j - 1;
        }
    }
}