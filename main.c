#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

/**
<<<<<<< HEAD
 * main - prints the environment
 * @ac: command-line arguments.
 * @av: argument strings.
 * @env: variable strings
 *
 * Return: Always 0.
=======
 * main - Entry point for the simple shell program.
 * @argc: The number of arguments.
 * @argv: An array of strings containing the arguments.
 * Return: The exit status of the shell.
>>>>>>> 4ab5ce3444d3ccb6d4b97537e264eb315034562f
 */
int main(int ac, char **av, char **env)
{
	int rc;
	struct stat file_info;

	env = copy_env(env);

	if (ac > 1 && stat(av[1], &file_info) == 0)
	{
		int fd = open(av[1], O_RDONLY);

		if (fd == -1)
		{

		}
		else
		{
			rc = run_file(ac, av, fd);
		}
<<<<<<< HEAD
	}
	else if (isatty(fileno(stdin)))
	{
		rc = run_command(ac, av, 1);
	}
	else
	{
		rc = run_command(ac, av, 0);
=======

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
>>>>>>> 4ab5ce3444d3ccb6d4b97537e264eb315034562f
	}

	free_env(env);

	return (rc);
}
