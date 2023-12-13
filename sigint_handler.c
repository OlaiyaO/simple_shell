#include "simple_shell.h"

/**
 * sigint_handler - Handles the SIGINT signal (Ctrl+C)
 * @sig: Signal number (should be SIGINT for Ctrl+C)
 *
 * Description: Signal handler for Ctrl+C, displays the shell prompt.
 */

void sigint_handler(int sig)
{
	(void) sig;

	PRINT("\nshell$ ");
	fflush(stdout);
}

