#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints its content to STDOUT.
 * @filename: The name of the text file to be read.
 * @letters: The number of letters to be read.
 * 
 * Return: The actual number of bytes read and printed on success, 0 on failure or if filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters);

/**
 * create_file - Creates a new file with the specified name and writes the given content to it.
 * @filename: The name of the file to be created.
 * @text_content: The content to be written to the file.
 * 
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content);

/**
 * append_text_to_file - Appends the specified content to an existing file.
 * @filename: The name of the file to which the content should be appended.
 * @text_content: The content to be appended.
 * 
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content);

#endif
