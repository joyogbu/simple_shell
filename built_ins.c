#include "shell.h"
#include <stdio.h>
#include <unistd.h>

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
	int status;
	int code;
	(void)args;
	status = 0;
	code = 0;
	/*size_t max;

	max = 999999999*/
	/*printf("exit status: %d", ex_stat);*/
	/*free(toks);*/
	/*free(lineptr);*/
	/*free(args);*/
	/*if (ex_stat == 126)
		exit(126);
	else if (ex_stat == 127)
		exit(127);
	else if (ex_stat == 1)
		exit(1);
	else if (ex_stat == 2)
		exit(2);
	else
		exit(0);*/
	if (toks[1] != NULL)
	{
		status = atoi(toks[1]);
		/*printf("status is %d", status);*/
		if ((atoi(toks[1]) < 0) || atoi(toks[1]) == 0)
		{
			/*err_msg3(name, status, circle);*/
			/*shell_exec(toks, name, circle);*/
			return(0);
		}
		if ((atoi(toks[1]) > 255))
		{
			code= status % 256;
			/*free(toks);
			free(lineptr);*/
			/*exit((long int)(toks[1]));*/
			/*exit(code);*/
		}
		/*else if ((atoi(toks[1]) < 0))
		{
			err_msg3(name, status, circle);
			return(1);
		}
		return(1);*/
		free(toks);
                free(lineptr);
                /*exit((long int)(toks[1]));*/
		exit(code);
	}
	else
	{
		free(toks);
		free(lineptr);
		if (ex_stat == 126)
			exit(126);
		else if (ex_stat == 127)
			exit(127);
		else if (ex_stat == 1)
			exit(1);
		else if (ex_stat == 2)
			exit(2);
		else
			exit(0);
	}
}

/**
 * err_msg3 - print error for illegal exit codes
 * @name: argument input
 * @status: exit code used
 * @circle: number of times of execution
 * Return: nothing
 */

void err_msg3(char *name, int status, int circle)
{
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	_print_d(circle);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number", 21);
	write(STDOUT_FILENO, ": ", 2);
	_print_d(status);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * err_msg4 - print error for illegal exit codes
 * @name: argument input
 * @status: exit code used
 * @circle: number of times of execution
 * Return: nothing
 */
/*
void err_msg4(char *name, char **args, int circle)
{                                              write(STDOUT_FILENO, name, _strlen(name));                                    write(STDOUT_FILENO, ": ", 2);         _print_d(circle);
        write(STDOUT_FILENO, ": ", 2);
        write(STDOUT_FILENO, "exit: Illegal number", 21);
        write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, args[1], _strlen(args[1]));
	write(STDOUT_FILENO, "\n", 1);
}*/

/**
 * change_dir - change directory
 * @toks: arguments supplied
 * Return: 0 on success otherwise 1
 */
int change_dir(char **toks)
{
	int ret;
	char s[1024];
	/*printf("former %s", getcwd(s, 1024));*/
	if (getcwd(s, 1024))
		*s = '\0';
	if ((toks[1] == NULL) || (_strcmp(toks[1], "~")) == 0)
	{
		toks[1] = getenv("HOME");
	}
	ret = chdir (toks[1]);
	setenv("PWD", getcwd(s, 1024), 1);
	/*printf("home is %s", toks[1]);*/
	/*printf("working_directory is %s", getcwd(s, 1024));*/
	return (ret);
}
