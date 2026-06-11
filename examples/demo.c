#define ARRAY_SIZE 16
#define NUMBERS 5

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
#include "../include/arr_lib.h"
#include "../include/utils_lib.h"

int main(void)
{
	int selected_library;
	int symbol;

	srand((unsigned int)time(NULL));

	puts("Select a module to test:");
	puts("1. Input/Output module;");
	puts("2. Sorting module;");
	puts("3. Random number generator module;");
	puts("4. Exit;");
	putchar('\n');

	puts("Enter your choice (1-4):");

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
				first_array[i] = (int)rand_32(51) - 25;
				second_array[i] = (int)rand_32(51) - 25;
				third_array[i] = (int)rand_32(51) - 25;
				fourth_array[i] = (int)rand_32(51) - 25;
			}
			putchar('\n');

			puts("Generated arrays:");
			for (int i = 0; i < 4; i++)
			{
				printf("Array #%d: ", i + 1);
				if (!arr_print(arrays[i], ARRAY_SIZE, sizeof(int), print_int, " "))
				{
					puts("Function arr_print() argument error!");
					return 3;
				}
				putchar('\n');
			}
			putchar('\n');
			
			puts("Maximum and minimum of arrays:");
			for (int i = 0; i < 4; i++)
			{
				int* maximum = (int*)arr_extremum(arrays[i], ARRAY_SIZE, sizeof(int), cmp_int_asc);
				int* minimum = (int*)arr_extremum(arrays[i], ARRAY_SIZE, sizeof(int), cmp_int_desc);
				if (maximum == NULL || minimum == NULL)
				{
					puts("Function arr_extremum() argument error!");
					return 3;
				}
				printf("Array #%d: maximum = %d, minimum = %d", i + 1, *maximum, *minimum);
				putchar('\n');
			}
			putchar('\n');

			puts("Sorting arrays...");
			if (!insertion_sort(first_array, ARRAY_SIZE, sizeof(int), cmp_int_asc))
			{
				puts("Function insertion_sort() some error!");
				return 4;
			}
			if (!insertion_sort(second_array, ARRAY_SIZE, sizeof(int), cmp_int_desc))
			{
				puts("Function insertion_sort() some error!");
				return 4;
			}
			if (!counting_sort(third_array, ARRAY_SIZE, true))
			{
				puts("Function counting_sort() some error!");
				return 4;
			}
			if (!counting_sort(fourth_array, ARRAY_SIZE, false))
			{
				puts("Function counting_sort() some error!");
				return 4;
			}
			putchar('\n');

			puts("Sorted arrays:");
			puts("1/2 - Insertion sort (Ascending and descending)");
			puts("3/4 - Counting sort (Ascending and descending)");
			putchar('\n');

			for (int i = 0; i < 4; i++)
			{
				printf("Sorted array #%d: ", i + 1);
				if (!arr_print(arrays[i], ARRAY_SIZE, sizeof(int), print_int, " "))
				{
					puts("Function arr_print() argument error!");
					return 3;
				}
				putchar('\n');
			}
			break;
		}
		case 3: {
			puts("Random numbers in range [-2^30, 2^30 - 1]:");
			for (size_t i = 0; i < NUMBERS; i++)
				printf("%d\n", (int)rand_32((uint32_t)INT_MAX + 1) - 1073741824);
			break;
		}
		case 4: {
			puts("Exit...");
			break;
		}
		default: {
			puts("Invalid input!");
			return 1;
		}
	}
	return 0;
}