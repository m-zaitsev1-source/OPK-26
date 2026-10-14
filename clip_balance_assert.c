#include <stdio.h>
#include <assert.h>
#include "clip_balance.h"
#include "clip_balance.c"
int main() {
    // Empty string
    char str1[] = "";
    assert(is_balanced(str1) == 0);
    // Balanced string
    char str2[] = "({[]})\0";
    char str3[] = "<(()())>\0";
    // Unbalanced string
    char str4[] = "({[})\0";
    char str5[] = "<(()()>\0";
    char str6[] = "({[})\0";
    char str7[] = "<(()()>\0";
    char str8[] = "({[})\0";
    char str9[] = "<(()()>\0";
    char str10[] = "({[aaaaaaaa})\0";
    char str11[] = "<(()()aaaaaaaa>\0";
    char str12[] = "[[BIG SHOT]]\0";
    char str13[] = "a(b)c[d]e{f}g<h>i\0";
    char str14[] = "a(b)c[d]e{f}g<h\0";
    char str15[] = "[[THE HEAVENS]] listen [[BIG SHOT]]\0";
    assert(is_balanced(str2) == 1);
    assert(is_balanced(str3) == 1);
    assert(is_balanced(str10) == 0);
    assert(is_balanced(str4) == 0);
    assert(is_balanced(str5) == 0);
    assert(is_balanced(str6) == 0);
    assert(is_balanced(str7) == 0);
    assert(is_balanced(str8) == 0);
    assert(is_balanced(str9) == 0);
    assert(is_balanced(str11) == 0);
    assert(is_balanced(str12) == 1);
    // Balanced string with other characters
    assert(is_balanced(str13) == 1);
    // Unbalanced string with other characters
    assert(is_balanced(str14) == 0);
    assert(is_balanced(str15) == 1);
    printf("All tests passed!\n");
    return 1;
}