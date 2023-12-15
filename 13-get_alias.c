#include <stdio.h>
#include "main.h"
/**
 * _getalias - string length
 * @keyword : pointer
 * Return: Always 0.
 */

char *_getalias(const char *keyword)
{
	int j;
	char ch;
	char **alias = get_shell_alias();

	if (alias == NULL)
	{
		return (NULL);
	}

	for (; *alias != NULL; alias++)
	{
		j = 0;
		ch = *(*alias + j);
		while (keyword[j] != '\0' && ch != '\0')
		{

			if (keyword[j] != ch)
			{
				break;
			}
			j++;
			ch = *(*alias + j);
			if (ch == '=')
			{
				return (*alias + j + 1);
			}
		}
	}
	return (NULL);
}
