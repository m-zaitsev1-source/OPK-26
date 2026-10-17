#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void heapify(void *arr, 
            int n, 
            int i, 
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
        char temp[element_size];
        memcpy(temp, (char*)arr+i*element_size, element_size);
        memcpy((char*)arr+i*element_size, (char*)arr+largest*element_size, element_size);
        memcpy((char*)arr+largest*element_size, temp, element_size);
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
        memcpy(temp, (char*)arr+0*element_size, element_size);
        memcpy((char*)arr+0*element_size, (char*)arr+i*element_size, element_size);
        memcpy((char*)arr+i*element_size, temp, element_size);
        heapify(arr, i, 0, element_size, compare);
    }
}