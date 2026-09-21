#include <stdio.h>
#include <math.h>
#include "binary_search.h"
#define EPSILON 1e-6

int compare(const void* a, const void* b) {
    double diff = *(double*)a - *(double*)b;
    if (fabs(diff) < EPSILON) {
        return 0;
    } else if (diff < 0) {
        return -1;
    } else {
        return 1;
    }
}

size_t binary_search(void* arr[], size_t num_elements, const void* target) {
    size_t left = 0;
    size_t right = num_elements - 1;
    if (num_elements <= 0) {
        return -1;
    }
    else if (num_elements == 1) {
        if (compare(*arr, target) == 0 ) {
            return 0;
        } else {
            return -1;
        }
    }
    if (compare(*(arr+left), target) == 0) {
        return left;
    }
    if (compare(*(arr+right), target) == 0) {
        return right;
    }
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        int cmp = compare(*(arr+mid), target);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
