#include "shell.h"

/**
 * print_out - Print a string to the standard output.
 * @string: The string to be printed.
 *
 * This function writes the provided string to the standard output (stdout).
 * It uses the write function to achieve this.
 */
void print_out(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
