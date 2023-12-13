#include "simple_shell.h"

/**
 * change_directory - Change the current working directory.
 * @cmd: Parsed command.
 * @last_status: Status of the last executed command.
 * Return: 0 on success, 1 on failure.
 */
int change_directory(char **cmd, __attribute__((unused))int last_status)
{
	int result = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		result = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		result = chdir(getenv("OLDPWD"));
	}
	else
		result = chdir(cmd[1]);

	if (result == -1)
	{
		perror("shell");
		return (-1);
	}
	else if (result != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

