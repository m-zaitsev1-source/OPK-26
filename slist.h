#include <stdio.h>
#pragma once
typedef void *Pointer;

typedef struct tSList {
    Pointer data;
    struct tSList *next;
} SList;

void slist_create(SList *list);
void slist_destroy(SList *list);
size_t slist_length(SList *list);
Pointer slist_get(SList *list, int index);
Pointer slist_get_last(SList *list);
void slist_prepend(SList *list, Pointer data);
void slist_append(SList *list, Pointer data);
Pointer slist_remove(SList *list, int index);
int slist_find(SList *list, Pointer data);
Pointer slist_remove_first(SList *list, Pointer data);
size_t slist_remove_all(SList *list, Pointer data);
void slist_copy(SList *dst, SList *src);
void slist_concat(SList *dst, SList *src);
void slist_foreach(SList *list, void (*func)(Pointer data, void *arg), void *arg);
int slist_find_custom(SList *list, int (*predicate)(Pointer data, void *arg), void *arg, Pointer *out);
void slist_from_array(SList *list, Pointer *arr, size_t n);
Pointer *slist_to_array(SList *list, size_t n);