#include "shell.h"

/**
* interactive_mode - checks interative mode.
*
* This function is used to handle signals and maintain the
* interactivity of the shell. It writes a newline and prompt
* to standard error when a signal is received.
*
* @sig_num: The signal number.
*
* Return: Returns nothing.
*/
void interactive_mode(int sig_num)
{
(void)sig_num;
write(STDERR_FILENO, "\n", 1);
write(STDERR_FILENO, "MASWARI-SHELL$ ", 15);
}
