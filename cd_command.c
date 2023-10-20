#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * cd_command - Change the current directory of the process.
 *
 * @args: An array of strings containing the command and argument.
 *
 * Return: 0 on success, 1 on failure.
 */

int cd_command(char **args)
{
	char *new_dir = NULL;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
	new_dir = getenv("HOME");
	}
	else if (strcmp(args[1], "-") == 0) 
	{
	new_dir = getenv("OLDPWD");

	if (new_dir)
	{
	write(STDOUT_FILENO, new_dir, strlen(new_dir));
	write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
	new_dir = args[1];
	}
	if (new_dir != NULL)
	{
	char current_dir[1024];
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
	perror("getcwd");
	return (1);
	}

	if (chdir(new_dir) != 0)
	{
	perror("chdir");
	return (1);
	}
	if (update_pwd_env(getcwd(NULL, 0)) != 0) {
 	perror("update PWD");
 	return (1);
	}

	if (update_pwd_env(current_dir) != 0)
	{
        perror("update OLDPWD");
	return (1);
	}
	else 
	{
	write(STDERR_FILENO, "cd: HOME not set\n", 17);
	return (1);
	}
	return (0);
}

