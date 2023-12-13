#include "simple_shell.h"
/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the previously allocated memory
 * @old_size: Size of the old allocated space
 * @new_size: Size of the new memory block
 *
 * Return: Pointer to the reallocated memory block, or NULL on failure
 */

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (old_size >= new_size)
		return (ptr);

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	memcpy(new_ptr, ptr, old_size);
	free(ptr);

	return (new_ptr);
}
