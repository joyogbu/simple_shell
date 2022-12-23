#include "shell.h"

/**
 * shell_exit - function that exits the shell
 * @args: arguments parameters
 * @lineptr: pointer to buffer holding the commands enterd
 * @toks: double pointer to the tokenized string
 * Return: exit status 0
 */
int shell_exit(char **args, char *lineptr, char **toks)
{
	(void)args;
	free(toks);
	free(lineptr);
	/*free(args);*/
	exit(2);
}
