#include "shell.h"

/**
 * _execute - Executes a command
 * @command: The command to be executed
 * @argv: Array of strings
 * Return: Status
 */
int _execute(char **command, char **argv)
{
	pid_t child;
	int status;
	char *full_path;

	full_path = find_path(command[0]);
	if (!full_path)
	{
		perror(argv[0]);
		free_arr(command);
		return (127);
	}

	child = fork();

	if (child == -1)
	{
		free_arr(command);
		free(full_path), full_path = NULL;
		return (-1);
	}

	if (child == 0)
	{
		if (execve(full_path, command, environ) == -1)
		{
			perror(argv[0]);
			free_arr(command);
			free(full_path), full_path = NULL;
		}

	}
	else
	{
		waitpid(child, &status, 0);
		free_arr(command);
		free(full_path), full_path = NULL;
	}
	return (WEXITSTATUS(status));
}
