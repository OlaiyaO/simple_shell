#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * internal_cd - Change the current directory of the process.
 * @ac: Argument count.
 * @av: Argument vector.
 * @env: Environment variables.
 *
 * Return: 0 on success, -1 on failure.
 */
int internal_cd(int ac, char **av, char **env)
{
	char *new_dir;

	if (ac == 1)
	{
		new_dir = _getenv(env, "HOME");
	}
	else
	{
		new_dir = av[1];
	}
	if (new_dir == NULL)
	{
		return (-1);
	}
	if (chdir(new_dir) == -1)
	{
		return (-1);
	}
	_setenv(env, "PWD", new_dir);
	return (0);
}
