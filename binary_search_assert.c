#include <stdio.h>
#include <assert.h>
#include "binary_search.c"
#include <stdlib.h>

int main() {
    // Тэст 1:Элемент присутствует в массиве
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = 5;
    int target1 = 3;
    int result1 = binary_search(arr1, size1, target1);
    assert(result1 == 2);

    // Тест 2:Элемент не присутствует в массиве
    int arr2[] = {1, 2, 3, 4, 5};
    int size2 = 5;
    int target2 = 6;
    int result2 = binary_search(arr2, size2, target2);
    assert(result2 == -1);
    
    // Тест 3:Один элемент в массиве
    int arr3[] = {10};
    int size3 = 1;
    int target3 = 10;
    int result3 = binary_search(arr3, size3, target3);
    assert(result3 == 0);

    // Тест 4:Пустой массив
    int arr4[] = {};
    int size4 = 0;
    int target4 = 1;
    int result4 = binary_search(arr4, size4, target4);
    assert(result4 == -1);

    // Тест 5:Элемент находится в начале массива, в середине и в конце массива
    int arr5[] = {1, 2, 3, 4, 5};
    int size5 = 5;
    int target5 = 1;
    int result5 = binary_search(arr5, size5, target5);
    assert(result5 == 0);

    int target6 = 3;
    int result6 = binary_search(arr5, size5, target6);
    assert(result6 == 2);

    int target7 = 5;
    int result7 = binary_search(arr5, size5, target7);
    assert(result7 == 4);

    // Тест 6:Повторяющиеся элементы в массиве
    int arr6[] = {1, 2, 2, 2, 3, 4, 5};
    int size6 = 7;
    int target8 = 2;
    int result8 = binary_search(arr6, size6, target8);
    assert(result8 == 1 || result8 == 2 || result8 == 3); 
    return 0;
}