#ifndef _SHELL_
#define _SHELL_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* envrn1.c  */
char *_getenv(const char *name);
int _env(void);

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;
char **token(char *buffer);
void free_arg(char **argv);
void errors(char *sh_name, char *command, unsigned int count);
char *path(char *filename);
int _strncmp(char *s1, char *s2, int n);
char *_strcpy(char *dest, char *src);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void exit_err(char *sh_name, char *command, unsigned int count, char *arg);
int exit_shell(char *arg);

#endif
