# C-library
A modular C library with sorting algorithms, I/O functions, large random number generating functions, comparators, main structure types ***(in progress)*** and functions for working with arrays ***(in progress)***.
## About
This project was created as a way for me to learn C, Git/GitHub, different algorithms and data structures in C, as well as to build a portfolio.  
For the necessary function arguments, please check the header or see the hints in your IDE.
## Features
The repository includes the following modules:
1. I/O module **`io_lib.h`**:
	- `getstr()` is a function similar to the standard C `getchar()` function, but used for the strings. It returns a string of any length. ***You must free the allocated memory yourself***;
	- `clear_stdin()` helps you clear the standard input stream after using functions like `scanf()`;
	- `print_arr()` prints an array of any type to the standard output stream ***(in progress)***;
2. Sorting module **`sort_lib.h`**:
	- `quick_sort()` - quick sort algorithm ***(in progress)***;
	- `insertion_sort()` - insertion sort algorithm;
	- `counting_sort()` - counting sort algorithm;
3. Comparator module **`cmp_lib.h`**:
	- Ascending and descending comparator functions for `int`, `float` and `double`;
4. Random number generation module **`rand_lib.h`**:
	- `rand_32()` and `rand_64()` allow you to generate 32-bit and 64-bit positive random numbers. They generate numbers with a uniform distribution, like standard C `rand()` function, but without its range limits;
5. Array utilities module **`arr_lib.h`** ***(in progress)***:
	- `swap()` swaps the values of two variables ***(in progress)***;
	- `arr_max()` and `arr_min()` search for the maximum and minimum values in an array of any type ***(in progress)***;
## License
This project is licensed under the [MIT](LICENSE) license.