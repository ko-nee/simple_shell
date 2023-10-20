#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/* Function to execute a command */
void execute_command(char *command) {
    // Tokenize the command and arguments
    char *args[MAX_INPUT_SIZE];
    int i = 0;
    char *token = strtok(command, " \t\n");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;

    if (i == 0) {
        // Empty command; do nothing
        return;
    }

    // Check for built-in commands
    if (strcmp(args[0], "cd") == 0) {
        // Handle cd command
        // ...
    } else if (strcmp(args[0], "exit") == 0) {
        // Handle exit command
        // ...
    } else {
        // Execute external command
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp"); // Exec failed
            exit(1);
        } else if (pid < 0) {
            perror("fork");
        } else {
            // Parent process
            int status;
            wait(&status);
            if (WIFEXITED(status)) {
                // Handle exit status here, if needed
            }
        }
    }
}

int main()
{
    char input[MAX_INPUT_SIZE];

    char *token = strtok(input, ";");
	while (token != NULL) {

        write(STDOUT_FILENO, token, strlen(token));
        write(STDOUT_FILENO, "\n", 1);
        
        execute_command(token);
        token = strtok(NULL, ";");
    }

	return (0);
}

