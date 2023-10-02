#include "main.h"


/**
 * create_file - reads a text file and prints it
 * to the POSIX standard output.
 * @filename:  the name of the file to create
 * @text_content: is a NULL terminated string to write to the file
 * Return: success 1 faillure -1
 */
int create_file(const char *filename, char *text_content)
{
	int num_char = 0;
	int file;


	if (!filename)
		return (-1);

	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file == -1)
		return (-1);

	if (!text_content)
	{
		text_content = "";
		num_char = 0;
	} else
	{
		while (text_content[num_char] != '\0')
		{
			num_char++;
		}
	}
	if (write(file, text_content, num_char) == -1)
		return (-1);

	return (1);
}