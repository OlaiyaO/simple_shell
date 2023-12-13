#include "simple_shell.h"

/**
 * process_command - Parse and execute a command.
 * @line: Command line.
 * @counter: Line counter.
 * @file: File descriptor.
 * @argv: Program name.
 * Return: Exit status.
 */

int process_command(char *line, int counter, FILE *file, char **argv)
{
	char **cmd_tokens;
	int status = 0;

	cmd_tokens = tokenize_input(line);

	if (is_builtin_command(cmd_tokens))
	{
		if (_strcmp(cmd_tokens[0], "exit") == 0)
		{
			handle_exit(cmd_tokens, line, file);
		}
		else
		{
			status = handle_builtin_cmd(cmd_tokens, status);
		}
	}
	else
	{
		status = handle_executable(cmd_tokens, line, counter, argv);
	}

	free(cmd_tokens);
	return (status);
}
