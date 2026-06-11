#ifndef ARR_LIB_H
#define ARR_LIB_H

void* arr_extremum(const void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b));

#endif