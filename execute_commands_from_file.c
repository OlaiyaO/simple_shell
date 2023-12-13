#include "simple_shell.h"

/**
 * execute_commands_from_file - Read commands from a file and execute them.
 * @filename: Filename of the file containing commands.
 * @argv: Program name.
 * Return: Exit status.
 */

int execute_commands_from_file(char *filename, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	int line_counter = 0;
	int exit_status = 0;

	file = fopen(filename, "r");

	if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}

	for (line_counter = 1; getline(&line, &len, file) != -1; line_counter++)
	{
		exit_status = process_command(line, line_counter, file, argv);
	}

	if (line)
		free(line);

	fclose(file);
	return (exit_status);
}
