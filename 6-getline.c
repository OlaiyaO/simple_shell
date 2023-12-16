#include <stdio.h>
#include <unistd.h>
#include "main.h"

#define MAX_LINE_LENGTH 1024
static char buffer[MAX_LINE_LENGTH];
static ssize_t bytes_read;
static int buffer_index;
/**
 * finish_read - string length
 * @lineptr : ...
 * @n : ...
 * @index : ..
 * @line_buffer: ..
 * Return: Always 0.
 */
int finish_read(int index, char **lineptr, size_t *n, char *line_buffer)
{
	if (index > 0)
	{
		line_buffer[index] = 0;
		*n = index;
		*lineptr = _strdup(line_buffer);
		return ((ssize_t)index);
	}
	return (-1);
}

/**
 * is_eof - string length
 * @lineptr : ...
 * @n : ...
 * @index : ..
 * Return: Always 0.
 */

int is_eof(int index, char **lineptr, size_t *n)
{
	if (bytes_read == 0 && index == 0)
	{
		*n = _strlen("exit");
		*lineptr = _strdup("exit");
		return (0);
	}
	return (1);
}

/**
 * _getline - string length
 * @lineptr : ...
 * @n : ...
 * @fd : ..
 * Return: Always 0.
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char line_buffer[512];
	int index = 0;

	while (1)
	{
		if (buffer_index == bytes_read)
		{
			bytes_read = read(fd, buffer, (size_t)MAX_LINE_LENGTH);
			if (is_eof(index, lineptr, n) == 0)
			{
				return (0);
			}
			buffer_index = 0;
			if (bytes_read <= 0)
			{
				return (finish_read(index, lineptr, n, line_buffer));
			}
		}
		while (buffer_index < bytes_read && buffer[buffer_index] != '\n')
		{
			line_buffer[index++] = buffer[buffer_index++];
		}
		if (buffer[buffer_index] == '\n')
		{
			line_buffer[index] = 0;
			*n = index;
			*lineptr = _strdup(line_buffer);
			buffer_index++;
			return ((ssize_t)index);
		}
	}
	return ((ssize_t) 0);
}
