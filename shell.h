#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> // for std input/output.h 
#include <stdlib.h> // for specific MAKROS
#include <string.h> // for strlen function
#include <unistd.h> // for the write function

void flashing_prompt(void);
void execute_instruction(const char *instruction);
void print_out(const char *string);


#endif
