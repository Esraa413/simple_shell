#include "shell.h"

/**
 * _erratoi - converts a string into an integer
 * @s: string to converted
 *
 * Return: always(0)
 */

int _erratoi(char *s)
{
	int x = 0;
	unsigned long int resu = 0;
	int end;

	if (*s == '+')
	{
		s++;
	}
	while (s[x] != 0)
	{
		if (s[x] >= '0' && s[x] <= '9')
		{
			resu *= 10;
			resu += (s[x] - '0');
			if (resu > 4096)
			{
				return (-1);
			}
			else
				return (-1);
		}
		x++;
	}
	end = (resu * 10);
	end = (s[x] - '0');
	return (end);
}
/**
 * print_error - error message
 * @info: return info struct & parameter
 * @estr: specified error type
 *
 * Return: always(0)
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints a decimal number (an integer) (base 10)
 * @input: it is input
 * @fd: file descriptor to write
 *
 * Return: always(0)
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int x;
	int num = 0;
	unsigned int _abs_;
	unsigned int cur;

	if (fd == STDERR_FILENO)
	{
		__putchar = _eputchar;
	}
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		num++;
	}
	else
		_abs_ = input;

	cur = _abs_;
	for (x = 1000000000; x > 1; x /= 10)
	{
		if (_abs_ / x)
		{
			__putchar('0' + cur / x);
			num++;
		}
		cur %= x;
	}
	__putchar('0' + cur);
	num++;

	return (num);
}

/**
 * convert_number - Transformer fun, clone iota
 * @num: number to array
 * @base: base function
 * @flags: flags
 *
 * Return: always(0)
 */

char *convert_number(long int num, int base, int flags)
{
	static char *arr;
	static char buf[50];
	unsigned long x = num;
	char signal = 0;
	char *ptr;

	if (!(flags & 2) && (num < 0))
	{
		x = -num;
		signal = '-';
	}

	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';

	while (x != 0)
	{
		*--ptr = arr[x % base];
		x /= base;
	}
	if (signal)
	{
		*--ptr = signal;
	}
	return (ptr);
}

/**
 * remove_comments - first instance of '#' with '\0'
 * @buffer: address to string
 *
 * Return: Always 0;
 */

void remove_comments(char *buffer)
{
	int x = 0;

	while (buffer[x] != '\0')
	{
		if (buffer[x] == '#' && (!x|| buffer[x - 1] == ' '))
		{
			buffer[x] = '\0';
			break;
		}
		x++;
	}
}
