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

while (*env_ptr)
{
if (string_compare_n(*env_ptr, "PATH=", 5) == 0)
{
path = *env_ptr;
while (*path && a < 5)
{
path++;
a++;
}
return (path);
}
env_ptr++;
}
return (NULL);
}
