#include <stdio.h>
#include <unistd.h>
#include "main.h"

#define MAX_LINE_LENGTH 1024
static char buffer[MAX_LINE_LENGTH];
static ssize_t bytes_read = 0;
static int buffer_index = 0;


/**
 * _getline - string length
 * @lineptr : ...
 * @stream : pointer
 * @n : ...
 * @fd : ..
 * Write your own getline function
 * Use a buffer to read many chars at once and
 * call the least possible the read system call
 * You will need to use static variables
 * You are not allowed to use getline
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
			/** attempt to read more icharacters */
			bytes_read = read(fd, buffer, (size_t)MAX_LINE_LENGTH);
			buffer_index = 0;
			if (bytes_read <= 0)
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
