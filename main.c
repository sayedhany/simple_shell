#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
/**
 * print_prompt - print the command
 */
void print_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}
