#ifndef UTILS_LIB_H
#define UTILS_LIB_H

#include <stddef.h>
#include <stdbool.h>

#define MAX_STACK_SIZE_FOR_SWAP 64

bool val_swap_stack(void* a, void* b, size_t size);
bool val_swap_heap(void* a, void* b, size_t size);
bool val_swap(void* a, void* b, size_t size);

#endif