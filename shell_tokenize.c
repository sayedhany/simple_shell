#include "main.h"

/**
 * tokenize - tokenize command line arguments
 * @command: command line to tokenize
 * Return: Array of tokens
 */
char **tokenize(char *command)
{
	const char *delim = " ";
	char *token = NULL;
	char **tokens = NULL;
	int token_count = 0;

	/* allocate memory got token array */
	tokens = malloc(sizeof(char *) * 10);

	/* tokenize command line */
	token = strtok(command, delim);
	while (token != NULL)
	{
		tokens[token_count] = token;
		token_count++;

		/* check if more memory is needed */
		if (token_count % 10 == 0)
			tokens = realloc(tokens, sizeof(char *) * (token_count + 10));
		/* get next token */
		token = strtok(NULL, delim);
	}
	tokens[token_count] = NULL;
	return (tokens);
}
