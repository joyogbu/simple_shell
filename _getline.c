#include "shell.h"

int _getchar(void);
int _getline(char **lineptr);
/**
 * _getchar - function that reads a character
 * Return: the character read
 */

int _getchar(void)
{
	static char buf[BUF_SIZE];
	static char *ch;
	int r = 0;

	while (1)
	{
		r = read(STDIN_FILENO, buf, 1);
		if (r == 0)
			break;
		if (r > 0)
			ch = buf;
		return (*ch++);
	}
	return (EOF);
}

/**
 * _getline - read a line of input
 * @lineptr: address of the pointer containing the character
 * Return: -1 on failure and the charactera read on success
 */

int _getline(char **lineptr)
{
	char *buffer;
	int n_size;
	int i = 0;
	char c = 'x';

	fflush(STDIN_FILENO);

	n_size = BUF_SIZE;
	buffer = malloc(sizeof(char) * n_size + 1);
	if (buffer == NULL)
		return (-1);
	while ((c = _getchar()) != '\n')
	{
		if (i == n_size - 1)
		{
			n_size += BUF_SIZE;
			buffer = _realloc(buffer, n_size, n_size + 1);
			if (buffer == NULL)
			{
				perror("Error: Cannot Reallocate");
				return (-1);
			}
		}
		if (c == EOF)
		{
			if (i == 0)
				return (-1);
			break;
		}
		else
		{
			buffer[i] = c;
			i++;
		}
	}
	buffer[i] = '\0';
	*lineptr = malloc(sizeof(char) * (i + 1));
	_strcpy(*lineptr, buffer);
	free(buffer);
	return (i);
}
