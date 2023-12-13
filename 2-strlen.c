#include "simple_shell.h"
#include "string_utils.h"

/**
 * _strlen - Function to swap an integerm.
 *
 * Description: This function is the swaps 2 pointers holding.
 *		ineger values..
 * @s: The first integer to be swaped.
 * Return: void (Success)
 */

int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
