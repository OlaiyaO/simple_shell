#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * handle_zero - integer to a string.
 * Return: result.
 */
char *handle_zero(void)
{
	char *result;

	result = (char *)malloc(2);
	if (result != NULL)
	{
		result[0] = '0';
		result[1] = '\0';
	}
	return (result);
}
/**
 * count_digits - integer to a string.
 * @number: integer to convert.
 *
 * Return: result.
 */
int count_digits(int number)
{
	int digitCount;
	int temp;

	temp = number;
	digitCount = 0;
	while (temp > 0)
	{
		temp /= 10;
		digitCount++;
	}
	return (digitCount);
}
/**
 * _itoa - integer to a string.
 * @number: integer to convert.
 *
 * Return: result.
 */
char *_itoa(int number)
{
	char *result;
	bool isNegative;
	int digitCount;
	int index;

	if (number == 0)
	{
		return (handle_zero());
	}
	isNegative = false;
	if (number < 0)
	{
		isNegative = true;
		number = -number;
	}

	digitCount = count_digits(number);

	result = (char *)malloc(digitCount + (isNegative ? 2 : 1));

	if (result != NULL)
	{
		index = digitCount + (isNegative ? 1 : 0);
		result[index] = '\0';

		while (number > 0)
		{
			index--;
			result[index] = '0' + (number % 10);
			number /= 10;
		}
		if (isNegative)
		{
			result[0] = '-';
		}
	}
	return (result);
}
