#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>

#define BUF_SIZE 1024
#define TOKEN_DELIM " \n\t\r"

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *s);
int _strlen(char *s);
char strtok1(char *str, const char *delimiters);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _getchar(void);
int _getline(char **lineptr);
char **_split_line(char *line);
void shell_exec(char **args, char *name, int circle);


#endif
