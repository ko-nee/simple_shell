#include "shell.h"

/**
 * print_env_var - Print the environment variables to standard output.
 *
 * This function iterates through the environment variables and prints
 * each one, followed by a newline, to the standard output.
 */
void print_env_var(void)
{
int index = 0;
char **env = environ;

while (env[index])
{
write(STDOUT_FILENO, env[index], string_length(env[index));
write(STDOUT_FILENO, "\n", 1);
index++;
}
}

