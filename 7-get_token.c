#include <stdio.h>
#include "main.h"

/**
 * get_token - string length
 * @delim : ...
 * @str : pointer
 * Return: Always 0.
 */

char *get_token(char *str, const char *delim)
{
	static char *nextToken;
	char *tokenStart = NULL;

	if (str != NULL)
	{
		nextToken = str;
	}
	while (*nextToken != '\0' && _strchr(delim, *nextToken) != -1)
	{
		nextToken++;
	}
	if (*nextToken == '\0')
	{
		return (NULL);
	}

	tokenStart = nextToken;

	while (*nextToken != '\0' && _strchr(delim, *nextToken) == -1)
	{
		nextToken++;
	}
	if (*nextToken != '\0')
	{
		*nextToken = '\0';
		nextToken++;
	}
	return (tokenStart);
}
