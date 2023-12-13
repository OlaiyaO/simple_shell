#include <stdio.h>
#include <stdlib.h>
#include "main.h"


static char **shell_env;

/**
 * get_shell_env - string length
 * Return: Always 0.
 */
char **get_shell_env(void)
{
	return (shell_env);
}
/**
 * copy_env - string length
 * @env : ...
 * Return: Always 0.
 */
char **copy_env(char **env)
{
	char **new_env;
	int i;
	int env_count = 0;

	while (env[env_count] != NULL)
	{
		env_count++;
	}

	new_env = malloc((env_count + 1) * sizeof(char *));

	if (new_env == NULL)
	{
		perror("malloc");
		return ((char **)NULL);
	}

	for (i = 0; i < env_count; i++)
	{
		new_env[i] = _strdup(env[i]);
	}

	new_env[env_count] = NULL;

	shell_env = new_env;

	return (shell_env);
}
/**
 * free_env - string length
 * @env : ...
 * Return: Always 0.
 */
void  free_env(char **env)
{
	int i = 0;

	if (env != shell_env)
	{
		return;
	}

	while (env[i] != NULL)
	{
		free(env[i]);
		i++;
	}
	free(env);
}
/**
 * add_env - string length
 * @env_variable : destination
 * @env : ...
 * Return: Always 0.
 */
int add_env(char **env, char *env_variable)
{
	char **new_env;
	int i;
	int env_count = 0;

	while (env[env_count] != NULL)
	{
		env_count++;
	}
	new_env = malloc((env_count + 2) * sizeof(char *));
	if (new_env == NULL)
	{
		perror("malloc");
		return (1);
	}

	for (i = 0; i < env_count; i++)
	{
		new_env[i] = _strdup(env[i]);
	}
	new_env[env_count] = env_variable;
	new_env[env_count + 1] = NULL;

	free_env(shell_env);

	shell_env = new_env;
	return (0);
}
/**
 * internal_env - string length
 * @ac : pointer
 * @av : destination
 * @env : ...
 * Return: Always 0.
 */

int internal_env(int ac, char **av, char **env)
{
	unsigned int i;

	av = av;
	ac = ac;
	i = 0;
	while (env[i] != NULL)
	{
		_printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
