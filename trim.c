#include <stdio.h>
#include <string.h>

/**
 * is_whitespace - prints the environment
 * @ch: ...
 * Return: Always 0.
 */
int is_whitespace(int ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r');
}

/**
 * _trim - prints the environment
 * @str: ...
 * Return: Always 0.
 */

char *_trim(char *str)
{
	int i = 0;
	int j;
	int len;

	while (is_whitespace(str[i]))
	{
		i++;
	}
	j = 0;

	while (str[i] != '\0')
	{
		str[j] = str[i];

		i++;
		j++;
	}
	str[j] = '\0';

	len = strlen(str);
	i = len - 1;
	while (i >= 0 && is_whitespace(str[i]))
	{
		i--;
	}
	str[i + 1] = '\0';

	return (str);
}
