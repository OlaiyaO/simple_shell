/*
 * File: 2-strlen.c
 * Author: Oniya Olaiya
 * Description: This returns the length of a string passed in.
 *
 */

#include "simple_shell.h"

/**
 * _strcpy - Function to swap an integerm.
 *
 * Description: This function is the swaps 2 pointers holding.
 *		ineger values..
 * @dest: The first integer to be swaped.
 * @src: The second int.
 * Return: void (Success)
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
