#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"

/**
 * _strlen - function to return the lenght of string
 * @s: input string
 * Return: returns int of lenght
*/

int _strlen(char *s)
{
	int x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;
	return (x);
}

/**
 * _strcmp - function to compare two strangs
 * @s1: input string
 * @s2: input string
 * Return: returns if s1 < s2 return negative
 *	if s1 > s2 return postive, if s1 = s2 return 0
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - function to cheak starts with haystack
 * @haystack: input
 * @needle: input
 * Return: returns void
*/

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - function to concatente
 * @dest: input
 * @src: input
 * Return: returns pointer buffer
*/

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
