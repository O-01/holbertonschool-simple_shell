#include "shell.h"

/**
 * lePrompt - gets line from input and maintains prompt
 * @prmptStyle: How we want the prompt to look
 * @inPut: input received from stdin
 * @len: the length of the input from stdin
 * Return: the number of characters read, -1 upon EOF, 1 upon single line break
 */

ssize_t lePrompt(const char *prmptStyle, char **inPut, size_t *len)
{
	ssize_t gotLine = 0;

	if (isatty(STDIN_FILENO)) /* program in interactive mode */
		write(STDOUT_FILENO, prmptStyle, strlen(prmptStyle));

	gotLine = getline(inPut, len, stdin); /* retrieve line from stdin */
	if (gotLine == EOF)
		return (-1);
	if (!gotLine)
		return (1);

	return (gotLine);
}
