#include "shell.h"

/**
 * exit_command - Frees resources and exits the shell.
 *
 * Function is responsible for freeing allocated memory and safely exiting
 * the shell. It takes care of releasing the memory used for the input line
 * and the tokenized input command. After cleanup, it gracefully exits the
 * shell with a status code of 0.
 *
 * @input_cmd: Tokenized user input.
 * @line: The input line obtained from the `getline` function.
 */
void exit_command(char **input_cmd, char *line)
{
	free(line);
	free_buffers(input_cmd);
	exit(0);
}
