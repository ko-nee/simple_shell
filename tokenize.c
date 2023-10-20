#include "shell.h"

/**
* tokenize_input - Tokenize a given input line into an array of strings.
* @input: The input line to be tokenized.
*
* Return: An array of strings (tokens) on success, or NULL on failure.
*/
char **tokenize_input(char *input)
{
char *buf_input = NULL, *buf_ptr = NULL, *token = NULL;
char *delimiter = " :\t\r\n";
char **tokens = NULL;
int tokencount = 1;
size_t index = 0, flag = 0;

buf_input = string_duplicate(input);
if (!buf_input)
return (NULL);
buf_ptr = buf_input;

while (*buf_ptr)
{
if (string_search(delimiter, *buf_ptr) != NULL && flag == 0)
{
tokencount++;
flag = 1;
}
else if (string_search(delimiter, *buf_ptr) == NULL && flag == 1)
flag = 0;
buf_ptr++;
}
tokens = malloc(sizeof(char *) * (tokencount + 1));
token = strtok(buf_input, delimiter);
while (token)
{
tokens[index] = string_duplicate(token);
if (tokens[index] == NULL)
{
free(tokens);
return (NULL);
}
token = strtok(NULL, delimiter);
index++;
}
tokens[index] = '\0';
free(buf_input);
return (tokens);
}
