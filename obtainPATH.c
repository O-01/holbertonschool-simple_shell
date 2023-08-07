#include "shell.h"

/**
 * obtainPATH - processes PATH env var for stat/access use
 * @cmdS: command to be appended with slash to individual PATH directories
 * Return: processed PATH elements for use in spoon function, NULL upon malloc
 * failure, input vector unavailable, or PATH variable empty/unaccessible
 */

char **obtainPATH(char *cmdS)
{
	int mem = 0;
	char *tehPath = NULL, *chop = NULL;
	char **chopDir = NULL, **outPut = NULL;

	if (!cmdS)
		return (NULL);

	tehPath = getenvY("PATH");
	if (!tehPath)
		return (NULL);

	mem = memCalcPATH(tehPath, cmdS);
	chop = malloc(sizeof(char) * mem);
	if (!chop)
		return (NULL);
	chopDir = deColon(tehPath, chop);
	outPut = slashCMD(chopDir, cmdS);

	free(chopDir), free(chop), free(tehPath);

	return (outPut);
}
