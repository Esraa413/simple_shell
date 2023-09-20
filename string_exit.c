#include "shell.h"

/**
 * _strncpy - copy the string
 * @dest: Destination string to be copied to
 * @src: Source string
 * @n: Number of characters to be copied
 *
 * Return: always(0)
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - It connects two chains
 * @dest: first string
 * @src: second string
 * @n: The amount of bytes to use to the maximum
 *
 * Return: always(0)
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * _strchr - Specifies the location of a character in a string
 * @s: String to parse
 * @c: character to looking for
 *
 * Return: always(0)
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
