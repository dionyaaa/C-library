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


typedef struct queue_element
{
	void* value;
	struct queue_element* next_element;
} queue_element;

struct queue
{
	queue_element* first;
	queue_element* last;
	size_t element_size;
};

queue* queue_create(size_t element_size)
{
	assert(element_size != 0);
	queue* ptr = (queue*)malloc(sizeof(queue));
	if (ptr == NULL)
		return NULL;
	ptr->first = NULL;
	ptr->last = NULL;
	ptr->element_size = element_size;
	return ptr;
}

bool queue_push(queue* queue_ptr, const void* value)
{
	assert(queue_ptr != NULL && value != NULL);
	queue_element* tmp = (queue_element*)malloc(sizeof(queue_element));
	if (tmp == NULL)
		return false;

	tmp->value = (void*)malloc(queue_ptr->element_size);
	if (tmp->value == NULL)
	{
		free(tmp);
		return false;
	}

	memcpy(tmp->value, value, queue_ptr->element_size);
	tmp->next_element = NULL;
	if (queue_ptr->last != NULL)
		queue_ptr->last->next_element = tmp;
	queue_ptr->last = tmp;
	if (queue_ptr->first == NULL)
		queue_ptr->first = tmp;
	return true;
}

bool queue_pop(queue* queue_ptr, void* value)
{
	assert(queue_ptr != NULL && value != NULL);
	if (queue_ptr->first == NULL)
		return false;

	memcpy(value, queue_ptr->first->value, queue_ptr->element_size);
	queue_element* tmp = queue_ptr->first;
	queue_ptr->first = queue_ptr->first->next_element;
	free(tmp->value);
	free(tmp);
	if (queue_ptr->first == NULL)
		queue_ptr->last = NULL;
	return true;
}

void queue_clear(queue* queue_ptr)
{
	assert(queue_ptr != NULL);
	queue_element* tmp;
	while (queue_ptr->first != NULL)
	{
		tmp = queue_ptr->first;
		queue_ptr->first = queue_ptr->first->next_element;
		free(tmp->value);
		free(tmp);
	}
	queue_ptr->last = NULL;
}

void queue_destroy(queue* queue_ptr)
{
	assert(queue_ptr != NULL);
	queue_clear(queue_ptr);
	free(queue_ptr);
}


struct darray_stack
{
	void* array;
	size_t array_size;
	size_t element_size;
	size_t top;
};

darray_stack* darray_stack_create(size_t element_size)
{
	assert(element_size != 0);
	darray_stack* ptr = (darray_stack*)malloc(sizeof(darray_stack));
	if (ptr == NULL)
		return NULL;

	ptr->array_size = DARRAY_STACK_FIRST_SIZE;
	ptr->element_size = element_size;
	ptr->top = 0;

	ptr->array = (void*)malloc(ptr->array_size * element_size);
	if (ptr->array == NULL)
	{
		free(ptr);
		return NULL;
	}

	return ptr;
}

bool darray_stack_push(darray_stack* darray_stack_ptr, const void* value)
{
	assert(darray_stack_ptr != NULL && value != NULL);
	if (darray_stack_ptr->top == darray_stack_ptr->array_size)
	{
		void* tmp = (void*)realloc(darray_stack_ptr->array, (darray_stack_ptr->array_size * 2) * darray_stack_ptr->element_size);
		if (tmp == NULL)
			return false;
		darray_stack_ptr->array = tmp;
		darray_stack_ptr->array_size = darray_stack_ptr->array_size * 2;
	}
	memcpy((unsigned char*)darray_stack_ptr->array + darray_stack_ptr->top * darray_stack_ptr->element_size, value, darray_stack_ptr->element_size);
	darray_stack_ptr->top++;
	return true;
}

bool darray_stack_pop(darray_stack* darray_stack_ptr, void* value)
{
	assert(darray_stack_ptr != NULL && value != NULL);
	if (darray_stack_ptr->top == 0)
		return false;
	memcpy(value, (unsigned char*)darray_stack_ptr->array + (darray_stack_ptr->top - 1) * darray_stack_ptr->element_size, darray_stack_ptr->element_size);
	darray_stack_ptr->top--;
	return true;
}

void darray_stack_clear(darray_stack* darray_stack_ptr)
{
	assert(darray_stack_ptr != NULL);
	darray_stack_ptr->top = 0;
}

void darray_stack_destroy(darray_stack* darray_stack_ptr)
{
	assert(darray_stack_ptr != NULL);
	free(darray_stack_ptr->array);
	free(darray_stack_ptr);
}