#include <stdio.h>
#include <stdlib.h>
#include "clip_balance.h"
int is_balanced(char* str) {
    if (str == NULL|| str[0] == '\0'){return 0;}
    static int clip_balance1 = 0;
    static int clip_balance2 = 0;
    static int clip_balance3 = 0;
    static int clip_balance4 = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            clip_balance1++;
        } else if (str[i] == ')') {
            clip_balance1--;
        }
        if (str[i] == '{') {
            clip_balance2++;
        } else if (str[i] == '}') {
            clip_balance2--;
        }
        if (str[i] == '[') {
            clip_balance3++;
        } else if (str[i] == ']') {
            clip_balance3--;
        }
        if (str[i] == '<') {
            clip_balance4++;
        } else if (str[i] == '>') {
            clip_balance4--;
        }
        if (clip_balance1 < 0 || clip_balance2 < 0 || clip_balance3 < 0 || clip_balance4 < 0) {
            return 0;
        }
    }
    if (clip_balance1 != 0 || clip_balance2 != 0 || clip_balance3 != 0 || clip_balance4 != 0) {
        return 0;
    }
    return 1;
}