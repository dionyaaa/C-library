#include <assert.h>
#include "../include/cmp_lib.h"


int cmp_int_asc(const void* a, const void* b)
{
	assert(a != NULL && b != NULL);
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	if (arg1 > arg2)
		return 1;
	if (arg1 < arg2)
		return -1;
	return 0;
}


int cmp_int_desc(const void* a, const void* b)
{
	assert(a != NULL && b != NULL);
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;
	if (arg1 < arg2)
		return 1;
	if (arg1 > arg2)
		return -1;
	return 0;
}


int cmp_float_asc(const void* a, const void* b)
{
	assert(a != NULL && b != NULL);
	float arg1 = *(const float*)a;
	float arg2 = *(const float*)b;
	if (arg1 > arg2)
		return 1;
	if (arg1 < arg2)
		return -1;
	return 0;
}


int cmp_float_desc(const void* a, const void* b)
{
	assert(a != NULL && b != NULL);
	float arg1 = *(const float*)a;
	float arg2 = *(const float*)b;
	if (arg1 < arg2)
		return 1;
	if (arg1 > arg2)
		return -1;
	return 0;
}


int cmp_double_asc(const void* a, const void* b)
{
	assert(a != NULL && b != NULL);
	double arg1 = *(const double*)a;
	double arg2 = *(const double*)b;
	if (arg1 > arg2)
		return 1;
	if (arg1 < arg2)
		return -1;
	return 0;
}


int cmp_double_desc(const void* a, const void* b)
{
	assert(a != NULL && b != NULL);
	double arg1 = *(const double*)a;
	double arg2 = *(const double*)b;
	if (arg1 < arg2)
		return 1;
	if (arg1 > arg2)
		return -1;
	return 0;
}