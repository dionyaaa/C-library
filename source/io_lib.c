#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
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


char* getstr(size_t* input_length)
{
	if (input_length == NULL)
	{
		size_t tmp;
		input_length = &tmp;
	}
	*input_length = 0;
	size_t input_size = 16;
	char* input_string = (char*)malloc(input_size);
	if (input_string == NULL)
		return NULL;

	do {
		int input_symbol = getchar();

		if (input_symbol == '\n' || input_symbol == EOF)
			break;

		if (*input_length >= input_size - 1)
		{
			input_size *= 2;
			char* new_array = (char*)realloc(input_string, input_size);
			if (new_array == NULL)
			{
				free(input_string);
				return NULL;
			}
			input_string = new_array;
		}

		input_string[*input_length] = (char)input_symbol;
		++*input_length;
	} while (true);

	input_string[*input_length] = '\0';
	return input_string;
}


void clear_stdin(void)
{
	int symbol = getchar();
	while (symbol != '\n' && symbol != EOF)
		symbol = getchar();
}