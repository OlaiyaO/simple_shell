#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * internal_exit - string length
 * @ac : pointer
 * @av : destination
 * @env : ...
 * Return: Always 0.
 */

int internal_exit(int ac, char **av, char **env)
{
	int rc = 0;

	env = env;

	if (ac > 1)
	{
		rc = _atoi(av[1]);
	}
	free_av(av);
	free_env(env);
	exit(rc);
	return (0);
}
