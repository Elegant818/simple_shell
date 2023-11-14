#include "shell.h"

/**
 * free_arr - frees allocated memory for an array of strings
 * @array: The pointer to the allocated memory
 *
 * Return: Nothing
 */
void free_arr(char **array)
{
	int i;

	if (array)
	{
		for (i = 0; array[i]; i++)
		{
			free(array[i]);
			array[i] = NULL;
		}
		free(array), array = NULL;
	}
	else
		return;
}
