#include "shell.h"

/**
 *flashing_prompt - function that showsthe flashing prompt
 *
 *does not take any parameters - void
 */

void flashing_prompt(void)
{
if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
set_flags.interactive = 1;
if (set_flags.interactive)
write(STDERR_FILENO, "$ ", 2);
}
