#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritm_rabin_karp.h"
#define PRIME 31

int hash(char *str, size_t length) {
    int hash_value = 0;
    for (size_t i = 0; i < length; i++) {
        hash_value = hash_value + str[i]*PRIME^(length - i - 1);
    }
    return hash_value%PRIME;
}
size_t rabin_karp(char *text, char *pattern) {
    size_t text_length = strlen(text);
    size_t pattern_length = strlen(pattern);
    if (text == "" || pattern == "" || pattern_length > text_length) {
        return -1;
    }
    int pattern_hash = hash(pattern, pattern_length);
    int text_hash = hash(text, pattern_length);

    for (size_t i = 0; i <= text_length - pattern_length; i++) {
        if (pattern_hash == text_hash) {
            size_t j;
            for (j = 0; j < pattern_length; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == pattern_length) {
                return i;
            }
        }
        if (i < text_length - pattern_length) {
            text_hash = hash(text + i + 1, pattern_length);
        }
    }
    return -1;
}