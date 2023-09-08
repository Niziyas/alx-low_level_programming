#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * is_digit - function checks if string is digit
 * @s: the string
 * Return: return 0 or 1
 */
int is_digit(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}
/**
 * main - function multiplies two num
 * @argc: the size of array
 * @argv: the array
 * Return: 0 for success
 */
int main(int argc, char **argv)
{
	unsigned long num1, num_h1;
	unsigned long num2, num_h2;

	if (argc < 3)
		exit(98);

	if (!is_digit(argv[2]))
		exit(98);
	if (!is_digit(argv[1]))
		exit(98);
	if (strlen(argv[1]) > 10)
	{
		if (sscanf(argv[1], "%lu%lu%lu%lu", &num1, &num_h1, &num2, &num_h2) != 4)
			exit(98);
		printf("%lu\n", num1 * num2);
		printf("%lu\n", num_h1 * num_h2);
	}
	else
	{
		if (sscanf(argv[1], "%lu", &num1) != 1)
			exit(98);
		num_h1 = 0;
		if (sscanf(argv[2], "%lu", &num2) != 1)
			exit(98);
		num_h2 = 0;
		printf("%lu\n", num1 * num2);
	}
	return 0;
}
