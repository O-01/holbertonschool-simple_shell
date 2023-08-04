#include "shell.h"

/**
 * obtainPath - processes PATH env var for stat/access use
 * @cmdS: command to be appended with slash to individual PATH directories
 * Return: 0 upon success, -1 upon malloc failure
 */

char **obtainPath(char *cmdS)
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
