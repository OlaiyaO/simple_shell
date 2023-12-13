/*
 * File: 0-main.c
 * Author: Oniya Olaiya
 */

#include "simple_shell.h"

/**
 * _strcat - Concatenates tw strings.
 *
 * Description: This function is the entry point for the program.
 *		It calls the print_sign function to do the checks.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the resulting string 'dest'
 */

char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int i;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
