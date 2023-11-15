#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void tokenise(char *buffer, char *arr[], char *delim);
int _print(char *string);
int _putchar(char c);
void rm_newline(char *str);

#endif
