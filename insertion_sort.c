#include <stdio.h>
#include <math.h>
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


void insertion_sort(void *arr[], int*n, int (*compare)(const void *, const void *)) {
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