#include "shell.h"

/**
* execute_builtin - Execute built-in commands if they
* are present in the user's input.
*
* This function checks if the provided command is a built-in command
* (e.g., "env_var" or "exit"). If the command is a built-in, it is executed.
* Otherwise, the function returns 0.
*
* @input_cmd: Tokenized user input.
* @line: The input read from stdin.
*
* Return: 1 if a built-in command is executed, 0 if not.
*/
int execute_builtin(char **input_cmd, char *line)
{
struct builtin builtin = {"env_var", "exit"};

if (string_compare(*input_cmd, builtin.env_var) == 0)
{
print_env_var();
return (1);
}
else if (string_compare(*input_cmd, builtin.exit) == 0)
{
exit_command(input_cmd, line);
return (1);
}
return (0);
}
