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

extern char **environ;
#define BUF_SIZE 1024
#define TOKEN_DELIM " \n\t\r"

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *s);
int _strlen(const char *s);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char strtok1(char *str, const char *delimiters);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _getchar(void);
int gtline(char **lineptr);
int _putchar(char c);
void _print_d(int n);
char **_split_line(char *line, const char *delimiters);
char **getPATH(const char *env);
void _getenv(char **env);
int shell_exec(char **args, char *name, int circle);
int shell_exit(int ex_stat, char **args, char *lineptr, char **toks);
int _get_char(void);

#endif
