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
	(void)ac;
	(void)av;
	(void)env;

	free_av(av);
	free_env(env);
	free_shell_alias();

	exit(EXIT_SUCCESS);
	return (0);
}
