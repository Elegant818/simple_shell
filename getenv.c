#include "shell.h"

/**
 * _getenv - Get the environment variable value
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable
 */
char *_getenv(char *name)
{
	unsigned int i = 0;
	char *var, *var_name, *val;

	if (!name)
		return (NULL);

	while (environ[i])
	{
		var = _strdup(environ[i]);
		var_name = strtok(var, "=");

		if (var_name)
		{
			if (_strcmp(var_name, name) == 0)
			{
				val = _strchr(environ[i], '=');

				if (val)
				{
					free(var);
					return (val + 1);
				}
				else
				{
					free(var);
					return ("");
				}
			}
		}
		free(var);
		i++;
	}

	return (NULL);
}
