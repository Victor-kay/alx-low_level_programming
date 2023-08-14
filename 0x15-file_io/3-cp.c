#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h> // Add this header for strerror

#define BUF_SIZE 1024

void print_error(const char *msg, const char *file_name, const char *error_msg) {
    dprintf(STDERR_FILENO, msg, file_name, error_msg); // Updated argument list
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int fd_from, fd_to;
    ssize_t bytes_read, bytes_written;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        print_error("Error: Can't read from file %s: %s\n", argv[1], strerror(errno));

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
        print_error("Error: Can't write to %s: %s\n", argv[2], strerror(errno));

    while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1)
            print_error("Error: Can't write to %s: %s\n", argv[2], strerror(errno));
    }

    if (bytes_read == -1)
        print_error("Error: Can't read from file %s: %s\n", argv[1], strerror(errno));

    if (close(fd_from) == -1)
        print_error("Error: Can't close fd %d: %s\n", fd_from, strerror(errno));

    if (close(fd_to) == -1)
        print_error("Error: Can't close fd %d: %s\n", fd_to, strerror(errno));

    return EXIT_SUCCESS;
}
