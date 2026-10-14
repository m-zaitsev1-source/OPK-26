#include <stdio.h>
#pragma once
void compare_assert(void* a, void* b, size_t size, size_t element_size);
int compare_int(const void *a, const void *b);
int compare_double(const void *a, const void *b);
int compare_char(const void *a, const void *b);