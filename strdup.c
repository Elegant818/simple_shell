#include "shell.h"

/**
 * _strdup - Duplicate to new memory space location
 * @str: char
 *
 * Return: 0
 */
char *_strdup(char *str)
{
	char *aaa;
	int i = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	while (str[i] != '\0')
		i++;

	aaa = malloc(sizeof(char) * (i + 1));

	if (aaa == NULL)
		return (NULL);

	_strcpy(aaa, str);

	return (aaa);
}

