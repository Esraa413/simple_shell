#include "shell.h"

/**
 * input_buf - Commands for constrained buffer chains
 * @info: parameter
 * @buf: address of  the buffer
 * @len: address of len a variable
 *
 * Return: always(0)
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	size_t leng = 0;
	ssize_t input = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);

		input = getline(buf, &leng, stdin);
		input = _getline(info, buf, &leng);

		if (input > 0)
		{
			if ((*buf)[input - 1] == '\n')
			{
				(*buf)[input - 1] = '\0';
				input--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = input;
				info->cmd_buf = buf;
			}
		}
	}
	return (input);
}

/**
 * get_input - minus the newline to get line
 * @info: parameter
 *
 * Return: always(0
 */

ssize_t get_input(info_t *info)
{
	static size_t x, y, leng;
	static char *buf;
	ssize_t output = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(-1);
	output = input_buf(info, &buf, &leng);

	if (output == -1)
	{
		return (-1);
	}
	if (leng)
	{
		p = buf + x;
		check_chain(info, buf, &y, x, leng);
		for (y = 0; y < leng; y++)
		{
			if (is_chain(info, buf, &y))
				break;
		}
		x = y + 1;
		if (x >= leng)
		{
			x = leng = 0;
			info->cmd_buf_type = 0;
		}
		*buf_p = p;
		return (_strlen(p));
	}
	*buf_p = buf;
	return (output);
}

/**
 * read_buf - ther function read thr buffer
 * @info: parameter
 * @buf: the  buffer
 * @i: the size
 *
 * Return: always(0)
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t output = 0;

	if (i)
	{
		return (0);
	}
	output = read(info->readfd, buf, 1024);
	if (output)
	{
		*i = output;
	}
	return (output);
}

/**
 * _getline - function that gets the next line from the input bar from STDIN
 * @info: parameter
 * @ptr: address of pointer
 * @length: size of preallocated to length
 *
 * Return: always(0)
 */

int _getline(info_t *info, char **ptr, size_t *length)
{
	static size_t x, leng;
	size_t y, output = 0, j = 0;
	static char buf[1024];
	char *p = NULL, *new_p = NULL;
	char *c;

	p = *ptr;
	if (p && length)
		j = *length;
	if (x == leng)
	{
		x = leng = 0;
	}
	output = read_buf(info, buf, &leng);
	if (output)
		return (-1);
	if (output == 0 && leng == 0)
		return (-1);
	c = strchr(buf + x, '\n');
	y = c ? 1 + (unsigned int)(c - buf) : leng;
	new_p = _realloc(p, j, j ? j + y : y + 1);
	if (!new_p)
	{
		return (p ? free(p), -1 : -1);
	}
	if (j)
		_strncat(new_p, buf + x, y - x);
	else
		_strncpy(new_p, buf + x, y - x + 1);
	j += y - x;
	x = y;
	p = new_p;
	if (length)
		*length = j;
	*ptr = p;
	return (j);
}

/**
 * sigintHandler - function that blocks the ctrl-C
 * @sig_num: The number being signal to
 *
 * Return: always(0
 */

void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
