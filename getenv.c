#include <stdio.h>

/**
 * _getenv - string length
 * env: ...
 * @keyword : pointer
 * Return: Always 0.
 */

char *_getenv(char **env, const char *keyword)
{
	int j;
	char ch;

	for (; *env != NULL; env++)
	{
		j = 0;
		ch = *(*env + j);
		while (keyword[j] != '\0' && ch != '\0')
		{

			if (keyword[j] != ch)
			{
				break;
			}
			j++;
			ch = *(*env + j);
			if (ch == '=')
			{
				return (*env + j + 1);
			}
		}
	}
	return (NULL);
}
