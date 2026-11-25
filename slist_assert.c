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
    slist_append(list1, (void*)a);
    slist_append(list1, (void*)b);
    slist_append(list1, (void*)c);
    assert(slist_length(list1)==3);
    return 0;    
}
