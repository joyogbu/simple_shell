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
int _strlen(const char *s)
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

/**
 * _strncmp - compares n characters in two strings
 * @n: number of characters to compare
 * @s1: first string
 * @s2: second string
 * Return: 0 if the two strings are equal or their difference
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (s1[i] && s2[i] && i <= n)
	{
		i++;
		n--;
	}
	while (n > 0)
		/*for(; i<=n; n--, i++)*/
	{
		if (s1[i] > s2[i])
			break;
		if (i == n)
			return (0);
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		n--;
		/*return(0);*/
	}
	/*return (0);*/
	return (s1[i] - s2[i]);
}

/**
 * _strchr - locates a character in a string
 * @s: input string
 * @c: character to be located
 * Return: apointer to the first occurence of the string
 */
char *_strchr(char *s, char c)
{
	int i = 0;
	char *sptr = s;

	while (s[i] >= '\0')
	{
		if (s[i] == c)
		{
			return (sptr + i);
		}
		i++;
	}
	/*return ('\0');*/
	return (NULL);
}
