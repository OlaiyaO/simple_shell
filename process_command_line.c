#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * replace_variable - Replaces variables.
 * @var: The variable to replace.
 * Return: 0.
 */

char *replace_variable(char *var)
{
	if (var[1] == '?')
	{
		return (_itoa(get_last_status()));
	}
	else if (var[1] == '$')
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
 * process_token - prints the environment
 * @token: command-line arguments.
 * @last_status: ...
 * Return: Always 0.
 */

char *process_token(char *token, int last_status)
{
	char *alias = _getalias(token);

	if (alias != NULL)
	{
		token = alias;
	}
	else if (token[0] == '$')
	{
		token = replace_variable(token);
	}
	else if (_strcmp(token, "&&") == 0)
	{
		if (last_status == 0)
		{
		}
	}
	else if (_strcmp(token, "||") == 0)
	{
	}
	return (token);
}

/**
 * process_command_line - prints the environment
 * @lineptr: command-line arguments.
 * @av: ...
 * Return: Always 0.
 */
int process_command_line(char **av, char *lineptr)
{
	char *token, *command, *new_av[10];
	int new_ac;
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
			token = process_token(token, last_status);

			new_av[++new_ac] = (char *)_strdup(token);
			token = get_token(NULL, " ");
		}
		new_av[++new_ac] = NULL;
		last_status = process_command(av, new_ac, new_av);
	}
	return (0);
}
