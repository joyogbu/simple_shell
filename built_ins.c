#include "shell.h"

int shell_exit(char *lineptr, char **toks)
{
	free(toks);
	free(lineptr);
	exit(EXIT_SUCCESS);
}
