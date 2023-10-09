#include "shell.h"

/**
 * - function that takes user input
 *
 *
 */

void read_string(char *string, side_t size);
{
	if(fgets(string, size, stdin) == NULL) {// can't use scanf, use fgets
		if (feof(stdin)) {
		print_out("\n");
		exit(EXIT_SUCCESS);
		} else {
	       	print_out("Error while reading input.\n");
		exit(EXIT_FAILURE);
		}
	}
	string[strcspn(string,"\n")] = '\0';
}
		
	
