#include "shell.h"

/**
* free_buffers - Deallocate memory used for a list of buffers.
* @buffers: The list of buffers to be freed.
*
* This function frees each buffer in the list and the list itself.
*/
void free_buffers(char **buffers)
{
int index = 0;

if (buffers == NULL)
return;

while (buffers[index])
{
free(buffers[index]);
index++;
}

free(buffers);
}
