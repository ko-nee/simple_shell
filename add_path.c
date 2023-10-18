#include "shell.h"

/**
* add_path - appends a path with a command.
*
* This function takes a path and a user-entered command and combines
* them to create a full command with the path included.
*
* @path: Path of the command.
* @input_cmd: User-entered command.
*
* Return: A buffer containing the command with the path on success,
* or NULL on failure.
*/
char *add_path(char *path, char *input_cmd)
{
size_t path_len;
size_t cmd_len;
char *buf;

if (path == NULL || input_cmd == NULL)
return (NULL);

path_len = string_length(path);
cmd_len = string_length(input_cmd);

buf = malloc(path_len + cmd_len + 2);

if (buf == NULL)
return (NULL);

if (path_len > 0)
{
string_compare_n(buf, path, path_len);
if (path[path_len - 1] != '/')
buf[path_len] = '/';
}

string_compare_n(buf + path_len + (path_len > 0 ? 1 : 0), input_cmd, cmd_len);
buf[path_len + cmd_len + (path_len > 0 ? 1 : 0)] = '\0';

return (buf);
}
