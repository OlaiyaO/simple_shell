#include "simple_shell.h"

/**
 * read_character - Helper function to read a single character from stdin.
 * @current_char: Pointer to the variable where the read character will be
 *		stored.
 * Return: 0 on success, -1 on failure or if the program is terminated.
 */
static int read_character(char *current_char)
{
	int rd = read(STDIN_FILENO, current_char, 1);

	if (rd == 0)
	{
		return (-1);
	}

	if (rd == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}

	return (0);
}

/**
 * _getline - Reads a line of input from the standard input.
 *
 * This function reads characters from the standard input until it encounters
 * a newline character or EOF. It dynamically allocates memory to store the
 * input and adjusts the buffer size as needed. The function also handles
 * the case of reaching the end of the input stream.
 *
 * Return: A pointer to the allocated buffer containing the input line,
 *         or NULL if memory allocation fails or if the program is terminated.
 */
char *_getline(void)
{
	int index = 0;
	int buffsize = BUFFSIZE;
	char current_char;
	char *buffer = malloc(buffsize);

	if (buffer == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (current_char != EOF && current_char != '\n')
	{
		fflush(stdin);

		if (read_character(&current_char) == -1)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[index] = current_char;

		if (buffer[0] == '\n')
		{
			free(buffer);
			return ("\0");
		}
		if (index >= buffsize)
		{
			buffer = _realloc(buffer, buffsize, buffsize + 1);

			if (buffer == NULL)
				return (NULL);
		}
		index++;
	}
	buffer[index] = '\0';
	handle_hashtag(buffer);
	return (buffer);
}
