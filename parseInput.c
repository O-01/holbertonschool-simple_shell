#include "shell.h"

/**
 * parseInput - parses/tokenizes input into string vector
 * @inPut: object string
 * @cmdS: destination string vector
 * Return: 0 if inPut parsed to cmdS, 1 otherwise
 */

int parseInput(char *inPut, char *cmdS[])
{
	int iter = 0;
	char *cmdT = NULL, *dup = NULL;

	dup = inPut;
	for (iter = 0; (cmdT = nonVoid(&dup)); iter++)
	{
		cmdS[iter] = cmdT;
		if (strcmp("exit", cmdS[0]) == 0)
		{
			freecmdS(cmdS);
			if (inPut)
				free(inPut);
			exit(0);
		}
	}
	if (cmdT != NULL)
		cmdT = NULL;

	if (dup != NULL)
		free(dup), dup = NULL;

	return (*cmdS ? 0 : -1);
}
