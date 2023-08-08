#include "shell.h"

/**
 * goFission - splits/tokenizes input string per delimiter(s)
 * (ideal application in loops)
 * @input: input
 * @delim: delimiter(s) by which input is to be divided
 * Return: non-empty tokenized segment from input string, NULL otherwise
 */

char *goFission(char **input, char *delim)
{
	char *cmdT = NULL;

	/* pull first non-empty string from input segmented by delimiter */
	while ((cmdT = strsep(input, delim)) && !*cmdT)
		;

	return (cmdT);
}
