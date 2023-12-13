#include "simple_shell.h"
#include "string_utils.h"

/**
 * print_execution_error - Print an error message for command execution.
 * @command: The name of the command that failed to execute.
 * @line_counter: The line counter value.
 * @arguments: Array of command-line arguments.
 */

void print_command_not_found_error(
	char *command,
	int line_counter,
	char **arguments
)
{
	char *line_counter_str = _itoa(line_counter);

	PRINT(arguments[0]);
	PRINT(": ");
	PRINT(line_counter_str);
	PRINT(": ");
	PRINT(command);
	PRINT(": not found\n");

	free(line_counter_str);
}

/**
 * print_illegal_number_error - Print an error message for an
 *				illegal number in a command.
 * @program_name: Name of the program.
 * @counter: Counter value.
 * @command: Name of the command.
 * @illegal_number: The specific illegal number.
 */

void print_illegal_number_error(
	char **arguments,
	int counter,
	char **command
)
{
	char *counter_str = _itoa(counter);

	PRINT(arguments[0]);
	PRINT(": ");
	PRINT(counter_str);
	PRINT(": ");
	PRINT(command[0]);
	PRINT(": Illegal number: ");
	PRINT(command[1]);
	PRINT("\n");

	free(counter_str);
}
