#include "shell.h"

/**
 * builtIn_exit - built-in provision for terminal exit upon command
 * @code: exit code, if desired
 * @input: CLI input from main to be freed, if necessary
 * @cmdS: argument vector parsed from input, to be freed
 * Return: 0, if exit fails
 */

int builtIn_exit(char *code, char *input, char **cmdS)
{
	int status = 0, cod3 = 0;

	if (code)
		cod3 = atoi(code), status = cod3;

	freecmdS(cmdS);
	if (input)
		free(input);

	exit(status);

	return (0);
}
