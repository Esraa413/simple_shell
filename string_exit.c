#include "shell.h"

/**
 * _strchr - Specifies the location of a character in a string
 * @s: String to parse
 * @c: character to looking for
 *
 * Return: always(0)
 */

char *_strchr(char *s, char c)
{
	int x;

	for (x = 0; s[x] != '\0'; x++)
	{
		if (s[x] == c)
			return (s);
	}
	if (c == 0)
	{
		return (s);
	}

	return (NULL);
}

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
	char *s = dest;
	int x = 0;
	int y;

	for (x = 0; src[x] != '\0' && x < n - 1; x++)
	{
		dest[x] = src[x];
	}
	if (x < n)
	{
		for (y = x; y < n;  y++)
			dest[y] = '\0';
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
	char *s = dest;
	int x;
	int y = 0;

	for (x = 0; dest[x] != '\0'; x++)
		;

	while (src[y] != '\0' && y < n)
	{
		dest[y] = src[y];
		x++;
		y++;
	}
	if (y < n)
	{
		dest[x] = '\0';
	}
	return (s);

}
