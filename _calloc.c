#include "simple_shell.h"

/**
 * _calloc - Allocates Memory for an Array, Using Malloc.
 * @nmemb: Number of elements
 * @size: Size of each element
 * Return: Void Pointer
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *array;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	array = malloc(nmemb * size);

	if (array == NULL)
		return (NULL);

	i = 0;
	while (i < nmemb * size)
	{
		array[i] = '\0';
		i++;
	}

	return (array);
}
