#include <stdio.h>
#include <math.h>
#include "binary_search.h"
#include <stdlib.h>
#include <string.h>
#define EPSILON 1e-6
// function to perform binary search

int binary_search(const void *arr, size_t size, size_t element_size, const void *target, int (*compare)(const void*, const void*)) {
    if (arr == NULL || size == 0 || compare == NULL || target == NULL|| element_size == 0) {
        return -1;
    }
    int left = 0;
    int right = (int)size - 1;
    if (compare(arr, target) == 0) {
        return 0;
    }
    if (compare((const char*)arr + (size - 1) * element_size, target) == 0) {
        return (int)size - 1;
    }
    while (left <= right) {
        int mid = left + (right - left) / 2;
        const char *mid_ptr = (const char*)arr + mid * element_size;
        int cmp_result = compare(mid_ptr, target);
        if (cmp_result == 0) {
            return mid;
        } else if (cmp_result < 0) {
            left = mid + 1;  
        } else {
            right = mid - 1; 
        }
    }
    return -1;
}

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
