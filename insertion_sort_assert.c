#include <stdio.h>
#include <assert.h>
#include "insertion_sort.c"
#include "insertion_sort_assert.h"
void compare_assert(const void* a, const void* b, size_t size, size_t element_size){
    for (size_t i = 0; i < size; i++) {
        assert(*((const char*)a + i*element_size) == *((const char*)b + i*element_size));
    }
}

int main() {
    //int
    int arr[] = {5, 2, 9, 1, 5, 6};
    size_t n = 6;
    insertion_sort(arr, n, sizeof(int), compare_int);
    int expected[] = {1, 2, 5, 5, 6, 9};
    compare_assert(arr, expected, n, sizeof(int));
    printf("Insertion sort int test passed!\n");
    //double
    double arr_d[] = {5.1, 2.2, 9.3, 1.4, 5.5, 6.6};
    size_t n_d = 6;
    insertion_sort(arr_d, n_d, sizeof(double), compare_double);
    double expected_d[] = {1.4, 2.2, 5.1, 5.5, 6.6, 9.3};
    compare_assert(arr_d, expected_d, n_d, sizeof(double));
    printf("Insertion sort double test passed!\n");
    //char
    char arr_c[] = {'e', 'b', 'i', 'a', 'e', 'f'};
    size_t n_c = 6;
    insertion_sort(arr_c, n_c, sizeof(char), compare_char);
    char expected_c[] = {'a', 'b', 'e', 'e', 'f', 'i'};
    compare_assert(arr_c, expected_c, n_c, sizeof(char));
    printf("Insertion sort char test passed!\n");
    // 0 arr
    int arr_0[] = {};
    size_t n_0 = 0;
    insertion_sort(arr_0, n_0, sizeof(int), compare_int);
    int expected_0[] = {};
    compare_assert(arr_0, expected_0, n_0, sizeof(int));
    printf("Insertion sort 0 elements test passed!\n");
    // equal elements
    int arr_eq[] = {5, 5, 5, 5, 5};
    size_t n_eq = 5;
    insertion_sort(arr_eq, n_eq, sizeof(int), compare_int);
    int expected_eq[] = {5, 5, 5, 5, 5};
    compare_assert(arr_eq, expected_eq, n_eq, sizeof(int));
    printf("Insertion sort equal elements test passed!\n");
    // big array
    int arr_big[1000];
    for (int i = 0; i < 1000; i++) {
        arr_big[i] = rand() % 1000;
    }
    size_t n_big = 1000;
    insertion_sort(arr_big, n_big, sizeof(int), compare_int);
    for (int j = 1; j < 1000; j++) {
        assert(arr_big[j-1] <= arr_big[j]);
    }
    printf("Insertion sort big array test passed!\n");
    return 0;
}