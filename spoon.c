#include "shell.h"

/**
 * spoon - manages input cmd, filtering through builtIn & fileExist, then
 * calling forkExec if file exists & can be accessed
 * @input: CLI input
 * @cmd: the first element of input & command to be run, if possible
 * @argv: vector of arguments retrieved from input
 * @prog: name of program, passed to error functions
 * Return: 0 upon success, 1 if built-in called, -1 upon error
 */

int spoon(char *input, char *cmd, char **argv, char *prog)
{
	int iter = 0, flag = 0;
	char **feeD = NULL;

	if (builtIn(cmd, argv[1], input, argv) == 1)
		return (1);
	if (fileExist(cmd) == 0)
	{
		if (access(cmd, F_OK) == 0)
			forkExec(input, cmd, argv);
		else
		{
			perror(cmd);
			if (isatty(STDIN_FILENO) == 0)
				exit(13);
		}
	}
	else
	{
		feeD = obtainPath(cmd);
		if (!feeD && isatty(STDIN_FILENO) == 0)
			perror(cmd), exit(127);
		else if (!feeD)
			return (-1);
		for (iter = 0; feeD[iter]; iter++)
			if (fileExist(feeD[iter]) == 0 &&
			    access(feeD[iter], F_OK) == 0)
			{forkExec(input, feeD[iter], argv), flag = 1;
				break;
			}
		for (iter = 0; feeD[iter]; iter++)
			free(feeD[iter]), feeD[iter] = NULL;
		free(feeD);
		if (flag == 0)
		{
			eX127(cmd, prog);
			if (isatty(STDIN_FILENO) == 0)
				exit(127);
		}
	}
	return (0);
}

/**
 * eX127 - prints error message to stderr for exit code 127
 * @cmd: command that is not found
 * @prog: name of program
 * Return: 0 upon success
 */

int eX127(char *cmd, char *prog)
{
	fprintf(stderr, "%s: 1: %s: not found\n", prog, cmd);

	return (0);
}
