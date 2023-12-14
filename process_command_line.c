#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

char *replace_variable(char *var)
{
	if(var[1] == '?')
	{
		return (_itoa(get_last_status()));
	}
	else if(var[1] == '$')
	{
		return (_itoa((int)getpid()));
	}
	else
	{
		return (_getenv(get_shell_env(), ++var));
	}
	return ((char *)NULL);
}
/**
 * process_command_line - prints the environment
 * @lineptr: command-line arguments.
 * @av: ...
 * Return: Always 0.
 */

int process_command_line(char **av, char *lineptr)
{
	char *token;
	char *command;
	int new_ac;
	char *new_av[10];
	int last_status = 0;

	token = get_token(lineptr, " ");
	if (token != NULL)
	{
		command = _strdup(token);
		new_ac = 0;
		new_av[new_ac] = (char *) command;
		token = get_token(NULL, " ");
		while (token != NULL)
		{
			if (token[0] == '#')
			{
				break;
			}
			else if(token[0] == '$')
			{
				token = replace_variable(token);
			}
			else if(_strcmp(token, "&&") == 0)
			{
				if(last_status == 0)
				{
				}
			}
			else if(_strcmp(token, "||") == 0)
			{

			}

			new_av[++new_ac] = (char *)_strdup(token);
			token = get_token(NULL, " ");
		}
		new_av[++new_ac] = NULL;

		last_status = process_command(av, new_ac, new_av);
	}
	return (0);
}
