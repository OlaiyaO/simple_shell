#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_all_alias - string length
 * Return: Always 0.
 */

int print_all_alias(void)
{
	int i;
	char **shell_alias = get_shell_alias();

	if (shell_alias == NULL)
	{
		return (0);
	}
	i = 0;
	while (shell_alias[i] != NULL)
	{
		_printf("%s\n", shell_alias[i]);
		i++;
	}
	return (0);
}
/**
 * build_alias_command - string length
 * @ac : pointer
 * @av : destination
 * Return: Always 0.
 */
char *build_alias_command(int ac, char **av)
{
	int i;
	int j;
	int k;
	int length = 0;
	char *alias_str;

	for (i = 1; i < ac; i++)
	{
		length += _strlen(av[i]) + 1;
	}
	alias_str = malloc(sizeof(char) * (length + 1));
	if (alias_str == NULL)
	{
		return (NULL);
	}
	k = 0;
	for (i = 1; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			alias_str[k] = av[i][j];
			k++;
			j++;
		}
		if (i < (ac - 1))
		{
			alias_str[k++] = ' ';
		}
	}
	alias_str[k]  = 0;
	return (alias_str);
}

/**
 * internal_alias - string length
 * @ac : pointer
 * @av : destination
 * @env : ...
 * Return: Always 0.
 */

int internal_alias(int ac, char **av, char **env)
{
	int i;
	int rc = 0;

	env = env;
	ac = ac;
	i = 0;
	if (ac == 1)
	{
		print_all_alias();
	}
	else
	{
		char *command = build_alias_command(ac, av);

		if (command == NULL)
		{
			return (1);
		}
		printf("command: %s\n", command);
		if (_strchr(command, '=') != -1)
		{
			rc = add_alias(command);
		}
		else
		{
			for (i = 1; i < ac; i++)
			{
				char *alias = _getalias(_trim(av[i]));

				if (alias != NULL)
				{
					_printf("%s\n", alias);
				}
			}
		}
		free(command);
	}
	return (rc);
}
