#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: input string 1
 * @src: input string 2
 * Return: a pointer
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char *pt = dest;

	while (dest[i] != '\0')
	{
		pt[j] = dest[i];
		i++;
		j++;
	}
	while (src[k] != '\0')
	{
		pt[j] = src[k];
		i++;
		j++;
		k++;
	}
	pt[j] = '\0';
	return (pt);
}

/**
 * _strlen - function that returns the length of a string
 * @s: an input string
 * Return: nothing
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcpy - function that copies the string pointed to
 * by src including the terminating (\0) null byte
 * @dest: pointer to destination of string
 * @src: poi ter to source of string
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int j = -1;

	do {
		j++;
		dest[j] = src[j];
	} while (src[j] != '\0');
	return (dest);
}
