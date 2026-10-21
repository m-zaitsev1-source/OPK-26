#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "algoritm_rabin_karp.c"

int main(){
    // Подстрока входит в строку
    char *text1 = "Hello, world!";
    char *pattern1 = "world";
    size_t result1 = rabin_karp(text1, pattern1);
    assert(result1 == 7);
    char *text2 = "Hellllo, world!";
    char *pattern2 = "Hellllo";
    size_t result2 = rabin_karp(text2, pattern2);
    assert(result2 == 0);
    printf("Test 1 passed!\n");

    // Подстрока не входит в строку
    char *text3 = "Hello, world!";
    char *pattern3 = "lol";
    size_t result3 = rabin_karp(text3, pattern3);
    assert(result3 == -1);
    char *text5 = "Gooooooool";
    char *pattern5 = "gool";
    size_t result5 = rabin_karp(text5, pattern5);
    assert(result5 == -1);
    printf("Test 2 passed!\n");

    // Cтрока пустая
    char *text4 = "";
    char *pattern4 = "Hello";
    size_t result4 = rabin_karp(text4, pattern4);
    assert(result4 == -1);
    printf("Test 3 passed!\n");

    // Подстрока пустая
    char *text6 = "Hello, world!";
    char *pattern6 = "";
    size_t result6 = rabin_karp(text6, pattern6);
    assert(result6 == -1);
    printf("Test 4 passed!\n");
    
    // Подстрока длиннее строки
    char *text7 = "lol";
    char *pattern7 = "loooooooooooooooooool";
    size_t result7 = rabin_karp(text7, pattern7);
    assert(result7 == -1);
    printf("Test 5 passed!\n");
    return 0;
}