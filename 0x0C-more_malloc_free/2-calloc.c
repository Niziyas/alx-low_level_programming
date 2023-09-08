#include "main.h"
#include <stdlib.h>
/**
 * _calloc - function allocates memory for array
 * @nmemb: the array ellemnts
 * @size: int the sze of memory for each elements
 * Return: void pointer
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int num;

	if (size <= 0 || nmemb <= 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	for (num = 0; num < (size * nmemb); num++)
	{
		ptr[num] = 0;
	}
	return (ptr);
}
