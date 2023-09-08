#include "main.h"
#include<stdio.h>
#include<stdlib.h>
/**
 * *malloc_checked - allocates memory
 * @b: int param
 * Return: ponter
 */

void *malloc_checked(unsigned int b)
{
	char *ptr = malloc((sizeof(char) * b));

	if (!ptr)
		exit(98);
	return (ptr);
}
