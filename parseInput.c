#include "shell.h"

/**
 * parseInput - parses/tokenizes input into string vector
 * @inPut: object string
 * @cmdS: destination string vector
 * @delim: delimiter to be fed to splitting/tokenizing function
 * Return: 1 if inPut parsed to cmdS, 0 if not, -1 otherwise
 */

int parseInput(char *inPut, char *cmdS[], char *delim)
{
	int iter = 0;
	char *cmdT = NULL, *dup = NULL;

	if (!inPut || !delim)
		return (-1);
	/* segment input by delimiter using goFission (strsep loop) function */
	for (dup = inPut, iter = 0; (cmdT = goFission(&dup, delim)); iter++)
		cmdS[iter] = cmdT; /* loads new segments into segment vector */

	if (cmdT != NULL)
		cmdT = NULL;

	if (dup != NULL)
		free(dup), dup = NULL;

	return (iter > 0 ? 1 : 0);
}
