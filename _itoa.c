#include "simple_shell.h"

/**
 * _itoa - Convert Integer To Char
 * @num: Integer To Convert
 * Return: Char Pointer
 */

char *_itoa(unsigned int num)
{
	int length = 0, index;
	char tmp, *result;
	unsigned int original_num = num;

	while (num != 0)
	{
		length++;
		num /= 10;
	}

	result = malloc(length + 1);

	if (!result)
		return (NULL);

	*result = '\0';

	for (index = 0; index < (length / 2); index++)
	{
		tmp = result[index];
		result[index] = result[(length - 1) - index];
		result[(length - 1) - index] = tmp;
	}

	num = original_num;
	for (index = 0; num > 0; index++)
	{
		result[index] = (num % 10) + '0';
		num /= 10;
	}

	result[index] = '\0';

	return (result);
}
