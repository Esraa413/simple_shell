#include "shell.h"

/**
 * clear_info - Initializes the info_t to  Struct
 * @info: the struct address
 *
 */

void clear_info(info_t *info)
{
	info->path = 0;
	info->argv = 0;
	info->argc = 0;
	info->arg = 0;
}

/**
 * set_info - initializes the info_t to struct
 * @info: the struct address
 * @av: the argument vector
 *
 */

void set_info(info_t *info, char **av)
{
	int var = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \n\t");
		if (info->argv != 0)
		{
			info->argv = malloc(sizeof(char *) * 2);
			info->argv[1] = 0;
		}
	}
	while (info->argv && info->argv[var])
	{
		var++;
	}
	info->argc = var;
	replace_alias(info);
	replace_vars(info);
}

/**
 * free_info - Edits and free the info_t Struct fields
 * @info: the address to struct
 * @all: the freeing all fields
 *
 */

void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = 0;
	info->path = NULL;
	if (all)
	{
		if (info->cmd_buf != 0)
		{
			free(info->arg);
		}
		else if (info->environ)
		{
			free_list(&(info->env));
		}
		else if (info->history)
		{
			free_list(&(info->history));
		}
		else if (info->alias)
		{
			free_list(&(info->alias));
		}
		ffree(info->environ);
		info->environ = 0;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
		{
			close(info->readfd);
		}
		_putchar(-1);
	}
}
