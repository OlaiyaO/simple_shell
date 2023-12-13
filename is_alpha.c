#include "simple_shell.h"
#include "string_utils.h"

/**
 * _isalpha - Check if Alphabetic
 * @_char: Character
 * Return: 1 If True, 0 If Not
 */

int _isalpha(int _char)
{
	if ((_char >= 97 && _char <= 122) || (_char >= 65 && _char <= 90))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
