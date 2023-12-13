#include "simple_shell.h"

/**
 * input_history - Store user input in a history file
 * @user_input: User input string to be stored
 * Return: 0 on success, -1 on failure
 */

int input_history(char *user_input)
{
	char *history_file = ".simple_shell_history";
	ssize_t file_descriptor, bytes_written;
	int input_length = 0;

	if (!history_file)
		return (-1);

	file_descriptor =
		open(history_file, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (file_descriptor < 0)
		return (-1);

	if (user_input)
	{
		while (user_input[input_length])
			input_length++;
		bytes_written = write(file_descriptor, user_input, input_length);
		if (bytes_written < 0)
			return (-1);
	}

	close(file_descriptor);
	return (0);
}
