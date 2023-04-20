#include "main.h"

#define BUFSIZE 1024
/**
 * main - the main function for simple shell
 * Return: 0
 */
int main(void)
{
	char *command = NULL;
	size_t bufsize = BUFSIZE;

	while (1)
	{
		print_prompt();
		getline(&command, &bufsize, stdin);
		command[strlen(command) - 1] = '\0';

		if (strcmp(command, "exit") == 0)
			exit(EXIT_SUCCESS);
		if (execute_command(command) == -1)
			printf("./hsh");
	}
	return (0);
}
