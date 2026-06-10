#ifndef SORT_LIB_H
#define SORT_LIB_H

#include <stddef.h>
#include <stdbool.h>

bool insertion_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b));
bool counting_sort(int* array, size_t array_size, bool is_ascending);

#endif