#include "shell.h"

/**
 *  _myenv - This prints the current environment
 *  @info: Contains possible arguments. It is used for maintenance
 *
 *  Return: always(0)
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - It returns the value of the variable in the current environment
 * @info: Contains possible arguments. It is used for maintenance
 * @name: environment, variable, name
 *
 * Return: always(0)
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - modify an existing or Initialize a environment variable
 * @info: Contains possible arguments. It is used for maintenance
 *
 * Return: Always (0)
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - remove to the environment variables
 * @info: Contains possible arguments. It is used for maintenance
 *
 * Return: Always (0)
 */

int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - popu_lates environ in linked list
 * @info: Contains possible arguments. It is used for maintenance
 *
 * Return: Always (0)
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
