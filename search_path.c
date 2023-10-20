#include "shell.h"

/**
* search_path - Locate the PATH environment variable within
* the global environment.
*
* This function is designed to search for the "PATH" environment variable in
* the global environment variable array. It will return the path if found.
*
* Return: A pointer to the PATH string if it's found, or NULL if it's
* not found.
*/
char *search_path(void)
{
char **env_ptr = environ;
char *path = NULL;
int a;

int a = 0;

while (*env_ptr)
{
if (strncmp(*env_ptr, "PATH=", 5) == 0)
{
path = *env_ptr + 5;
return (path);
}
env_ptr++;
}
return (NULL);
}
