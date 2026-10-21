#include <stdio.h>
#include <stdlib.h>
#pragma once

void swap(void *a, void *b, size_t size);
void heapify(void *arr, int n, int i, size_t element_size, int (*compare)(const void *, const void *));
void heapSort(void *arr, int n, size_t element_size, int (*compare)(const void *, const void *));