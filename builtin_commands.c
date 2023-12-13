#include "simple_shell.h"

/**
 * get_builtin_commands - Get the array of built-in commands.
 *
 * Return: Pointer to the array of built-in commands.
 */

builtin_t *get_builtin_commands(void)
{
	static builtin_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};

	return (fun);
}

/**
 * get_command_functions - Get the array of command functions.
 *
 * Return: Pointer to the array of command functions.
 */

builtin_t *get_command_functions(void)
{
	static builtin_t commands[] = {
		{"cd", change_directory},
		{"env", display_environment},
		{"help", _help},
		{"echo", execute_echo},
		{"history", display_history},
		{NULL, NULL}
	};

	return (commands);
}
