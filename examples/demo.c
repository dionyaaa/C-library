#define INVALID_INPUT_ERROR 1
#define MEMORY_ALLOCATION_ERROR 2
#define SORTING_FUNCTION_ERROR 3
#define EXTREMUM_FUNCTION_ERROR 4
#define STACK_FUNCTION_ERROR 5

#define SORTING_ARRAY_SIZE 16
#define STACK_SIZE 16
#define RANDOM_NUMBERS 16
#define SWAP_ARRAY_SIZE 32
#define SWAP_ITERATION_NUMBER 999999

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#include "../include/io_lib.h"
#include "../include/sort_lib.h"
#include "../include/ds_lib.h"
#include "../include/cmp_lib.h"
#include "../include/rand_lib.h"
#include "../include/arr_lib.h"
#include "../include/utils_lib.h"

int main(void)
{
	puts("Select a module to test:");
	puts("1. Input/Output module;");
	puts("2. Sorting and arrays module;");
	puts("3. Data structures module;");
	puts("4. Random number generator module;");
	puts("5. Utils module;");
	putchar('\n');
	puts("0. Exit;");
	putchar('\n');

	puts("Enter your choice (0-5):");

	srand((unsigned int)time(NULL));
	int symbol;

	int selected_library;
	if (scanf("%d", &selected_library) < 1)
	{
		putchar('\n');
		puts("Invalid input!");
		return INVALID_INPUT_ERROR;
	}
	if ((symbol = getchar()) != '\n' && symbol != EOF)
	{
		clear_stdin();
		putchar('\n');
		puts("Invalid input!");
		return INVALID_INPUT_ERROR;
	}
	putchar('\n');

	switch (selected_library) {
		case 0: {
			puts("Exit...");
			break;
		}

		case 1: {
			puts("Enter a string of any length:");
			char* input_string = getstr(NULL);
			if (input_string == NULL)
			{
				puts("Memory allocation error!");
				return MEMORY_ALLOCATION_ERROR;
			}
			putchar('\n');

			printf("You entered the string:\n\"%s\"\n", input_string);
			free(input_string);
			break;
		}

		case 2: {
			puts("Generating random array...");
			int array[SORTING_ARRAY_SIZE];
			for (int i = 0; i < SORTING_ARRAY_SIZE; i++)
				array[i] = (int)rand_32(51) - 25;
			putchar('\n');

			puts("Generated array:");
			arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
			puts("\n");

			puts("Maximum and minimum of array:");
			int* maximum = (int*)arr_extremum(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_asc);
			int* minimum = (int*)arr_extremum(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_desc);
			if (maximum == NULL || minimum == NULL)
			{
				puts("Function arr_extremum() argument error!");
				return EXTREMUM_FUNCTION_ERROR;
			}
			printf("Maximum = %d, minimum = %d\n", *maximum, *minimum);
			putchar('\n');

			puts("Select a sorting function:");
			puts("1. Hoares_quick_sort();");
			puts("2. Lomuto_quick_sort();");
			puts("3. Bubble_sort();");
			puts("4. Selection_sort();");
			puts("5. Insertion_sort();");
			puts("6. Counting_sort();");
			putchar('\n');
			puts("0. Exit;");
			putchar('\n');

			puts("Enter your choice (0-6):");

			int selected_sorting;
			if (scanf("%d", &selected_sorting) < 1)
			{
				putchar('\n');
				puts("Invalid input!");
				return INVALID_INPUT_ERROR;
			}
			if ((symbol = getchar()) != '\n' && symbol != EOF)
			{
				clear_stdin();
				putchar('\n');
				puts("Invalid input!");
				return INVALID_INPUT_ERROR;
			}
			putchar('\n');

			switch (selected_sorting) {
				case 0: {
					puts("Exit...");
					break;
				}

				case 1: {
					puts("Sorting by Hoares_quick_sort()...");
					putchar('\n');

					if (!Hoares_quick_sort(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_asc))
					{
						puts("Function Hoares_quick_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Ascending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					puts("\n");

					if (!Hoares_quick_sort(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_desc))
					{
						puts("Function Hoares_quick_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Descending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					putchar('\n');

					break;
				}

				case 2: {
					puts("Sorting by Lomuto_quick_sort()...");
					putchar('\n');

					if (!Lomuto_quick_sort(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_asc))
					{
						puts("Function Lomuto_quick_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Ascending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					puts("\n");

					if (!Lomuto_quick_sort(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_desc))
					{
						puts("Function Lomuto_quick_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Descending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					putchar('\n');

					break;
				}

				case 3: {
					puts("Sorting by bubble_sort()...");
					putchar('\n');

					if (!bubble_sort(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_asc))
					{
						puts("Function bubble_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Ascending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					puts("\n");

					if (!bubble_sort(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_desc))
					{
						puts("Function bubble_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Descending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					putchar('\n');

					break;
				}

				case 4: {
					puts("Sorting by selection_sort()...");
					putchar('\n');

					if (!selection_sort(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_asc))
					{
						puts("Function selection_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Ascending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					puts("\n");

					if (!selection_sort(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_desc))
					{
						puts("Function selection_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Descending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					putchar('\n');

					break;
				}

				case 5: {
					puts("Sorting by insertion_sort()...");
					putchar('\n');

					if (!insertion_sort(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_asc))
					{
						puts("Function insertion_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Ascending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					puts("\n");

					if (!insertion_sort(array, SORTING_ARRAY_SIZE, sizeof(int), cmp_int_desc))
					{
						puts("Function insertion_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Descending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					putchar('\n');

					break;
				}

				case 6: {
					puts("Sorting by counting_sort()...");
					putchar('\n');

					if (!counting_sort(array, SORTING_ARRAY_SIZE, true))
					{
						puts("Function counting_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Ascending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					puts("\n");

					if (!counting_sort(array, SORTING_ARRAY_SIZE, false))
					{
						puts("Function counting_sort() some error!");
						return SORTING_FUNCTION_ERROR;
					}
					puts("Descending:");
					arr_print(array, SORTING_ARRAY_SIZE, sizeof(int), print_int, " ");
					putchar('\n');

					break;
				}

				default: {
					puts("Invalid input!");
					return INVALID_INPUT_ERROR;
				}
			}
			break;
		}

		case 3: {
			puts("Testing stack functions:");
			putchar('\n');

			stack* test_stack = stack_create(sizeof(size_t));
			if (test_stack == NULL)
				return STACK_FUNCTION_ERROR;

			for (size_t i = 0; i < STACK_SIZE; i++)
			{
				if (!stack_push(test_stack, &i))
					return STACK_FUNCTION_ERROR;
				printf("Push(): %zu\n", i);
			}
			putchar('\n');

			size_t value;
			for (size_t i = 0; i < STACK_SIZE / 2; i++)
			{
				if (!stack_pop(test_stack, &value))
					return STACK_FUNCTION_ERROR;
				printf("Pop(): %zu\n", value);
			}
			putchar('\n');

			stack_clear(test_stack);
			puts("Stack successfully cleared!");
			putchar('\n');

			stack_destroy(test_stack);
			puts("Stack successfully destroyed!");
			break;
		}

		case 4: {
			puts("Random numbers in range [-2^30, 2^30 - 1]:");
			for (size_t i = 0; i < RANDOM_NUMBERS; i++)
				printf("%d\n", (int)rand_32((uint32_t)INT_MAX + 1) - 1073741824);
			break;
		}

		case 5: {
			int array[SWAP_ARRAY_SIZE];

			puts("Testing val_swap_stack():");
			for (size_t i = 0;i < SWAP_ARRAY_SIZE; i++)
				array[i] = i;

			clock_t stack_start = clock();
			for (size_t i = 0; i < SWAP_ITERATION_NUMBER; i++)
				for (size_t j = 0; j < SWAP_ARRAY_SIZE / 2; j++)
					val_swap_stack(&array[j], &array[SWAP_ARRAY_SIZE - 1 - j], sizeof(int));
			clock_t stack_end = clock();

			printf("Time: %lf s\n", (double)(stack_end - stack_start) / CLOCKS_PER_SEC);
			puts("Array:");
			arr_print(array, SWAP_ARRAY_SIZE, sizeof(int), print_int, " ");
			puts("\n");

			puts("Testing val_swap_heap():");
			for (size_t i = 0;i < SWAP_ARRAY_SIZE; i++)
				array[i] = i;

			clock_t heap_start = clock();
			for (size_t i = 0; i < SWAP_ITERATION_NUMBER; i++)
				for (size_t j = 0; j < SWAP_ARRAY_SIZE / 2; j++)
					val_swap_heap(&array[j], &array[SWAP_ARRAY_SIZE - 1 - j], sizeof(int));
			clock_t heap_end = clock();

			printf("Time: %lf s\n", (double)(heap_end - heap_start) / CLOCKS_PER_SEC);
			puts("Array:");
			arr_print(array, SWAP_ARRAY_SIZE, sizeof(int), print_int, " ");
			putchar('\n');
			break;
		}

		default: {
			puts("Invalid input!");
			return INVALID_INPUT_ERROR;
		}
	}
	return 0;
}