#include "jael.h"

/**
 * str_len - Calculates the length of a string
 * @str: String that needs length to be found
 * Return: Length of a string if success. 0 otherwise
 */
int str_len(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
 * double_free - Free double pointer variables
 * @to_be_freed: The address of the elements that need to be freed
 */
void double_free(char **to_be_freed)
{
	int index;

	for (index = 0; to_be_freed[index] != NULL; index++)
		free(to_be_freed[index]);
	free(to_be_freed);
}

/**
 * single_free - Free n amount of pointers to a string
 * @n: the number of pointers to free
 */
void single_free(int n, ...)
{
	int i;
	char *str;
	va_list a_list;

	va_start(a_list, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(a_list, char*);
		if (str == NULL)
			str = "(nil)";
		free(str);
	}
	va_end(a_list);
}

/**
 * print_error - Prints an error message when a command is not found.
 * @count: A counter that keeps track of the number of commands run
 * @av: The name of the program running the shell
 * @command: The specific command not being found
 */
void print_error(char *av, int count, char *command)
{
	print_str(av, 1);
	print_str(": ", 1);
	print_number(count);
	print_str(": ", 1);
	print_str(command, 1);
}

/**
 * exec_error - Prints execution errors
 * @av: Name of the program running the shell
 * @count: A counter that Keeps track of number of command entered
 * @tmp_command: the command that is filed
 */
void exec_error(char *av, int count, char *tmp_command)
{
	print_error(av, count, tmp_command);
	print_str(": ", 1);
	perror("");
	exit(1);
}
