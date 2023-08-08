#include "shell.h"

/**
 * _calloc - allocs/initializes to 0, mem for array of objects of spec size
 * @num: array objects for which memory to be allocated
 * @size: size of each object
 * Return: pointer to allocated memory, NULL if either param is 0 or alloc fail
 */

void *_calloc(size_t num, size_t size)
{
	void *memSeg = NULL;
	char *iniT = NULL;
	size_t iter = 0;

	if (num == 0 || size == 0)
		return (NULL);

	memSeg = malloc(num * size);

	if (memSeg == NULL)
		return (NULL);
	/* memory allocated initialized to zero */
	for (iter = 0, iniT = memSeg; iter != (size * num); iter++)
		iniT[iter] = '\0';

	return (memSeg);
}
