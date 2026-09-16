#include <stdio.h>
#include "binary_search.h"
#define EPSILON 1e-6
void* binary_search(void* arr[], size_t element_size, size_t num_elements, const void* target) {
    size_t left = 0;
    size_t right = num_elements - 1;
    if (num_elements <= 0) {
        return NULL;
    }
    else if (num_elements == 1) {
        return fabs(*arr - *target) < EPSILON ? *arr : NULL;
    }
    if (fabs(*(arr+left) - *target) < EPSILON) {
        return left;
    }
    if (fabs(*(arr+right) - *target) < EPSILON) {
        return right;
    }
    while (left - right < EPSILON) {
        size_t mid = left + (right - left) / 2;
        if (fabs(*(arr+mid) - *target) < EPSILON) {
            return mid;
        } else if (*(arr+mid) - *target < -EPSILON) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return NULL;
}
