#ifndef IO_LIB_H
#define IO_LIB_H

#include <stddef.h>

void print_int(const void* element);
void print_float(const void* element);
void print_double(const void* element);

void arr_print(const void* array, size_t array_size, size_t block_size, void (*form)(const void* element), const char* separator);

char* getstr(size_t* input_length);
void clear_stdin(void);

#endif