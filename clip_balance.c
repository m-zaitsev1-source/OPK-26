#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clip_balance.h"
int is_balanced(char str[], int size)
{
    if (str == NULL|| str[0] == '\0'){return 0;}
    int count = 0;
    for (int i = 1; i <= size; i++){
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
    }
    if (count == 0){
        return 0;
    }
    if (count == size){
        return 1;
    }
    else if (count > 0 && count < size){
        for (int j = 0; j < size; j++){
            if (str[j] != '0'){
                return 0;
            }
        }
    }
    return 1;
}