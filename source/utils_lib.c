#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "../include/utils_lib.h"


bool val_swap_stack(void* a, void* b, size_t size)
{
	assert(a != NULL && b != NULL && size != 0 && size <= MAX_STACK_SIZE_FOR_SWAP);

	unsigned char tmp[MAX_STACK_SIZE_FOR_SWAP];

	memcpy(tmp, a, size);
	memcpy(a, b, size);
	memcpy(b, tmp, size);

	return true;
}


bool val_swap_heap(void* a, void* b, size_t size)
{
	assert(a != NULL && b != NULL && size != 0);

	void* tmp = malloc(size);
	if (tmp == NULL)
		return false;

	memcpy(tmp, a, size);
	memcpy(a, b, size);
	memcpy(b, tmp, size);

	free(tmp);
	return true;
}


bool val_swap(void* a, void* b, size_t size)
{
	assert(a != NULL && b != NULL && size != 0);

	if (size <= MAX_STACK_SIZE_FOR_SWAP)
		return val_swap_stack(a, b, size);
	else
		return val_swap_heap(a, b, size);
}