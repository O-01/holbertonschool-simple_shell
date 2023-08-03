#include "shell.h"

/**
 * obtainPath - processes PATH env var for stat/access use
 * @cmdS: command to be appended with slash to individual PATH directories
 * Return: 0 upon success, -1 upon malloc failure
 */

int obtainPath(char *cmdS)
{
	int iter = 0, colon = 0;
	char slash[MAX_LEN] = "/", *slashed = NULL;
	char *grabPath = NULL, *pathVar = "PATH=", *patH = NULL;
	char *enV = NULL, *enV1 = NULL, *chop = NULL, *chop1 = NULL;
	char *chopPath[BUFSIZ] = { NULL }, *chopDir[BUFSIZ] = { NULL };

	for (iter = 0; environ[iter]; iter++)
		if (strncmp(environ[iter], pathVar, 5) == 0)
			grabPath = environ[iter];
	enV = malloc(sizeof(char) * (strlen(grabPath) + 1));
	if (!enV)
		return (-1);
	strcpy(enV, grabPath), grabPath = NULL;
	for (iter = 0, enV1 = enV;
	     (chopPath[iter] = goFission(&enV1, "=")) != NULL;
	     iter++)
		;
	for (iter = 0; chopPath[1][iter]; iter++)
		if (chopPath[1][iter] == ':')
			colon++;
	colon++;
	colon *= (strlen(cmdS) + 1);
	colon += (strlen(chopPath[1]) + 1);
	chop = malloc(sizeof(char) * colon);
	if (!chop)
		return (-1);
	strcpy(chop, chopPath[1]);
	for (iter = 0, chop1 = chop;
	     (chopDir[iter] = goFission(&chop1, ":"));
	     iter++)
		;
	slashed = strcat(slash, cmdS);
	for (iter = 0; chopDir[iter] != NULL; iter++)
	{
		patH = str_concat(chopDir[iter], slashed);
		printf("%s\n", patH), free(patH), patH = NULL;
	}
	freecmdS(chopDir), freecmdS(chopPath), free(chop), free(enV);
	return (0);
}
