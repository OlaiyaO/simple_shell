#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * command_exists - prints the environment
 * @command: command-line arguments.
 * @command_path: argument strings.
 * @env: variable strings
 * Return: Always 0.
 */

int command_exists(const char *command, char *command_path, char **env)
{
	struct stat file_info;
	int status, len;
	char *path;
	const char *token;
	char *path_copy;

	if (_strchr(command, '/') != -1)
	{
		status = stat(command, &file_info);
		if (status == 0)
		{
			return (_strcpy(command_path, command, 512));
		}
	}
	else
	{
		path = _getenv(env, "PATH");
		path_copy = _strdup(path);
		token = get_token(path_copy, ":");
	while (token != NULL)
	{
		len = buildpath(token, command, command_path, 512);
		if (len != -1)
		{
			status = stat(command_path, &file_info);
			if (status == 0)
			{
				free(path_copy);
				return (len);
			}
		}
		token = get_token(NULL, ":");
	}
	free(path_copy);
	}
	return (-1);
}
