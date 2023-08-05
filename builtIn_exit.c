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
	int status = 0, cod3 = 0, yes = 0, iter = 0;

	if (!code)
	{
		freecmdS(cmdS);
		if (input)
			free(input);
		exit(0);
	}
	if (code)
	{
		cod3 = atoi(code), status = cod3;
		for (iter = 0; code[iter]; iter++)
			if (code[iter] < '0' || code[iter] > '9')
			{
				yes = 1;
				break;
			}
	}
	if (yes == 1 || status < 0)
	{
		fprintf(stderr,
			"./hsh: 1: %s: Illegal number: %s\n",
			cmdS[0], code);
		freecmdS(cmdS);
		if (input)
			free(input);
		exit(2);
	}
	if (input)
		free(input);
	freecmdS(cmdS), exit(status);

	return (0);
}
