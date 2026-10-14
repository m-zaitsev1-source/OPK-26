#include <stdio.h>
#include <stdlib.h>

void heapify(void *arr, 
            int n, 
            int i, 
            size_t element_size, 
            int (*compare)(const void *, const void *)) 
    {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && compare((const char*)arr+l, (const char*)arr+largest) > 0)
        largest = l;

    if (r < n && compare((const char*)arr+r, (const char*)arr+largest) > 0)
        largest = r;

    if (largest != i) {
        char temp[element_size];
        memcpy(temp, (const char*)arr+i, element_size);
        memcpy((const char*)arr+i, (const char*)arr+largest, element_size);
        memcpy((const char*)arr+largest, temp, element_size);
        heapify(arr, n, largest, element_size, compare);
    }
}
void heapSort(void *arr, int n, 
            size_t element_size, 
            int (*compare)(const void *, const void *)) {

    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i, element_size, compare);
    }
    for (int i = n - 1; i > 0; i--) {
        char temp[element_size];
        memcpy(temp, (const char*)arr+0, element_size);
        memcpy((const char*)arr+0, (const char*)arr+i, element_size);
        memcpy((const char*)arr+i, temp, element_size);
        heapify(arr, i, 0, element_size, compare);
    }
}