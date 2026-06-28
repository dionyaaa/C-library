#ifndef SORT_LIB_H
#define SORT_LIB_H

#include <stddef.h>
#include <stdbool.h>

#define MAX_TMP_ARRAY_SIZE_FOR_COUNTING_SORT 4194304

unsigned char* part_of_Hoares_quick_sort(unsigned char* left, unsigned char* right, size_t block_size, int (*cmp)(const void* a, const void* b), void* pivot);
void recursion_of_Hoares_quick_sort(unsigned char* start, unsigned char* end, size_t block_size, int (*cmp)(const void* a, const void* b), void* pivot);
bool Hoares_quick_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b));

unsigned char* part_of_Lomuto_quick_sort(unsigned char* start, unsigned char* end, size_t block_size, int (*cmp)(const void* a, const void* b));
void recursion_of_Lomuto_quick_sort(unsigned char* start, unsigned char* end, size_t block_size, int (*cmp)(const void* a, const void* b));
bool Lomuto_quick_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b));

bool bubble_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b));
bool selection_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b));
bool insertion_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b));
bool counting_sort(int* array, size_t array_size, bool is_ascending);

#endif