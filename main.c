#include "shell.h"

void _EOF(void);
void _getenv(char **env);

/**
 * main - function display a shell prompt to execute a command
 * @argc: Number of arguments
 * @argv: actual arguments
 * @envp: environment variables
 * Return: 0
 */
int main(int argc, char **argv, char **envp)
{
	char **toks = NULL;
	int linelen;
	int ex_stat = 0;
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
		linelen = gtline(&lineptr);
		if (linelen == EOF)
		{
			_EOF();
		}
		if (linelen == 0)
		{
			continue;
		}
		toks = _split_line(lineptr, " \t\r");
		if (*toks == NULL)
		{
			/*free(toks);*/
			free(lineptr);
			free(toks);
			continue;
		}
		if (_strcmp(toks[0], "env") == 0)
			_getenv(environ);
		if (_strcmp(toks[0], "exit") == 0)
			shell_exit(ex_stat, argv, lineptr, toks);
		if (_strcmp(toks[0], "cd") == 0)
		{
			change_dir(toks);
		}
		else
		{
			ex_stat = shell_exec(toks, name, circle);
		}
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

/**
 * _getenv - function that prints the environment variables
 * @env: pointer to the environment variables
 * Return: Nothing
 */
void _getenv(char **env)
{
	size_t len = 0, i = 0;

	while (env[i] != NULL)
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
