#include "shell.h"

/**
 * getenvY - custom getenv function
 * @varNam: name of environmental variable to be retrieved
 * Return: requested environmental variable
 */

char *getenvY(char *varNam)
{
	int iter = 0, yes = 0;
	size_t varLen = 0;
	char *eVar = NULL, *graB = NULL, *enV = NULL, *enV1 = NULL;
	char *enVal = NULL, *eq = "=";
	char *choP[MAX_LEN] = { NULL };

	if (!varNam)
		return (NULL);
	eVar = str_concat(varNam, eq);
	for (iter = 0, varLen = strlen(eVar); environ[iter]; iter++)
		if (strncmp(eVar, environ[iter], varLen) == 0)
		{
			graB = environ[iter], yes = 1;
			break;
		}
	if (yes == 1)
	{
		enV = malloc(sizeof(char) + MAX_LEN);
		if (!enV)
			return (NULL);
		strcpy(enV, graB), graB = NULL;
		for (iter = 0, enV1 = enV;
		     (choP[iter] = goFission(&enV1, "=")) != NULL;
		     iter++)
			;
		if (!strlen(choP[1]))
			choP[1] = "";
		enVal = malloc(sizeof(char) + MAX_LEN);
		if (!enVal)
			return (NULL);
		strcpy(enVal, choP[1]);
		free(eVar), eVar = NULL, free(enV), enV = NULL,	freecmdS(choP);
		return (enVal);
	}
	free(eVar), eVar = NULL;
	return (NULL);
}
