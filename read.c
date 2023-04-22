#include "main.h"

/**
 * read_line - read a line from stdin
 * Return: The line read from stdin or NULL on failure
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t linelen = 0;

    linelen = getline(&line, &bufsize, stdin);
    if (linelen == -1) /* end of file or error */
    {
        free(line);
        line = NULL;
    }
    else if (line[linelen - 1] == '\n')
        line[linelen - 1] = '\0';

    return (line);
}
