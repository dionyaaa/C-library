#ifndef SORT_LIB_H
#define SORT_LIB_H

#include <stddef.h>
#include <stdbool.h>

#define MAX_TMP_ARRAY_SIZE_FOR_COUNTING_SORT 4194304

bool bubble_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b));
bool selection_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b));
bool insertion_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b));
bool counting_sort(int* array, size_t array_size, bool is_ascending);

#endif