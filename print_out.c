#include "shell.h"

/**
* _putchar - Writes the character to the standard output.
* @ch: The character to be written.
*
* Return: 1 on success, -1 on error with errno set accordingly.
*/
int _putchar(char ch)
{
return write(1, &ch, 1);
}

/**
* print_str - Prints a given string to the standard output.
* @str: The string to be printed.
*
* Return: the number of characters printed. If an error occurs,
* it returns -1.
*/
int print_str(char *str)
{
int char_count = 0;
int i = 0;

for (; str[i] != '\0'; i++)
{
if (_putchar(str[i]) == -1)
{
return (-1); /* Handle errors by returning -1 */
}
char_count++;
}

return (char_count);
}
