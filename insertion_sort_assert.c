#include <stdio.h>
#include <assert.h>
#include "insertion_sort.c"
int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    size_t n = 6;
    insertion_sort(arr, n, sizeof(int), compare_int);
    int expected[] = {1, 2, 5, 5, 6, 9};
    for (size_t i = 0; i < n; i++) {
        assert(arr[i] == expected[i]);
    }
    printf("Insertion sort test passed!\n");
    return 0;
}