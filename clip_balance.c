#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "clip_balance.h"
#define BANK_RIGHT_CLIPS {')', ']', '}', '>'}
#define BANK_LEFT_CLIPS {'(', '[', '{', '<'}
#define BANK_SIZE 4
#define SIZE 100

int stack[SIZE];
int top = -1; 

int in(char arr[], char ch, int size)
{
    for (int i = 0; i < size; i++){
        if (arr[i] == ch){
            return 1;
        }
    }
    return 0;
}
bool is_empty() {
    return top == -1;
}

bool is_full() {
    return top == SIZE - 1;
}

void push(int value) {
    if (is_full()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (is_empty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
bool is_balanced(char str[])
{
    char left_clips[BANK_SIZE] = BANK_LEFT_CLIPS;
    char right_clips[BANK_SIZE] = BANK_RIGHT_CLIPS;
    if (str == NULL|| str[0] == '\0' || sizeof(left_clips) != sizeof(right_clips)){return 0;}
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (in(left_clips, str[i], BANK_SIZE)) {
            push(str[i]);
            count++;
        } 
        else if (in(right_clips, str[i], BANK_SIZE)) {
            if (is_empty()) {
                return 0;
            }
            char left_clip = pop();
            char right_clip = str[i];
            int found = 0;
            for (int j = 0; j < BANK_SIZE; j++) {
                if (left_clip == left_clips[j] && right_clip == right_clips[j]) {
                    count--;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                return 0;
            }
        }
    }
    if (count != 0) {
        return 0;
    }
    return 1;
}