#include "simple_shell.h"

/**
 * execute_echo - Execute various cases for the echo command.
 * @cmd: Parsed command.
 * @last_status: Status of the last executed command.
 * Return: Always 0 or execute normal echo.
 */

int execute_echo(char **cmd, int last_status)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_int(last_status);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_unsigned_int(pid);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}
	else
	{
		return (perform_echo(cmd));
	}

	return (1);
}

/**
 * print_unsigned_int - Print Unsigned Integer using _putchar
 * @n: Unsigned Integer
 * Return: Void
 */

void print_unsigned_int(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_unsigned_int(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * print_int - Print Integer using _putchar
 * @n: Integer
 * Return: Void
 */

void print_int(int n)
{
	unsigned int x = (n < 0) ? -n : n;

	if (n < 0)
		_putchar('-');

	if ((x / 10) > 0)
		print_unsigned_int(x / 10);

	_putchar(x % 10 + '0');
}
