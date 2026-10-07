#include <stdio.h>
#include <math.h>
#define EPSILON 1e-9
int compare_int(void *a, void *b) {
    return (*(int *)a - *(int *)b);
}
int compare_double(void *a, void *b) {
    if (fabs(*(double *)a - *(double *)b) < EPSILON) {
        return 0;
    }
    else if (*(double *)a - *(double *)b > EPSILON) {
        return -1;
    } else {
        return 1;
    }
}

void insertion_sort(void *arr[], int*n, int (*compare)(void *,void *)) {
    int i, j;
    void *key;
    for (i = 1; i < *n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && compare(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}