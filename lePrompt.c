#include "shell.h"

/**
 * lePrompt - gets line from input and maintains prompt
 * @prmptStyle: How we want the prompt to look
 * @inPut: input received from stdin
 * @len: the length of the input from stdin
 * Return: the number of characters read
 */

ssize_t lePrompt(const char *prmptStyle, char **inPut, size_t *len)
{
	ssize_t gotLine = 0;

	if (isatty(STDIN_FILENO))
		fprintf(stdout, "%s", prmptStyle);
	gotLine = getline(inPut, len, stdin);
	if (gotLine == EOF)
		return (-1);

	return (gotLine);
}
