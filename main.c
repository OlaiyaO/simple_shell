#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

/**
 * main - prints the environment
 * @ac: command-line arguments.
 * @av: argument strings.
 * @env: variable strings
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	int rc;
	struct stat file_info;

	env = copy_env(env);

	if (ac > 1 && stat(av[1], &file_info) == 0)
	{
		int fd = open(av[1], O_RDONLY);

		if (fd == -1)
		{

		}
		else
		{
			rc = run_file(ac, av, fd);
		}
	}
	else if (isatty(fileno(stdin)))
	{
		rc = run_command(ac, av, 1);
	}
	else
	{
		rc = run_command(ac, av, 0);
	}

	free_env(env);

	return (rc);
}
