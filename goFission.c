#include "shell.h"

/**
 * goFission - splits/tokenizes input string per delimiter(s)
 * @input: input
 * @delim: delimiter(s) by which input is to be divided
 * Return: next acceptable instance of input, NULL otherwise
 */

char *goFission(char **input, char *delim)
{
	char *cmdT = NULL;

	while ((cmdT = strsep(input, delim)) && !*cmdT)
		;

	return (cmdT);
}