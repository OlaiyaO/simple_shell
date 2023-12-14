#include "simple_shell.h"
#include "string_utils.h"

/**
 * main - Entry point for the simple shell program.
 * @argc: The number of arguments.
 * @argv: An array of strings containing the arguments.
 * Return: The exit status of the shell.
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	int count = 0, statue = 1, st = 0;
	char *buffer = NULL;

	if (argv[1] != NULL)
		execute_commands_from_file(argv[1], argv);

	signal(SIGINT, sigint_handler);

	while (statue)
	{
		count++;

		if (isatty(STDIN_FILENO))
			display_prompt();

		buffer = get_user_input();

		if (buffer[0] == '\0')
		{
			free(buffer);
			continue;
		}

		process_user_command(buffer, st, count, argv);

		free(buffer);
	}

	return (statue);
}

/**
 * get_user_input - Reads user input from standard input.
 * Return: A dynamically allocated string containing the user input.
 */

char *get_user_input(void)
{
	char *buffer = _getline();

	return (buffer);
}

/**
 * process_user_command - Processes the user command.
 * @buffer: User input.
 * @st: Pointer to the shell status.
 * @count: Command count.
 * @argv: Command line arguments.
 */

void process_user_command(char *buffer, int st, int count, char **argv)
{
	char **command = NULL;

	input_history(buffer);
	command = tokenize_input(buffer);

	if (_strcmp(command[0], "exit") == 0)
	{
		exit_shell(command, buffer, argv, count);
	}
	else if (is_builtin_command(command) == 0)
	{
		st = handle_builtin_cmd(command, st);
	}
	else
	{
		st = handle_executable(command, buffer, count, argv);
	}

	free_pointers(command, buffer);
}

