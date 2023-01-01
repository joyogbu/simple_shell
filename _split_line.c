#include "shell.h"
char **_split_line(char *line, const char *delimiters);
int _putchar(char c);
void _print_d(int n);
int _strcmp(char *s1, char *s2);

/**
 * _split_line - function that splits a line into tokens
 * @line: pointer to the line to split
 * @delimiters: characters to split line on
 * Return: splitted tokens
 */
char **_split_line(char *line, const char *delimiters)
{
	ssize_t token_size;
	char *tokens = NULL;
	int i = 0;
	char **token_arr = NULL;
	/*char *delimiters " \:\t\r";*/

	token_size = BUF_SIZE;
	if (line == NULL)
	{
		return (NULL);
	}
	token_size = _strlen(line);
	token_arr = malloc(sizeof(char *) * token_size);
	if (token_arr == NULL)
	{
		perror("Error: Could not allocate space");
		free(line);
		exit(EXIT_FAILURE);
	}
	tokens = strtok(line, delimiters);
	while (tokens != NULL)
	{
		token_arr[i] = tokens;
		i++;
		if (i >= token_size)
		{
			token_size += BUF_SIZE;
			token_arr = _realloc(token_arr, token_size, token_size + 1);
			if (token_arr == NULL)
			{
				perror("Cannot reallocate");
				exit(EXIT_FAILURE);
			}
		}
		tokens = strtok(NULL, delimiters);
	}
	token_arr[i] = NULL;
	return (token_arr);
}

/**
 * _putchar - function to print a character
 * @c: character to print
 * Return: character printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_d - function to print an integer
 * @n: integer to print
 * Return: nothing
 */
void _print_d(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		_print_d(n / 10);
	}
	_putchar(n % 10 + '0');
}

/**
 * _strcmp - function that compares two strings
 * @s1: an input string
 * @s2: an input string
 * Return: the difference s1 - s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
	s1++;
	s2++;
	}
	return (*s1 - *s2);
}
