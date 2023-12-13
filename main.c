#include "simple_shell.h"
#include "string_utils.h"

/**
 * handle_user_input - Process user input in the shell.
 * @st: The current status of the shell.
 * @counter: Counter for command history.
 * @argv: An array of strings containing the arguments.
 * Return: The exit status of the shell.
 */
int handle_user_input(int st, int counter, char **argv)
{
	int status = 1;
	char *buffer = NULL;
	char **command;

	signal(SIGINT, sigint_handler);

	while (status)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		buffer = _getline();

		if (!buffer)
			break;

		input_history(buffer);
		command = tokenize_input(buffer);

		if (command[0] && *command[0])
		{
			if (is_builtin_command(command) == 0)
				st = handle_builtin_cmd(command, st);
			else if (_strcmp(command[0], "exit") == 0)
			{
				exit_shell(command, buffer, argv, counter);
				free_pointers(command, buffer);
				buffer = NULL;
				break;
			}
			else
				st = handle_executable(command, buffer, counter, argv);
		}

		free_pointers(command, buffer);
		buffer = NULL;
	}

	return (status);
}

/**
 * main - Entry point for the simple shell program.
 * @argc: The number of arguments.
 * @argv: An array of strings containing the arguments.
 * Return: The exit status of the shell.
 */

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	int st = 0, counter = 0;

	if (argv[1])
		execute_commands_from_file(argv[1], argv);

	st = handle_user_input(st, counter, argv);

	return (st);
}

