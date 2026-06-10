#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/io_lib.h"


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