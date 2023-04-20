#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
void execute_command(char **args);
void print_prompt(void);
char **tokenize(char *command);
#endif
