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
	int x, y;
	char *s = dest;

	for (x = 0; src[x] != '\0' && x < n - 1; x++)
	{
		dest[x] = src[x];
	}
	if (x < n)
	{
		for (y = x; y < n; y++)
		{
			dest[y] = '\0';
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
	int x, y;
	char *s = dest;

	x = 0;
	y = 0;
	for (x = 0; dest[x] != '\0'; x++)
		;
	for (y = 0; src[y] != '\0' && y < n; y++)
	{
		dest[x] = src[y];
		x++;
	}
	if (y < n)
	{
		dest[x] = '\0';
	}
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
		{
			return (s);
		}
	} while (*s++ != '\0');

	return (NULL);
}
