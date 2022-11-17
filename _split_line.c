include "shell.h"
/**
 * _split_line - function that splits a line into tokens
 * @line: pointer to the line to split
 * Return: tokens
 */
char **_split_line(char *line)
{
	ssize_t token_siz;
	char *tokens;
	int i = 0;
	char **token_arr;
	char *delimiters = " \t\r\n";

	if (line == NULL)
		return (NULL);
	token_size = _strlen(line);
	token_arr = malloc(sizeof(char *) * token_size);

	if (token_arr == NULL)
	{
		perror("Error: Could not allocate space");
		free(line);
		exit(EXIT_FAILURE);
	}
	tokens = strtok(line, delimiters);

	if (tokens == NULL)
		printf("canot tokenize");

	while (tokens != NULL)
	{
		token_arr[i] = malloc(_strlen(tokens));
		if (token_arr[i] == NULL)
		{
			perror("Unable to allocate buffer");
			return (NULL);
		}
		printf("toks: %s", tokens);
		/*token_arr[i] = tokens;*/
		_strcpy(token_arr[i], tokens);
		tokens = strtok(NULL, delimiters);
		i++;
		/* token_arr[i] = tokens; i++; tokens = strtok(NULL, delimiters)*/
	}
	token_arr[i] = NULL;
	return (token_arr);
}
