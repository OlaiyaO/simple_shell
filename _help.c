#include "simple_shell.h"
#include "string_utils.h"

/**
 * _help - Display help for a command.
 * @cmd: Parsed command.
 * @last_status: Status of the last command executed.
 * Return: 0 on success, -1 on failure.
 */

int _help(char **cmd, __attribute__((unused)) int last_status)
{
	int file_descriptor, bytes_written, bytes_read = 1;
	char current_char;

	file_descriptor = open(cmd[1], O_RDONLY);

	if (file_descriptor < 0)
	{
		perror("Error");
		return (0);
	}

	while (bytes_read > 0)
	{
		bytes_read = read(file_descriptor, &current_char, 1);
		bytes_written = write(STDOUT_FILENO, &current_char, bytes_read);

		if (bytes_written < 0)
		{
			return (-1);
		}
	}

	_putchar('\n');
	close(file_descriptor);

	return (0);
}
