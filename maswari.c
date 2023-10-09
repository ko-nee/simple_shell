#include "shell.h"

/**
 * main entry point - evokes the prompt on the terminal
 *
 */

int main(void)
{
	char instruction[150]; //allocated space for the characters

	while (1) //infinite loop, keeps prompt flashing
	{
	flashing_prompt();
	read_instruction(instruction, sizeof(instruction));
	execute_instruction(instruction);
	}

	return (0);
}
