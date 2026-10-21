#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma once
int hash(char *str, size_t length);
size_t rabin_karp(char *text, char *pattern);