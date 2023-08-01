#include "shell.h"

/**
 * emptyInput - judges if input is only space characters
 * @inPut: input string
 * Return: 0 if empty, 1 otherwise
 */

int emptyInput(char *inPut)
{
	int iter = 0;
	size_t spc = 0;

	if (inPut)
		for (iter = 0; inPut[iter]; iter++)
			if (inPut[iter] == ' ' ||
			    inPut[iter] == '\n' ||
			    inPut[iter] == '\t' ||
			    inPut[iter] == '\r')
				spc++;

	return (spc == strlen(inPut) ? 0 : 1);
}
