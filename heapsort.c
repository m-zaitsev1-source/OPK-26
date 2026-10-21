#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heapsort.h"
void swap(void *a, void *b, size_t size) { // переписат
    void *temp = malloc(size);
    if (temp == NULL) {
        return;
    }
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void heapify(void *arr, 
            size_t n, 
            size_t i, 
            size_t element_size, 
            int (*compare)(const void *, const void *)) 
    {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && compare((const char*)arr+l*element_size, (const char*)arr+largest*element_size) > 0)
        largest = l;

    if (r < n && compare((const char*)arr+r*element_size, (const char*)arr+largest*element_size) > 0)
        largest = r;

    if (largest != i) {
        swap((void*)((const char*)arr+i*element_size), (void*)((const char*)arr+largest*element_size), element_size);
        heapify(arr, n, largest, element_size, compare);
    }
}
void heapSort(void *arr, size_t n, 
            size_t element_size, 
            int (*compare)(const void *, const void *)) {

    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i, element_size, compare);
    }
    for (int i = n - 1; i > 0; i--) {
        swap((void*)((const char*)arr), (void*)((const char*)arr+i*element_size), element_size);
        heapify(arr, i, 0, element_size, compare);
    }
}