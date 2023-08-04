#include "shell.h"

/**
 * memCalcPATH - calculates memory to be allocated when handling PATH
 * @patH: input string suspected to contain colons
 * @cmdS: input command from main, necessary for calculation
 * Return: multiplier number for mem alloc calculation
 */

int memCalcPATH(char *patH, char *cmdS)
{
	int iter = 0, colon = 0;

	for (iter = 0; patH[iter]; iter++)
		if (patH[iter] == ':')
			colon++;

	colon++;
	colon *= (strlen(cmdS) + 1);
	colon += (strlen(patH) + 1);

	return (colon);
}
