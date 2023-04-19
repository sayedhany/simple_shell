#include "main.h"
#include <string.h>
/**
 * main - entry point
 *
 * Description: 'the main file for excuting other files and
 * tacking shell commands from stdin'
 *
 * @ac: arguments counter
 * @av: arguments vector
 * @env: envirnoment variables
 *
 * Return: 0 on success
 */

int main(int ac __attribute__((unused))
, char *av[] __attribute__((unused)), char **env)
{
	pid_t pid;
	char *line = NULL;
	size_t len = 0;
	char *args[2];
	int status;
	while (1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
		} else if (pid == 0)
		{
			printf("$ ");
			if (getline(&line, &len, stdin) == EOF)
				kill(pid, SIGTERM);
			line[strcspn(line, "\n")] = '\0';
			args[0] = line, args[1] = NULL;
			if (strcmp(line, "exit") == 0)
			{
				kill(pid, SIGTERM);
			} else if (strlen(line) == 0)
			{
				break;
			}
			if (access(line, X_OK) == -1)
			{
				perror("./hsh");
				break;
			} else if (execve(line, args, env) == -1)
			{
				perror("./hsh");
			}
		} else
		{
			waitpid(pid, &status, 0);
		}
	}
	free(line);
	return (0);
}
