#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * run_command - prints the environment
 * @ac: command-line arguments.
 * @av: argument strings.
 * @interactive: ...
 * Return: Always 0.
 */

int run_command(int ac, char **av, int interactive)
{
	char *lineptr = NULL;
	size_t n;

	ac = ac;
	av = av;

	while (1)
	{
		if (interactive)
		{
			prompt();
		}

		lineptr = NULL;
		n = 0;
		if (read_command(&lineptr, &n, 0)) 
		{
			process_command_line(av, lineptr);
			free(lineptr);
		}
		if (!interactive)
		{
			break;
		}
	}
	return (0);
}
