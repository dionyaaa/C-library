#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../include/utils_lib.h"

bool val_swap(void* a, void* b, size_t size)
{
	if (a == NULL || b == NULL || size == 0)
		return false;

	void* tmp = malloc(size);
	if (tmp == NULL)
		return false;

	memcpy(tmp, a, size);
	memcpy(a, b, size);
	memcpy(b, tmp, size);

	free(tmp);
	return true;
}