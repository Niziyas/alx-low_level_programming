#include "main.h"
#include <stdlib.h>
/**
 * create_array - a function to create an array of char
 *
 * @size: size of array created
 *
 * @c: character to be initialized
 *
 * Return: pointer to array
 */
char *create_array(unsigned int size, char c)
{
	char *p;

	unsigned int i = 0;

	if (size == 0)
	{
		return (NULL);
	}
	p = (char *) malloc(sizeof(char) * size);

	if (p == NULL)
	{
		return (0);
	}
	while (i < size)
	{
		p[i] = c;
		i++;
	}
	p[i] = '\0';
	return (p);
}
