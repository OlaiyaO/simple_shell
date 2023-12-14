#include "simple_shell.h"

/**
 * handle_executable - Execute a command
 * @cmd: Array of strings representing the command and its arguments
 * @input: The input string
 * @c: Counter variable
 * @argv: Command-line arguments
 *
 * Return: 0 on success, -1 on failure
 */

int handle_executable(char **cmd, char *input, int c, char **argv)
{
	int st;
	pid_t process_id;

	if (*cmd == NULL)
	{
		return (-1);
	}

	process_id = fork();
	if (process_id == -1)
	{
		perror("Error");
		return (-1);
	}

	if (process_id == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			search_and_build_path(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_command_not_found_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	wait(&st);
	return (0);
}

