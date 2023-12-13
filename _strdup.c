#include "simple_shell.h"
#include "string_utils.h"

/**
 * _strdup - Duplicates a string in dynamically allocated memory.
 * @str: The input string.
 *
 * Return: A pointer to the duplicated string.
 *
 * Description: Allocates memory for a new string containing a duplicate
 * of the input string @str. The new string is allocated using malloc, and
 * the caller is responsible for freeing the allocated memory when it is
 * no longer needed. Returns NULL if allocation fails or if @str is NULL.
 */

char *_strdup(char *str)
{
	char *duplicate;

	if (str == NULL)
		return (NULL);

	duplicate = malloc(_strlen(str) + 1);

	if (duplicate == NULL)
		return (NULL);

	_strcpy(duplicate, str);

	return (duplicate);
}
