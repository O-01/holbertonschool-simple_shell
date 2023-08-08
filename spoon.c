#include "shell.h"

/**
 * spoon - manages input cmd, filtering through builtIn & access, then
 * calling forkExec if file exists & can be accessed
 * @input: CLI input
 * @cmd: the first element of input & command to be run, if possible
 * @argv: vector of arguments retrieved from input
 * Return: 0 success, 1 built-in called, otherwise respective err no.
 */

int spoon(char *input, char *cmd, char **argv)
{
	int iter = 0, tag = 0, hack = 0;
	char **feeD = NULL;

	hack = hacK(); /* verifies PATH & PWD for NULL value or N/A */
	if (builtIn(cmd, argv[1], input, argv) == 1) /* verifies if built-in */
		return (1);
	if (access(cmd, F_OK) == -1) /* command not found (as entered) */
	{
		if (hack == 1) /* PATH = NULL, therefore cannot be processed */
			return (127); /* not found, by default */
		feeD = obtainPATH(cmd); /* process PATH with '/' + '/command' */
		if (!feeD)
			return (127);
		for (iter = 0; feeD[iter]; iter++)
			if (!access(feeD[iter], X_OK))
			{ /* cmd exists & may be executed by current user */
				forkExec(input, feeD[iter], argv), tag = 1;
				break; /* fork/execute */
			}
		for (iter = 0; feeD[iter]; iter++)
			free(feeD[iter]), feeD[iter] = NULL;
		free(feeD);
		if (tag == 0) /* command not found (after processing) */
			return (127);
	}
	else /* command found (as entered) */
	{
		if (!access(cmd, X_OK)) /* may be executed by current user */
		{
			if (hack == 1 && cmd[0] != '/')
				return (127);
			forkExec(input, cmd, argv); /* fork/execute */
		}
		else if (!access(cmd, F_OK) && access(cmd, X_OK) == -1)
			return (13); /* cmd exists, exec permission denied */
		else
			return (127);
	}
	return (0);
}
