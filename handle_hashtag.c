#include "simple_shell.h"

/**
 * handle_hashtag - Remove everything after # in the input string
 *		using a while loop.
 * @buff: Input string.
 * Return: void.
 */

void handle_hashtag(char *buff)
{
	int i = 0;

	while (buff[i] != '\0' && buff[i] != '#')
	{
		i++;
	}

	buff[i] = '\0';
}
