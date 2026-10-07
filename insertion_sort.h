#pragma once
#include <stdio.h>
int compare_int(const void *a, const void *b);
int compare_double(const void *a, const void *b);
int compare_char(const void *a, const void *b);
void insertion_sort(const void *arr,
                    size_t n, 
                    size_t element_size, 
                    int (*compare)(const void *, const void *));
void swap(void *a, void *b, size_t size);
