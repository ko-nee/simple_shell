#include "shell.h"

/**
* string_compare - Compares two strings and calculates the difference
* between them.
* @str1: The first string to compare.
* @str2: The second string to compare.
*
* Return: The numerical difference between the strings.
*/
int string_compare(char *str1, char *str2)
{
int i = 0, output;

while (*(str1 + i) == *(str2 + i) && *(str1 + i) != '\0')
i++;

output = (*(str1 + i) - *(str2 + i));

return (output);
}

/**
* string_length - Calculates the length of a given string.
* @str: The string for which to determine the length.
*
* Return: The length of the input string.
*/
int string_length(char *str)
{
int count = 0;

while (*str != '\0')
{
count++;
str++;
}
return (count);
}

/**
* string_compare_n - Compares two strings up to a specified number
* of bytes.
* @str1: The first string to compare.
* @str2: The second string to compare.
* @n: The maximum number of bytes to compare.
*
* Return: The difference between the first 'n' bytes of the strings.
*/
int string_compare_n(char *str1, char *str2, int n)
{
int i;

for (i = 0; str1[i] && str2[i] && i < n; i++)
{
if (str1[i] != str2[i])
return (str1[i] - str2[i]);
}
return (0);
}

/**
* string_duplicate - Duplicates a provided string.
* @str: The string to be duplicated.
*
* Return: A pointer to a duplicate of the input string
* or NULL on failure.
*/
char *string_duplicate(char *str)
{
char *ptr;
int i, len;

if (str == NULL)
return (NULL);

len = strlen(str);

ptr = malloc(sizeof(char) * (len + 1));
if (!ptr)
return (NULL);
for (i = 0; *str != '\0'; str++, i++)
ptr[i] = str[0];

ptr[i++] = '\0';
return (ptr);
}

/**
* string_search - Locates the first occurrence of a character
* within a string.
* @str: The string to search.
* @c: The character to find.
*
* Return: A pointer to the first occurrence of 'c' in the
* string or NULL if not found.
*/
char *string_search(char *str, char c)
{
while (*str)
{
if (*str == c)
return (str);
str++;
}
if (!c)
return (str);
return (NULL);
}
