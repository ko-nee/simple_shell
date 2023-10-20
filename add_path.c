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
char *buf;
size_t path_len = 0;
size_t cmd_len = 0;

if (input_cmd == 0)
input_cmd = "";

if (path == 0)
path = "";

buf = malloc(sizeof(char) * (string_length(path)
			+ string_length(input_cmd) + 2));
if (!buf)
return (NULL);

while (path[path_len])
{
buf[path_len] = path[path_len];
path_len++;
}

if (path[path_len - 1] != '/')
{
buf[path_len] = '/';
path_len++;
}
while (input_cmd[cmd_len])
{
buf[path_len + cmd_len] = input_cmd[cmd_len];
cmd_len++;
}
buf[path_len + cmd_len] = '\0';
return (buf);
}
