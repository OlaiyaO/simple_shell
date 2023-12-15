#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
 * internal_cd - Change the current directory of the process.
 * @ac: Argument count.
 * @av: Argument vector.
 * @env: Environment variables.
 *
 * Return: 0 on success, -1 on failure.
 */
int internal_cd(int ac, char **av, char **env)
{
    char *new_dir;
    char *current_dir;

    if (ac == 1 || (ac == 2 && strcmp(av[1], "~") == 0))
    {
        new_dir = _getenv(env, "HOME");
    }
    else if (ac == 2 && strcmp(av[1], "-") == 0)
    {
        new_dir = _getenv(env, "OLDPWD");
    }
    else
    {
        new_dir = av[1];
    }

    if (new_dir == NULL)
    {
        perror("cd");
        return (-1);
    }

    current_dir = getcwd(NULL, 0);

    if (chdir(new_dir) == -1)
    {
        perror("cd");
        free(current_dir);
        return (-1);
    }

    _setenv(env, "OLDPWD", current_dir);

    free(current_dir);

    current_dir = getcwd(NULL, 0);
    _setenv(env, "PWD", current_dir);

    free(current_dir);

    return (0);
}
