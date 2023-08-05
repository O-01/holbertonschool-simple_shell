#include "shell.h"

/**
 * spoon - manages input cmd, filtering through builtIn & fileExist, then
 * calling forkExec if file exists & can be accessed
 * @input: CLI input
 * @cmd: the first element of input & command to be run, if possible
 * @argv: vector of arguments retrieved from input
 * Return: 0 upon success, 1 if built-in called, -1 upon error
 */

int spoon(char *input, char *cmd, char **argv)
{
	int iter = 0, tag = 0, hack = 0;
	char **feeD = NULL;

	hack = hacK();
	if (builtIn(cmd, argv[1], input, argv) == 1)
		return (1);
	if (access(cmd, F_OK) == -1)
	{
		if (hack == 1)
			return (127);
		feeD = obtainPath(cmd);
		if (!feeD)
			return (127);
		for (iter = 0; feeD[iter]; iter++)
			if (!access(feeD[iter], X_OK))
			{
				forkExec(input, feeD[iter], argv), tag = 1;
				break;
			}
		for (iter = 0; feeD[iter]; iter++)
			free(feeD[iter]), feeD[iter] = NULL;
		free(feeD);
		if (tag == 0)
			return (127);
	}
	else
	{
		if (!access(cmd, X_OK))
		{
			if (hack == 1 && cmd[0] != '/')
				return (127);
			forkExec(input, cmd, argv);
		}
		else if (!access(cmd, F_OK) && access(cmd, X_OK) == -1)
			return (13);
		else
			return (127);
	}
	return (0);
}