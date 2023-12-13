#include "simple_shell.h"
#include "string_utils.h"

/**
 * exit_shell - Custom Exit Statue Shell
 * @cmd_array: Parsed Command
 * @user_input: User Input
 * @program_argv: Program Name
 * @execution_count: Execute Count
 * Return: Void (Exit Statue)
 */

void exit_shell(
	char **cmd_array,
	char *user_input,
	char **program_argv,
	int execution_count
)
{
	int exit_status, i;

	if (cmd_array[1] == NULL)
	{
		free(user_input);
		free(cmd_array);
		exit(EXIT_SUCCESS);
	}

	for (i = 0; cmd_array[1][i]; i++)
	{
		if (_isalpha(cmd_array[1][i]) != 0)
		{
			print_illegal_number_error(program_argv, execution_count, cmd_array);
			break;
		}
		else
		{
			exit_status = _atoi(cmd_array[1]);
			free(user_input);
			free(cmd_array);
			exit(exit_status);
		}
	}
}
