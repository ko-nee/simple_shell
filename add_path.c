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
char *add_path(const char *path, const char *input_cmd)
{
if (path == NULL || input_cmd == NULL)
return (NULL);

size_t path_len = string_length(path);
size_t cmd_len = string_length(input_cmd);

char *buf;
buf = malloc(path_len + cmd_len + 2);

if (buf == NULL)
return (NULL);

if (path_len > 0)
{
string_copy(buf, path, path_len);
if (path[path_len - 1] != '/')
buf[path_len] = '/';
}

string_copy(buf + path_len + (path_len > 0 ? 1 : 0), input_cmd, cmd_len);
buf[path_len + cmd_len + (path_len > 0 ? 1 : 0)] = '\0';

return (buf);
}
