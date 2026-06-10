#include <stdint.h>
#include <stdlib.h>
#include "../include/rand_lib.h"


uint32_t rand_32(uint32_t max_number)
{
	if (max_number == 0)
		return 0;
	uint32_t result = 0;
	result = (uint32_t)(rand() & 0x7FFF);
	result = (result << 15) | (uint32_t)(rand() & 0x7FFF);
	result = (result << 2) | (uint32_t)(rand() & 3);
	return result % max_number;
}


uint64_t rand_64(uint64_t max_number)
{
	if (max_number == 0)
		return 0;
	uint64_t result = 0;
	result = (uint64_t)(rand() & 0x7FFF);
	result = (result << 15) | (uint64_t)(rand() & 0x7FFF);
	result = (result << 15) | (uint64_t)(rand() & 0x7FFF);
	result = (result << 15) | (uint64_t)(rand() & 0x7FFF);
	result = (result << 4) | (uint64_t)(rand() & 15);
	return result % max_number;
}