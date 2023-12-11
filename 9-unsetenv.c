#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int unset_env_variable(char **env, char *keyword)
{
	int i;
	int j;
	int k;
        char ch;

	for (i = 0; env[i] != NULL; i++)
        {
                j = 0;
                ch = *(env[i] + j);
                while (keyword[j] != '\0' && ch != '\0')
                {
                        if (keyword[j] != ch)
                        {
                                break;
                        }
                        j++;
                        ch = *(env[i] + j);
                        if (ch == '=')
			{
				free(env[i]);
				env[i] = NULL;

				k = i + 1;
				while( env[k] != NULL)
				{
					env[k-1] = env[k];
					k++;
				}
				env[k-1] = NULL;
				return(0);
                        }
                }
	}
	return (-1);
}

/**
 * internal_unsetenv - string length
 * @ac : pointer
 * @av : destination
 * @env : ...
 * Return: Always 0.
 */

int internal_unsetenv(int ac, char **av, char **env)
{
	char *keyword;
	
	if (ac < 2) 
	{
		return (-1);
	}
        keyword = av[1];

	return (unset_env_variable(env, keyword));
}
