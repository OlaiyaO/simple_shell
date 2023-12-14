#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * internal_alias - string length
 * @ac : pointer
 * @av : destination
 * @env : ...
 * Return: Always 0.
 */

int internal_alias(int ac, char **av, char **env)
{
	ac = ac;
	av = av;
	env = env;

	_printf("alias\n");
	return (0);
}
