#include "shell.h"

/**
 *flashing_prompt - function that showsthe flashing prompt
 *
 *does not take any parameters - void
 */

void flashing_prompt(void)
{
<<<<<<< HEAD
	print_out("maswari_shell$ ");
=======
if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
set_flags.interactive = 1;
if (set_flags.interactive)
write(STDERR_FILENO, "MASWARI-SHELL$ ", 15);
>>>>>>> ca6847ddb6d03a99fb406d7ece46650f885d1434
}
