#include "shell.h"

/**
 * _myexit - exite check in the sell
 * @info: Contains possible arguments. It is used for maintenance
 *
 * Return: always(0)
 */

int _myexit(info_t *info)
{
	int exit;

	if (info->argv[1]) /* If  an exit arguement */
	{
		exit = _erratoi(info->argv[1]);
		if (exit == -1)
		{
			info->status = 2;
			print_error(info, "Ellegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - Changes the current directory of the operation
 * @info: Contains possible arguments. It is used for maintenance
 *
 * Return: Always (0)
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int ch_r;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			ch_r = /* TODO: what  this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			ch_r = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		ch_r = /* TODO: what  this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		ch_r = chdir(info->argv[1]);
	if (ch_r == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - change the cur directory of the operation
 * @info: Contains possible arguments. It is used for maintenance
 *
 * Return: Always (0)
 */

int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
	{
		_puts(*arg_array); /* att_unused workaround */
	}
	return (0);
}
