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
	char *command_lines[10];
	int num_commands=0;
	int i;
	char *token;

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
			num_commands = 0;
			token = get_token(lineptr, ";");
			while(token != NULL)
			{
				command_lines[num_commands++] = _strdup(_trim(token));
				token = get_token(NULL, ";");
			}
			for(i=0; i < num_commands; i++)
			{
				process_command_line(av, command_lines[i]);
				free(command_lines[i]);
			}
			free(lineptr);
		}
		if (!interactive)
		{
			break;
		}
	}
	return (0);
}
