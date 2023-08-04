#include "shell.h"

/**
 * getenvY - custom getenv function
 * @varNam: name of environmental variable to be retrieved
 * Return: requested environmental variable
 */

char *getenvY(char *varNam)
{
	int iter = 0;
	size_t varLen = 0;
	char *eVar = NULL, *enV = NULL;

	if (!varNam)
		return (NULL);

	eVar = str_concat(varNam, "=");

	for (iter = 0, varLen = strlen(varNam) + 1; environ[iter]; iter++)
	{
		if (strncmp(environ[iter], eVar, varLen) == 0)
		{
			enV = environ[iter];
			break;
		}
	}

	free(eVar), eVar = NULL;

	return (enV);
}
