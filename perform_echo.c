#include "simple_shell.h"

/**
 * perform_echo - Execute the echo command.
 * @echo_args: Parsed command arguments.
 * Return: 0 on success, -1 on failure.
 */

int perform_echo(char **echo_args)
{
	pid_t process_id;
	int process_status;

	process_id = fork();

	if (process_id == 0)
	{
		if (execve("/bin/echo", echo_args, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (process_id < 0)
	{
		return (-1);
	}
	else
	{
		while (!WIFEXITED(process_status) && !WIFSIGNALED(process_status))
		{
			waitpid(process_id, &process_status, WUNTRACED);
		}
	}

	return (1);
}
