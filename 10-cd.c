#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * internal_cd - string length
 * @ac : pointer
 * @av : destination
 * @env : ...
 * Return: Always 0.
 */

int internal_cd(int ac, char **av, char **env)
{
	char *new_dir;
	if(ac == 1)
	{
		new_dir = _getenv(env, "HOME");
	}
	else
	{
		new_dir = av[1];
	}
	if(new_dir == NULL)
	{
		return (-1);
	}
	if(chdir(new_dir) == -1)
	{
		return (-1);
	}

	_setenv(env, "PWD", new_dir);
	return (0);
}
