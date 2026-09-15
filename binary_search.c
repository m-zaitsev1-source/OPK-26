#include <stdio.h>
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    if (size <= 0) {
        return -1; 
    }
    else if (size == 1) {
        return (arr[0] == target) ? 0 : -1;
    }
    if (arr[left] == target) {
        return left;
    }
    if (arr[right] == target) {
        return right;
    }
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
