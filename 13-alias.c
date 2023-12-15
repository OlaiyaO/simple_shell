#include <stdio.h>
#include <stdlib.h>
#include "main.h"


static char **shell_alias = NULL;

/**
 * get_shell_alias - string length
 * Return: Always 0.
 */
char **get_shell_alias(void)
{
	return (shell_alias);
}

/**
 * free_shell_alias - string length
 * Return: Always 0.
 */
void  free_shell_alias(void)
{
	int i = 0;

	if (shell_alias == NULL)
	{
		return;
	}

	while (shell_alias[i] != NULL)
	{
		free(shell_alias[i]);
		i++;
	}
	free(shell_alias);
}
/**
 * add_alias - string length
 * @alias_variable : destination
 * Return: Always 0.
 */
int add_alias(char *alias_variable)
{
	char **new_alias;
	int i;
	int alias_count = 0;

	if (shell_alias != NULL)
	{
		while (shell_alias[alias_count] != NULL)
		{
			alias_count++;
		}
	}

	new_alias = malloc((alias_count + 2) * sizeof(char *));
	if (new_alias == NULL)
	{
		perror("malloc");
		return (1);
	}

	for (i = 0; i < alias_count; i++)
	{
		new_alias[i] = _strdup(shell_alias[i]);
	}
	new_alias[alias_count] = _strdup(alias_variable);
	new_alias[alias_count + 1] = NULL;

	free_shell_alias();

	printf("udpated aliases\n");
	shell_alias = new_alias;
	return (0);
}
