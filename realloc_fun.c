#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"

/**
 * _memset - function to fill memory
 * @s: input pointer to memory
 * @b: input byte
 * @n: input amount of bytes
 * Return: returns s pointer to memory
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}

/**
 * ffree - function to free string
 * @pp: input string
 * Return: void
*/

void ffree(char **pp)
{
	char **y = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(y);
}

/**
 * _realloc - function to reallocate a block of memory
 * @ptr: input pointer
 * @old_size: byte old size
 * @new_size: byte new size
 * Return: returns pointer
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *z;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);
	z = malloc(new_size);
	if (!z)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		z[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (z);
}
