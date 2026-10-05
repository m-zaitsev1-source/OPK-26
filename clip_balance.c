#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clip_balance.h"
int is_balanced(char* str) {
    if (str == NULL|| str[0] == '\0'){return 0;}
    size_t count = 0;
    while (*str != '\0'){
        size_t size = strlen(str);
        for (int i = 1; str[i] != '\0'; i++){
            if (str[i-1] == '(' && str[i] == ')' ||
                str[i-1] == '[' && str[i] == ']' || 
                str[i-1] == '{' && str[i] == '}' || 
                str[i-1] == '<' && str[i] == '>')
            {
                str[i-1]='0';
                str[i]='0';
                count = count + 2;
            }
            if (str[i-1] == '(' && str[size-1-(i-1)] == ')' ||
                str[i-1] == '[' && str[size-1-(i-1)] == ']' || 
                str[i-1] == '{' && str[size-1-(i-1)] == '}' || 
                str[i-1] == '<' && str[size-1-(i-1)] == '>')
            {
                str[i-1]='0';
                str[size-1-(i-1)]='0';
                count = count + 2;
            }
            if (count == 0){
                return 0;
            }
            char** temp = (char**)malloc(sizeof(char*) * (sizeof(str)-count + 1));
            if (temp == NULL) {
                return 0;
            }
            for (int j = 0, k = 0; str[j] != '\0'; j++) {
                if (str[j] != '0') {
                    temp[k] = str[j];
                    k++;
                }
            }
            str = *temp;
            free(temp);
        }
    }
    return 1;
}