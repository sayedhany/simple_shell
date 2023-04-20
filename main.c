#include "main.h"

/**
 * execute_command - Executes a command in a child process.
 * @command: the command to execute.
 * Return: 0 on success, -1 on failute
 */

int execute_command(char *command)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        return (-1);
    }
    if (child_pid == 0)
    {
        /* Child process */
        if (execl(command, command, NULL) == -1)
        {
            perror("./hsh");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
        {
            return (0);
        }
        else
        {
            
            return (-1);
        }
    }
    return (-1);
}

/**
 * print_prompt - print >
 */
void print_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}
