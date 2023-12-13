#include "simple_shell.h"

/**
 * search_and_build_path - Search in $PATH for executable command and build
 *			path.
 * @cmd: Parsed Input
 * Return: (1) Failure, (0) Success.
 */

int search_and_build_path(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;
	size_t len;

	path = _getenv("PATH");
	value = _strtok(path, ":");

	while (value != NULL)
	{
		len = _strlen(value) + _strlen(*cmd) + 2;
		cmd_path = malloc(sizeof(char) * len);

		if (!cmd_path)
		{
			free(path);
			perror("unable to allocate memory");
			return (1);
		}

		memset(cmd_path, 0, len);
		_strcat(_strcat(_strcat(cmd_path, value), "/"), *cmd);

		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}

		free(cmd_path);
		value = _strtok(NULL, ":");
	}

	free(path);
	return (1);
}
