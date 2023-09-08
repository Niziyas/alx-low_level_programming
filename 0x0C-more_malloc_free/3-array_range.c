#include "main.h"
#include <stdlib.h>
/**
 * array_range - function creates array
 * @min:  number from min
 * @max: the max number
 * Return: pointer int type
 */

int *array_range(int min, int max)
{
	int i, len = max - min + 1;
	int *ptr;

	if (min > max)
		return (NULL);
	ptr = malloc(sizeof(int) * len);

	if (!ptr)
		return (NULL);
	for (i = 0; i < len; i++)
		ptr[i] = i + min;
	return (ptr);
}
