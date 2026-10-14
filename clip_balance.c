#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clip_balance.h"
#define BANK_RIGHT_CLIPS {')', ']', '}', '>'}
#define BANK_LEFT_CLIPS {'(', '[', '{', '<'}
#define BANK_SIZE 4
int is_balanced(char str[], int size)
{
    char left_clips[BANK_SIZE] = BANK_LEFT_CLIPS;
    char right_clips[BANK_SIZE] = BANK_RIGHT_CLIPS;
    if (str == NULL|| str[0] == '\0' || sizeof(left_clips) != sizeof(right_clips)){return 0;}
    int count = 0;
    for (int i = 1; i <= size; i++){
        for (int j = 0; j < BANK_SIZE; j++){
            if (str[i-1] == left_clips[j] && str[i] == right_clips[j]){
                str[i-1]='0';
                str[i]='0';
                count = count + 2;
                break;
            }
            if (str[i-1] == right_clips[j] && str[size-1-(i-1)] == left_clips[j])
            {
                str[i-1]='0';
                str[size-1-(i-1)]='0';
                count = count + 2;
                break;
            }
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