# Jael Simple Shell


A simple UNIX command interpreter written as part of the low-level programming 

# Description

 
Jael is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

# Compilation


The shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Once compiled, to start the program, run:

./hsh

To exit the program, run:

Jael $ exit


The Jael shell supports most shell commands, such as cd, pwd, cat, echo, ls, -la and more.


# Built-Ins


The following built-ins are supported by the Jael shell:


env - Print the current environment

setenv VARIABLE VALUE - Initialize a new environment VARIABLE with VALUE, or modify an existing VARIABLE with VALUE

unsetenv VARIABLE - Remove an environment VARIABLE

cd - Changes the current working directory to the paramenters passed to cd

exit - Exit the shell

# Helper Functions


str_len - Calculates length of a string

double_free - Free double pointer variables

single_free - Free n amount of pointers to a string

print_error - Print a message error when a command is not found

exec_error - Prints execution error

# Return Value

Jael shell will exit with status 0 unless status is specified with syntax exit VALUE.

#List of Functions

parse_line - Parses the command line looking for commands and argumements.

create_Child - Forks the current process in order to execute another program.

tokenize - Separates a string in to an array of tokens based on a delimiter passed to the function.

count_token - Counts how many tokens are on a given string that is separated by a delimeter.

find_path - Looks through the environmental variables untill it finds the PATH variable, It then returns the index of its possition.

tokenize_path - Separates the PATH variable into separate strings each containing a directory in the PATH.

search_directories - Looks through directories stored in path_tokens for a specifc file name which represents a command.

build_path - Combines two strings, one representing the path directory and the other representing the command file.

_strcmp - Compares two strings and if they match the function returns 0.

_strdup - Duplicates a string.

print_str - Prints a string character by character.

cd_b - Changes the current working directory to the parameter passed to the command cd.

env_b - Prints all environmental variables available in the current shell.

check_built_ins - Checks if a command exitst as a builtin funcition and then it returns a pointer to the right function.
