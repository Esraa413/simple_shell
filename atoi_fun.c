#include "shell.h"

/**
 * interactive - returns shell interactive mode
 * @info: the struct address to sell
 *
 * Return: always(0)
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Check if character is specified
 * @c: character to check
 * @delim: specified string
 *
 * Return: always(0)
 */

int is_delim(char c, char *delim)
{
<<<<<<< HEAD
	int x;

	for (x = 0; *delim; x++)
	{
=======
	while (*delim)
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - alphabetic character
 * @c: The input character
 *
 * Return: always(0)
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
<<<<<<< HEAD
	{
=======
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
		return (1);
	else
	{
		return (0);
	}
}

/**
 * _atoi - Converts a string into an integer
 * @s: string to converted
 *
 * Return: always(0)
 */

int _atoi(char *s)
{
	int x, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (x = 0; s[x] != '\0' && flag != 2; x++)
	{
		if (s[x] == '-')
			sign *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[x] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
