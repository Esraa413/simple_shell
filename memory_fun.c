#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"

/**
 * bfree - function to free the pointer
 * @p: input
 * Return: return 1 if freed
*/

int bfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
