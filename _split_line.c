#include "shell.h"

/**
 * _split_line - function that splits a line into tokens
 * @line: pointer to the line to split
 * Return: tokens
 */
char **_split_line(char *line)
{
	ssize_t token_size;
	char *tokens = NULL;
	int i = 0;
	char **token_arr = NULL;
	char *delimiters = " \t\r\n";

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
