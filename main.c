#include "shell.h"

/**
 * check - Checks bellow functions
 * @command: Command to be executed
 * @status: Exit status
 *
 * Return: Return 0 or 1 or 2
 */
int check(char **command, int status)
{
	if (!command)
		return (1);
	else if (check_env(command))
	{
		print_environment(command);
		return (1);
	}
	else if (_setenv_unsetenv(command))
		return (1);
	else if (check_exit(command, &status))
		return (0);
	else
		return (2);

}

/**
 * main - Handel shell commands
 * @argc: Number of arguments
 * @argc: Array of strings (arguments)
 * Return: Return 0 if success
 */
int main(int argc, char **argv)
{
	char *buff;
	size_t n;
	ssize_t chars;
	char **command = NULL;
	int status = 0;
	(void)argc;

	while (1)
	{
		buff = NULL;
		n = 0;

		if (isatty(STDIN_FILENO))
			print_prompt();

		chars = getline(&buff, &n, stdin);

		if (chars == -1)
		{
			free(buff);
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			return (status);
		}

		command = tokenize(buff);

		if (check(command, status) == 1)
			continue;
		else if (check(command, status) == 0)
			break;

		status = _execute(command, argv);
	}
	return (0);
}


