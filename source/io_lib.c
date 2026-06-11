#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/io_lib.h"


void print_int(const void* element)
{
	printf("%d", *(const int*)element);
}


void print_float(const void* element)
{
	printf("%f", *(const float*)element);
}


void print_double(const void* element)
{
	printf("%lf", *(const double*)element);
}


bool arr_print(const void* array, size_t array_size, size_t block_size, void (*form)(const void* element), const char* separator)
{
	if (array == NULL || form == NULL || array_size == 0 || block_size < 1)
		return false;

	const char* ptr = (const char*)array;
	for (size_t i = 0; i < array_size; i++)
	{
		form(ptr + i * block_size);
		if (separator != NULL && i < array_size - 1)
			printf("%s", separator);
	}
	return true;
}


char* getstr(void)
{
	size_t input_length = 0, input_size = 1;
	char* input_string = (char*)malloc(input_size);
	if (input_string == NULL)
		return NULL;

	do {
		int input_symbol = getchar();

		if (input_symbol == '\n' || input_symbol == EOF)
			break;

		if (input_length >= input_size - 1)
		{
			input_size++;
			char* new_array = (char*)realloc(input_string, input_size);
			if (new_array == NULL)
			{
				free(input_string);
				return NULL;
			}
			input_string = new_array;
		}

		input_string[input_length] = (char)input_symbol;
		input_length++;
	} while (true);

	input_string[input_length] = '\0';
	return input_string;
}


void clear_stdin(void)
{
	int symbol = getchar();
	while (symbol != '\n' && symbol != EOF)
		symbol = getchar();
}