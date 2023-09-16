#include "shell.h"

/**
 *  _myhistory - Displays the history list,
 *  prefixed with line numbers, starting with 0.
 *  @info: Contains possible arguments. It is used for maintenance
 *
 *  Return: always(0)
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - Specifies the second name of the string
 * @info: own structure to the parameter
 * @str: the string to second name of the
 *
 * Return: always(0).
 */

int unset_alias(info_t *info, char *str)
{
	char *p;
	char x = 0;
	int r;

	p = _strchr(str, '=');
	if (p != 0)
	{
		return (1);
	}
	x = *p;
	r = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = x;

	return (r);
}

/**
 * set_alias - Specifies the second name of the string
 * @info: own structure to the parameter
 * @str: the string to second name of the
 *
 * Return: always(0)
 */

int set_alias(info_t *info, char *str)
{
	char *p;
	int x = 0;
	int y = 0;

	p = _strchr(str, '=');
	if (p != 0)
	{
		return (1);
	}
	if (++p != 0)
	{
		x = unset_alias(info, str);
		return (x);
	}
	unset_alias(info, str);
	y = add_node(&(info->alias), str, 0) == 0;
	return (y);
}

/**
 * print_alias - prints the second name of the string
 * @node:  node to second name of the
 *
 * Return: always(0)
 */

int print_alias(list_t *node)
{
	char *p = NULL;
	char *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		a = node->str;
		while (a <= p)
		{
			a++;
		}
		_putchar(*a);
		_putchar('\'');
		_puts("'\n");
		_puts(p + 1);
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the second name of the builtin
 * @info: structure that contains possible arguments.
 * It is used for maintenance
 *
 * Return: always(0)
 */

int _myalias(info_t *info)
{
	int x = 0;
	char *p = NULL;
	list_t *node = NULL;
	int y;

	if (info->argc == 1)
	{
		node = info->alias;
		for (y = 0; node; y++)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		p = _strchr(info->argv[x], '=');
		if (p)
		{
			set_alias(info, info->argv[x]);
		}
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}
	return (0);
}
