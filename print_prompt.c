#include "shell.h"

/**
 * print_prompt - Display the prompt
 *
 * Return: Nothing
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, "($) ", 4);
}
