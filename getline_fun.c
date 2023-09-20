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
	ssize_t r = 0;
	size_t len_x = 0;

	if (!*len) /*if  nothing left in  buffer, fill */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_x, stdin);
#else
		r = _getline(info, buf, &len_x);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0'; /* remove  newline */
				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is command chain? */
			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * get_input - minus the newline to get line
 * @info: parameter
 *
 * Return: always(0
 */

ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command  buffer */
	static size_t x, y, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /*EOF*/
		return (-1);
	if (len) /* we have commands left in chain buffer */
	{
		y = x; /* init iterator to current buffer position */
		p = buf + x; /* get pointer to return */
		check_chain(info, buf, &y, x, len);
		while (x < len)
		{
			if (is_chain(info, buf, &y))
				break;
			x++;
		}
		x = y + 1; /* increment  nulled ';'' */
		if (x >= len) /* reached end of buffer? */
		{
			x = len = 0; /* reset posit and length */
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_p = p; /* pass back  a pointer to current command posit */
		return (_strlen(p)); /* return length of a current */
	}
	*buf_p = buf; /* else not chain,  back buffer from  a _getline() */
	return (r); /* return length a buffer from  a _getline() */
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
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
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
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (x == len)
		x = len = 0;
	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + x, '\n');
	y = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + y : y + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);
	if (s)
		_strncat(new_p, buf + x, y - x);
	else
		_strncpy(new_p, buf + x, y - x + 1);

	s += y - x;
	x = y;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
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
