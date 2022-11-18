#include "shell.h"

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
	int status;
	char *comm = args[0];
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
			/*perror(": Command not found");*/
			printf("%s: %d: %s: not found\n", name, circle, args[0]);
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
