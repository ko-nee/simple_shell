#include "shell.h"

/**
 *execute_instruction-function that executes the prompt
 * @cmd_path: The path to the command to execute.
 * @cmd_args: An array of command arguments.
 */

void execute_instruction(char *cmd_path, char **cmd_args)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cmd_path);
	if (child_pid == 0)
	{
		execve(cmd_path, cmd_args, env);
		perror(cmd_path);
		free(cmd_path);
		free_buffers(cmd_args);
		exit(98);
	}
	else
		wait(&status);
}
