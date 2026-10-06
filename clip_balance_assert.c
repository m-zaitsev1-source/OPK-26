#include <stdio.h>
#include <assert.h>
#include "clip_balance.h"
#include "clip_balance.c"
int main() {
    // Empty string
    char str1[] = "";
    assert(is_balanced(str1, 0) == 0);
    // Balanced string
    char str2[] = "({[]})\0";
    char str3[] = "<(()())>\0";
    assert(is_balanced(str2, 6) == 1);
    assert(is_balanced(str3, 8) == 1);
    // Unbalanced string
    char str4[] = "({[})\0";
    char str5[] = "<(()()>\0";
    char str6[] = "({[})\0";
    char str7[] = "<(()()>\0";
    char str8[] = "({[})\0";
    char str9[] = "<(()()>\0";
    assert(is_balanced(str4, 5) == 0);
    assert(is_balanced(str5, 7) == 0);
    assert(is_balanced(str6, 5) == 0);
    assert(is_balanced(str7, 7) == 0);
    assert(is_balanced(str8, 5) == 0);
    assert(is_balanced(str9, 7) == 0);
    return 1;
}