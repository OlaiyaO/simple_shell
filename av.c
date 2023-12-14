#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_av - string length
 * @av : pointer
 * Return: Always 0.
 */

void free_av(char **av)
{
	int i;

	i = 0;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
}

