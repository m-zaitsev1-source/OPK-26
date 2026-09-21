#include <stdio.h>
#include <assert.h>
#include "binary_search.c"
#include <stdlib.h>
#include "binary_search.h"

int main() {
    //element in massive
    double arr1[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int arr2[] = {1, 2, 3, 4, 5};
    size_t num_elements = sizeof(arr1) / sizeof(arr1[0]);
    double target = 3.0;
    size_t result = binary_search((void**)arr1, num_elements, &target);
    assert(result == 2);
    assert(*(double*)(&arr1[result]) == target);
    size_t result2 = binary_search((void**)arr2, num_elements, &target);
    assert(result2 == 2);

    // target not in array
    target = 6.0;
    result = binary_search((void**)arr1, num_elements, &target);
    assert(result == -1);
    target = 6;
    result2 = binary_search((void**)arr2, num_elements, &target);
    assert(result2 == -1);

    // 1 element in array
    double arr3[] = {1.0};
    int arr4[] = {1};
    num_elements = sizeof(arr3) / sizeof(arr3[0]);
    target = 1.0;
    result = binary_search((void**)arr3, num_elements, &target);
    assert(result == 0);
    assert(*(double*)(&arr3[result]) == target);
    target = 2.0;
    result = binary_search((void**)arr3, num_elements, &target);
    assert(result == -1);

    // empty array
    double arr5[] = {};
    int arr6[] = {};
    num_elements = sizeof(arr5) / sizeof(arr5[0]);
    target = 1.0;
    result = binary_search((void**)arr5, num_elements, &target);
    assert(result == -1);
    
    //elements in end array
    double arr7[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int arr8[] = {1, 2, 3, 4, 5};
    num_elements = sizeof(arr7) / sizeof(arr7[0]);
    target = 5.0;
    result = binary_search((void**)arr7, num_elements, &target);
    assert(result == 4);
    result2 = binary_search((void**)arr8, num_elements, &target);
    assert(result2 == 4);
    return 0;
}