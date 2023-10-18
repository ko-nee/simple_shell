#include "shell.h"

/**
* find_exec_path - Search for a valid executable path in a list of
* directories.
* @directories: Tokenized directories to search.
* @input_cmd: User-entered command to append to each directory.
*
* Return: A valid path containing the command on success, or NULL on failure.
*/
char *find_exec_path(char **directories, char *input_cmd)
{
int index = 0;
char *result_path;

while (directories[index])
{
result_path = add_path(directories[index], input_cmd);
if (access(result_path, F_OK | X_OK) == 0)
{
return (result_path);
}
free(result_path);
index++;
}
return (NULL);
}
