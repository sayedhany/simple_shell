#include "main.h"
/**
 * get_path_dirs - Splits the PATH environment variable into individual
 *                 directories.
 *
 * Return: An array of strings representing the individual directories.
 */
char **get_path_dirs(void)
{
        char *path = _getenv("PATH");
        char **dirs;

        if (!path)
                return (NULL);

        dirs = split_string(path, ":");

        return (dirs);
}

/**
 * get_cmd_path - Gets the full path of a command, if it exists.
 *                Searches for the command in the directories specified
 *                in the PATH environment variable.
 *
 * @cmd: The command to search for.
 *
 * Return: The full path of the command, or NULL if it does not exist.
 */
char *get_cmd_path(char *cmd)
{
        char **dirs = get_path_dirs();
        char *path;
        int i;

        if (!dirs)
                return (NULL);

        for (i = 0; dirs[i]; i++)
        {
                path = str_concat(dirs[i], "/");
                path = str_concat(path, cmd);

                if (access(path, F_OK) == 0)
                {
                        free_split(dirs);
                        return (path);
                }

                free(path);
        }

        free_split(dirs);
        return (NULL);
}
