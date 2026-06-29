#ifndef DS_LIB_H
#define DS_LIB_H

#include <stddef.h>
#include <stdbool.h>

typedef struct stack stack;
stack* stack_create(size_t element_size);
bool stack_push(stack* stack_ptr, const void* value);
bool stack_pop(stack* stack_ptr, void* value);
void stack_clear(stack* stack_ptr);
void stack_destroy(stack* stack_ptr);

#endif