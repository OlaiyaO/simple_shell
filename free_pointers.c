#include "simple_shell.h"

/**
 * free_pointers - Free Array of Char Pointer and Char Pointer
 * @cmd: Array Pointer
 * @line: Char Pointer
 * Return: Void
 */

void free_pointers(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}
