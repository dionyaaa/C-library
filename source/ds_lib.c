#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "../include/ds_lib.h"


typedef struct stack_element
{
	void* value;
	struct stack_element* previous_element;
} stack_element;

struct stack
{
	stack_element* top;
	size_t element_size;
};

stack* stack_create(size_t element_size)
{
	assert(element_size != 0);
	stack* ptr = (stack*)malloc(sizeof(stack));
	if (ptr == NULL)
		return NULL;
	ptr->top = NULL;
	ptr->element_size = element_size;
	return ptr;
}

bool stack_push(stack* stack_ptr, const void* value)
{
	assert(stack_ptr != NULL && value != NULL);
	stack_element* tmp = (stack_element*)malloc(sizeof(stack_element));
	if (tmp == NULL)
		return false;

	tmp->value = (void*)malloc(stack_ptr->element_size);
	if (tmp->value == NULL)
	{
		free(tmp);
		return false;
	}
	memcpy(tmp->value, value, stack_ptr->element_size);
	tmp->previous_element = stack_ptr->top;
	stack_ptr->top = tmp;
	return true;
}

bool stack_pop(stack* stack_ptr, void* value)
{
	assert(stack_ptr != NULL && value != NULL);
	if (stack_ptr->top == NULL)
		return false;

	memcpy(value, stack_ptr->top->value, stack_ptr->element_size);
	stack_element* tmp = stack_ptr->top;
	stack_ptr->top = stack_ptr->top->previous_element;
	free(tmp->value);
	free(tmp);
	return true;
}

void stack_clear(stack* stack_ptr)
{
	assert(stack_ptr != NULL);
	stack_element* tmp;
	while (stack_ptr->top != NULL)
	{
		tmp = stack_ptr->top;
		stack_ptr->top = stack_ptr->top->previous_element;
		free(tmp->value);
		free(tmp);
	}
}

void stack_destroy(stack* stack_ptr)
{
	assert(stack_ptr != NULL);
	stack_clear(stack_ptr);
	free(stack_ptr);
}