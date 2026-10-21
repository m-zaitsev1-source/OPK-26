#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritm_rabin_karp.h"
#define PRIME 31

int hash(char *str, int length) {
    int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value = hash_value + str[i]*PRIME^(length - i - 1);
    }
    return hash_value%PRIME;
}
int rabin_karp(char *text, char *pattern) {
    if (text == "" || pattern == "" || strlen(pattern)>strlen(text)) {
        return -1;
    }
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);
    int pattern_hash = hash(pattern, pattern_length);
    int text_hash = hash(text, pattern_length);

    for (int i = 0; i <= text_length - pattern_length; i++) {
        if (pattern_hash == text_hash) {
            int j;
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