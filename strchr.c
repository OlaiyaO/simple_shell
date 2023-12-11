#include <stdio.h>

/**
 * _strchr - string length
 * @str : pointer
 * @ch : ...
 * Return: Always 0.
 */

int _strchr(const char *str, int ch)
{
	const char *start = str;

	while (*str != '\0')
	{
		if (*str == ch)
		{
			return ((int)(str - start));
		}
		str++;
	}

	return (-1);
}

