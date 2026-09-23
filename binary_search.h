// binary_search.h
int binary_search(const void *arr, size_t size, size_t element_size, const void *target, int (*compare)(const void*, const void*));
int compare_int(const void* a, const void* b);
int compare_double(const void* a, const void* b);
int compare_char(const void* a, const void* b); 