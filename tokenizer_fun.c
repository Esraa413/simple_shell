#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"

/**
 * **strtow - function to split a string into words
 * @str: the input string
 * @d: the delimeter string
 * Return: returns strings or NULL on failure
*/

char **strtow(char *str, char *d)
{
	int x, y, m, n, num = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			num++;

	if (num == 0)
		return (NULL);
	s = malloc((1 + num) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < num; y++)
	{
		while (is_delim(str[x], d))
			x++;
		n = 0;
		while (!is_delim(str[x + n], d) && str[x + n])
			n++;
		s[y] = malloc((n + 1) * sizeof(char));
		if (!s[y])
		{
			for (n = 0; n < y; n++)
				free(s[n]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < n; m++)
			s[y][m] = str[x++];
		s[y][m] = 0;
	}
	s[y] = NULL;
	return (s);
}

/**
 * **strtow2 - function to split a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: returns strings or NULL on failure
*/

char **strtow2(char *str, char d)
{
	int x, y, m, n, num = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
			num++;
	if (num == 0)
		return (NULL);
	s = malloc((1 + num) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < num; y++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		n = 0;
		while (str[x + n] != d && str[x + n] && str[x + n] != d)
			n++;
		s[y] = malloc((n + 1) * sizeof(char));
		if (!s[y])
		{
			for (n = 0; n < y; n++)
				free(s[n]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < n; m++)
			s[y][m] = str[x++];
		s[y][m] = 0;
	}
	s[y] = NULL;
	return (s);
}

