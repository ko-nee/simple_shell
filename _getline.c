#include "shell.h"

/**
* _getline - Read input line by line and return the lines.
*
* This function reads input from the standard input (stdin) and
* returns lines as they are encountered. It uses a static buffer to
* minimize calls to the read system call.
*
* Return: (char *) A dynamically allocated string containing the next
* line from stdin, or NULL at the end of input.
*/
char *_getline(void)
{
static char buffer[BUFFER_SIZE];
static size_t buffer_index = 0;
static size_t line_length = 0;

char *line = NULL;

while (1)
{
if (buffer_index >= line_length)
{
line_length = fread(buffer, 1, BUFFER_SIZE, stdin);
buffer_index = 0;

if (line_length == 0)
{
return (NULL); // End of input
}
}

size_t i;
for (i = buffer_index; i < line_length; i++)
{
if (buffer[i] == '\n')
{
line = (char *)malloc(i - buffer_index + 2);
if (line == NULL)
{
perror("Memory allocation error");
exit(1);
}
snprintf(line, i - buffer_index + 2, "%.*s", (int)(i - buffer_index + 1),
buffer + buffer_index);
buffer_index = i + 1;
return (line);
}
}

size_t remaining = line_length - buffer_index;
line = (char *)malloc(remaining + 1);
if (line == NULL) {
perror("Memory allocation error");
exit(1);
}
snprintf(line, remaining + 1, "%s", buffer + buffer_index);
buffer_index = line_length;
return (line);
}
}
