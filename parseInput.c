#include "shell.h"

/**
 * parseInput - parses/tokenizes input into string vector
 * @inPut: object string
 * @cmdS: destination string vector
 * @delim: delimiter to be fed to splitting/tokenizing function
 * Return: 0 if inPut parsed to cmdS, -1 otherwise
 */

int parseInput(char *inPut, char *cmdS[], char *delim)
{
	int iter = 0;
	char *cmdT = NULL, *dup = NULL;

	for (dup = inPut, iter = 0; (cmdT = goFission(&dup, delim)); iter++)
		cmdS[iter] = cmdT;

	if (cmdT != NULL)
		cmdT = NULL;

	if (dup != NULL)
		free(dup), dup = NULL;

	return (*cmdS ? 0 : -1);
}
