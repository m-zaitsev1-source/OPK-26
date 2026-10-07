#include <stdio.h>
#include <assert.h>
#include "insertion_sort.c"
int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = 6;
    insertion_sort((void **)arr, &n, compare_int);
    int expected[] = {1, 2, 5, 5, 6, 9};
    for (int i = 0; i < n; i++) {
        assert(arr[i] == expected[i]);
    }
    printf("Insertion sort test passed!\n");
    return 0;
}