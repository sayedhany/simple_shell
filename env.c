#include "main.h"

/**
 * env - display the environmet variables
 * @ac: arguments counter
 * @av: arguments vector
 * @env: envirnoment variables*
 * Return: 0 on success
 */

int env(int ac __attribute__((unused))
, char *av[] __attribute__((unused)), char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		printf("%s\n", env[i]);
	}
	return (0);
}
