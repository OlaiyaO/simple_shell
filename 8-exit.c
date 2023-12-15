#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * internal_exit - string length
 * @ac : pointer
 * @av : destination
 * @env : ...
 * Return: Always 0.
 */
int internal_exit(int ac, char **av, char **env)
{
    int exit_status = 0;

    (void)ac;
    (void)env;

    if (av[1] != NULL)
    {
        exit_status = _atoi(av[1]);
        if (exit_status == -1)
        {
            fprintf(stderr, "Error: Illegal number: %s\n", av[1]);
            exit_status = 2;
        }
    }

    free_av(av);
    free_env(env);
    free_shell_alias();

    exit(exit_status);
    return (0);
}

