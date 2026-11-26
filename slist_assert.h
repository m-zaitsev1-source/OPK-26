#include <stdio.h>
#include <math.h>
#include "slist.h"
#define EPSILON 0.00001
#define SIZE_SLIST 16
#pragma once
void add_sum(Pointer data, void *arg);
void add_double(void *data, void *user_data);
void add_char(void *data, void *user_data);
int compare_int(Pointer a, void *b);
int compare_double(Pointer a, void *b);
int compare_char(Pointer a, void *b);