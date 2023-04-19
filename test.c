#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 1024

void print_prompt(void);
int execute_command(char *command);
void cleanup(char *command);

/**
 * print_prompt - Prints the command prompt.
 */
void print_prompt(void)
{
    printf("> ");
    fflush(stdout);
}

/**
 * execute_command - Forks and executes a command.
 *
 * @command: The command to execute.
 *
 * Return: 1 if the command was executed successfully, otherwise 0.
 */
int execute_command(char *command)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return 0;
    }
    else if (pid == 0)
    {
        /* Child process, execute the command */
        if (execlp(command, command, (char *) NULL) == -1)
        {
            perror("execlp");
            exit(1);
        }
        exit(0);
    }
    else
    {
        /* Parent process, wait for the child to finish */
        int status;
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
            return 0;
        }
    }
    return 1;
}

/**
 * cleanup - Frees the memory allocated for the command.
 *
 * @command: The command to free.
 */
void cleanup(char *command)
{
    free(command);
}

/**
 * main - The main function.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *command = NULL;
    size_t command_len = 0;

    while (1)
    {
        print_prompt();

        if (getline(&command, &command_len, stdin) == -1)
        {
            /* End of file or error, exit the program */
            printf("\n");
            cleanup(command);
            exit(0);
        }

        /* Remove the newline character from the end of the command */
        command[strcspn(command, "\n")] = '\0';

        if (!execute_command(command))
        {
            printf("Error executing command: %s\n", command);
        }

        /* Cleanup the memory allocated for the command */
        cleanup(command);
        command = NULL;
        command_len = 0;
    }
    return 0;
}

