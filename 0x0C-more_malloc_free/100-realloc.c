#include "main.h"
#include <stdlib.h>
#include <string.h>
char *cpy(char *dest, char *src, unsigned int n);

/**
 * _realloc - allocates memory block using malloc and free
 * @ptr: pointer to the memory previosly allocated with malloc
 * @old_size: The size of the allocated space of ptr
 * @new_size: The new size to allocate
 * Return: new resized pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (new_size == 0  && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (new_size > old_size)
		new_size = old_size;
	if (!new_ptr)
		return (NULL);
	new_ptr = cpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}
/**
 * cpy - function copies part of data
 * @dest: the destination
 * @ptr: the source
 *@n: the size to copy
 * Return: new pointer
 */
char *cpy(char *dest, char *ptr, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		*(dest + i) = *(ptr + i);
		i++;
	}
	return (dest);
}
