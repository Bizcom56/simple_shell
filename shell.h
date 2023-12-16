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
#include <string.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* cd_shell.c */
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *s);
void set_env(const char *name, const char *value, char ***environ);
void rev_string(char *str);
char *_strtok(char *str, const char *delim);
void get_error(int *status, int code);
size_t _strlen(const char *s);

int cd_shell(char **args, char ***environ, int *status);
void cd_dot(char ***environ, int *status);
void cd_to(char *dir, char ***environ, int *status);
void cd_previous(char ***environ, int *status);
void cd_to_home(char ***environ, int *status);


/* sh_env.c  */
char *_getenv(const char *name);
int _env(void);

/* Function prototypes */
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
