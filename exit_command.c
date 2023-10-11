#include "shell.h"

/**
 * builtin_checker - Determine if the user input corresponds to a built-in
 * command or an external command.
 *
 * This function checks whether the given user input corresponds to a built-in
 * command. If it's a built-in command, it executes it. If not, it treats the
 * user input as an external command and attempts to execute it.
 *
 * @user_input_cmd: Tokenized user input.
 * @line: The input line obtained from the `getline` function.
 *
 * Return: 1 if the command is executed, 0 if it's not executed.
 */
void exit_command(char **input_cmd, char *line)
{
	free(line);
	free_buffers(input_cmd);
	exit(0);
}
