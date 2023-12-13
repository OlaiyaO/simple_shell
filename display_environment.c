#include "simple_shell.h"
#include "string_utils.h"

/**
 * display_environment - Display environment variables.
 * @cmd: Parsed command.
 * @last_status: Status of the last executed command.
 * Return: Always 0.
 */

int display_environment(__attribute__((unused)) char **cmd,
		__attribute__((unused)) int last_status)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
