#include "shell.h"

/**
 * _strlen - Calculates length of string.
 * @str: The string to measure.
 *
 * Return: The length of the string.
 */

size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
	len++;

	return len;
}

/**
 * _puts - Writes a string to std output.
 * @str: The string to write.
 */

void _puts(const char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * print_environment - Prints the current environment variables.
 */

void print_environment()
{
	extern char **environ;
	char **env_copy = environ;

	 for (char **env = env_copy; *env != NULL; env++)
	{
	_puts(*env);
	_puts("\n");
	}
}

int main()
{
	char *command[] = {"env", NULL};
	if (builtin_checker(command))
	{
	print_env();
	}

    return (0);
}
