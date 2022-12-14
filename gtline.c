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

	/*char *buf;*/
	static char *ch;
	static int r;
	static int i;

	/*buf = malloc(sizeof(char) * BUF_SIZE + 1);*/
	/*while (1)*/
	if (i >= r)
	{
		r = read(STDIN_FILENO, buf, 1024);
		if (r > 0)
		{
			ch = buf;
			i = 0;
			/*if (r == 0)*/
			/*break;*/
			/*if (r > 0)*/
			/*{*/
			/*buf[r] = '\0';*/
			/*ch = buf;*/
		/*free(buf);*/
			return (*(ch + i++));
		}
		else
			return (EOF);
	}
	else
	{
		return (*(ch + i++));
	}
}

/**
 * gtline - read a line of input
 * @lineptr: address of the pointer containing the character
 * Return: -1 on failure and the charactera read on success
 */

int gtline(char **lineptr)
{
	char *buffer;
	int n_size;
	static int i;
	/*char c = 'x';*/
	int c;

	fflush(STDIN_FILENO);

	i = 0;
	n_size = BUF_SIZE;
	buffer = malloc(sizeof(char) * n_size + 1);
	if (buffer == NULL)
		return (-1);
	while ((c = _getchar()) != '\n')
	{
		if (c == EOF || c == '\n')
		{
			if (i == 0)
			{
				free(buffer);
				return (-1);
			}
			buffer[i] = '\0';
			/*free(buffer);*/
			break;
		}
		/*if (c == EOF || c == '\n')*/
		/*{*/
		/**printf("endoffile");**/
		/*buffer[i] = '\0';*/
		/*break;*/
		/*}*/
		else
		{
			buffer[i] = c;
			i++;
		}
		/*i++;*/
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
	}
	buffer[i] = '\0';
	*lineptr = malloc(sizeof(char) * (i + 1));
	_strcpy(*lineptr, buffer);
	free(buffer);
	return (i);
}
