#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "shell.h"

/**
 *  is_chain - function to test if current char in buffer
 *	is a chain delimeter
 * @info: input
 * @buf: buffer
 * @p: address
 * Return: 1 if success, 0 otherwise
*/

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t y = *p;

	if (buf[y] == '|' && buf[y + 1] == '|')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[y] == '&' && buf[y + 1] == '&')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[y] == ';')
	{
		buf[y] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = y;
	return (1);
}

/**
 * check_chain - function to check we should continue
 *	chaining based on last status
 * @info: input
 * @buf: buffer
 * @p: address of buffer
 * @x: starting buffer
 * @len: the length of buffer
 * Return: Void
*/

void check_chain(info_t *info, char *buf, size_t *p, size_t x, size_t len)
{
	size_t y = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[x] = 0;
			y = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[x] = 0;
			y = len;
		}
	}

	*p = y;
}

/**
 * replace_alias - function to replace an aliases in the tokenized string
 * @info: input
 * Return: 1 if replaced, 0 otherwise
*/

int replace_alias(info_t *info)
{
	int x;
	list_t *node;
	char *p;

	for (x = 0; x < 10; x++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - function to replace vars in the tokenized string
 * @info: input
 * Return: 1 if replaced, 0 otherwise
*/

int replace_vars(info_t *info)
{
	int x = 0;
	list_t *node;

	for (x = 0; info->argv[x]; x++)
	{
		if (info->argv[x][0] != '$' || !info->argv[x][1])
			continue;

		if (!_strcmp(info->argv[x], "$?"))
		{
			replace_string(&(info->argv[x]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[x], "$$"))
		{
			replace_string(&(info->argv[x]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[x][1], '=');
		if (node)
		{
			replace_string(&(info->argv[x]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[x], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - function to replace string
 * @old: old string
 * @new: new string
 * Return: 1 if replaced, 0 otherwise
*/

int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

