#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * fork_command - prints the environment
 * @lineptr: command-line arguments.
 * @av: argument strings.
 * @env: environment
 * Return: Always 0.
 */

int fork_command(char *lineptr, char **av, char **env)
{
	int status;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		execve(lineptr, av, env);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
