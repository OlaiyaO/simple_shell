#include "simple_shell.h"
#include "string_utils.h"

/**
 * is_builtin_command - Check if the command is a built-in.
 *
 * This function checks if the given command is a built-in command by comparing
 * it with the array of built-in commands.
 *
 * @cmd: Command to check.
 * Return: 0 for success (built-in command found), -1 for failure (not found).
 */

int is_builtin_command(char **cmd)
{
	builtin_t *fun = get_builtin_commands();
	int i;

	if (*cmd == NULL)
	{
		return (-1);
	}

	for (i = 0; fun[i].command; i++)
	{
		if (_strcmp(cmd[0], fun[i].command) == 0)
		{
			return (0);
		}
	}

	return (-1);
}
