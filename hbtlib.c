#include "jael.h"

/**
 * _strcmp - compares two strings
 * @s1: String 1
 * @s2: String 2
 * Return: 0 if strings match,  and -1 if otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (str_len(s1) != str_len(s2))
		return (-1);

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}

	return (0);
}

/**
 * _strdup - create a copy of a string
 * @src: contains the original string
 * Return: Gives back the copy of string
 */
char *_strdup(char *src)
{
	int i, len;
	char *dest;

	len = str_len(src);
	dest = malloc(sizeof(char) * (len + 1));

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	
	dest[i] = '\0';

	return (dest);
}

/**
 * print_str - Print a string character by character
 * @str: String to be printed. 
 * Prints (null) if the string is NULL
 * @new_line: A new line will be printed if integer is 0
 * Nothing will be printed otherwise
 */
void print_str(char *str, int new_line)
{
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		write(STDOUT_FILENO, &str[i], 1);

	if (new_line == 0)
		write(STDOUT_FILENO, "\n", 1)
}
