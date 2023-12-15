#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * prompt - ..
 * return: 0.
 */

void prompt(void)
{
	write(STDOUT_FILENO, "($) ", 4);
}
/**
 * read_command - prints the environment
 * @lineptr: command-line arguments.
 * @n: argument strings.
 * @fd: ...
 * Return: Always 0.
 */


int read_command(char **lineptr, size_t *n, int fd)
{
	int num_read;
	int end;

	num_read = _getline(lineptr, n, fd);

	if (num_read == -1)
	{
		_printf("Exit simple_shell");
		return (-1);
	}
	end =  *n - 1;
	while ((end >= 0) && *(*lineptr + end) <= 32)
	{
		*(*lineptr + end) = 0;
		end--;
	}
	if (end <= 0)
	{
		return (0);
	}
	*n = end + 1;
	return (1);
}
