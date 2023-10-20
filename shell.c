#include "shell.h"
/**
* main - This function serves as the entry point for a loop that
* involves reading, executing, and printing output.
* @ac: The count of arguments.
* @av: An array of arguments.
* @env_arr: An array representing the environment.
*
* Return: 0 upon completion.
*/


int main(int ac, char **av, char *env_arr[])
{
char *line = NULL, *pathcommand = NULL, *path = NULL;
size_t buffer_size = 0;
ssize_t linesize = 0;
char **command = NULL, **paths = NULL;
(void)env_arr, (void)av;
if (ac < 1)
return (-1);
signal(SIGINT, interactive_mode);
while (1)
{
free_buffers(command);
free_buffers(paths);
free(pathcommand);
flashing_prompt();
linesize = getline(&line, &buffer_size, stdin);
if (linesize < 0)
break;
info_t.ln_count++;
if (line[linesize - 1] == '\n')
line[linesize - 1] = '\0';
command = tokenize_input(line);
if (command == NULL || *command == NULL || **command == '\0')
continue;
if (builtin_checker(command, line))
continue;
path = search_path();
paths = tokenize_input(path);
pathcommand = find_exec_path(paths, command[0]);
if (!pathcommand)
perror(av[0]);
else
execute_instruction(pathcommand, command);
}
if (linesize < 0 && set_flags.interactive)
write(STDERR_FILENO, "\n", 1);
free(line);
return (0);
}
