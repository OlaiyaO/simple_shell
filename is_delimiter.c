#include "simple_shell.h"

/**
 * is_delim - Checks if a character matches any delimiter.
 * @c: Character to check
 * @delim: Delimiter string
 * Return: 1 if c is a delimiter, 0 otherwise
 */

unsigned int is_delim(char c, const char *delim)
{
	unsigned int i = 0;

	while (delim[i] != '\0')
	{
		if (c == delim[i])
			return (1);

		i++;
	}

	return (0);
}
