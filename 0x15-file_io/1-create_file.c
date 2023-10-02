#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>  // Add this include for 'strlen'

int create_file(const char *filename, char *text_content);

int main(int ac, char **av) {
int res;

if (ac != 3) {
    printf("Usage: %s <filename> <text>\n", av[0]);
    return (1);
}

res = create_file(av[1], av[2]);

if (res == -1) {
    printf("Error: Could not create the file or write to it.\n");
    return (1);
}

printf("File created and written successfully.\n");
return (0);
}

int create_file(const char *filename, char *text_content) {
if (filename == NULL) {
    return -1;
}

int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1) {
    return -1;
}

if (text_content != NULL) {
    ssize_t bytes_written = write(fd, text_content, strlen(text_content));
if (bytes_written == -1) {
    close(fd);
    return -1;
}
}

close(fd);
return 1;
}
