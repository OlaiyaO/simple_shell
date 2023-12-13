#include "simple_shell.h"

/**
 * handle_builtin_cmd - Execute the appropriate built-in command.
 *
 * @cmd: Parsed command.
 * @er: Error code.
 * Return: Result of the built-in command execution.
 */

int handle_builtin_cmd(char **cmd, int er)
{
	builtin_t *commands = get_command_functions();
	int i;

	for (i = 0; commands[i].command; i++)
	{
		if (_strcmp(cmd[0], commands[i].command) == 0)
		{
			return (commands[i].fun(cmd, er));
		}
	}

	return (-1);
}
