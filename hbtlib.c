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
