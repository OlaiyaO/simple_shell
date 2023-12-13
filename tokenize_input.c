#include "simple_shell.h"

/**
 * tokenize_input - Splits input into tokens.
 * @user_input: User input to parse.
 * Return: Array of strings (tokens).
 */

char **tokenize_input(char *user_input)
{
	char **token_array;
	char *token;
	int index, buffer_size = BUFFSIZE;

	if (user_input == NULL)
		return (NULL);

	token_array = malloc(sizeof(char *) * buffer_size);
	if (!token_array)
	{
		perror("simple_shell");
		return (NULL);
	}

	token = _strtok(user_input, "\n ");
	for (index = 0; token; index++)
	{
		token_array[index] = token;
		token = _strtok(NULL, "\n ");
	}
	token_array[index] = NULL;

	return (token_array);
}

