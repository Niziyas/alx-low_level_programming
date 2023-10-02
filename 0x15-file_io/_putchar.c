#include <unistd.h>
#include "main.h"

/**
 * _putchar - print character
 * @c: character to be printed
 * Return: 0 on success
 */
int _putchar(char c)
{
  return(write(1, &c, 1));
  
}