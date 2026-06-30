# C-library
A modular C library with I/O functions, sorting algorithms, main data structure types, comparators, large random number generating functions and functions for working with arrays.
## About
This project was created as a way for me to learn C, Git/GitHub, different algorithms and data structures in C, as well as to build a portfolio. I also plan to use this library in my future projects, and I would be glad if it helps someone else too.  
For the necessary function arguments, please check the header files or see the hints in your IDE.
## Features
The repository includes the following modules:
1. I/O module **`io_lib.h`**:
	- `getstr()` is a function similar to the standard C `getchar()` function, but used for the strings. It returns a string of any length. ***You must free the allocated memory yourself***.
	- `clear_stdin()` helps you clear the standard input stream after using functions like `scanf()`.
	- `arr_print()` prints an array of any type to the standard output stream.
	- `print_int()`, `print_float()` and `print_double()` are used in `arr_print()` for formatting of array output.
2. Sorting module **`sort_lib.h`**:
	- `Hoares_quick_sort()` - quick sort algorithm with Hoare partition scheme.
	- `Lomuto_quick_sort()` - quick sort algorithm with Lomuto partition scheme.
	- `bubble_sort()` - bubble sort algorithm.
	- `selection_sort()` - selection sort algorithm.
	- `insertion_sort()` - insertion sort algorithm.
	- `counting_sort()` - counting sort algorithm.
3. Data structures module **`ds_lib.h`**:
	- **Stack (Linked list)** - classic stack implementation using linked structures (LIFO).
	- **Queue (Linked list)** - classic queue implementation using linked structures (FIFO).
	- **Stack (Dynamic array)** - stack implementation using a dynamic array with automatic resizing (LIFO).
4. Comparator module **`cmp_lib.h`**:
	- Ascending and descending comparator functions for `int`, `float` and `double`.
5. Random number generation module **`rand_lib.h`**:
	- `rand_32()` and `rand_64()` allow you to generate 32-bit and 64-bit positive random numbers. They generate numbers with a uniform distribution, like standard C `rand()` function, but without its range limits.
6. Array utilities module **`arr_lib.h`**:
	- `arr_extremum()` searchs for the maximum or minimum values in an array of any type. To use it, you need to provide a comparator: an ascending comparator finds the maximum, while a descending comparator finds the minimum.
7. General utilities module **`utils_lib.h`**:
	- `val_swap()` automatically chooses a method to swap the values of two variables of any type.
	- `val_swap_stack()` swaps the values of two variables of any type using stack memory.
	- `val_swap_heap()` swaps the values of two variables of any type using heap memory.
## License
This project is licensed under the [MIT](LICENSE) license.