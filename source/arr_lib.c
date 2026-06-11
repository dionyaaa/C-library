#include <stddef.h>
#include "../include/arr_lib.h"

void* arr_extremum(const void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b))
{
	if (array == NULL || cmp == NULL || array_size == 0 || block_size < 1)
		return NULL;
	if (array_size == 1)
		return (void*)array;

	const char* ptr = (const char*)array;
	const char* res = ptr;

	for (size_t i = 1; i < array_size; i++)
		if (cmp(ptr + i * block_size, res) > 0)
			res = ptr + i * block_size;

	return (void*)res;
}