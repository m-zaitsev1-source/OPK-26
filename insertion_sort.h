#pragma once
#include <stdio.h>
void insertion_sort(void *arr,
                    size_t n, 
                    size_t element_size, 
                    int (*compare)(const void *, const void *));
void swap(void *a, void *b, size_t size);
