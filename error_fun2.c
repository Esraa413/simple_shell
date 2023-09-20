#include "shell.h"

/**
 * _eputs - function that prints the input string
 * @str: the input string
 *
 * Return: always(0)
 */

void _eputs(char *str)
{
	int x;

	if (!str)
	{
		return;
	}
	for (x = 0; str[x] != '\0'; x++)
	{
		_eputchar(str[x]);
	}
}

/**
 * _eputchar - Writes the letter c
 * @c: printed character
 *
 * Return: always(0)
 */

int _eputchar(char c)
{
	static int x;
	static char buffer[1024];

	if (c == -1)
	{
		write(2, buffer, x);
		x = 0;
	}
	else if (x >= 1024)
	{
		write(2, buffer, x);
		x = 0;
	}
	if (c != -1)
	{
		buffer[x++] = c;
	}
	return (1);
}

/**
 * _putfd - Writes the letter c in the given fd
 * @c: printed character
 * @fd: The file to be written to
 *
 * Return: always(0)
 */

int _putfd(char c, int fd)
{
	static int x;
	static char buffer[1024];

	if (c == -1)
	{
		write(fd, buffer, x);
		x = 0;
	}
	if (x >= 1024)
	{
		write(fd, buffer, x);
		x = 0;
	}
	if (c != -1)
	{
		buffer[x++] = c;
	}
	return (1);
}

/**
 * _putsfd - function that prints the input string
 * @str: the input string
 * @fd: The file to be written to
 *
 * Return: always(0)
 */

int _putsfd(char *str, int fd)
{
	int x = 0;
	int y;

	if (!str)
	{
		return (0);
	}
	for (y = 0; *str; y++)
	{
		x += _putfd(*str++, fd);
	}
	return (x);

}
