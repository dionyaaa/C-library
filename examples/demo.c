#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#define ARRAY_SIZE 16

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>
#include "../include/io_lib.h"
#include "../include/sort_lib.h"
#include "../include/cmp_lib.h"
#include "../include/rand_lib.h"

int main(void)
{
	int selected_library;
	int symbol;
	srand(time(NULL));

	puts("Select a module to test:");
	puts("1. Input/Output module;");
	puts("2. Sorting module;");
	puts("3. Random number generator module;");
	putchar('\n');

	puts("Enter your choice (1-3):");

	if (scanf("%d", &selected_library) < 1)
	{
		puts("Invalid input!");
		return 1;
	}
	if ((symbol = getchar()) != '\n' && symbol != EOF)
	{
		clear_stdin();
		puts("Invalid input!");
		return 1;
	}
	putchar('\n');

	switch (selected_library) {
	case 1: {
		puts("Enter a string of any length:");
		char* input_string = getstr();
		if (input_string == NULL)
		{
			puts("Memory allocation error!");
			return 2;
		}
		printf("You entered the string:\n\"%s\"\n", input_string);
		free(input_string);
		break;
	}
	case 2: {
		int first_array[ARRAY_SIZE];
		int second_array[ARRAY_SIZE];
		int third_array[ARRAY_SIZE];
		int fourth_array[ARRAY_SIZE];
		int* arrays[4] = {first_array, second_array, third_array, fourth_array};

		puts("Generating random arrays...");
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			first_array[i] = (int)rand_32(101) - 50;
			second_array[i] = (int)rand_32(101) - 50;
			third_array[i] = (int)rand_32(101) - 50;
			fourth_array[i] = (int)rand_32(101) - 50;
		}
		putchar('\n');

		puts("Generated arrays:");
		for (int i = 0; i < 4; i++)
		{
			printf("Array #%d: ", i + 1);
			for (int j = 0;j < ARRAY_SIZE;j++)
				printf("%d ", arrays[i][j]);
			putchar('\n');
		}
		putchar('\n');

		puts("Sorting arrays...");
		if (!insertion_sort(first_array, ARRAY_SIZE, sizeof(int), cmp_int_asc))
			return 3;
		if (!insertion_sort(second_array, ARRAY_SIZE, sizeof(int), cmp_int_desc))
			return 3;
		if (!counting_sort(third_array, ARRAY_SIZE, true))
			return 3;
		if (!counting_sort(fourth_array, ARRAY_SIZE, false))
			return 3;
		putchar('\n');

		puts("Sorted arrays:");
		puts("1/2 - Insertion sort (Ascending and descending)");
		puts("3/4 - Counting sort (Ascending and descending)");
		putchar('\n');

		for (int i = 0; i < 4; i++)
		{
			printf("Sorted array #%d: ", i + 1);
			for (int j = 0;j < ARRAY_SIZE;j++)
				printf("%d ", arrays[i][j]);
			putchar('\n');
		}
		break;
	}
	case 3: {
		puts("Random number in range [-2^30, 2^30 - 1]:");
		printf("%d\n", (int)rand_32((uint32_t)INT_MAX + 1) - 1073741824);
		break;
	}
	default: {
		puts("Invalid input!");
		return 1;
	}
	}
	return 0;
}