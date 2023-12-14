#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strcpy - string length
 * @src : pointer
 * @dest : destination
 * @buffer_size : ...
 * Return: Always 0.
 */
int _strcpy(char *dest, const char *src, int buffer_size)
{
	int copied = 0;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;

		if (++copied >= buffer_size)
		{
			break;
		}
	}
	*dest = '\0';

	return (copied);
}

char *_strdup(const char *str)
{
	size_t len;
	char *new_str;

	if (str == NULL)
	{
		return NULL;
	}

	len = _strlen(str);

	new_str = (char *)malloc(len + 1);

	if (new_str == NULL)
	{
		return NULL;
	}

	_strcpy(new_str, str, len);

	return (new_str);
}
