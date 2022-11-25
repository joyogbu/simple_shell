#include "shell.h"

void _EOF(char *lineptr, char **toks);

/**
 * main - function display a shell prompt to execute a command
 * @argc: Number of arguments
 * @argv: actual arguments
 * @envp: environment variables
 * Return: 0
 */
int main(int argc, char **argv, char **envp)
/*int main(int argc __attribute__ ((unused)),*/
 /*char **argv __attribute__ ((unused)), char**envp __attribute__ ((unused)))*/
{
	char **toks = NULL;
	int linelen;
	char *name;
	int circle = 0;
	char *lineptr = NULL;
	(void)argc;
	(void)envp;

	while (1)
	{
		circle++;
		name = argv[0];
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "~$ ", 3);
		linelen = _getline(&lineptr);
		if (*lineptr == '\n')
		{
			free(toks);
			free(lineptr);
		}
		if (linelen == EOF)
		{
			_EOF(lineptr, toks);
		}
		if (linelen == 0)
		{
			continue;
		}
		toks = _split_line(lineptr);
		if (*toks == NULL)
		{
			continue;
		}
		shell_exec(toks, name, circle);
	}
	free(toks);
	free(lineptr);
	return (0);
}

/**
 * _EOF - handle end of file
 * Return: nothing
 * @lineptr: pointer to buffer to be freed if EOF
 * @toks: pointr to the splitted tokens
 */
void _EOF(char *lineptr, char **toks)
{
	if (isatty(STDIN_FILENO))
	{

		write(STDOUT_FILENO, "\n", 1);
	}
	free(toks);
	free(lineptr);
	exit(EXIT_SUCCESS);
}
