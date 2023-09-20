#include "shell.h"

/**
 * get_environ - Returns a string array version of our environment
 * @info: Contains possible arguments. It is used for maintenance
 *
 * Return: Always (0)
 */

char **get_environ(info_t *info)
{
	if (!info->environ)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	if (info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
 * _unsetenv - function to remove an environment variable
 * @info: Contains possible arguments. It is used for maintenance
 * @var: the string environ and variable
 *
 * Return: Always (0)
 */

int _unsetenv(info_t *info, char *var)
{
	size_t x;
	char *p;
	list_t *node;

	node = info->env;
	if (!node)
		return (0);
	if (!var)
		return (0);
	for (x = 0; node; x++)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), x);
			x = 0;
			node = info->env;
			continue;
		}
		node = node->next;
	}
	return (info->env_changed);
}

/**
 * _setenv - Create a new environment variable or modify an existing one
 * @info: Contains possible arguments. It is used for maintenance
 * @var: the string environ and variable
 * @value: the string environ and variable value
 *
 * Return: Always (0)
 */

int _setenv(info_t *info, char *var, char *value)
{
	list_t *node;
	char *buf = NULL;
	char *p;

	if (!var)
		return (0);
	if (!value)
		return (0);
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, " = ");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
