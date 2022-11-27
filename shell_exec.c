#include "shell.h"

int _putchar(char c);
void _print_d(int n);
void err_msg(char **args, char *name, int circle);
void shell_exec(char **args, char *name,
int circle);

/**
 * _putchar - function to print a character
 * @c: character to print
 * Return: character printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_d - function to print an integer
 * @n: integer to print
 * Return: nothing
 */
void _print_d(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		_print_d(n / 10);
	}
	_putchar(n % 10 + '0');
}

/**
 * shell_exec - function to execute shell commands
 * @args: list of commands
 * @name: name of the program
 * @circle: number of times my loop is called
 * Return: nothing
 */

void shell_exec(char **args, char *name, int circle)
{
		char * const newenvp[] = {NULL};
		/*char *new[100];*/
	pid_t c_pid;
	/*int status;*/
	char *comm;

	comm = args[0];

	/**const char *val;**/
	/**char *path = malloc(sizeof(char) * 10);**/
	/**extern char **environ;**/
	/**while(environ[i])**/
		/**printf("%s", environ[i++]);**/
	/**val = getenv("PATH");**/
	/**puts(val);**/
	/**if(strchr(args[0], '/') != NULL)**/
	/**{**/
		/**check = 1;**/
		/**printf("yes");**/
		/**_strcpy(path, args[0]);**/
	/**}**/
	/**else**/
	/**{**/
		/**printf("no");**/
		/**_strcpy(path, "/bin/");**/
		/**_strcat(path, comm);**/
	/**}**/
	/**char  path[128] = "/bin/";**/
	/**_strcpy(path, "/bin/");**/
	/**if (!*args)**/
		/**comm = "";**/
	/**_strcat(path, comm);**/
	/**new[0] = path;**/
	/**new[1] = NULL;**/
	c_pid = fork();
	if (c_pid == 0)
	{
		if (execve(comm, args, newenvp) == -1)
		/*if (execve(path, new, newenvp) == -1)*/
		{
			if (errno == EACCES)
			{
				err_msg(&args[0], name, circle);
			}
			else
			{
			write(STDOUT_FILENO, name, _strlen(name));
			write(STDOUT_FILENO, ": ", 2);
			_print_d(circle);
			/*write(STDOUT_FILENO, &c, 1);*/
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, args[0], _strlen(args[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, "not found\n", 10);
			}
			free(args);
			free(comm);
			exit(0);
		}
	}
	if (c_pid < 0)
	{
		perror("Could not create a process");
	}
	else
	{
	/*	do {*/
			wait(NULL);
		/*} while (!WIFEXITED(status) && !WIFSIGNALED(status));*/
	}
}

/**
 * err_msg - function that prints an error message
 * @args: argument input
 * @name: program name
 * @circle: number of execution time
 * Return: nothing
 */
void err_msg(char **args, char *name, int circle)
{
	/*char *c*/
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	/*write(STDOUT_FILENO, c, 1);*/
	_print_d(circle);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, args[0], _strlen(args[0]));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "Permission denied\n", 18);
}
