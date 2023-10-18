#include "shell.h"

/**
* tokenize_input - Tokenize a given input line into an array of strings.
* @input: The input line to be tokenized.
*
* Return: An array of strings (tokens) on success, or NULL on failure.
*/
char **tokenize_input(char *input)
{
char *input_copy = NULL, *token = NULL, *delimiter = " \t\r\n";
char **tokens = NULL;
int token_count = 0;
size_t index = 0, flag = 0;
char *input_ptr;

/* Duplicate the input string */
input_copy = string_duplicate(input);
if (!input_copy)
return NULL;

/* Count the number of tokens */
input_ptr = input_copy;
while (*input_ptr)
{
if (string_search(delimiter, *input_ptr) != NULL && flag == 0)
{
token_count++;
flag = 1;
}
else if (string_search(delimiter, *input_ptr) == NULL && flag == 1)
{
flag = 0;
}
input_ptr++;
}

/* Allocate memory for the tokens array */
tokens = malloc(sizeof(char *) * (token_count + 1));
if (!tokens)
{
free(input_copy);
return (NULL);
}

/* Tokenize the input and store the tokens */
token = strtok(input_copy, delimiter);
while (token)
{
tokens[index] = string_duplicate(token);
if (!tokens[index])
{
free(tokens);
free(input_copy);
return (NULL);
}
token = strtok(NULL, delimiter);
index++;
}
tokens[index] = NULL;

/* Clean up and return the tokens array */
free(input_copy);
return (tokens);
}
