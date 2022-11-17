#include "shell.h"

/**
 * shell_exec - function to execute shell commands
 * @args: list of commands
 * Return: nothing
 */

void shell_exec(char **args)
{
	char * const newenvp[] = {NULL};
	char *new[100];
	pid_t c_pid;
	int status;
	char *comm = args[0];
	char  path[128] = "/bin/";

	_strcpy(path, "/bin/");

	if (!*args)
		comm = "";
	_strcat(path, comm);
	new[0] = path;
	new[1] = NULL;
	c_pid = fork();
	if (c_pid == 0)
	{
		/**printf("Command is: %s", comm);
		printf("i got: %s", path);**/
		if (execve(path, new, newenvp) == -1)
		{
			/**printf("\n%s doesnt exist", args[0]);**/
			perror("Unable to execute command");
			exit(1);
		}
	}
	if (c_pid < 0)
	{
		perror("Could not create a process");
	}
	else
	{
		do {
			wait(NULL);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
