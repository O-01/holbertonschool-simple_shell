#include "shell.h"

/**
 * slashCMD - concatenates slash + cmdS to all strings in a vector
 * @dest: input vector, to all elements of which slash + cmdS to be appended
 * @cmdS: command from main
 * Return: strings concatenated with slash followed by input cmd
 */

char **slashCMD(char **dest, char *cmdS)
{
	int iter = 0;
	char slash[MAX_LEN] = "/", *slashed = NULL, *patH = NULL;
	char **slasher = NULL;

	if (!dest || !cmdS)
		return (NULL);

	slasher = _calloc(sizeof(char *) + MAX_LEN, 1);
	if (!slasher)
		return (NULL);

	slashed = strcat(slash, cmdS);
	for (iter = 0; dest[iter]; iter++)
	{
		patH = str_concat(dest[iter], slashed);
		slasher[iter] = malloc(sizeof(char) * (strlen(patH) + 1));
		if (slasher[iter] == NULL)
			return (NULL);
		strncpy(slasher[iter], patH, strlen(patH) + 1);
		free(patH), patH = NULL;
	}

	return (slasher);
}
