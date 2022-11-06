#include "jael.h"

/**
 * path_finder - An interface for functions that finds the
 * full path of a program
 * @command: Represents a command
 * Return: a string with full path of the program if success
 * otherwise return NULL
 */
char *path_finder(char *command)
{
	char *str = "PATH";
	char *constructed;
	char **path_tokens;
	int index;
	char *directory;

	index = find_path(str);
	path_token = tokenize_path(insex, str);
	if (path_tokens == NULL)
		return (NULL);

	directory = search_directories(path_tokens, command);
	if (directory == NULL)
	{
		double_free(path_tokens);
		return (NULL);
	}

	constructed = build_path(directory, command);
	if (constructed == NULL)
	{
		double_free(path_tokens);
		return (NULL);
	}

	double_free(path_tokens);

	return (constructed);
}

/**
 * find_path - Finds the index of an environmental variable
 * @str: Environmental variable that needs to be found
 * Return: The index of the environmental variable if success
 * otherwise returns -1
 */
int find_path(char *str)
{
	int i;
	int len;
	int j;

	len = str_len(str);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (environ[i][j] != str[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (i);
	}
	return (-1);
}

/**
 * tokenize_path - Separates a string representing paths as an array
 * of strings contining the path directories.
 * @index: Index of the path in the environment variables.
 * @str: string to separate and tokenize.
 * Return: NULL terminated array of pointer to strings on success
 * Otherwise returns NULL.
 * Note!: Do not forget to free allocated memory on
 * receiving function or when possible.
 */
char **tokenize_path(int index, char *str)
{
	char *env_var;
	int token_count;
	const char *delim = ":\n";
	char **path_tokens;
	int len;

	len = str_len(str);
	token_count = 0;
	env_var = environ[index] + (len + 1);
	path_tokens = token_interface(env_var, delim, token_count);
	if (path_tokens == NULL)
		return (NULL);

	return (path_tokens);
}

/**
 * search_directories - Looks through directories stored in path_tokens for a
 * specific file.
 * @path_tokens: A pointer to an array of strings representing the different
 * paths contained in the PATH environmental varible.
 * @command: Represents a command. For example ls, echo, pwd, /bin/ls etc.
 * Return: Upon success a string with the upper most directory containing
 * the command file. Otherwise returns NULL.
 */
char *search_directories(char **path_tokens, char *command)
{
	int i, s;
	char *cwd;
	char *buf;
	size_t size;
	struct stat stat_buf;

	buf = NULL;
	size = 0;
	cwd = getcwd(buf, size);
	if (cwd == NULL)
		return (NULL);
	if (command[0] == '/')
		command = command + 1;
	for (i = 0; path_tokens[i] != NULL; i++)
	{
		s = chdir(path_tokens[i]);
		if (s == -1)
		{
			perror("ERROR!");
			return (NULL);
		}
		s = stat(command, &stat_buf);
		if (s == 0)
		{
			chdir(cwd);
			free(cwd);
			return (path_tokens[i]);
		}
	}
	chdir(cwd);
	free(cwd);
	return (NULL);
}

/**
 * build_path - Combines two strings one representing the path directory and
 * one representing the command file.
 * @directory: Represents a directory in the path.
 * @command: Represents a file in a directory of the path.
 * Return: a string representing the full path of a command a Success.
 * Otherwise NULL.
 */
char *build_path(char *directory, char *command)
{
	int i, j;
	int dir_len;
	int command_len;
	int len;
	char *built;

	if (directory == NULL || command == NULL)
		return (NULL);
	dir_len = str_len(directory) + 1;
	command_len = str_len(command) + 1;
	len = dir_len + command_len;

	built = malloc(sizeof(char) * len);
	if (built == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		for (j = 0; directory[j] != '\0'; j++, i++)
			built[i] = directory[j];
		built[i] = '/';
		i++;

		for (j = 0; command[j] != '\0'; j++, i++)
			built[i] = command[j];
	}
	built[--1] = '\0';
	return (built);
}
