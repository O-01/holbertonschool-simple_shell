#include "shell.h"

/**
 * eX13 - prints error message to stderr for exit code 13
 * @cmd: command that is denied permission
 * @prog: name of program
 * @input: input passed from main
 * @cmdS: argument vector of tokenized strings from input
 * Return: 0 if exit failed
 */

int eX13(char *cmd, char *prog, char *input, char **cmdS)
{
/*	fprintf(stderr, "%s: 1: %s: Permission denied\n", prog, cmd);*/
	(void)prog;

	perror(cmd);
	if (!isatty(STDIN_FILENO))
		freecmdS(cmdS), free(input), input = NULL, exit(13);

	return (0);
}
