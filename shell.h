#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define DELIM " \t\n"
extern char **environ;

void print_prompt(void);
char *read_line(void);
char **tokenize(char *buff);
void free_arr(char **array);
char *_getenv(char *name);
int _execute(char **command, char **av);
int main(int ac, char **av);
int check(char **command, int status);
char *find_path(char *command);
int check_exit(char **command, int *status);
int check_env(char **command);
void print_environment(char **command);
int _setenv_unsetenv(char **command);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _atoi(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

#endif
