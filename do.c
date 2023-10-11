#include "shell.h"

/**
 *execute_instruction-function that executes the prompt
 *
 * @instruction: this parameter takes a string
 */

void execute_instruction(const char *instruction)
{
	/* _t for tracking the processes, fork executes child process */
	pid_t child_pid = fork();

	if (child_pid == -1) /* means error */
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
	/* child process to execute:set number */
	execlp(instruction, instruction, (char *)NULL);
	perror("execlp");
	exit(EXIT_FAILURE);
	}
	else
	{
	/* parent process waits for the child process first */
	wait(NULL)
	}
}
