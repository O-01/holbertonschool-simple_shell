#include "shell.h"

/**
 * deColon - divides input string into several based on colons present
 * @src: input string to be divided
 * @chop: empty input string to take copy of src, to be freed elsewhere
 * Return: populated string vector, upon success, NULL upon mem alloc failure
 */

char **deColon(char *src, char *chop)
{
	int iter = 0;
	char *chop1 = NULL;
	char **chopDir = NULL;

	if (!src || !chop)
		return (NULL);

	chopDir = malloc(sizeof(char *) + MAX_LEN);
	if (!chopDir)
		return (NULL);

	strcpy(chop, src);
	for (iter = 0, chop1 = chop;
	     (chopDir[iter] = goFission(&chop1, ":"));
	     iter++)
		;

	return (chopDir);
}
