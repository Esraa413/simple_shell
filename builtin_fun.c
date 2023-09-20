#include "shell.h"

/**
 * _myexit - exite check in the sell
 * @info: Contains possible arguments. It is used for maintenance
 *
 * Return: always(0)
 */

int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])/* If there is an exit arguement */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
<<<<<<< HEAD
			print_error(info, "ElLegal number: ,");
=======
			print_error(info, "Illegal number: ");
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
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
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
<<<<<<< HEAD
		_puts("To do: >> geodetic failure ems here << \n");
=======
		_puts("TODO: >>getcwd failure emsg here<<\n");
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO : what should this be ha ? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
<<<<<<< HEAD
	else if (_strcmp(info->argv[1], " - ") == 0)
=======
	else if (_strcmp(info->argv[1], "-") == 0)
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
<<<<<<< HEAD
		chdir_r =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : " / ");
=======
		chdir_ret =/* TODO : what should this be ha ? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
<<<<<<< HEAD
		print_error(info, "can't cd");
=======
		print_error(info, "can't cd to ");
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
<<<<<<< HEAD
		_setenv(info, "OLDPWD:", _getenv(info, "PWD:"));
		_setenv(info, "PWD:", getcwd(buf, 1024));
=======
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
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

<<<<<<< HEAD
	arg_arr = info->argv;
	_puts("help call works. not yet implemented \n");
=======
	arg_array = info->argv;
	_puts(" help call works. Function not yet implemented \n ");
>>>>>>> fb84cee8d69f9af85b6a040048792b08d6aa627b
	if (0)
		_puts(*arg_array); /* temp temp att_unused workaround */
	return (0);
}
