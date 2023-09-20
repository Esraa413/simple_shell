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
<<<<<<< HEAD
	char *p;
	char x;
	int r;
=======
	char *p, c;
	int ret;
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b

	p = _strchr(str, '=');
	if (!p)
		return (1);
<<<<<<< HEAD
	}
	x = *p;
	*p = 0;
	r = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = x;

	return (r);
=======
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
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

	p = _strchr(str, '=');
	if (!p)
		return (1);
<<<<<<< HEAD
	}
	if (!++p)
	{
		return (unset_alias(info, str));
	}
=======
	if (!*++p)
		return (unset_alias(info, str));

>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
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
<<<<<<< HEAD
		a = node->str;
		while (a <= p)
		{
			a++;
		}
=======
		for (a = node->str; a <= p; a++)
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
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
	int h = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
<<<<<<< HEAD
	while ( info->argv[x])
=======
	for (h = 1; info->argv[h]; h++)
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
	{
		p = _strchr(info->argv[h], '=');
		if (p)
			set_alias(info, info->argv[h]);
		else
<<<<<<< HEAD
		{
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
		}
		x = 1;
		x++;
=======
			print_alias(node_starts_with(info->alias, info->argv[h], '='));
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
	}

	return (0);
}
