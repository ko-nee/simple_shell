#include "shell.h"

/**
 *read_string - function that takes user input
 *@string - input from the user entered on the interface
 *@size - length of string in character count
 *
 */

void read_string(char *string, side_t size);
{
	if (fgets(string, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
		print_out("\n");
		exit(EXIT_SUCCESS);
		}
		else
		{
		print_out("Error while reading input.\n");
		exit(EXIT_FAILURE);
		}
	}
	string[strcspn(string, "\n")] = '\0';
}

/**
 *print_out - creates a function that can print to the standard output
 *@string - output printed out onto the interface
 *
 */

void print_out(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
