#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * create_buffer - copy file
 * @file: file discriptor
 * Return: 0 on success, 1 on faliur
 * 
 */
char *create_buffer(char *file)
{
char *buffer;

buffer = malloc(sizeof(char) * BUFFER_SIZE);
if (buffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
free(buffer);
exit(99);
}
return (buffer);
}
/**
 * close_file - close file
 * @file_discriptor: fd to be closed
 * Return: 0 on success, 1 on faliur
 * 
 */
void close_file(int file_discriptor)
{
int close_fd;
close_fd = close(file_discriptor);
if (close_fd == -1)
{
  dprintf(STDERR_FILENO, "Error: Can't close fd %d", file_discriptor);
  exit(100);
}
}
/**
 * main - main entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 on success, 1 on faliur
 * 
 */
int main(int argc, char *argv[])
{
  int fd_from, fd_to;
  int bytes_read, bytes_written;
  char *buffer;
  bytes_read = 0;

buffer = create_buffer(argv[2]);

if (argc != 3)
{
dprintf(STDERR_FILENO,"Usage: cp file_from file_to");
exit (97);
}
fd_from = open(argv[1], O_RDONLY);
fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | 0664);

while((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) != 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (fd_to == -1 || bytes_written == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s", argv[2]);
free(buffer);
exit(99);
}
fd_to = open(argv[2], O_WRONLY | O_APPEND);

if (fd_from == -1 || bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit (98);
} 
}
close(fd_from);
close(fd_to);
free(buffer);
return (1);
}