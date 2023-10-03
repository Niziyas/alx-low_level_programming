#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

char *create_buffer(const char *file) {
    char *buffer;

    buffer = malloc(sizeof(char) * BUFFER_SIZE);
    if (buffer == NULL) {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
        free(buffer);
        exit(99);
    }
    return buffer;
}

void close_file(int file_descriptor) {
    int close_fd;
    close_fd = close(file_descriptor);
    if (close_fd == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d", file_descriptor);
        exit(100);
    }
}

int main(int argc, char *argv[]) {
    int fd_from, fd_to;
    ssize_t bytes_read, bytes_written;
    char *buffer;

    buffer = create_buffer(argv[1]);

    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        free(buffer);
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        free(buffer);
        exit(98);
    }

    fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd_to == -1) {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        free(buffer);
        exit(99);
    }

    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            free(buffer);
            exit(99);
        }
    }

    if (bytes_read == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        free(buffer);
        exit(98);
    }

    close_file(fd_from);
    close_file(fd_to);
    free(buffer);
    return 0;
}
