#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_env_variable - string length
 * @keyword : pointer
 * @value : destination
 * Return: Always 0.
 */
char *create_env_variable(char *keyword, char *value)
{
	int buffer_length;
	char *buffer;
	int i = 0;

	/**
	 * env string is keyword=value\0
	 */
	buffer_length = _strlen(keyword) + 1 + _strlen(value) + 1;
	buffer = (char *)malloc(sizeof(char) * buffer_length);
	if (buffer == NULL)
	{
		return ((char *)NULL);
	}
	while (*keyword != 0)
	{
		buffer[i++] = *keyword++;
	}
	buffer[i++] = '=';
	while (*value != 0)
	{
		buffer[i++] = *value++;
	}
	buffer[i] = 0;
	return (buffer);
}
/**
 * _setenv - string length
 * @keyword : pointer
 * @value : destination
 * @env : ..
 * Return: Always 0.
 */

int _setenv(char **env, char *keyword, char *value)
{
	int i;
	int j;
	char ch;

	for (i = 0; env[i] != NULL; i++)
	{
		j = 0;
		ch = *(env[i] + j);

		while (keyword[j] != '\0' && ch != '\0')
		{
			if (keyword[j] != ch)
			{
				break;
			}
			j++;
			ch = *(env[i] + j);
			if (ch == '=')
			{
				/**
				 * we match on the environment variable, we need to replace the string
				 * with a keyword=value string
				 */
				char *str = create_env_variable(keyword, value);

				env[i] = str;

				return (0);
			}
		}
	}
	return (-1);
}
/**
 * append_env_variable - string length
 * @keyword : pointer
 * @value : destination
 * @env : ..
 * Return: Always 0.
 */

int append_env_variable(char **env, char *keyword, char *value)
{
	char *str = create_env_variable(keyword, value);

	return (add_env(env, str));
}

/**
 * internal_setenv - string length
 * @ac : pointer
 * @av : destination
 * @env : ...
 * Return: Always 0.
 */

int internal_setenv(int ac, char **av, char **env)
{
	/**
	 * search for the environment variable and update
	 * or extend the array and append at the end
	 * setenv KEYWORD value
	 */

	char *keyword;
	char *value;

	if (ac < 3)
	{
		return (-1);
	}
	keyword = av[1];
	value = av[2];

	if (_setenv(env, keyword, value) == -1)
	{
		return (append_env_variable(env, keyword, value));
	}
	return (0);
}

