#include <stdio.h>
#include <assert.h>
#include "binary_search.c"
#include <stdlib.h>
#include "binary_search.h"
//assert
int main() {
    //element in massive
    double arr1[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int arr2[] = {1, 2, 3, 4, 5};
    char* arr3[] = {"apple", "banana", "cherry", "date", "fig"};
    size_t num_elements = sizeof(arr1) / sizeof(arr1[0]);
    double target11 = 3.0;
    int target12 = 3;
    char* target13 = "cherry";
    int result11 = binary_search(arr1, num_elements, sizeof(double), &target11, compare_double);
    assert(result11 == 2);
    int result12 = binary_search(arr2, num_elements, sizeof(int), &target12, compare_int);
    assert(result12 == 2);
    int result13 = binary_search(arr3, num_elements, sizeof(char*), &target13, compare_char);
    assert(result13 == 2);

    // target not in array
    double target21 = 6.0;
    int result21 = binary_search(arr1, num_elements, sizeof(double), &target21, compare_double);
    assert(result21 == -1);
    int target22 = 6;
    int result22 = binary_search(arr2, num_elements, sizeof(int), &target22, compare_int);
    assert(result22 == -1);

    // 1 element in array
    double arr4[] = {1.0};
    int arr5[] = {1};
    char* arr6[] = {"apple"};
    num_elements = sizeof(arr4) / sizeof(arr4[0]);
    double target31 = 1.0;
    int target32 = 1;
    char* target33 = "apple";
    double target34 = 2.0;
    int result31 = binary_search(arr4, num_elements, sizeof(double), &target31, compare_double);
    assert(result31 == 0);
    int result32 = binary_search(arr5, num_elements, sizeof(int), &target32, compare_int);
    assert(result32 == 0);
    int result33 = binary_search(arr6, num_elements, sizeof(char*), &target33, compare_char);
    assert(result33 == 0);
    int result34 = binary_search(arr4, num_elements, sizeof(double), &target34, compare_double);
    assert(result34 == -1);

    // empty array
    double arr7[] = {};
    int arr8[] = {};
    char* arr9[] = {};
    num_elements = sizeof(arr7) / sizeof(arr7[0]);
    double target41 = 1.0;
    int target42 = 1;
    char* target43 = "apple";
    int result41 = binary_search(arr7, num_elements, sizeof(double), &target41, compare_double);
    int result42 = binary_search(arr8, num_elements, sizeof(int), &target42, compare_int);
    int result43 = binary_search(arr9, num_elements, sizeof(char*), &target43, compare_char);
    assert(result41 == -1);
    assert(result42 == -1);
    assert(result43 == -1);

    //elements in end array
    double arr10[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int arr11[] = {1, 2, 3, 4, 5};
    char* arr12[] = {"apple", "banana", "cherry", "date", "fig"};
    num_elements = sizeof(arr10) / sizeof(arr10[0]);
    double target51 = 5.0;
    int target52 = 5;
    char* target53 = "fig";
    int result51 = binary_search(arr10, num_elements, sizeof(double), &target51, compare_double);
    assert(result51 == 4);
    int result52 = binary_search(arr11, num_elements, sizeof(int), &target52, compare_int);
    assert(result52 == 4);
    int result53 = binary_search(arr12, num_elements, sizeof(char*), &target53, compare_char);
    assert(result53 == 4);

    //elements in start array
    double arr13[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int arr14[] = {1, 2, 3, 4, 5};
    char* arr15[] = {"apple", "banana", "cherry", "date", "fig"};
    num_elements = sizeof(arr13) / sizeof(arr13[0]);
    double target61 = 1.0;
    int target62 = 1;
    char* target63 = "apple";
    int result61 = binary_search(arr13, num_elements, sizeof(double), &target61, compare_double);
    assert(result61 == 0);
    int result62 = binary_search(arr14, num_elements, sizeof(int), &target62, compare_int);
    assert(result62 == 0);
    int result63 = binary_search(arr15, num_elements, sizeof(char*), &target63, compare_char);
    assert(result63 == 0);

    //elements in middle array
    double arr16[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int arr17[] = {1, 2, 3, 4, 5};
    char* arr18[] = {"apple", "banana", "cherry", "date", "fig"};
    num_elements = sizeof(arr16) / sizeof(arr16[0]);
    double target71 = 3.0;
    int target72 = 3;
    char* target73 = "cherry";
    int result71 = binary_search(arr16, num_elements, sizeof(double), &target71, compare_double);
    assert(result71 == 2);
    int result72 = binary_search(arr17, num_elements, sizeof(int), &target72, compare_int);
    assert(result72 == 2);
    int result73 = binary_search(arr18, num_elements, sizeof(char*), &target73, compare_char);
    assert(result73 == 2);
    return 0;
}