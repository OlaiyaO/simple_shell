#include <stdio.h>
#include <string.h>

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

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r')
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
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'))
	{
		i--;
	}
	str[i + 1] = '\0';

	return str;
}
