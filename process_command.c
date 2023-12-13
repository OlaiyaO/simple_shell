#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

static int last_status = 0;

int get_last_status(void)
{
	return (last_status);
}

/**
 * process_command - prints the environment
 * @new_ac: command-line arguments.
 * @new_av: argument strings.
 * @av: variable strings
 * Return: Always 0.
 */

int process_command(char **av, int new_ac, char **new_av)
{
	char command_path[512];
	InternalFunction internal_function;
	int status = 0;
	char **env = get_shell_env();

	internal_function = is_internal_command(new_av[0]);
	if (internal_function != NULL)
	{
		status = internal_function(new_ac, new_av, env);
	}
	else if (command_exists(new_av[0], command_path, env) != -1)
	{
		free(new_av[0]);
		new_av[0] = _strdup(command_path);
		status = fork_command(command_path, new_av, env);
	}
	else
	{
		_printf("%s: %s: command not found\n", av[0], new_av[0]);
		status = 1;
	}
	last_status = status;
	free_av(new_av);
	return (status);
}
