#include "shell.h"

/**
 * read_string - Function that takes user input.
 * @string: Pointer to the character array where the input will be stored.
 * @size: The maximum number of characters to read.
 *
 * This function reads a line of input from the standard input (stdin) and
 * stores it in the 'string' buffer, up to 'size' characters. It removes the
 * newline character from the end if present.
 */

void read_string(char *string, size_t size)
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
	string[strcspn(string, "\n")] = '\0'; /* Remove newline character if present*/
}
