#include "simple_shell.h"

/**
 * read_character - Helper function to read a single character from stdin.
 * Return: The character read.
 */

static char read_character(char *buffer)
{
	char current_char;
	int read_status = read(STDIN_FILENO, &current_char, 1);

	if (read_status == 0)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	return (current_char);
}

/**
 * _getline - Read input from stdin.
 * Return: Input string.
 */

char *_getline()
{
	int index = 0, buffer_size = BUFFSIZE;
	char *buffer = malloc(buffer_size);
	char current_char;

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	current_char = read_character(buffer);

	while (current_char != EOF && current_char != '\n')
	{
		buffer[index] = current_char;

		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}

		if (index >= buffer_size - 1)
		{
			buffer = _realloc(buffer, buffer_size, buffer_size + 1);
			if (buffer == NULL)
			{
				return (NULL);
			}
		}

		index++;
		current_char = read_character(buffer);
	}

	buffer[index] = '\0';
	handle_hashtag(buffer);
	return (buffer);
}
