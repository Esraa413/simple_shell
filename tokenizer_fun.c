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
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
	{
		return (NULL);
	}
	if (!d)
	{
		d = " ";
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
		{
			numwords++;
		}
		i++;
	}

	if (numwords == 0)
	{
		return (NULL);
	}
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
	{
		return (NULL);
	}
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		for (k = 0; !is_delim(str[i + k], d) && str[i + k]; k++)
			;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			k = 0;
			while (k < j)
			{
				free(s[k]);
				k++;
			}
			free(s);
			return (NULL);
		}
		m = 0;
		while (m < k)
		{
			s[j][m] = str[i++];
			m++;
		}
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - function to split a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: returns strings or NULL on error
*/

char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
		{
			numwords++;
		}
		i++;
	}
	if (numwords == 0)
	{
		return (NULL);
	}
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
	{
		return (NULL);
	}
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			k = 0;
			while (k < j)
			{
				free(s[k]);
				k++;
			}
			free(s);
			return (NULL);
		}
		m = 0;
		while (m < k)
		{
			s[j][m] = str[i++];
			m++;
		}
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
