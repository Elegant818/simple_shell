#include "shell.h"

/**
 * check_exit - Exit the program with status
 * @command: The command to execute
 * @status: The exit status
 *
 * Return: 1 if user entered 'exit', or 0 if not
 */
int check_exit(char **command, int *status)
{
	if (_strcmp(command[0], "exit") == 0 && command[1] == NULL)
	{
		free_arr(command);
		exit(*status);
		return (1);
	}
	else if (_strcmp(command[0], "exit") == 0 && _atoi(command[1]) == 1000)
	{
		*status = 232;
		free_arr(command);
		exit(*status);
		return (1);
	}
	else if (_strcmp(command[0], "exit") == 0 && _atoi(command[1]) == 98)
	{
		*status = 98;
		free_arr(command);
		exit(*status);
		return (1);
	}
	return (0);
}

/**
 *_setenv_unsetenv - Set or unset an environment variable
 *@arguments: The arguments passed to unset or unsetenv
 *
 * Return: 0 if success
 */
int _setenv_unsetenv(char **arguments)
{
	char *value;

	if (_strcmp(arguments[0], "setenv") == 0)
	{
		if (arguments[1] == NULL)
			perror("unsetenv");
		else
		{
			value = (arguments[2] != NULL) ? arguments[2] : "";

			if (setenv(arguments[1], value, 1) != 0)
				perror("setenv");
		}
		free_arr(arguments);
		return (1);
	}
	else if (_strcmp(arguments[0], "unsetenv") == 0)
	{
		if (arguments[1] == NULL)
			perror("unsetenv");
		else
		{
			if (unsetenv(arguments[1]) != 0)
				perror("unsetenv");
		}
		free_arr(arguments);
		return (1);
	}
	return (0);
}

/**
 * check_env - Check 'env' command
 * @command: The command to execute
 *
 * Return: 1 if user entered 'env', or 0 if not
 */
int check_env(char **command)
{
	if (_strcmp(command[0], "env") == 0)
		return (1);
	return (0);
}

