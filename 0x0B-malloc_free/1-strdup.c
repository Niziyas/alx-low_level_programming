#include "main.h"
#include <stdlib.h>
/**
 * _strdup - a function to duplicate a string
 *
 * @str: string to be duplicated
 *
 * Return: a pointer
 *
 */
char *_strdup(char *str)
{
	int i;
	int c = 0;
	char *t;

	if (str == NULL)
		return (NULL);

	while (str[c] != '\0')
		c++;

	t = malloc(sizeof(char) * c + 1);

	if (t == NULL)
		return (NULL);

	for (i = 0; i < c; i++)
		t[i] = str[i];

	return (t);

}
