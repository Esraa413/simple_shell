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
	int x;

	for (x = 0; delim[x] != '\0'; x++)
	{
		if (delim[x] == c)
			return (1);
	}
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
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
		return (0);
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
		return (0);

	putchar ('\n');
}

/**
 * _atoi - Converts a string into an integer
 * @s: string to converted
 *
 * Return: always(0)
 */

int _atoi(char *s)
{
	int st = 0;
	int code = 1, fl = 0;
	int end;
	unsigned int resu = 0;

	while (s[st] != '\0')
	{
		if (s[st] == '-')
			code = -1;
		if (s[st] >= '0' && s[st] <= '9')
		{
			fl = 1;
			resu *= 10;
			resu += (s[st] - '0');
		}
		else if (fl == 1)
		{
			fl = 2;
		}
		st++;
	}
	if (code == -1)
		end = -resu;
	else
		 end = resu;

	return (end);
}
