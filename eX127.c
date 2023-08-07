#include "shell.h"

/**
 * eX127 - prints error message to stderr for exit code 127
 * @cmd: command that is not found
 * @prog: name of program
 * @input: input passed from main
 * @cmdS: argument vector of tokenized strings from input
 * Return: 0 if exit failed
 */

int eX127(char *cmd, char *prog, char *input, char **cmdS)
{
	fprintf(stderr, "%s: 1: %s: not found\n", prog, cmd);

	if (!isatty(STDIN_FILENO))
		freecmdS(cmdS), free(input), input = NULL, exit(127);

	return (0);
}
