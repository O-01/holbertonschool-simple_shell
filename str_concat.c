#include "shell.h"

/**
 * str_concat - concatenates two given strings
 * @dest: string to which src is to be concatenated "to"
 * @src: string concatenated to dest "from"
 * Return: pointer to result of concatenation in resp. freshly allocated memory
 */

char *str_concat(char *dest, char *src)
{
	size_t dIter = 0, sIter = 0, destLen = 0, srcLen = 0;
	char *combo = 0;

	if (dest == NULL)
		dest = "";
	if (src == NULL)
		src = "";

	destLen = strlen(dest), srcLen = strlen(src) + 1;

	combo = malloc((sizeof(char) * destLen) + (sizeof(char) * srcLen));
	if (combo == 0)
		return (NULL);

	for (; dest[dIter]; dIter++)
		combo[dIter] = dest[dIter];
	for (; src[sIter]; dIter++, sIter++)
		combo[dIter] = src[sIter];

	combo[dIter] = '\0';

	return (combo);
}
