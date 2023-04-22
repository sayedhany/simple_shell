#include "main.h"
/**
 * execute_command - Executes the command given as input.
 * @args: An array of strings containing the command and its arguments.
 * Return: 1 on success, -1 on failure.
 */
int execute_command(char **args)
{
	pid_t pid;
	char *path = NULL;
	struct stat st;

	if (args == NULL || args[0] == NULL)
		return (-1);

	path = _getpath(args[0]);

	if (path == NULL)
	{
		print_error(args[0], "not found");
		return (-1);
	}

	if (stat(path, &st) == -1)
	{
		free(path);
		print_error(args[0], "not found");
		return (-1);
	}

	pid = fork();

	if (pid == -1)
	{
		free(path);
		perror("Error");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			free(path);
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);

	free(path);
	return (1);
}
