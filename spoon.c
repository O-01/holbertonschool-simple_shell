#include "shell.h"

/**
 * spoon - manages input cmd, filtering through builtIn & fileExist, then
 * calling forkExec if file exists & can be accessed
 * @input: CLI input
 * @cmd: the first element of input & command to be run, if possible
 * @argv: vector of arguments retrieved from input
 * @eXit: exit flag received from main, to be passed to forkExec
 * Return: 0 upon success, 1 if built-in called, -1 upon error
 */

int spoon(char *input, char *cmd, char **argv, int eXit)
{
	int i = 0, tag = 0, hack = 0;
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
		for (i = 0; feeD[i]; i++)
			if (!access(feeD[i], X_OK))
			{
				forkExec(input, feeD[i], argv, eXit), tag = 1;
				break;
			}
		for (i = 0; feeD[i]; i++)
			free(feeD[i]), feeD[i] = NULL;
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
			forkExec(input, cmd, argv, eXit);
		}
		else if (!access(cmd, F_OK) && access(cmd, X_OK) == -1)
			return (13);
		else
			return (127);
	}
	return (0);
}
