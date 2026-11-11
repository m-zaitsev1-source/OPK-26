#include <stdio.h>
#include <assert.h>
#include "dek.c"

int main() {
    // int 3 elements
    Deque d1;
    int a_int = 1;
    int b_int = 2;
    int c_int = 3;
    int *p_int = &a_int;
    int *q_int = &b_int;
    int *r_int = &c_int;
    deque_create(&d1);
    assert(deque_size(&d1) == 0);
    deque_push_back(&d1, p_int);
    assert(deque_size(&d1) == 1);
    deque_push_back(&d1, q_int);
    assert(deque_size(&d1) == 2);
    deque_push_front(&d1, r_int);
    assert(deque_peek_front(&d1) == r_int);
    assert(deque_peek_back(&d1) == q_int);
    Pointer elem1_int = deque_pop_front(&d1);
    assert(elem1_int == r_int);
    assert(deque_size(&d1) == 2);
    Pointer elem2_int = deque_pop_front(&d1);
    assert(elem2_int == p_int);
    assert(deque_size(&d1) == 1);
    Pointer elem3_int = deque_pop_back(&d1);
    assert(elem3_int == q_int);
    assert(deque_size(&d1) == 0);
    deque_destroy(&d1);
    // double 3 elements
    Deque d2;
    double a_double = 1.0;
    double b_double = 2.0;
    double c_double = 3.0;
    double *p_double = &a_double;
    double *q_double = &b_double;
    double *r_double = &c_double;
    deque_create(&d2);
    assert(deque_size(&d2) == 0);
    deque_push_back(&d2, p_double);
    assert(deque_size(&d2) == 1);
    deque_push_back(&d2, q_double);
    assert(deque_size(&d2) == 2);
    deque_push_front(&d2, r_double);
    assert(deque_peek_front(&d2) == r_double);
    assert(deque_peek_back(&d2) == q_double);
    Pointer elem1_double = deque_pop_front(&d2);
    assert(elem1_double == r_double);
    assert(deque_size(&d2) == 2);
    Pointer elem2_double = deque_pop_front(&d2);
    assert(elem2_double == p_double);
    assert(deque_size(&d2) == 1);
    Pointer elem3_double = deque_pop_back(&d2);
    assert(elem3_double == q_double);
    assert(deque_size(&d2) == 0);
    deque_destroy(&d2);
    //char 3 elements
    Deque d3;
    char a_char = 'a';
    char b_char = 'b';
    char c_char = 'c';
    char *p_char = &a_char;
    char *q_char = &b_char;
    char *r_char = &c_char;
    deque_create(&d3);
    assert(deque_size(&d3) == 0);
    deque_push_back(&d3, p_char);
    assert(deque_size(&d3) == 1);
    deque_push_back(&d3, q_char);
    assert(deque_size(&d3) == 2);
    deque_push_front(&d3, r_char);
    assert(deque_peek_front(&d3) == r_char);
    assert(deque_peek_back(&d3) == q_char);
    Pointer elem1_char = deque_pop_front(&d3);
    assert(elem1_char == r_char);
    assert(deque_size(&d3) == 2);
    Pointer elem2_char = deque_pop_front(&d3);
    assert(elem2_char == p_char);
    assert(deque_size(&d3) == 1);
    Pointer elem3_char = deque_pop_back(&d3);
    assert(elem3_char == q_char);
    assert(deque_size(&d3) == 0);
    deque_destroy(&d3);
    //null deque
    Deque d4;
    deque_create(&d4);
    assert(deque_size(&d4) == 0);
    deque_destroy(&d4);
    // 10 elements
    Deque d5;
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque_create(&d5);
    for (int i = 0; i < 10; i++) {
        deque_push_back(&d5, &arr[i]);
        printf("Pushed back: %d\n", *(int *)deque_peek_back(&d5));
    }
    assert(deque_peek_back(&d5) == &arr[9]);
    assert(deque_peek_front(&d5) == arr);
    assert(deque_size(&d5) == 10);
    for (int i=0; i < 10; i++) {
        Pointer elem = deque_pop_back(&d5);
        printf("Popped back: %d\n", *(int *)elem);
    }
    assert(deque_size(&d5) == 0);
    deque_destroy(&d5);
    return 0;
}