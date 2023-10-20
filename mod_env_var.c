#include "shell.h"

/**
 * setenv_command - Create or modify an environment variable.
 * @input_cmd: An array of tokens containing the command and its arguments.
 */
void setenv_command(char **input_cmd)
{
	if (input_cmd[1] == NULL || input_cmd[2] == NULL)
	{	
	write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", strlen("Usage: setenv VARIABLE VALUE\n"));
	return;
	}

	    char *env_variable = malloc(strlen(input_cmd[1]) + strlen(input_cmd[2]) + 2);
	if (env_variable == NULL)
	{
	perror("malloc");
	return;
	}
	sprintf(env_var, "%s=%s", input_cmd[1], input_cmd[2]);

	if (putenv(env_var) != 0)
	{
	perror("putenv");
	free(env_var);
	return;
	}

	free(env_var);
}

