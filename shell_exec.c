#include "shell.h"

void err_msg(char **args, char *name, int circle);
void err_msg2(char **args, char *name, int circle);
char **getPATH(const char *env);
int shell_exec(char **args, char *name,
int circle);

/**
 * getPATH - get environment path variables
 * @env: pointer array to PATH environment variables
 * Return: tokenized path variables
 */
char **getPATH(const char *env)
{
	int l;
	unsigned int i = 0;

	l = _strlen(env);
	while (environ[i])
	{
		if (_strncmp("PATH", environ[i], l) == 0)
		{
			return (&environ[i]);
		}
		i++;
	}
	return (NULL);
}

/**
 * shell_exec - function to execute shell commands
 * @args: list of commands
 * @name: name of the program
 * @circle: number of times my loop is called
 * Return: error code if there was any error otherwise
 * returns the exit status of the last executed command
 */

int shell_exec(char **args, char *name, int circle)
{
	char * const newenvp[] = {"HOME=/root", "PATH=/bin:/sbin", NULL};
	pid_t c_pid;
	int status;
	int error_code;
	int err;
	char *comm = NULL;
	char tokens2[1024];
	char tokens3[1024];
	char **pathways;
	char paths[1024];
	char *result;
	char *result2;
	int flag = 0;
	struct stat stats;

	err = 0;
	error_code = 0;
	comm = args[0];
	/*if(_strchr(comm, '/') == NULL)*/
	if (comm[0] != '/' && comm[0] != '.')
	{
		flag = 1;
		pathways = getPATH("PATH");
		_strcpy(paths, *pathways);
		result = strtok(paths, "=");
		result = strtok(NULL, "\n");
		_strcpy(tokens2, result);
		result2 = strtok(tokens2, ":");
		while (result2 != NULL)
		{
			_strcpy(tokens3, result2);
			_strcat(tokens3, "/");
			_strcat(tokens3, comm);
			result2 = strtok(NULL, ":");
		}
		comm = tokens3;
	}
	if (args[1] != NULL)
	{
		error_code = atoi(args[1]);
		if (error_code < 0)
		{
			err_msg3(name, error_code, circle);
		}
		if (atoi(args[1]) == 0)
		{
			err_msg4(name, &args[1], circle);
		}
		return(1);
	}
	if (stat(comm, &stats) == -1)
	{
		if (errno == EACCES)
		{
			err_msg(&args[0], name, circle);
			err = 126;
			
		}
		else
		{
			err_msg2(&args[0], name, circle);
			err = 127;
			
		}

		return(err);
		/*printf("exit %d", err);*/
		
	}
	else
	{
		c_pid = fork();
		if (c_pid < 0)
		{
			perror("Could not create a process");
			return (1);
		}
		if (c_pid == 0)
		{
			if (execve(comm, args, newenvp) == -1)
			{
				if (errno == EACCES)
				{
					err_msg(&args[0], name, circle);
					err = 126;
				}
				else
				{
					err_msg2(&args[0], name, circle);
					err = 127;
				}
				_exit(err);
			}
		}
		/*else if (c_pid < 0)
		{
			perror("Could not create a process");
		}*/
		else
		{
			do {
			/*wait(NULL);*/
				waitpid(c_pid, &status, 0);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		/*printf("status: %d", WEXITSTATUS(status));*/
		err = WEXITSTATUS(status);
		}
		if (flag == 1)
		{
		}
		/*return(err);*/
	}
	return (err);
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
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	/*write(STDOUT_FILENO, circle, 2);*/
	_print_d(circle);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, args[0], _strlen(args[0]));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "Permission denied\n", 18);
}

/**
 * err_msg2 - function that prints an error message
 * @args: argument input
 * @name: program name
 * @circle: number of execution time
 * Return: nothing
 */
void err_msg2(char **args, char *name, int circle)
{
	char c;

	c = circle + '0';
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	/*_print_d(circle);*/
	write(STDERR_FILENO, &c, 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
}

/**                                     * err_msg4 - print error for illegal exit codes                               * @name: argument input                * @status: exit code used
 * @circle: number of times of execution
 * Return: nothing
 */
                                       void err_msg4(char *name, char **args, int circle)                            {                                              write(STDOUT_FILENO, name, _strlen(name));                                    write(STDOUT_FILENO, ": ", 2);         _print_d(circle);                      write(STDOUT_FILENO, ": ", 2);         write(STDOUT_FILENO, "exit: Illegal number", 21);
        write(STDOUT_FILENO, ": ", 2);
        perror(args[1]);
        write(STDOUT_FILENO, "\n", 1);
}
