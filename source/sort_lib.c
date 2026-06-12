#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "../include/utils_lib.h"
#include "../include/sort_lib.h"


bool bubble_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b))
{
	assert(array != NULL && cmp != NULL && block_size != 0);
	if (array_size <= 1)
		return true;

	unsigned char* ptr = (unsigned char*)array;
	while (array_size != 0)
	{
		size_t index = 0;
		for (size_t i = 1; i < array_size; i++)
			if (cmp(ptr + (i - 1) * block_size, ptr + i * block_size) > 0)
			{
				val_swap(ptr + (i - 1) * block_size, ptr + i * block_size, block_size);
				index = i;
			}
		array_size = index;
	}
	return true;
}


bool selection_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b))
{
	assert(array != NULL && cmp != NULL && block_size != 0);
	if (array_size <= 1)
		return true;

	unsigned char* ptr = (unsigned char*)array;
	for (size_t i = 0; i < array_size - 1; i++)
	{
		size_t index = i;
		for (size_t j = i + 1;j < array_size;j++)
			if (cmp(ptr + index * block_size, ptr + j * block_size) > 0)
				index = j;
		if (index != i)
			val_swap(ptr + index * block_size, ptr + i * block_size, block_size);
	}
	return true;
}


bool insertion_sort(void* array, size_t array_size, size_t block_size, int (*cmp)(const void* a, const void* b))
{
	assert(array != NULL && cmp != NULL && block_size != 0);
	if (array_size <= 1)
		return true;

	unsigned char* ptr = (unsigned char*)array;
	unsigned char* tmp = (unsigned char*)malloc(block_size);
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
	assert(array != NULL);
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
	if (range > MAX_TMP_ARRAY_SIZE_FOR_COUNTING_SORT)
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