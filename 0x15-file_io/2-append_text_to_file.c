#include "main.h"
#include <unistd.h>
/**
 * append_text_to_file - read text file
 * @filename: name of the file
 * @text_content: text content
 * Return: on success   , on error
 */
int append_text_to_file(const char *filename, char *text_content)
{
size_t write_len;
int fd;
if (!filename)
return (-1);

fd = open(filename, O_RDWR | O_APPEND);
if (!text_content)
{
if (fd == -1)
return (-1);
else
return (1);
}
write_len = 0;
while (*(text_content + write_len))
{
write_len++;
}
if (write(fd, text_content, write_len) == -1)
{
return (-1);
}
return (1);
}