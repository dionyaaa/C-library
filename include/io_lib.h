#ifndef IO_LIB_H
#define IO_LIB_H

void print_int(const void* element);
void print_float(const void* element);
void print_double(const void* element);

bool arr_print(const void* array, size_t array_size, size_t block_size, void (*form)(const void* element), const char* separator);

char* getstr(void);
void clear_stdin(void);

#endif