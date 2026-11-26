#include <assert.h>
#include <stdlib.h>
#include "slist.c"
#include "slist_assert.h"
#define EPSILON 0.00001
#define SIZE_SLIST 16
void add_sum(Pointer data, void *arg) {
        int *p = (int*)arg;
        *(int*)data += *p;
        return;
    }
void add_double(void *data, void *user_data) {
    *(double *)data += *(double *)user_data;
}
void add_char(void *data, void *user_data) {
    *(char *)data += *(char *)user_data;
}
int compare_int(Pointer a, void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib);
}
int compare_double(Pointer a, void *b) {
    double da = *(const double*)a;
    double db = *(const double*)b;
    if (fabs(da - db) < EPSILON) {
        return 1;
    }
    return (da > db);
}

int compare_char(Pointer a, void *b) {
    char ca = *(const char*)a;
    char cb = *(const char*)b;
    return (ca >= cb);
}
int main() {
    //int
    SList *list1_i = malloc(SIZE_SLIST);
    slist_create(list1_i);
    int a_i = 1;
    int b_i = 2;
    int c_i = 3;
    slist_append(list1_i, &a_i);
    slist_append(list1_i, &b_i);
    slist_append(list1_i, &c_i);
    assert(slist_length(list1_i)==3);
    slist_destroy(list1_i);
    list1_i = NULL;

    assert(slist_length(list1_i)==0);
    assert(slist_get(list1_i, 0)==NULL);
    SList *list_new_int = malloc(SIZE_SLIST);
    slist_create(list_new_int);
    int arr_int[] = {0,1,2,3,4,5,6,7,8,9};
    int**arr_mall_int=malloc(sizeof(int*)*10);
    for (int i = 0; i<10; i++){
        arr_mall_int[i] = &arr_int[i];
    }
    slist_from_array(list_new_int, (void**)arr_mall_int, 10);

    SList *list_copy_int = malloc(SIZE_SLIST);
    slist_copy(list_copy_int, list_new_int);
    assert(slist_length(list_copy_int)==10);
    int not_fnd_int = 11;
    int fnd1_int = slist_find(list_new_int, &not_fnd_int);
    int fnd2_int = slist_find(list_new_int, &arr_int[5]);
    int *lst_int= slist_get_last(list_new_int);
    assert(fnd1_int == -1);
    assert(fnd2_int == 5);
    assert(lst_int == &arr_int[9]);
    for (int i = 0; i< 10; i++){
        int *p = slist_remove(list_new_int, 0);
        assert(p==&arr_int[i]);
    }
    assert(slist_length(list_new_int)==0);
    assert(slist_get(list_new_int, 10)==NULL);
    assert(slist_length(list_copy_int) == 10);
    slist_append(list_new_int, &not_fnd_int);
    assert(slist_remove_first(list_copy_int, &not_fnd_int) == NULL);
    slist_concat(list_copy_int, list_new_int);
    assert(slist_get(list_copy_int, 10) == &not_fnd_int);
    int **arr_con_int = (int**)slist_to_array(list_copy_int, 11);
    for (int i = 0; i<11; i++){
        printf("%d ", *arr_con_int[i]);
    }
    printf("\n");
    int add = 1;
    slist_foreach(list_copy_int, add_sum, &add);
    int **arr_add = (int**)slist_to_array(list_copy_int, 11);
    for (int i = 0; i<11; i++){
        printf("%d ", *arr_add[i]);
    }
    printf("\n");
    int **out_int = malloc(sizeof(int*));
    slist_find_custom(list_copy_int, compare_int, &add, (void**)out_int);
    assert(**out_int == 2);

    //double
    SList *list1_d = malloc(SIZE_SLIST);
    slist_create(list1_d);
    double a_d = 1.5, b_d = 2.5, c_d = 3.5;
    slist_append(list1_d, &a_d);
    slist_append(list1_d, &b_d);
    slist_append(list1_d, &c_d);
    assert(slist_length(list1_d) == 3);
    assert(slist_get(list1_d, 1) == &b_d);
    slist_destroy(list1_d);
    list1_d = NULL;

    assert(slist_length(list1_d) == 0);
    assert(slist_get(list1_d, 0) == NULL);

    SList *list_new_double = malloc(SIZE_SLIST);
    slist_create(list_new_double);
    double arr_double[] = {0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5};
    double **arr_mall_double = malloc(sizeof(double*) * 10);
    for (int i = 0; i < 10; i++) {
        arr_mall_double[i] = &arr_double[i];
    }
    slist_from_array(list_new_double, (void**)arr_mall_double, 10);

    SList *list_copy_double = malloc(SIZE_SLIST);
    slist_copy(list_copy_double, list_new_double);
    assert(slist_length(list_copy_double) == 10);

    double not_fnd_double = 11.75;
    int fnd1_double = slist_find(list_new_double, &not_fnd_double);
    int fnd2_double = slist_find(list_new_double, &arr_double[5]);
    double *lst_double = slist_get_last(list_new_double);
    assert(fnd1_double == -1);
    assert(fnd2_double == 5);
    assert(lst_double == &arr_double[9]);

    for (int i = 0; i < 10; i++) {
        double *p = slist_remove(list_new_double, 0);
        assert(p == &arr_double[i]);
    }
    assert(slist_length(list_new_double) == 0);
    assert(slist_get(list_new_double, 10) == NULL);
    assert(slist_length(list_copy_double) == 10);

    slist_append(list_new_double, &not_fnd_double);
    assert(slist_remove_first(list_copy_double, &not_fnd_double) == NULL);
    slist_concat(list_copy_double, list_new_double);
    assert(slist_length(list_copy_double) == 11);
    assert(slist_get(list_copy_double, 10) == &not_fnd_double);

    double **arr_con_double = (double**)slist_to_array(list_copy_double, 11);
    for (int i = 0; i < 11; i++) {
        printf("%.2f ", *arr_con_double[i]);
    }
    printf("\n");

    double add_d = 0.25;
    slist_foreach(list_copy_double, add_double, &add_d);
    double **arr_add_double = (double**)slist_to_array(list_copy_double, 11);
    for (int i = 0; i < 11; i++) {
        printf("%.2f ", *arr_add_double[i]);
    }
    printf("\n");
    assert(fabs(*arr_add_double[0] - 0.25) < EPSILON);
    assert(fabs(*arr_add_double[10] - 12.0) < EPSILON);

    double key_d = 1.25;
    double **out_double = malloc(sizeof(double*));
    slist_find_custom(list_copy_double, compare_double, &key_d, (void**)out_double);
    assert(*out_double != NULL);
    assert(fabs(**out_double - 1.25) < EPSILON);
    assert(*out_double == &arr_double[2]);
    // char

    SList *list1_c = malloc(SIZE_SLIST);
    slist_create(list1_c);
    char a_c = 'x', b_c = 'y', c_c = 'z';
    slist_append(list1_c, &a_c);
    slist_append(list1_c, &b_c);
    slist_append(list1_c, &c_c);
    assert(slist_length(list1_c) == 3);
    assert(slist_get(list1_c, 0) == &a_c);
    assert(slist_get(list1_c, 2) == &c_c);
    slist_destroy(list1_c);
    list1_c = NULL;

    assert(slist_length(list1_c) == 0);
    assert(slist_get(list1_c, 0) == NULL);

    SList *list_new_char = malloc(SIZE_SLIST);
    slist_create(list_new_char);
    char arr_char[] = {'a','b','c','d','e','f','g','h','i','j'};
    char **arr_mall_char = malloc(sizeof(char*) * 10);
    for (int i = 0; i < 10; i++) {
        arr_mall_char[i] = &arr_char[i];
    }
    slist_from_array(list_new_char, (void**)arr_mall_char, 10);

    SList *list_copy_char = malloc(SIZE_SLIST);
    slist_copy(list_copy_char, list_new_char);
    assert(slist_length(list_copy_char) == 10);

    char not_fnd_char = 'z';
    int fnd1_char = slist_find(list_new_char, &not_fnd_char);
    int fnd2_char = slist_find(list_new_char, &arr_char[5]);
    char *lst_char = slist_get_last(list_new_char);
    assert(fnd1_char == -1);
    assert(fnd2_char == 5);
    assert(lst_char == &arr_char[9]);

    for (int i = 0; i < 10; i++) {
        char *p = slist_remove(list_new_char, 0);
        assert(p == &arr_char[i]);
    }
    assert(slist_length(list_new_char) == 0);
    assert(slist_get(list_new_char, 10) == NULL);
    assert(slist_length(list_copy_char) == 10);

    slist_append(list_new_char, &not_fnd_char);
    assert(slist_remove_first(list_copy_char, &not_fnd_char) == NULL);
    slist_concat(list_copy_char, list_new_char);
    assert(slist_length(list_copy_char) == 11);
    assert(slist_get(list_copy_char, 10) == &not_fnd_char);

    char **arr_con_char = (char**)slist_to_array(list_copy_char, 11);
    for (int i = 0; i < 11; i++) {
        printf("%c ", *arr_con_char[i]);
    }
    printf("\n");

    char add_c = 1;
    slist_foreach(list_copy_char, add_char, &add_c);
    char **arr_add_char = (char**)slist_to_array(list_copy_char, 11);
    for (int i = 0; i < 11; i++) {
        printf("%c ", *arr_add_char[i]);  
    }
    printf("\n");
    assert(*arr_add_char[0] == 'b');
    assert(*arr_add_char[9] == 'k');

    char key_c = 'c';
    char **out_char = malloc(sizeof(char*));
    slist_find_custom(list_copy_char, compare_char, &key_c, (void**)out_char);
    assert(*out_char != NULL);
    assert(**out_char == 'c');                
    assert(*out_char == &arr_char[1]);         

    free(out_char);
    free(arr_con_char);
    free(arr_add_char);
    free(arr_mall_char);
    free(out_double);
    free(arr_con_double);
    free(arr_add_double);
    free(arr_mall_double);
    slist_destroy(list_copy_double);
    slist_destroy(list_new_double);
    free(out_int);
    free(arr_con_int);
    free(arr_add);
    free(arr_mall_int);
    slist_destroy(list_copy_int);
    slist_destroy(list_new_int);
    return 0;
}
