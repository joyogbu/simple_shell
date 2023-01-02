#include "shell.h"

/**
 * shell_exit - function that exits the shell
 * @ex_stat: status returned from exit
 * @args: arguments parameters
 * @lineptr: pointer to buffer holding the commands enterd
 * @toks: double pointer to the tokenized string
 * Return: exit status 0
 */
int shell_exit(int ex_stat, char **args, char *lineptr, char **toks)
{
	(void)args;
	/*printf("exit status: %d", ex_stat);*/
	free(toks);
	free(lineptr);
	/*free(args);*/
	if (ex_stat == 126)
		exit(126);
	if (ex_stat == 127)
		exit(127);
	else if (ex_stat == 1)
		exit(1);
	else if (ex_stat == 2)
		exit(2);
	else
		exit(0);
}
