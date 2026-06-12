#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "../include/sort_lib.h"


#define MAX_ARRAY_RANGE 4194304


bool insertion_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b))
{
	if (array == NULL || cmp == NULL || block_size == 0)
		return false;
	if (array_size <= 1)
		return true;

	char* ptr = (char*)array;
	char* tmp = (char*)malloc(block_size);
	if (tmp == NULL)
		return false;

	for (size_t i = 1; i < array_size; i++)
	{
		size_t j = i;
		memcpy(tmp, ptr + i * block_size, block_size);

		while (j > 0 && cmp(ptr + (j - 1) * block_size, tmp) > 0)
		{
			memcpy(ptr + j * block_size, ptr + (j - 1) * block_size, block_size);
			j--;
		}
		memcpy(ptr + j * block_size, tmp, block_size);
	}
	free(tmp);
	return true;
}


bool counting_sort(int* array, size_t array_size, bool is_ascending)
{
	if (array == NULL)
		return false;
	if (array_size <= 1)
		return true;

	int max_number = array[0];
	int min_number = array[0];
	for (size_t i = 1; i < array_size; i++)
	{
		if (array[i] > max_number)
			max_number = array[i];
		if (array[i] < min_number)
			min_number = array[i];
	}

	size_t range = (size_t)((int64_t)max_number - (int64_t)min_number + 1);
	if (range > MAX_ARRAY_RANGE)
		return false;
	int* tmp_array = (int*)calloc(range, sizeof(int));
	if (tmp_array == NULL)
		return false;

	for (size_t i = 0; i < array_size; i++)
	{
		size_t index = (size_t)((int64_t)array[i] - (int64_t)min_number);
		tmp_array[index]++;
	}

	if (is_ascending)
		for (size_t i = 0, j = 0; i < range; i++)
			for (size_t k = 0; k < tmp_array[i]; k++)
				array[j++] = (int)((int64_t)i + (int64_t)min_number);
	else
		for (size_t i = range, j = 0; i-- > 0;)
			for (size_t k = 0; k < tmp_array[i]; k++)
				array[j++] = (int)((int64_t)i + (int64_t)min_number);

	free(tmp_array);
	return true;
}