#include <stdio.h>
#pragma once
int compare_int(const void *a, const void *b);
int compare_double(const void *a, const void *b);
int compare_char(const void *a, const void *b);
void compare_assert(void* a, void* b, size_t size, size_t element_size);