#include <stdio.h>
#include <assert.h>
#include "binary_search.c"
#include <stdlib.h>
#include "binary_search.h"

int main() {
    //element in massive
    double arr1[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int arr2[] = {1, 2, 3, 4, 5};
    char* arr3[] = {"apple", "banana", "cherry", "date", "fig"};
    size_t num_elements = sizeof(arr1) / sizeof(arr1[0]);
    double target1 = 3.0;
    int target2 = 3;
    char* target3 = "cherry";
    size_t result = binary_search((void**)arr1, num_elements, &target1);
    assert(result == 2);
    assert(*(double*)(&arr1[result]) == target1);
    size_t result2 = binary_search((void**)arr2, num_elements, &target2);
    assert(result2 == 2);
    size_t result3 = binary_search((void**)arr3, num_elements, &target3);
    assert(result3 == 2);

    // target not in array
    double target1 = 6.0;
    size_t result = binary_search((void**)arr1, num_elements, &target1);
    assert(result == -1);
    int target2 = 6;
    size_t result2 = binary_search((void**)arr2, num_elements, &target2);
    assert(result2 == -1);

    // 1 element in array
    double arr3[] = {1.0};
    int arr4[] = {1};
    char* arr5[] = {"apple"};
    num_elements = sizeof(arr3) / sizeof(arr3[0]);
    double target1 = 1.0;
    int target2 = 1;
    char* target3 = "apple";
    result = binary_search((void**)arr3, num_elements, &target1);
    assert(result == 0);
    assert(*(double*)(&arr3[result]) == target1);
    target1 = 2.0;
    result = binary_search((void**)arr3, num_elements, &target1);
    assert(result == -1);

    // empty array
    double arr5[] = {};
    int arr6[] = {};
    char* arr7[] = {};
    num_elements = sizeof(arr5) / sizeof(arr5[0]);
    double target1 = 1.0;
    int target2 = 1;
    char* target3 = "apple";
    result = binary_search((void**)arr5, num_elements, &target1);
    result2 = binary_search((void**)arr6, num_elements, &target2);
    result3 = binary_search((void**)arr7, num_elements, &target3);
    assert(result == -1);
    assert(result2 == -1);
    assert(result3 == -1);

    //elements in end array
    double arr7[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int arr8[] = {1, 2, 3, 4, 5};
    char* arr9[] = {"apple", "banana", "cherry", "date", "fig"};
    num_elements = sizeof(arr7) / sizeof(arr7[0]);
    double target1 = 5.0;
    int target2 = 5;
    char* target3 = "fig";
    result = binary_search((void**)arr7, num_elements, &target1);
    assert(result == 4);
    result2 = binary_search((void**)arr8, num_elements, &target2);
    assert(result2 == 4);
    result3 = binary_search((void**)arr9, num_elements, &target3);
    assert(result3 == 4);
    return 0;
    //elements in start array
    double arr10[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int arr11[] = {1, 2, 3, 4, 5};
    char* arr12[] = {"apple", "banana", "cherry", "date", "fig"};
    num_elements = sizeof(arr10) / sizeof(arr10[0]);
    double target1 = 1.0;
    int target2 = 1;
    char* target3 = "apple";
    result = binary_search((void**)arr10, num_elements, &target1);
    assert(result == 0);
    result2 = binary_search((void**)arr11, num_elements, &target2);
    assert(result2 == 0);
    result3 = binary_search((void**)arr12, num_elements, &target3);
    assert(result3 == 0);

    //elements in middle array
    double arr13[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int arr14[] = {1, 2, 3, 4, 5};
    char* arr15[] = {"apple", "banana", "cherry", "date", "fig"};
    num_elements = sizeof(arr13) / sizeof(arr13[0]);
    double target1 = 3.0;
    int target2 = 3;
    char* target3 = "cherry";
    result = binary_search((void**)arr13, num_elements, &target1);
    assert(result == 2);
    result2 = binary_search((void**)arr14, num_elements, &target2);
    assert(result2 == 2);
    result3 = binary_search((void**)arr15, num_elements, &target3);
    assert(result3 == 2);
}