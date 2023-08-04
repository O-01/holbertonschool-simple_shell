#include "shell.h"

/**
 * obtainPath - processes PATH env var for stat/access use
 * @cmdS: command to be appended with slash to individual PATH directories
 * Return: 0 upon success, -1 upon malloc failure
 */

char **obtainPath(char *cmdS)
{
	int iter = 0, mem = 0;
	char *grabPath = NULL, *enV = NULL, *enV1 = NULL, *chop = NULL;
	char *chopPath[MAX_LEN] = { NULL }, **chopDir = NULL, **outPut = NULL;

	if (!cmdS)
		return (NULL);

	grabPath = getenvY("PATH");

	enV = malloc(sizeof(char) * (strlen(grabPath) + 1));
	if (!enV)
		return (NULL);

	strcpy(enV, grabPath), grabPath = NULL;
	for (iter = 0, enV1 = enV;
	     (chopPath[iter] = goFission(&enV1, "=")) != NULL;
	     iter++)
		;

	mem = memCalcPATH(chopPath[1], cmdS);
	chop = malloc(sizeof(char) * mem);
	if (!chop)
		return (NULL);
	chopDir = deColon(chopPath[1], chop);
	outPut = slashCMD(chopDir, cmdS);

	free(chopDir);
	freecmdS(chopPath), free(chop), free(enV);

	return (outPut);
}
