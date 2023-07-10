#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(char *file);
void close_file_descriptor(int fd);

/**
 * allocate_buffer - Allocates a buffer of size 1024 bytes.
 * @file: The name of the file for which the buffer is being allocated.
 *
 * Return: A pointer to the newly allocated buffer.
 */
char *allocate_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Failed to allocate buffer for %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file_descriptor - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file_descriptor(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents from one file to another.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with exit codes:
 *   97 if the argument count is incorrect.
 *   98 if file_from does not exist or cannot be read.
 *   99 if file_to cannot be created or written to.
 *   100 if file_to or file_from cannot be closed.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	bytes_read = read(file_from, buffer, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || bytes_read == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Failed to read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		bytes_written = write(file_to, buffer, bytes_read);
		if (file_to == -1 || bytes_written == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Failed to write to file %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		bytes_read = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (bytes_read > 0);

	free(buffer);
	close_file_descriptor(file_from);
	close_file_descriptor(file_to);

	return (0);
}
