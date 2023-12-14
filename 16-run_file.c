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
	char *command_lines[10];
        int num_commands=0;
        int i;
        char *token;

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
		else
		{
			break;
		}
	}
	return (0);
}
