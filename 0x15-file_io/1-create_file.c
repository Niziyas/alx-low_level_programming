#include "main.h"
#include <unistd.h>
/**
 * create_file - read text file
 * @filename: name of the file
 * @text_content: text content
 * Return: number of bytes read
 */
int create_file(const char *filename, char *text_content)
{
int fd, check_len;
size_t write_len;

if (!filename)
return (-1);
if (!text_content)
{
text_content = "";
write_len = 0; /*check this latter*/
}
else
{
write_len = 0;
while (*(text_content + write_len))
{
write_len++;
}

}
fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
if (fd == -1)
return (-1);
check_len = write(fd, text_content, write_len);
if (check_len == -1)
return (-1);
close(fd);
return (1);

}