#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 *Logical_operators : function handles && and || shell logical operators
 *
 */

int execute_instruction(char *instruction)
{
    char *args[MAX_INPUT_SIZE];
    int i = 0;
    char *token = strtok(command, " \t\n");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;

    if (i == 0) {
        return 0;
    }

    if (strcmp(args[0], "cd") == 0)
	{
        return (1);
	}
	 else if (strcmp(args[0], "exit") == 0)
	 {
        return (1);
	} 
	else
	{
        pid_t pid = fork();
        if (pid == 0)
	{
	execvp(args[0], args);
	perror("execvp");
	exit(1);
	} else if (pid < 0) {
	perror("fork");
	return (0);
        } else {
	int status;
	wait(&status);
	return WIFEXITED(status) ? WEXITSTATUS(status) : 0;
        }
    }
}

int main() {
    char input[MAX_INPUT_SIZE];


    char *token = strtok(input, ";");
    int success = 1;
    while (token != NULL) {
        int result;
        if (success) {
            result = execute_instruction(token);
        } else {
            result = 0;
        }

        if (strstr(token, "&&")) {
            success = result;
        } else if (strstr(token, "||")) {
            success = !result;
        }

        token = strtok(NULL, ";");
    }

    return (0);
}

