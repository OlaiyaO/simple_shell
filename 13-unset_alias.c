#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * unset_alias ...
 * @alias : ..
 * Return: Always 0.
 */
int unset_alias( char *keyword)
{
	int i;
	int j;
	int k;
	char ch;
	char **alias = get_shell_alias();

	for (i = 0; alias[i] != NULL; i++)
	{
		j = 0;
		ch = *(alias[i] + j);

		while (keyword[j] != '\0' && ch != '\0')
		{
			if (keyword[j] != ch)
			{
				break;
			}
			j++;
			ch = *(alias[i] + j);
			if (ch == '=')
			{
				free(alias[i]);
				alias[i] = NULL;

				k = i + 1;
				while (alias[k] != NULL)
				{
					alias[k - 1] = alias[k];
					k++;
				}
				alias[k - 1] = NULL;
				return (0);
			}
		}
	}
	return (-1);
}

