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
	char *eVar, *graB = NULL, *enV = NULL, *enV1 = NULL;
	char *enVal = NULL;
	char *choP[MAX_LEN] = { NULL };

	if (!varNam)
		return (NULL);
	eVar = str_concat(varNam, "=");
	for (iter = 0, varLen = strlen(eVar); environ[iter]; iter++)
		if (strncmp(environ[iter], eVar, varLen) == 0)
		{
			graB = environ[iter], yes = 1;
			break;
		}
	if (yes == 1)
	{
		if (strlen(graB) == varLen)
		{
			free(eVar), eVar = NULL;
			free(enV), enV = NULL, freecmdS(choP);
			return (NULL);
		}
		enV = malloc(sizeof(char) * (strlen(graB) + 1));
		if (!enV)
			return (NULL);
		strcpy(enV, graB), graB = NULL;
		for (iter = 0, enV1 = enV;
		     (choP[iter] = goFission(&enV1, "=")) != NULL;
		     iter++)
			;
		enVal = malloc(sizeof(char) * (strlen(choP[1]) + 1));
		if (!enVal)
			return (NULL);
		strcpy(enVal, choP[1]);
		free(eVar), eVar = NULL, free(enV), enV = NULL,	freecmdS(choP);
		return (enVal);
	}
	free(eVar), eVar = NULL;
	return (NULL);
}
