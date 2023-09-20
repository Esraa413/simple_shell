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
	ssize_t ret = 0;
	size_t len_x = 0;

	if (!*len) /* nothing left in the buffer */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		ret = getline(buf, &len_x, stdin);
#else
		ret = _getline(info, buf, &len_x);
#endif
		if (ret > 0)
		{
			if ((*buf)[ret - 1] == '\n')
			{
				(*buf)[ret - 1] = '\0'; /* remove  newline */
				ret--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) command chain? */
			{
				*len = ret;
				info->cmd_buf = buf;
			}
		}
	}
	return (ret);
}

/**
 * get_input - minus the newline to get line
 * @info: parameter
 *
 * Return: always(0
 */

ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t x, y, len;
	ssize_t ret = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	ret = input_buf(info, &buf, &len);
	if (ret == -1)
		return (-1);
	if (len)
	{
		y = x;
		p = buf + x;
		check_chain(info, buf, &y, x, len);
		while (x < len)
		{
			if (is_chain(info, buf, &y))
				break;
			x++;
		}
		x = y + 1;
		if (x >= len)
		{
			x = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_p = p;
		return (_strlen(p));
	}
	*buf_p = buf;
	return (ret);
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
	ssize_t ret = 0;

	if (*i)
	{
		return (0);
	}
	ret = read(info->readfd, buf, READ_BUF_SIZE);
	if (ret >= 0)
		*i = ret;
	return (ret);
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
	static char buf[READ_BUF_SIZE];
	static size_t x, len;
	size_t y;
	ssize_t ret = 0, st = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		st = *length;
	if (x == len)
		x = len = 0;
	ret = read_buf(info, buf, &len);
	if (ret == -1 || (ret == 0 && len == 0))
		return (-1);
	c = _strchr(buf + x, '\n');
	y = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, st, st ? st + y : y + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);
	if (st)
		_strncat(new_p, buf + x, y - x);
	else
		_strncpy(new_p, buf + x, y - x + 1);

	st += y - x;
	x = y;
	p = new_p;

	if (length)
		*length = st;
	*ptr = p;
	return (st);
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
