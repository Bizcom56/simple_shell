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
#define TOK_BUFSIZE 156
#define TOK_DELIM " \t\r\n\a"

char *getenv(const char *name);
int env(void);

extern char **environ;
char **token(char *buffer);
void free_arg(char **argv);
void print_errors(char *shell_name, char *command_name, unsigned int pro_count);
char *sh_path(char *filename);
int strcmp(char *str_1, char *str_2, int n);
char *strcpy(char *dest, char *src);
void ex_sh_err(char *shell_name, char *command_name, unsigned int pro_count, char *arg);


#endif

