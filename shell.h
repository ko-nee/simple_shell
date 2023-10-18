#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/* Shell built-ins */
void interactive_mode(int sig_num);
void print_env_var(void);
void flashing_prompt(void);
void execute_instruction(char *cmd_path, char **cmd_args);
void print_out(const char *string);
int builtin_checker(char **user_input_cmd, char *line);
void exit_command(char **input_cmd, char *line);
char *add_path(char *path, char *input_cmd);
int execute_builtin(char **input_cmd, char *line);
char *find_exec_path(char **directories, char *input_cmd);
void free_buffers(char **buffers);
char **tokenize_input(char *input);

/* String manipulation function */
int string_compare(char *str1, char *str2);
int string_length(char *str);
int string_compare_n(char *str1, char *str2, int n);
char *string_duplicate(char *str);
char *string_search(char *str, char c);
int shell_builtin(char **user_input_cmd, char *line);
char *search_path(void);

struct builtin
{
	char *env_var;
	char *exit;
} builtin;

struct set_flags
{
	bool interactive;
} set_flags;

struct info_t
{
	int final_exit;
	int ln_count;
} info_t;

extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
#endif
