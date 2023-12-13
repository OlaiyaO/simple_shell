#include "simple_shell.h"

/**
 * exit_bul_for_file - Exit Shell Case Of File
 * @command: Parsed Command
 * @line_from_file: Line From A File
 * @file_descriptor: File Descriptor
 * Return: Case Of Exit in A File Line
 */

void handle_exit(char **command, char *line_from_file, FILE *file_descriptor)
{
	int exit_status, i;

	if (command[1] == NULL)
	{
		free(line_from_file);
		free(command);
		fclose(file_descriptor);
		exit(EXIT_SUCCESS);
	}

	for (i = 0; command[1][i]; i++)
	{
		if (!_isalpha(command[1][i]))
		{
			perror("illegal number");
		}
	}

	exit_status = _atoi(command[1]);
	free(line_from_file);
	free(command);
	fclose(file_descriptor);
	exit(exit_status);
}
