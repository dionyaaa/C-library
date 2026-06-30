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

typedef struct queue queue;
queue* queue_create(size_t element_size);
bool queue_push(queue* queue_ptr, const void* value);
bool queue_pop(queue* queue_ptr, void* value);
void queue_clear(queue* queue_ptr);
void queue_destroy(queue* queue_ptr);

#endif