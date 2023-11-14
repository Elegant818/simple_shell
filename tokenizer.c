#include "shell.h"

/**
 * tokenize - tokenize a string
 * @buff: The string to be tokenized
 *
 * Return: Array of tokens
 */
char **tokenize(char *buff)
{
	char **command;
	char *token;
	int i;

	if (!buff)
		return (NULL);

	token = strtok(buff, DELIM);
	if (!token)
	{
		free(buff);
		return (NULL);
	}

	command = malloc(sizeof(char *) * 1000);

	if (!command)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; token; i++)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIM);
	}
	free(buff);
	command[i] = NULL;

	return (command);
}
