#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void flashing_prompt(void);
void execute_instruction(const char *instruction);
void print_out(const char *string);

/* String manipulation function */
int string_compare(char *str1, char *str2);
int string_length(char *str);
int string_compare_n(char *str1, char *str2, int n);
char *string_duplicate(const char *str);
char *string_search(char *str, char c);

struct builtin
{
	char *env_var;
	char *exit;
} builtin;
#endif
