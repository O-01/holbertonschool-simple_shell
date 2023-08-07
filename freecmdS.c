#include "shell.h"

/**
 * freecmdS - frees memory related to cmdS argv created in main
 * @cmdS: argument vector
 */

void freecmdS(char **cmdS)
{
	int iter = 0;

	for (iter = 0; cmdS[iter]; iter++)
		cmdS[iter] = NULL;

	if (*cmdS)
		free(*cmdS), *cmdS = NULL;
}
