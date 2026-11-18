#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "slist.c"
#define EPSILON 0.00001
void add_sum(Pointer data, void *arg) {
        int *p = (int*)arg;
        p += *(int*)data;
        return;
    }
int compare_int(Pointer a, void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int compare_double(Pointer a, void *b) {
    double da = *(const double*)a;
    double db = *(const double*)b;
    if (fabs(da - db) < EPSILON) {
        return 0;
    }
    return (da > db) - (da < db);
}

int compare_char(Pointer a, void *b) {
    char ca = *(const char*)a;
    char cb = *(const char*)b;
    return (ca > cb) - (ca < cb);
}
int main() {
    //test slist_create, slist_append, slist_get, slist_get_last, slist_length, and slist_destroy
    SList *list = (SList*)malloc(sizeof(SList));
    slist_create(list);
    assert(slist_length(list) == 0);
    slist_append(list, (Pointer)1);
    slist_append(list, (Pointer)2);
    slist_append(list, (Pointer)3);
    assert(slist_get(list, 0) == (Pointer)1);
    assert(slist_get(list, 1) == (Pointer)2);
    assert(slist_get(list, 2) == (Pointer)3);
    assert(slist_get_last(list) == (Pointer)3);
    slist_destroy(list);

    //test slist_prepend, slist_remove, slist_find, slist_remove_first, and slist_remove_all
    SList *list2 = (SList*)malloc(sizeof(SList));
    slist_create(list2);
    slist_prepend(list2, (Pointer)1);
    slist_prepend(list2, (Pointer)2);
    slist_prepend(list2, (Pointer)3);
    assert(slist_get(list2, 0) == (Pointer)3);
    assert(slist_get(list2, 1) == (Pointer)2);
    assert(slist_get(list2, 2) == (Pointer)1);
    assert(slist_find(list2, (Pointer)2) == 1);
    assert(slist_remove(list2, 1) == (Pointer)2);
    assert(slist_find(list2, (Pointer)2) == -1);
    assert(slist_remove_first(list2, (Pointer)3) == (Pointer)3);
    assert(slist_find(list2, (Pointer)3) == -1);
    SList *old_node = list2;
    slist_append(list2, (Pointer)4);
    slist_append(list2, (Pointer)4);
    assert(slist_remove_all(list2, (Pointer)4) == 2);
    assert(old_node == list2);
    slist_destroy(list2);
    slist_destroy(old_node);

    //test slist_copy, slist_concat
    SList *list3 = (SList*)malloc(sizeof(SList));
    slist_create(list3);
    slist_append(list3, (Pointer)1);
    slist_append(list3, (Pointer)2);
    SList *list4 = (SList*)malloc(sizeof(SList));
    slist_create(list4);
    slist_copy(list4, list3);
    assert(slist_length(list4) == 2);
    slist_concat(list3, list4);
    assert(slist_length(list3) == 4);
    slist_destroy(list3);
    slist_destroy(list4);

    // test slist_from_array and slist_to_array
    int* arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = malloc(sizeof(int));
        *arr[i] = rand() % 100;
    }
    SList *list5 = (SList*)malloc(sizeof(SList));
    slist_from_array(list5, (Pointer*)arr, 100);
    Pointer *arr2 = slist_to_array(list5, 100);
    for (int i = 0; i < 100; i++) {
        assert(arr[i] == arr2[i]);
    }
    slist_destroy(list5);

    // test slist_foreach
    SList *list6 = (SList*)malloc(sizeof(SList));
    slist_create(list6);
    for (int i = 0; i < 10; i++) {
        slist_append(list6, (Pointer)i);
    }
    int sum = 0;
    slist_foreach(list6, add_sum, &sum);
    assert(sum == 45);
//////////////////////////////////////
    // test slist_find_custom
    SList *list_int = (SList*)malloc(sizeof(SList));
    slist_create(list_int);
    for (int i = 0; i < 10; i++) {
        slist_append(list_int, *(const Pointer*)&i);
    }
    Pointer out;
    int out_index = slist_find_custom(list_int, compare_int, (void*)5, (void*)&out);
    assert(out_index == 5);
    assert(out == (Pointer)5);
    /*SList *list_double = (SList*)malloc(sizeof(SList));
    slist_create(list_double);
    for (double i = 0.0; i < 10.0; i=i+1.0) {
        slist_append(list_double, (Pointer)i);
    }
    double out_double;
    int out_index_double = slist_find_custom(list_double, compare_double, (void*)5.0, (void*)&out_double);
    assert(out_index_double == 5);
    assert(out_double == (double)5.0);*/
    SList *list_char = (SList*)malloc(sizeof(SList));
    slist_create(list_char);
    char charr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    for (int i = 0; i < 10; i++) {
        slist_append(list_char, *(const Pointer*)(charr+i));
    }
    char out_char;
    int out_index_char = slist_find_custom(list_char, compare_char, (void*)'e', (void*)&out_char);
    assert(out_index_char == 4);
    assert(out_char == (char)'e');
    free(list);
    free(list2);
    free(list3);
    free(list4);
    free(list5);
    free(list6);
    return 0;
}
