#include "shell.h"

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
		if (linelen == EOF)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(lineptr);
			free(toks);
			exit(EXIT_SUCCESS);
		}
		if (linelen == 0)
		{
			continue;
		}
		toks = _split_line(lineptr);
		if (*toks == NULL)
		{
			free(lineptr);
			continue;
		}
		shell_exec(toks, name, circle);
	}
	free(toks);
	free(lineptr);
	return (0);
}
