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

	if (code)
	{
		for (iter = 0; code[iter]; iter++)
			if (code[iter] < '0' || code[iter] > '9')
			{
				yes = 1;
				break;
			}
	}
	if (yes == 1)
	{
		printf("./hsh: 1: %s: Illegal number: %s\n", cmdS[0], code);
		freecmdS(cmdS);
		if (input)
			free(input);
		exit(2);
	}
	cod3 = atoi(code), status = cod3;
	if (status < 0)
	{
		printf("./hsh: 1: %s: Illegal number: %d", cmdS[0], status);
		freecmdS(cmdS);
		if (input)
			free(input);
		exit(2);
	}
/* ^ Above redundant ? */
	if (input)
		free(input);
	freecmdS(cmdS), exit(status);

	return (0);
}
