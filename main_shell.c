#include "main.h"

/**
 * main - the main function for simple shell
 * Return: 0
 */
int main(void)
{
	char *command = NULL, **args = NULL;
	ssize_t read = 0;
	size_t len = 0;

	while (1)
	{
		print_prompt();

		read = getline(&command, &len, stdin);

		if (read == -1)
		{
			putchar('\n');
			break;
		}
		if (command[read - 1] == '\n')
			command[read - 1] = '\0';

		args = tokenize(command);

		execute_command(args);

		free(args);
		args = NULL;
		free(command);
		command = NULL;
	}
	return (0);
}
