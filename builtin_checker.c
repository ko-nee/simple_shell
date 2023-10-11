#include "shell.h"

/**
* builtin_checker - Check if the user_input_cmd is a built-in
* or an external command.
*
* This function checks if the given user_input_cmd is a built-in command
* and if so, it executes it. Otherwise, it treats the user_input_cmd as an
* external one and attempts to execute it.
*
* @user_input_cmd: Tokenized user input.
* @line: Line derived from the `getline` function.
*
* Return: 1 if the command is executed, 0 if it's not executed.
*/
int builtin_checker(char **user_input_cmd, char *line)
{
if (shell_builtin(user_input_cmd, line))
return 1;
else if (**user_input_cmd == '/')
{
execute_instruction(user_input_cmd[0], user_input_cmd);
return (1);
}
return (0);
}
