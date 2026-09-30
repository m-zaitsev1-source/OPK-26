#include <stdio.h>
#include <assert.h>
#include "clip_balance.h"
#include "clip_balance.c"
int main() {
    // Empty string
    char* str1 = "";
    assert(is_balanced(str1) == 0);
    // Balanced string
    char* str2 = "({[]})";
    char* str3 = "<(()())>";
    assert(is_balanced(str2) == 1);
    assert(is_balanced(str3) == 1);
    // Unbalanced string
    char* str4 = "({[})";
    char* str5 = "<(()()>";
    char* str6 = "({[})";
    char* str7 = "<(()()>";
    char* str8 = ")({[})";
    char* str9 = "}({[})";
    char* str10 = "]({[})(";
    char* str11 = ">({[})(";
    char* str12 = "(){}[]{})";
    assert(is_balanced(str12) == 0);
    assert(is_balanced(str4) == 0);
    assert(is_balanced(str5) == 0);
    assert(is_balanced(str6) == 0);
    assert(is_balanced(str7) == 0);
    assert(is_balanced(str8) == 0);
    assert(is_balanced(str9) == 0);
    assert(is_balanced(str10) == 0);
    assert(is_balanced(str11) == 0);
    return 0;
}