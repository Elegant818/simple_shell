#include "shell.h"

/**
 * print_environment - Prints environment variables
 * @command: The command to execute
 *
 * Return: Nothing
 */
void print_environment(char **command)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
	free_arr(command);
}
