#include "simple_shell.h"

/**
 * _strtok - Retrieves the next token from a string.
 * @str: String
 * @delim: Delimiter
 * Return: Pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *token_start, *next_token;
	unsigned int i;

	if (delim == NULL || (str == NULL && next_token == NULL))
		return (NULL);

	if (str != NULL)
		next_token = str;

	token_start = next_token;

	while (token_start != NULL &&
			(*token_start != '\0' && is_delim(*token_start, delim) == 1))
		token_start++;

	if (token_start == NULL || *token_start == '\0' || *token_start == '#')
	{
		next_token = NULL;
		return (NULL);
	}

	next_token = token_start;

	for (i = 0; next_token[i] != '\0'; i++)
	{
		if (is_delim(next_token[i], delim) == 1)
			break;
	}

	if (next_token[i] == '\0')
		next_token = NULL;
	else
	{
		next_token[i] = '\0';
		next_token = next_token + i + 1;
		if (*next_token == '\0')
			next_token = NULL;
	}

	return (token_start);
}
