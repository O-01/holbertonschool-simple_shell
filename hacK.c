#include "shell.h"

/**
 * hacK - checks status of PATH & PWD environmental variables
 * Return: 0 if PATH & PWD, 1 if PATH NULL, 2 if PWD NULL
 */

int hacK(void)
{
	int hack = 0;
	char *chk1 = NULL, *chk2 = NULL;

	chk1 = getenvY("PATH"); /* retrieve PATH enironmental variable value */
	if (!chk1)
	{
		free(chk1), chk1 = NULL;
		return (1);
	}
	chk2 = getenvY("PWD"); /* retrieve PWD environmental variable value */
	if (!chk2)
	{
		free(chk2), chk2 = NULL;
		return (2);
	}

	if (chk1)
		free(chk1), chk1 = NULL;
	if (chk2)
		free(chk2), chk2 = NULL;

	return (hack);
}
