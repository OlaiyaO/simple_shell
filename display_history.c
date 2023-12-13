#include "simple_shell.h"

/**
 * display_history - Display history of user input in the simple shell.
 * @command: Parsed command.
 * @last_status: Status of the last executed command.
 * Return: 0 on success, -1 on failure.
 */

int display_history(__attribute__((unused)) char **command,
		__attribute__((unused)) int last_status)
{
	char *filename = ".simple_shell_history";
	FILE *file_pointer;
	char *line_buffer = NULL;
	size_t buffer_size = 0;
	int command_counter = 0;
	char *counter_str;

	file_pointer = fopen(filename, "r");
	if (file_pointer == NULL)
	{
		return (-1);
	}

	for (; getline(&line_buffer, &buffer_size, file_pointer) != -1;
			command_counter++)
	{
		counter_str = _itoa(command_counter);
		PRINT(counter_str);
		free(counter_str);
		PRINT(" ");
		PRINT(line_buffer);
	}

	if (line_buffer)
		free(line_buffer);

	fclose(file_pointer);
	return (0);
}
