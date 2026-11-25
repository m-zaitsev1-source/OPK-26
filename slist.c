#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
//lol
void slist_create(SList *list) { 
    list->data = NULL;
    list->next = NULL;
}
//lol
void slist_destroy(SList *list) {
    SList *current = list;
    while (current->next != NULL)
    {
        SList *next = current->next;
        free(current);
        current = next;
    }
    list->data = NULL;
    list->next = NULL;
}
//lol
size_t slist_length(SList *list){
    if ((list == NULL) || (list->next == NULL && list->data == NULL)) return 0;
    size_t num = 1;
    SList *current = list;
    while (current->next != NULL)
    {
        SList *next = current->next;
        num += 1;
        current = next;
    }
    return num;
}
//lol
Pointer slist_get(SList *list, int index){
    size_t num = 0;
    SList *current = list;
    while (current != NULL)
    {
        if (num == index) return current->data;
        SList *next = current->next;
        num += 1;
        current = next;
    }
    return NULL;
}
//lol
Pointer slist_get_last(SList *list){
    SList *current = list;
    while (current->next != NULL)
    {
        SList *next = current->next;
        current = next;
    }
    return current->data;
}
//lol
void slist_prepend(SList *list, Pointer data){
    if (list->data == NULL){
        list->data = data;
        return;
    }
    else{
        SList *new_node = (SList*)malloc(sizeof(SList));
        if (new_node == NULL) {
            return;
        }
        slist_create(new_node);
        new_node->data = list->data;
        new_node->next = list->next;
        list->next = new_node;
        list->data = data;
    }
}
//lol
void slist_append(SList *list, Pointer data){
    if (list->data == NULL) {
        list->data = data;
        return;
    }
    SList *new_node = (SList*)malloc(sizeof(SList));
    if (new_node == NULL) {
        return;
    }
    slist_create(new_node);
    new_node->data = data;
    new_node->next = NULL;
    SList *current = list;
    while (current->next != NULL)
    {
        SList *next = current->next;
        current = next;
    }
    current->next = new_node;
}
//lol
Pointer slist_remove(SList *list, int index){
    size_t num = 0;
    SList *current = list;
    Pointer Data = NULL;
    while (current->next != NULL)
    {
        SList *next = current->next;
        Data = current->data;
        if (num == index){
            current->next = next->next;
            current->data = next->data;
            return Data;  
        }
        num += 1;
        current = next;
    }
    if (num == index){
        Data = current->data;
        current->data = NULL;
        return Data;
    }
    return NULL;
}
//lol
int slist_find(SList *list, Pointer data){
    size_t num = 0;
    SList *current = list;
    while (current != NULL)
    {
        if (current->data == data) return num;
        SList *next = current->next;
        num += 1;
        current = next;
    }
    return -1;
    }
//lol
Pointer slist_remove_first(SList *list, Pointer data){
    SList *current = list;
    while (current != NULL)
    {
        SList *next = current->next;
        if (current->data == data){
            if (next == NULL) {
                current->data = NULL;
                current->next = NULL;
                
            }
            else {
                current->data = next->data;
                current->next = next->next;
            }
            return data;
        }
        current = next;
    }
    return NULL;
}
size_t slist_remove_all(SList *list, Pointer data){
    size_t count = 0;
    SList *current = list;
    while (current != NULL)
    {
        SList *next = current->next;
        if (current->data == data){
            count += 1;
            if (next == NULL) {
                current->data = NULL;
                current->next = NULL;
                break;
            }
            current->data = next->data;
            current->next = next->next; 
        }
        current = next;
    }
    return count;
}
//lol
void slist_copy(SList *dst, SList *src){
    SList *current = src;
    while (current != NULL)
    {
        slist_append(dst, current->data);
        SList *next = current->next;
        current = next;
    }
}
//lol
void slist_concat(SList *dst, SList *src){
    SList *current = dst;
    while (current->next != NULL)
    {
        SList *next = current->next;
        current = next;
    }
    SList *new_node = (SList*)malloc(sizeof(SList));
        if (new_node == NULL) {
            return;
        }
    slist_create(new_node);
    new_node->data = src->data;
    new_node->next = src->next;
    current->next = new_node;
    
}
void slist_foreach(SList *list, void (*func)(Pointer data, void *arg), void *arg){
    SList *current = list;
    while (current != NULL)
    {
        func(current->data, arg);
        SList *next = current->next;
        current = next;
    }
}
int slist_find_custom(SList *list, int (*predicate)(Pointer data, void *arg), void *arg, Pointer *out){
    SList *current = list;
    int index = 0;
    while (current != NULL)
    {
        if (predicate(current->data, arg)){
            *out = current->data;
            return index;  
        }
        SList *next = current->next;
        current = next;
        index += 1;
    }
    return -1;
}
void slist_from_array(SList *list, Pointer *arr, size_t n){
    for (size_t i = 0; i < n; i++)
    {
        slist_append(list, arr[i]);
    }
}
Pointer *slist_to_array(SList *list, size_t n){
    n = slist_length(list);
    Pointer *arr = (Pointer*)malloc(sizeof(Pointer) * n);
    SList *current = list;
    size_t i = 0;
    while (current != NULL)
    {
        arr[i] = current->data;
        SList *next = current->next;
        current = next;
        i += 1;
    }
    return arr;
}
