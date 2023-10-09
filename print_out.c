#include "shell.h"

/**
 * print_out - creates a function that can print to the standard output
 * standard input - stdin - 0
 * standard output - stdout - 1
 * standard error - 2 diagnostic output
 *
 */

void print_out(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
