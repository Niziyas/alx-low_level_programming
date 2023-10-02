#include "main.h"
/**
 * close_file - close file
 * @fd: fd to be closed
 * Return: 0 on success, 1 on faliur
 */
void close_file(int fd)
{
int close_fd;
close_fd = close(fd);
if (close_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d", fd), exit(100); }
}
/**
 * main - copy file
 * @argc: argument count
 * @argv: argument vector
 * Return: bytes read, 0 on failur
 */
int main(int argc, char *argv[])
{
char *buffer;
int fd_from, fd_to, file_len, writen_len;

buffer = malloc(BUFFER_SIZE);
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97); }
fd_from = open(argv[1], O_RDONLY), file_len = read(fd_from, buffer, 1024);
fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer), exit(99); }
if (!buffer)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99); }
do {
if (fd_from == -1 || file_len == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer), exit(98); }
writen_len = write(fd_to, buffer, file_len);
if (writen_len != file_len || fd_to == -1 || writen_len == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer), exit(99); }
file_len = read(fd_from, buffer, BUFFER_SIZE);
fd_to = open(argv[2], O_WRONLY | O_APPEND);
} while (file_len > 0);
close_file(fd_from);
close_file(fd_to);
free(buffer);
return (0); }