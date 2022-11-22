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
	char **toks;
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
			/*free(lineptr);*/
			exit(EXIT_SUCCESS);
		}
		if (linelen == 0)
		{
			/*free(lineptr);*/
			continue;
		}
		toks = _split_line(lineptr);
		if (*toks == NULL)
		{
			free(lineptr);
			continue;
		}
		/**printf("My Tokens are: %s", *toks);**/
		shell_exec(toks, name, circle);
	}
	free(lineptr);
	return (0);
}
