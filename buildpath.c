#include <stdio.h>
#include <string.h>

/**
 * buildpath - Concatenate two strings
 * @str1: 1st string.
 * @str2: 2nd string.
 * @result: ...
 * @buffer_size: Size of buffer.
 * Return : 0
 */

int buildpath(const char *str1, const char *str2, char *result, size_t buffer_size)
{
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	size_t i, j;

	if (buffer_size <(len1 + len2 + 2))
	{
		fprintf(stderr, "Buffer size is too small for concatenation.\n");
		return (-1);
	}

	for (i = 0; i < len1; i++)
	{
		result[i] = str1[i];
	}

	result[i] = '/';
	i++;

	for (j = 0; j < len2; j++)
	{
		result[i + j] = str2[j];

	}	
	result[i + j] = '\0';
	return ((int)(i + j));
}

