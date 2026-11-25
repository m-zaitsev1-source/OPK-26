#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "slist.c"
#define EPSILON 0.00001
#define SIZE_SLIST 4
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
    //int
    SList *list1 = malloc(SIZE_SLIST);
    slist_create(list1);
    int a = 1;
    int b = 2;
    int c = 3;
    slist_append(list1, &a);
    slist_append(list1, &b);
    slist_append(list1, &c);
    assert(slist_length(list1)==3);
    slist_destroy(list1);
    list1 = NULL;
    assert(slist_length(list1)==0);
    assert(slist_get(list1, 0)==NULL);
    SList *list_new = malloc(SIZE_SLIST);
    slist_create(list_new);
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int**arr_mall=malloc(sizeof(int*)*10);
    for (int i = 0; i<10; i++){
        arr_mall[i] = &arr[i];
    }
    slist_from_array(list_new, (void**)arr_mall, 10);
    SList *list_copy = malloc(SIZE_SLIST);
    slist_copy(list_copy, list_new);
    assert(slist_length(list_copy)==10);
    int not_fnd = 1;
    int fnd1 = slist_find(list_new, &not_fnd);
    int fnd2 = slist_find(list_new, &arr[5]);
    int *lst= slist_get_last(list_new);
    assert(fnd1 == -1);
    assert(fnd2 == 5);
    assert(lst == &arr[9]);
    for (int i = 0; i< 10; i++){
        int *p = slist_remove(list_new, 0);
        assert(p==&arr[i]);
    }
    assert(slist_length(list_new)==0);
    assert(slist_get(list_new, 10)==NULL);
    assert(slist_length(list_copy) == 10);
    slist_append(list_new, &not_fnd);
    assert(slist_remove_first(list_copy, &not_fnd) == NULL);
    slist_concat(list_copy, list_new);
    assert(slist_remove_first(list_copy, &not_fnd) != NULL);
    int *arr_con = (int*)slist_to_array(list_copy, 11);
    for (int i = 0; i<10; i++){
        printf("%d", arr_con[i]);
    } 
    return 0;
}
