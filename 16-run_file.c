#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * run_file - prints the environment
 * @ac: command-line arguments.
 * @av: argument strings.
 * @env: variable strings
 * @fd: ...
 * Return: Always 0.
 */

int run_file(int ac, char **av, int fd)
{
	char *lineptr = NULL;
	size_t n = 0;

	n = n;
	ac = ac;
	av = av;
	fd = fd;
	lineptr = lineptr;

	while (1)
	{
		lineptr = NULL;
		n = 0;
		if (read_command(&lineptr, &n, fd))
		{
			process_command_line(av, lineptr);
			free(lineptr);
		}
		else
		{
			break;
		}
	}
	return (0);
}
