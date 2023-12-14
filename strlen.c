#include <stdio.h>

/**
 * _strlen - string length
 * @str : pointer
 * Return: Always 0.
 */

size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
	length++;
	}

	return (length);
}
