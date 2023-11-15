#include "shell.h"

/**
 *_strlen - return the length of a string
 *@s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		s++;
		i++;
	}

	return (i);
}

/**
 * _strcpy - copies the string pointed to by src
 * including the terminnating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compare 2 string
 * @s1:string
 * @s2:strmp
 *
 * Return:int
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0') && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strchr - locates a character in a string
 *
 * @c: occurance of the character
 * @s: in the string
 *
 * Return: a pointer to the first occurance of the character
 */
char *_strchr(char *s, char c)
{
	if (c == '\0')
		return (s);

	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	return (NULL);
}


/**
 * _strcat - concat 2 string
 * @dest:char
 * @src:char
 *
 * Return:char
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
