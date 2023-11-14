#include "shell.h"

/**
 * find_path - Finds the path of a command
 * @command: The command of the user
 *
 * Return: The full path of the command
 */
char *find_path(char *command)
{
	char *full_path = NULL, *var = NULL, *temp = NULL, *value = NULL;

	if (_strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (_strdup(command));
		return (NULL);
	}

	var = _getenv("PATH");
	if (var == NULL)
		return (NULL);
	temp = _strdup(var);
	value = strtok(temp, ":");

	while (value)
	{
		full_path = malloc(_strlen(value) + _strlen(command) + 2);

		if (full_path)
		{
			_strcpy(full_path, value);
			_strcat(full_path, "/");
			_strcat(full_path, command);

			if (access(full_path, X_OK) == 0)
			{
				free(temp), temp = NULL;
				return (full_path);
			}
			free(full_path), full_path = NULL;
		}
		value = strtok(NULL, ":");
	}
	free(temp), temp = NULL;
	return (NULL);
}



