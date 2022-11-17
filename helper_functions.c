#include "shell.h"

/**
 * _realloc - function reallocstes memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: size of the allocated memory
 * @new_size: new size of the new memory block
 * Return: ptr if new_size == old_size
 * NULL if new_size==0
 * otherwise a pointer to the new size
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	void *nptr;
	char *appoint;
	char *ptr2;

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		nptr = malloc(new_size);
		if (nptr == NULL)
		{
			return (NULL);
		}
		return (nptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr2 = ptr;
	nptr = malloc(sizeof(*ptr2) * new_size);
	if (nptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	appoint = nptr;
	for (i = 0; i < new_size && i < old_size; i++)
	{
		appoint[i] = *ptr2++;
	}
	free(ptr);
	return (nptr);
}
