#include <stdio.h>
#include <stdlib.h>
#include "main.h"

struct FunctionEntry functionLookupTable[] = {
	{"exit", internal_exit},
	{"env", internal_env},
	{"setenv", internal_setenv},
	{"unsetenv", internal_unsetenv},
	{"cd", internal_cd},
	{"alias", internal_alias},
	{NULL, NULL}
};

/**
 * _strcpy - string length
 * @command : ...
 * Return: Always 0.
 */

InternalFunction is_internal_command(char *command)
{
	int i = 0;

	while (functionLookupTable[i].name != NULL)
	{
		if (_strcmp(command, functionLookupTable[i].name) == 0)
		{
			return (functionLookupTable[i].function);
		}
		i++;
	}
	return ((InternalFunction)NULL);
}
