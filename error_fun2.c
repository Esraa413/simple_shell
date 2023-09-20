#include "shell.h"

/**
 * _eputs - function that prints the input string
 * @str: the input string
 *
 * Return: always(0)
 */

void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;
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
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
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
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fd, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
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

	if (!str)
		return (0);
	while (*str)
	{
		x += _putfd(*str++, fd);
	}
	return (x);
}
