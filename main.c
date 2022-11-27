#include "shell.h"

void _EOF(void);

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
		/*if (linelen == '\n')
		{
			free(lineptr);
			free(toks);
		}*/
		if (linelen == EOF)
		{
			_EOF();
		}
		if (linelen == 0)
		{
			continue;
		}
		toks = _split_line(lineptr);
		if (*toks == NULL)
		{
			/*free(toks);*/
			free(lineptr);
			free(toks);
			continue;
		}
		if (strcmp(toks[0], "exit") == 0)
			shell_exit(lineptr, toks);
		else
		{
			shell_exec(toks, name, circle);
		}
		/*free(toks);*/
		free(lineptr);
		free(toks);
	}
	return (0);
}

/**
 * _EOF - handle end of file
 * Return: nothing
 */
void _EOF(void)
/*void _EOF(char *lineptr, char **toks)*/
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
	}
	/*free(toks);*/
	/*free(lineptr);*/
	exit(EXIT_SUCCESS);
}
