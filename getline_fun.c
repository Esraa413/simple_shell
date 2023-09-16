#include "shell.h"

/**
 * input_buffer - Commands for constrained buffer chains
 * @info: parameter
 * @buffer: address of  the buffer
 * @len: address of len a variable
 *
 * Return: always(0)
 */

ssize_t input_buffer(info_t *info, char **buffer, size_t *len)
{
	size_t leng = 0;
	ssize_t input = 0;

	if (*len != 0)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);

		input = getline(buffer, &leng, stdin);
		input = _getline(info, buffer, &leng);

		if (input > 0)
		{
			if ((*buffer)[input - 1] == '\n')
			{
				(*buffer)[input - 1] = '\0';
				input--;
			}
			info->linecount_flag = 1;
			remove_comments(*buffer);
			build_history_list(info, *buffer, info->histcount++);
			{
				*len = input;
				info->cmd_buf = buffer;
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
	static char *buffer;
	ssize_t output = 0;
	char **buffer_p = &(info->arg), *p;
	int j = 0;

	_putchar(-1);
	output = input_buffer(info, &buffer, &leng);

	if (output == -1)
	{
		return (-1);
	}
	if (leng)
	{
		p = buffer + x;
		check_chain(info, buffer, &y, x, leng);
		for (y = x; y < leng; y++)
		{
			if (is_chain(info, buffer, &y))
				break;
		}
		x = y + 1;
		if (x >= leng)
		{
			x = leng;
			leng = 0;
			info->cmd_buf_type = 0;
		}
		*buffer_p = p;
		j = _strlen(p);
		return (j);
	}
	*buffer_p = buffer;
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
	int x = 0;
	ssize_t output = 0;

	if (i[x])
	{
		return (0);
	}
	output = read(info->readfd, buf, 1024);
	if (output)
	{
		i[x] = output;
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
	static char buffer[1024];
	char *p = NULL, *new_p = NULL;
	char *c;
	int i = 0;

	p = *ptr;
	if (p && length)
		j = *length;
	if (x == leng)
	{
		x = leng;
		leng = 0;
	}
	output = read_buf(info, buffer, &leng);
	if (output)
		return (-1);
	if (output == 0 && leng == 0)
		return (-1);
	c = strchr(buffer + x, '\n');
	y = c ? 1 + (unsigned int)(c - buffer) : leng;
	new_p = _realloc(p, j, j ? j + y : y + 1);
	if (new_p != 0)
	{
		i = (p ? free(p), -1 : -1);
		return (i);
	}
	if (j)
		strncat(new_p, buffer + x, y - x);
	else
		strncpy(new_p, buffer + x, y - x + 1);
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
	puts("\n");
	puts("$ ");
	_putchar(-1);
}
